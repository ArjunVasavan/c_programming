#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "one,two,three,four";   // String to be tokenized
    const char delimiter[2] = ",";       // Delimiter (comma)
    char *token;

    // Get the first token
    token = strtok(str, delimiter);

    // Walk through other tokens
    while (token != NULL) {
        printf("Token: %s\n", token);

        // Get next token
        token = strtok(NULL, delimiter);
    }

    return 0;
}

