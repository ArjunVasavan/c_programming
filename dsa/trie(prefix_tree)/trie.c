#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


#define NUM_CHARS 256

typedef struct trienode {
    struct trienode* children[NUM_CHARS];
    bool terminal; /* to check wheather the trie is terminated */
} trienode;

trienode* create_node() {
    trienode* new_node = malloc(sizeof(trienode));

    for ( int i = 0; i < NUM_CHARS; i++) {
        new_node->children[i] = NULL;
    }
    new_node->terminal = false;
    return new_node;
}

bool trie_insert(trienode** root, char* signed_text) {

    if ( *root == NULL ) {
        *root = create_node();
    }

    unsigned char* text = (unsigned char*)signed_text;

    trienode* temp = *root;
    int length = strlen(signed_text);

    for ( int i = 0; i < length; i++) {
        if ( temp->children[text[i]] == NULL ) {
            temp->children[text[i]] = create_node();

        }
        temp = temp->children[text[i]];
    }

    if ( temp->terminal == true ) {
        return false; /* meaning this string was already present */
    } else {
        temp->terminal = true;
        return true;
    }
}

void trie_recursive_print( trienode* node, unsigned char* prefix, int length) {
    unsigned char new_prefix[length+2]; /* 1 - character adding, 1 - null character, 1 + 1 = 2 */
    memcpy(new_prefix, prefix, length);
    new_prefix[length] = '\0';

    if ( node->terminal ) {
        printf("Word is: %s\n", new_prefix);
    }

    for ( int i = 0; i < NUM_CHARS; i++) {
        if ( node->children[i] != NULL ) {
            new_prefix[length] = i;
            trie_recursive_print(node->children[i], new_prefix, length+1);
        }
    }
}

void trie_print(trienode* root) {
    if ( root == NULL ) {
        printf("trie is empty\n");
        return;
    }
    unsigned char prefix[2] = "";
    trie_recursive_print(root,prefix, 0);
}

int main(int argc, char** argv) {
    trienode* root = NULL;
    trie_insert(&root, "KIT");
    trie_insert(&root, "KATTLE");
    trie_insert(&root, "KITE");
    trie_insert(&root, "KID");
    trie_insert(&root, "KART");

    trie_print(root);
}
