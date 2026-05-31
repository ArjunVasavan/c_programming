/* # Extreme C string quiz — 24 brutal questions */

/* **Instructions**: For each question below, read the C program, determine its output (or whether it exhibits undefined behavior), and choose the correct option (A–D). These are intentionally tricky — many test sequence points, pointer arithmetic, hidden `\0` bytes, overlapping copies, and platform-independent edge cases. **No answers are shown.** */

/* --- */

/* ### Question 1 */

/* ```c */
/* #include <stdio.h> */
/* #include <string.h> */

/* int main(void) { */
/*     char s[] = "1234567"; */
/*     memcpy(s + 2, s, 5); */
/*     printf("%s\n", s); */
/*     return 0; */
/* } */
/* ``` */

/* A) `1212347` */
/* B) `121234567` */
/* C) `1234123` */
/* D) Undefined behavior (because `memcpy` with overlapping ranges) */

/* --- */

/* ### Question 2 */

/* ```c */
/* #include <stdio.h> */

/* int main(void) { */
/*     char *p = "ABC"; */
/*     printf("%c %c\n", *p, *++p); */
/*     return 0; */
/* } */
/* ``` */

/* A) `A A` */
/* B) `A B` */
/* C) `B C` */
/* D) Undefined behavior (due to unsequenced modification/access of `p` in one call) */

/* --- */

/* ### Question 3 */

/* ```c */
/* #include <stdio.h> */

/* int main(void) { */
/*     char s[] = { 'x', 'y', 'z' }; */
/*     printf("%s\n", s); */
/*     return 0; */
/* } */
/* ``` */

/* A) `xyz` then newline */
/* B) prints `xyz` followed by garbage until a `\0` is found */
/* C) prints nothing (blank line) */
/* D) Compile-time error */

/* --- */

/* ### Question 4 */

/* ```c */
/* #include <stdio.h> */
/* #include <string.h> */

/* int main(void) { */
/*     char s1[6] = "hello"; */
/*     strncat(s1, "WORLD", 3); */
/*     printf("%s\n", s1); */
/*     return 0; */
/* } */
/* ``` */

/* A) `helloWOR` */
/* B) `helloW` */
/* C) `helloWORLD` */
/* D) Undefined behavior (buffer overflow) */

/* --- */

/* ### Question 5 */

/* ```c */
/* #include <stdio.h> */

/* int main(void) { */
/*     char *p = "12" "34"; */
/*     printf("%c %c\n", *(p+1), p[2]); */
/*     return 0; */
/* } */
/* ``` */

/* A) `1 2` */
/* B) `2 3` */
/* C) `2 4` */
/* D) `3 4` */

/* --- */

/* ### Question 6 */

/* ```c */
/* #include <stdio.h> */

/* int main(void) { */
/*     char s[] = "ab\0cd"; */
/*     printf("%zu %c %c\n", sizeof(s), s[2], s[3]); */
/*     return 0; */
/* } */
/* ``` */

/* A) `5 \0 c` */
/* B) `6 \0 c` */
/* C) `5 c d` */
/* D) `6 c d` */

/* --- */

/* ### Question 7 */

/* ```c */
/* #include <stdio.h> */
/* #include <string.h> */

/* int main(void) { */
/*     char s[5] = "AB"; */
/*     memcpy(s+2, "CDEF", 3); */
/*     printf("%s\n", s); */
/*     return 0; */
/* } */
/* ``` */

/* A) `ABCDEF` */
/* B) `ABC` */
/* C) `ABCD` */
/* D) Undefined behavior (no room for full copy) */

/* --- */

/* ### Question 8 */

/* ```c */
/* #include <stdio.h> */

/* int main(void) { */
/*     char a[] = "\060"; /1* octal escape for '0' *1/ */
/*     printf("%s %zu\n", a, sizeof(a)); */
/*     return 0; */
/* } */
/* ``` */

/* A) `0 2` */
/* B) `60 3` */
/* C) `\060 4` */
/* D) `0 3` */

/* --- */

/* ### Question 9 */

/* ```c */
/* #include <stdio.h> */

/* int main(void) { */
/*     char s[] = "hello"; */
/*     char *p = s + 5; */
/*     printf("%d\n", (int)(p - s)); */
/*     return 0; */
/* } */
/* ``` */

/* A) `4` */
/* B) `5` */
/* C) `6` */
/* D) Undefined behavior (pointer one-past-end used) */

/* --- */

/* ### Question 10 */

/* ```c */
/* #include <stdio.h> */

/* int main(void) { */
/*     char s[] = "ab"; */
/*     char *p = s; */
/*     *p++; */
/*     printf("%s\n", s); */
/*     return 0; */
/* } */
/* ``` */

/* A) `ab` */
/* B) `b` */
/* C) empty line */
/* D) undefined behavior */

/* --- */

/* ### Question 11 */

/* ```c */
/* #include <stdio.h> */
/* #include <string.h> */

/* int main(void) { */
/*     char s1[4] = "abc"; */
/*     char s2[] = "XYZ"; */
/*     memcpy(s1+1, s2, 3); */
/*     printf("%s\n", s1); */
/*     return 0; */
/* } */
/* ``` */

/* A) `aXYZ` */
/* B) `aXY` */
/* C) `aXYZ\0` printed as `aXYZ` */
/* D) Undefined behavior (no terminating `\0`) */

/* --- */

/* ### Question 12 */

/* ```c */
/* #include <stdio.h> */

/* int main(void) { */
/*     char s[] = "\x41\x42"; /1* 'A' 'B' *1/ */
/*     printf("%c %c\n", s[0], s[1]); */
/*     return 0; */
/* } */
/* ``` */

/* A) `A B` */
/* B) `AB` alone on a line */
/* C) prints integer values 65 66 */
/* D) Undefined behavior */

