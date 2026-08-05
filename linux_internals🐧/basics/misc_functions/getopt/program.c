#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int opt;

    while ((opt = getopt(argc, argv, "abf:")) != -1) {
        switch (opt) {
        case 'a':
            printf("Option -a\n");
            break;

        case 'b':
            printf("Option -b\n");
            break;

        case 'f':
            printf("File: %s\n", optarg);
            break;

        case '?':
            printf("Unknown option: -%c\n", optopt);
            break;
        }
    }

    return 0;
}

