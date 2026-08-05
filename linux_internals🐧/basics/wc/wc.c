/*

╔════════════════════════════════════════════════════════════════════════════╗
║                          DOCUMENT SPECIFICATION                            ║
╠════════════════════════════════════════════════════════════════════════════╣
║                                                                            ║
║  AUTHOR           : Arjun Vasavan                                          ║
║  DATE             : December 03, 2025                                      ║
║  DESCRIPTION      : Program to implement my own wc command                 ║
║                                                                            ║
║                                                                            ║
╚════════════════════════════════════════════════════════════════════════════╝

SAMPLE EXECUTION

════════════════════════════════════════════════════════════════════════════════

1.When no arguments or file is  passed 

./word_count

Hai hello world

1 3 16 lines words characters
Reads from stdin till EOF (ctrl + d) and count lines words and bytes.


2. When one file passed

./word_count file.txt

 10 20 45
Reads from file till EOF (ctrl + d) and count lines words and bytes.


3.When Mutilple files are passed

./word_count f1.txt f2.txt

5 7 40 f1.txt

3 4 10 f2.txt

8 11 50 total


3. When options passed (-l, -w, -c).

./word_count file.txt –l –w
 
10 20
 

════════════════════════════════════════════════════════════════════════════════
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void printing_part(char* file_name, int line_count, int word_count,
                   int character_count, int line_flag, int word_flag,
                   int character_flag){

    if ( line_flag == 0 && word_flag == 0 && character_flag == 0 ){

        printf("\n%d %d %d %s\n",line_count,word_count,character_count,file_name);

    } else if ( line_flag && word_flag) {

        printf("\n%d %d %s\n",line_count,word_count,file_name);

    } else if (line_flag && character_flag ) {

        printf("\n%d %d %s\n",line_count,character_count,file_name);

    } else if ( word_flag && character_flag ) {

        printf("\n%d %d %s\n",word_count,character_count,file_name);

    } else if (line_flag) {

        printf("\n%d %s\n",line_count,file_name);

    } else if (word_flag) {

        printf("\n%d %s\n",word_count,file_name);

    } else if (character_flag) {

        printf("\n%d %s\n",character_count,file_name);

    }


}

void total_print( int total_line, int total_word, int total_character, int line_flag, 
                 int word_flag, int character_flag){


    if ( line_flag == 0 && word_flag == 0 && character_flag == 0 ){

        printf("\n%d %d %d %s\n",total_line,total_word,total_character,"total");

    } else if ( line_flag && word_flag) {

        printf("\n%d %d %s\n",total_line,total_word,"total");

    } else if (line_flag && character_flag ) {

        printf("\n%d %d %s\n",total_line,total_character,"total");

    } else if ( word_flag && character_flag ) {

        printf("\n%d %d %s\n",total_word,total_character,"total");

    } else if (line_flag) {

        printf("\n%d %s\n",total_line,"total");

    } else if (word_flag) {

        printf("\n%d %s\n",total_word,"total");

    } else if (character_flag) {

        printf("\n%d %s\n",total_character,"total");

    }
}

void my_wc(char* file_name, int* line_count, int* word_count, int* character_count){

    FILE* fd;

    *line_count = 0;
    *word_count = 0;
    *character_count = 0;


    if ( file_name == NULL ){

        fd = stdin;

    } else {

        fd = fopen(file_name,"r");

    }

    if ( fd == NULL ){
        printf("[ERROR] at fd\n");
    }

    int inside_word = 0;
    int edge_case = 0;
    int ch;
    while (1) {

        ch = getc(fd);


        if( ch == EOF ){

            if(inside_word == 1){

                (*word_count)+=1;
                inside_word = 0;
            }
            if(edge_case == 1){
                (*line_count)+=1;
            }

            return;
        }

        if ( ch == '\n' ){
            (*line_count)+=1;
            edge_case = 0;
        } else {

            edge_case = 1;
        }

        (*character_count)+=1;

        if( ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) && ( inside_word == 0 ) ){

            inside_word = 1;

        }

        if ( ( ch == ' ' || ch == '\n' ) && inside_word == 1 ){
            (*word_count)+=1;
            inside_word = 0;
        }

    }
}
int main(int argc, char** argv) {

    int line_flag = 0 , word_flag = 0 , character_flag = 0;

    int line_count = 0, word_count = 0 , character_count = 0;

    int total_line = 0 , total_word = 0 , total_character = 0;

    int return_value;


    while ( (return_value = getopt(argc,argv,"lwc")) != -1 ) {

        switch (return_value) {

            case 'l':{

                line_flag+=1;
                break;
            }

            case 'w':{

                word_flag+=1;
                break;
            }

            case 'c':{

                character_flag+=1;
                break;
            }

            case '?':{

                printf("Unknown ?\n");
                exit(1);
                break;
            }

        }

    }

    if (optind >= argc) {
        my_wc(NULL, &line_count, &word_count, &character_count);
        printing_part("stdin", line_count, word_count, character_count,
                      line_flag, word_flag, character_flag);
        return 0;
    } else {

        int more_than_one_file = 0;
        int count;
        if ( (argc - optind) >= 2 ){
            more_than_one_file = 1;
        }


        for ( int i = optind ; i < argc ;i++){

            int line_count = 0, word_count = 0 , character_count = 0;

            my_wc(argv[i],&line_count,&word_count,&character_count);

            printing_part(argv[i],line_count,word_count,character_count,line_flag,word_flag,character_flag);

            if ( more_than_one_file == 1){

                total_line += line_count;
                total_word += word_count;
                total_character += character_count;
            }
        }

        if ( more_than_one_file == 1 ){

            total_print(total_line,total_word,total_character,line_flag,word_flag,character_flag);

        }
    }

}
