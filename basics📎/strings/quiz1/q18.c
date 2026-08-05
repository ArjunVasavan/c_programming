/* Great question! The compiler knows `\060` is octal because of the **syntax rules** for escape sequences in C: */

/* ## Escape Sequence Rules: */
/* - `\` followed by **1-3 octal digits (0-7)** = octal escape sequence */
/* - `\0` = shorthand for `\000` (null character) */
/* - `\x` followed by hex digits = hex escape sequence */

/* ## Why `\060` is interpreted as octal: */
/* ```c */
/* \060 */
/* ^   ^ */
/* |   |-- octal digits: 0, 6, 0 */
/* |------ escape character */
/* ``` */

/* The compiler sees: */
/* 1. `\` - "This is an escape sequence" */
/* 2. `060` - "These are octal digits (0-7), so this is octal" */
/* 3. Converts: `060₈ = 48₁₀` = character '0' */

/* ## Comparison: */
/* ```c */
/* char a[] = "\0";     // \0 = null character (special case) */
/* char a[] = "\000";   // \000 = octal for null (0) */
/* char a[] = "\060";   // \060 = octal for '0' character (48) */
/* char a[] = "\x00";   // \x00 = hex for null */
/* char a[] = "\x30";   // \x30 = hex for '0' character (48) */
/* ``` */

/* The compiler doesn't "decide" what you meant - it follows **fixed syntax rules**. `\060` has 3 octal digits, so it's parsed as octal and equals 48 (character '0'), not 0 (null character). */

/* It's not magic - it's just following the language specification! */

#include <stdio.h>


int main(void) {
char a[] = "\060"; /* octal escape for '0' */
printf("%s %zu\n", a, sizeof(a));
return 0;
}
