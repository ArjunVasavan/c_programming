#include <stdio.h>      // printf
#include <unistd.h>     // getopt, optarg, optind

int main(int argc, char *argv[])
{
    int opt;            // Stores option returned by getopt()
    int verbose = 0;    // Flag for -v option
    char *name = NULL;  // Stores argument of -n option

    /*
     * getopt() LOOP
     *
     * IMPORTANT BEHAVIOR:
     * -------------------
     * GNU getopt() automatically REORDERS arguments.
     *
     * This means:
     *   Options (-v, -n) are processed first
     *   Normal arguments (files) are moved to the end
     *
     * So these commands behave the SAME:
     *   ./demo -v -n Arjun file1 file2
     *   ./demo file1 -v file2 -n Arjun
     */
    while ((opt = getopt(argc, argv, "vn:")) != -1) {

        switch (opt) {

        case 'v':
            /*
             * User passed -v
             * Enable verbose mode
             */
            verbose = 1;
            break;

        case 'n':
            /*
             * User passed -n <value>
             * getopt() automatically sets optarg to <value>
             */
            name = optarg;
            break;

        default:
            /*
             * Unknown option or missing argument
             */
            printf("Usage: %s [-v] [-n name] files...\n", argv[0]);
            return 1;
        }
    }

    /*
     * After getopt() finishes:
     *
     * optind now points to the FIRST non-option argument
     *
     * getopt() has already:
     *   - parsed all options
     *   - rearranged argv internally (GNU behavior)
     */
    if (verbose) {
        printf("Verbose mode enabled\n");
    }

    if (name != NULL) {
        printf("Hello %s\n", name);
    }

    /*
     * Process remaining arguments (files)
     * Always start from optind
     */
    printf("Files provided:\n");

    for (int i = optind; i < argc; i++) {
        printf("  %s\n", argv[i]);
    }

    return 0;
}

