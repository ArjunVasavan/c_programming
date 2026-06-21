#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct {

    int word_flag;
    int line_flag;
    int char_flag;
    int unkn_flag;

}flags ;

typedef struct {

    int l_count;
    int w_count;
    int c_count;
    //total is only printed when files are above 2
    int total_l;
    int total_w;
    int total_c;

} container;

void word_count(int fd, container *counter)
{
    char ch;
    int word_flag = 0;

    counter->w_count = 0;
    counter->l_count = 0;
    counter->c_count = 0;

    while (read(fd, &ch, 1) > 0) {

        counter->c_count++;
        counter->total_c++;

        if (ch == '\n') {
            counter->l_count++;
            counter->total_l++;
        }

        if (ch == ' ' || ch == '\n' || ch == '\t') {
            if (word_flag) {
                counter->w_count++;
                counter->total_w++;
                word_flag = 0;
            }
        } else {
            word_flag = 1;
        }
    }

    /* Count last word if file doesn't end with space */
    if (word_flag) {
        counter->w_count++;
        counter->total_w++;
    }
}


int main(int argc, char** argv) {

    flags f_count;
    container counter;

    f_count.word_flag=0;
    f_count.char_flag=0;
    f_count.line_flag=0;
    f_count.unkn_flag=0;

    int opt;
    while( (opt = getopt(argc,argv,"lwc")) != -1 ) {

        switch (opt) {
            case 'l': {
                f_count.line_flag+=1;
                break;
            }
            case 'w': {
                f_count.word_flag+=1;
                break;
            }
            case 'c': {
                f_count.char_flag+=1;
                break;
            }
            case '?': {
                f_count.unkn_flag+=1;
                break;
            }
            default:{
                printf("Default reached\n");
            }
        }
    }

    int number_of_files = argc - optind;

    printf("Number of files to be open are : %d\n",number_of_files);

    int fd[number_of_files];

    for ( int i = 0 ; i < number_of_files ; i++ ) {
        fd[i] = open(argv[optind],O_RDONLY);
        printf("Opened %s\n",argv[optind]);
        word_count(fd[i],&counter);
        if ( number_of_files > 1 ) {
            printf("%d %d %d\n",counter.l_count,counter.w_count,counter.c_count);
        } else {

            printf("%d %d %d %s\n",counter.l_count,counter.w_count,counter.c_count,argv[optind]);
        } 

        optind+=1;
    }

    if ( argc > 1 ) {

            printf("%d %d %d %s\n",counter.total_l,counter.total_w,counter.total_c,"total");

    }
        
}
