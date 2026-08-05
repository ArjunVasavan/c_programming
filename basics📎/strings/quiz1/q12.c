/* Alright Arjun — here’s the clear, beginner‑to‑pro breakdown of **`memcpy`** in C. */  

/* --- */

/* ## 📌 What is `memcpy`? */
/* - **Purpose**: Copies a block of memory from one location to another. */
/* - **Prototype** (from `<string.h>`): */
/*   ```c */
/*   void *memcpy(void *dest, const void *src, size_t n); */
/*   ``` */
/* - **Parameters**: */
/*   - `dest` → pointer to the destination memory block. */
/*   - `src` → pointer to the source memory block. */
/*   - `n` → number of bytes to copy (type `size_t`). */
/* - **Return value**: Returns `dest` (so you can chain calls if you want). */

/* --- */

/* ## 🧠 Key Points */
/* - **Binary copy**: Works on raw bytes, not just strings — can copy any type of data. */
/* - **No null‑terminator awareness**: Unlike `strcpy`, it doesn’t stop at `'\0'`; it copies exactly `n` bytes. */
/* - **Fast**: Usually optimized by the compiler or CPU instructions. */
/* - **Danger**: If `src` and `dest` **overlap**, behavior is **undefined** — use `memmove` instead. */

/* --- */

/* ## 🛠 Example */

/* ```c */
/* #include <stdio.h> */
/* #include <string.h> */

/* int main() { */
/*     char src[] = "Hello"; */
/*     char dest[10]; */

/*     memcpy(dest, src, strlen(src) + 1); // +1 to copy '\0' */
/*     printf("Copied string: %s\n", dest); */
/*     return 0; */
/* } */
/* ``` */

/* **Output:** */
/* ``` */
/* Copied string: Hello */
/* ``` */

/* --- */

/* ## ⚠️ Common Mistakes */
/* - Forgetting to copy the null terminator when dealing with strings: */
/*   ```c */
/*   memcpy(dest, src, strlen(src)); // ❌ Missing '\0' */
/*   ``` */
/* - Using it with overlapping memory regions — leads to corrupted data: */
/*   ```c */
/*   memcpy(s + 2, s, 5); // ❌ Undefined behavior if regions overlap */
/*   ``` */

/* --- */

/* 💡 **Rule of thumb**: */  
/* - Use `memcpy` for **non‑overlapping** raw memory copies. */  
/* - Use `memmove` if there’s any chance of overlap. */  

/* --- */

/* If you want, I can also give you a **visual byte‑by‑byte diagram** showing
 * how `memcpy` works internally — that makes it super easy to remember for interviews and debugging. Would you like me to prepare that? */


#include <stdio.h>
#include <string.h>


int main(void) {
char s[] = "1234567";
memcpy(s + 2, s, 5);
printf("%s\n", s);
return 0;
}
