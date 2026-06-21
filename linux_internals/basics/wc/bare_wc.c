#include <stdio.h>

int main(int argc, char** argv) {
    
    FILE* fptr = fopen("text.txt","r");
    if (!fptr) {
        printf("Cannot open file\n");
        return 1;
    }

    int ch = 0;

    int char_count = 0; 
    int line_count = 0;
    int word_count = 0;

    int its_a_word = 0;
    int edge_case = 0;

    while (1) {

        ch = getc(fptr);

        if (char_count == 0 && ch == EOF) {   // empty file
            break;
        }

        if (ch == EOF) {   // end of file
            if (its_a_word == 1) { 
                word_count++; 
                its_a_word = 0;
            }
            if (edge_case == 1) { 
                line_count++; 
            }
            break;
        }

        char_count++;

        // line detection
        if (ch == '\n') {
            line_count++;
            edge_case = 0;  
        } else {
            edge_case = 1;  
        }

        // start of a word (alphabet only)
        if (((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) 
            && its_a_word == 0) {
            its_a_word = 1;
        }

        // end of a word
        if ((ch == ' ' || ch == '\n') && its_a_word == 1) {
            word_count++;
            its_a_word = 0;
        }
    }

    printf("Line count = %d\n", line_count);
    printf("Character count = %d\n", char_count);
    printf("Word count = %d\n", word_count);

    fclose(fptr);

    return 0;
}