/* --- */

/* ### Question 13 */

/* ```c */
/* #include <stdio.h> */

/* int main(void) { */
/*     char s[] = "hello"; */
/*     printf("%zu %zu\n", strlen(s), sizeof(s)); */
/*     return 0; */
/* } */
/* ``` */

/* A) `5 5` */
/* B) `5 6` */
/* C) `6 6` */
/* D) `6 5` */

/* --- */

/* ### Question 14 */

/* ```c */
/* #include <stdio.h> */

/* int main(void) { */
/*     char s[] = "abc"; */
/*     char *p = s + 1; */
/*     *(p++) = 'X'; */
/*     printf("%s\n", s); */
/*     return 0; */
/* } */
/* ``` */

/* A) `aXc` */
/* B) `aXc` with undefined behavior */
/* C) `aXc\0` printed as `aXc` */
/* D) `abc` */

/* --- */

/* ### Question 15 */

/* ```c */
/* #include <stdio.h> */
/* #include <string.h> */

/* int main(void) { */
/*     char s1[5] = "foo"; */
/*     strncat(s1, "bar", 2); */
/*     printf("%s\n", s1); */
/*     return 0; */
/* } */
/* ``` */

/* A) `foobar` */
/* B) `fooba` */
/* C) `foor` */
/* D) Undefined behavior (no space for result) */

/* --- */

/* ### Question 16 */

/* ```c */
/* #include <stdio.h> */

/* int main(void) { */
/*     char *p = "xyz"; */
/*     if (p[0] == 'x') */
/*         p[0] = 'X'; */
/*     printf("%s\n", p); */
/*     return 0; */
/* } */
/* ``` */

/* A) `Xyz` */
/* B) `xyz` */
/* C) Compile-time error */
/* D) Undefined behavior (attempt to modify string literal) */

/* --- */

/* ### Question 17 */

/* ```c */
/* #include <stdio.h> */

/* int main(void) { */
/*     char s[4] = "ab"; /1* room for 4 bytes *1/ */
/*     s[3] = 'Z'; */
/*     printf("%c %d\n", s[3], (int)sizeof(s)); */
/*     return 0; */
/* } */
/* ``` */

/* A) `Z 4` */
/* B) `Z 3` */
/* C) garbage */
/* D) Undefined behavior */

/* --- */

/* ### Question 18 */

/* ```c */
/* #include <stdio.h> */

/* int main(void) { */
/*     char s[] = "\0ABC"; */
/*     printf("%s %c\n", s, s[1]); */
/*     return 0; */
/* } */
/* ``` */

/* A) prints empty line then `A` */
/* B) prints `\0ABC` then `A` */
/* C) prints `ABC A` */
/* D) Compile-time error */

/* --- */

/* ### Question 19 */

/* ```c */
/* #include <stdio.h> */

/* int main(void) { */
/*     char s[] = "1234"; */
/*     char *p = s + 1; */
/*     *(p += 2) = 'X'; */
/*     printf("%s\n", s); */
/*     return 0; */
/* } */
/* ``` */

/* A) `12X4` */
/* B) `1X34` */
/* C) `123X` */
/* D) Undefined behavior */

/* --- */

/* ### Question 20 */

/* ```c */
/* #include <stdio.h> */

/* int main(void) { */
/*     char s[] = "a\nb"; */
/*     printf("%s\n", s); */
/*     printf("%c\n", s[1]); */
/*     return 0; */
/* } */
/* ``` */

/* A) prints `a` newline `b` on separate lines */
/* B) prints `a` then a newline then prints `\n` (visibly blank) */
/* C) prints `a\nb` literally */
/* D) undefined behavior */

/* --- */

/* ### Question 21 */

/* ```c */
/* #include <stdio.h> */

/* int main(void) { */
/*     char s[3] = { 'a', 'b', '\0' }; */
/*     char *p = s + 2; */
/*     printf("%d\n", *(p - 3)); */
/*     return 0; */
/* } */
/* ``` */

/* A) prints ASCII code for `a` */
/* B) prints ASCII code for `b` */
/* C) prints `0` */
/* D) Undefined behavior (out-of-bounds access) */

/* --- */

/* ### Question 22 */

/* ```c */
/* #include <stdio.h> */
/* #include <string.h> */

/* int main(void) { */
/*     char s1[8] = "1234"; */
/*     memmove(s1+1, s1, 4); */
/*     printf("%s\n", s1); */
/*     return 0; */
/* } */
/* ``` */

/* A) `11234` */
/* B) `12341234` */
/* C) `1 1234` */
/* D) Undefined behavior */

/* --- */

/* ### Question 23 */

/* ```c */
/* #include <stdio.h> */

/* int main(void) { */
/*     char s[] = "\x30\012"; /1* '\x30' = '0', '\012' = '\n' *1/ */
/*     printf("%zu %d %d\n", sizeof(s), s[0], s[1]); */
/*     return 0; */
/* } */
/* ``` */

/* A) `3 48 10` */
/* B) `4 48 10` */
/* C) `3 48 49` */
/* D) `2 48 10` */

/* --- */

/* ### Question 24 */

/* ```c */
/* #include <stdio.h> */

/* int main(void) { */
/*     char s[] = "ab" "cd"; */
/*     printf("%zu %s\n", sizeof(s), s); */
/*     return 0; */
/* } */
/* ``` */

/* A) `5 abcd` */
/* B) `4 abcd` */
/* C) `5 abcd\0` printed as `abcd` */
/* D) `6 abcd` */

/* --- */

/* **If you want**: tell me whether to (A) give the full answer key, (B) give detailed explanations for any subset you choose, or (C) convert this into a printable PDF/markdown or spaced quiz for a test. Pick one and I’ll proceed. */

