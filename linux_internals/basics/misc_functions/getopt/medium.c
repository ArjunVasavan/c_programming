#include <stdio.h>      // For printf()
#include <unistd.h>     // For getopt(), optarg, optind

int main(int argc, char *argv[])
{
    int opt;            // Will store the option returned by getopt()
    int verbose = 0;    // Flag to check if -v was given
    char *name = NULL;  // Pointer to store value given with -n

    /*
     * getopt() loop:
     * - Reads one option at a time from argv
     * - "vn:" means:
     *      v  -> option -v (no argument)
     *      n: -> option -n requires an argument
     */
    while ((opt = getopt(argc, argv, "vn:")) != -1) {

        /*
         * Check which option getopt() returned
         */
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
             * optarg automatically points to <value>
             */
            name = optarg;
            break;

        default:
            /*
             * If an unknown option is passed
             * Print usage message and exit
             */
            printf("Usage: %s [-v] [-n name] files...\n", argv[0]);
            return 1;
        }
    }

    /*
     * After getopt() finishes:
     * optind points to the first non-option argument
     */

    if (verbose) {
        /*
         * If -v was provided, print extra info
         */
        printf("Verbose mode ON\n");
    }

    if (name != NULL) {
        /*
         * If -n was provided, print the name
         */
        printf("Hello %s\n", name);
    }

    /*
     * Remaining arguments (files, etc.)
     * Start from optind, NOT from 1
     */
    printf("Remaining arguments:\n");

    for (int i = optind; i < argc; i++) {
        /*
         * Print each non-option argument
         */
        printf("  %s\n", argv[i]);
    }

    return 0;   // Program finished successfully
}

