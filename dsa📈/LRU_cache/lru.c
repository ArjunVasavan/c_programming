#include <stdio.h>
#include <stdlib.h>

/* NOTE: Working of LRU cache 

   We keep all items in a DOUBLY LINKED LIST.
     - The HEAD side of the list = most recently used item.
     - The TAIL side of the list  = least recently used item.

   Every time an item is used (get or put), we move it to the HEAD.
   When the cache is full and we need to make room, we remove
   whatever is at the TAIL, because that's the item nobody has
   touched in the longest time.

   The problem: searching a linked list to find a key takes too long
   (one by one, from head to tail).

   The fix: we also keep a HASH TABLE that maps key -> pointer to the
   node in the linked list. So finding a node is instant, and once we
   have the pointer, moving it around the list is also instant.

   So: hash table = fast lookup, linked list = fast reordering.
*/

#define CAPACITY 3          /* how many items the cache can hold */
#define HASH_SIZE 10        /* number of buckets in our hash table */

/* One item stored in the cache. It lives inside the linked list. */
typedef struct Node {
    int key;
    int value;
    struct Node *prev;
    struct Node *next;
    struct Node *hash_next; /* used to chain nodes inside the same hash bucket */
} Node;

typedef struct {
    Node *head;             /* most recently used item */
    Node *tail;             /* least recently used item */
    Node *buckets[HASH_SIZE]; /* the hash table itself */
    int size;               /* how many items are currently stored */
} LRUCache;

/* Very basic hash function: just spread keys across the buckets */
int hash(int key) {
    if (key < 0) key = -key;
    return key % HASH_SIZE;
}

/* Create an empty cache */
LRUCache *create_cache() {
    LRUCache *cache = malloc(sizeof(LRUCache));
    cache->head = NULL;
    cache->tail = NULL;
    cache->size = 0;
    for (int i = 0; i < HASH_SIZE; i++) {
        cache->buckets[i] = NULL;
    }
    return cache;
}

/* Look up a node by key using the hash table. Returns NULL if not found. */
Node *find_node(LRUCache *cache, int key) {
    int idx = hash(key);
    Node *node = cache->buckets[idx];
    while (node != NULL) {
        if (node->key == key) return node;
        node = node->hash_next; /* check next node in this bucket's chain */
    }
    return NULL;
}

/* Add a node into the hash table so we can find it quickly later */
void hash_insert(LRUCache *cache, Node *node) {
    int idx = hash(node->key);
    node->hash_next = cache->buckets[idx]; /* put it at the front of the chain */
    cache->buckets[idx] = node;
}

/* Remove a node from the hash table (needed when we evict it) */
void hash_remove(LRUCache *cache, Node *node) {
    int idx = hash(node->key);
    Node *curr = cache->buckets[idx];
    Node *prev = NULL;
    while (curr != NULL) {
        if (curr == node) {
            if (prev == NULL) cache->buckets[idx] = curr->hash_next;
            else prev->hash_next = curr->hash_next;
            return;
        }
        prev = curr;
        curr = curr->hash_next;
    }
}

/* Unhook a node from the linked list (its neighbors get reconnected) */
void list_remove(LRUCache *cache, Node *node) {
    if (node->prev) node->prev->next = node->next;
    else cache->head = node->next; /* it was the head */

    if (node->next) node->next->prev = node->prev;
    else cache->tail = node->prev; /* it was the tail */
}

/* Place a node at the head of the list (marks it as "just used") */
void list_push_front(LRUCache *cache, Node *node) {
    node->prev = NULL;
    node->next = cache->head;
    if (cache->head) cache->head->prev = node;
    cache->head = node;
    if (cache->tail == NULL) cache->tail = node; /* list was empty before */
}

/* Move an already-existing node to the head (used it, so it's fresh again) */
void move_to_front(LRUCache *cache, Node *node) {
    if (cache->head == node) return; /* already at the front, nothing to do */
    list_remove(cache, node);
    list_push_front(cache, node);
}

/* Get a value from the cache. Returns -1 if the key isn't found. */
int cache_get(LRUCache *cache, int key) {
    Node *node = find_node(cache, key);
    if (node == NULL) {
        printf("GET %d -> not found\n", key);
        return -1;
    }
    move_to_front(cache, node); /* using it makes it "recently used" */
    printf("GET %d -> %d\n", key, node->value);
    return node->value;
}

/* Add or update a key/value pair in the cache */
void cache_put(LRUCache *cache, int key, int value) {
    Node *existing = find_node(cache, key);

    if (existing != NULL) {
        /* key already in cache: just update its value and refresh it */
        existing->value = value;
        move_to_front(cache, existing);
        printf("PUT %d=%d (updated)\n", key, value);
        return;
    }

    /* cache full: evict the least recently used item (the tail) */
    if (cache->size == CAPACITY) {
        Node *lru = cache->tail;
        printf("Cache full: evicting key %d\n", lru->key);
        list_remove(cache, lru);
        hash_remove(cache, lru);
        free(lru);
        cache->size--;
    }

    /* create the new node and add it to both structures */
    Node *node = malloc(sizeof(Node));
    node->key = key;
    node->value = value;

    list_push_front(cache, node);
    hash_insert(cache, node);
    cache->size++;

    printf("PUT %d=%d (new)\n", key, value);
}

/* Print the cache from most-recently-used to least-recently-used */
void print_cache(LRUCache *cache) {
    printf("Cache (MRU -> LRU): ");
    Node *node = cache->head;
    while (node != NULL) {
        printf("[%d=%d] ", node->key, node->value);
        node = node->next;
    }
    printf("\n");
}

int main() {
    LRUCache *cache = create_cache(); /* capacity is 3, see CAPACITY above */

    cache_put(cache, 1, 100);
    cache_put(cache, 2, 200);
    cache_put(cache, 3, 300);
    print_cache(cache);              /* [3] [2] [1] */

    cache_get(cache, 1);             /* 1 becomes most recently used */
    print_cache(cache);              /* [1] [3] [2] */

    cache_put(cache, 4, 400);        /* cache full -> evicts 2 (least recently used) */
    print_cache(cache);              /* [4] [1] [3] */

    cache_get(cache, 2);             /* not found, was evicted */

    return 0;
}
