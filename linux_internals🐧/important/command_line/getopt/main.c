/*
 * getopt_example.c
 *
 * Demonstrates how to use getopt() for parsing command-line options in C.
 *
 * Usage:
 *   ./getopt_example [-v] [-h] [-o outputfile] [-n number]
 *
 * Options:
 *   -v             Enable verbose mode (flag, no argument)
 *   -h             Show help message (flag, no argument)
 *   -o <file>      Specify output file (requires an argument)
 *   -n <number>    Specify a number   (requires an argument)
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>   /* getopt() lives here on POSIX systems */

/* ---------------------------------------------------------------
 * print_help
 *   Prints a usage/help message to stdout.
 *   argc/argv are not needed here, so the function takes no args.
 * --------------------------------------------------------------- */
void print_help(void)
{
    printf("Usage: getopt_example [-v] [-h] [-o file] [-n number]\n");
    printf("  -v          Enable verbose mode\n");
    printf("  -h          Show this help message\n");
    printf("  -o <file>   Set output filename\n");
    printf("  -n <num>    Set a numeric value\n");
}

/* ---------------------------------------------------------------
 * main
 *   Entry point. getopt() is called in a loop to consume each
 *   option flag from the argv array.
 * --------------------------------------------------------------- */
int main(int argc, char *argv[])
{
    int   opt;             /* Holds the character returned by getopt()   */
    int   verbose  = 0;    /* Flag: set to 1 when -v is passed           */
    int   number   = 0;    /* Value supplied with -n                     */
    char *outfile  = NULL; /* Pointer to the argument string for -o      */

    /*
     * getopt() option string: "vho:n:"
     *
     *  v   -> flag only,        no argument  (-v)
     *  h   -> flag only,        no argument  (-h)
     *  o:  -> requires argument after colon  (-o file)
     *  n:  -> requires argument after colon  (-n 42)
     *
     * A leading ':' in the string (e.g. ":vho:n:") makes getopt()
     * return ':' for a missing argument instead of '?', which lets
     * you distinguish "unknown option" from "missing argument".
     */
    while ((opt = getopt(argc, argv, "vho:n:")) != -1) {

        /*
         * getopt() returns -1 when there are no more options to parse,
         * which ends the loop. For each recognised option it returns
         * the option character; for an unrecognised one it returns '?'.
         */
        switch (opt) {

        case 'v':
            /* -v has no argument; simply set the verbose flag. */
            verbose = 1;
            printf("[getopt] verbose mode enabled\n");
            break;

        case 'h':
            /* -h has no argument; print help and exit immediately. */
            print_help();
            return 0;

        case 'o':
            /*
             * optarg is a global pointer set by getopt() to point at
             * the argument string that follows the option, e.g.
             *   -o report.txt   -> optarg == "report.txt"
             */
            outfile = optarg;
            printf("[getopt] output file set to: %s\n", outfile);
            break;

        case 'n':
            /*
             * Convert the argument string to an integer with atoi().
             * optarg is still the raw string, so conversion is manual.
             */
            number = atoi(optarg);
            printf("[getopt] number set to: %d\n", number);
            break;

        case '?':
            /*
             * getopt() already prints an error like:
             *   "illegal option -- X"
             * We just remind the user how to get help.
             */
            fprintf(stderr, "Unknown option. Use -h for help.\n");
            return 1;

        default:
            /* Should never reach here, but good practice to handle it. */
            fprintf(stderr, "Unexpected getopt return value: %c\n", opt);
            return 1;
        }
    }

    /*
     * After getopt() finishes, optind is the index in argv of the
     * first non-option argument (i.e. a plain filename or word that
     * was not preceded by a '-' flag).
     *
     * Example:  ./prog -v -o out.txt  file1.txt file2.txt
     *           After the loop, argv[optind] == "file1.txt"
     */
    if (optind < argc) {
        int i;
        printf("\nNon-option arguments (plain arguments after all flags):\n");
        for (i = optind; i < argc; i++) {
            printf("  argv[%d] = %s\n", i, argv[i]);
        }
    }

    /* ---- Summary of what was parsed ---- */
    printf("\n--- Parsed options summary ---\n");
    printf("  verbose : %s\n",  verbose ? "yes" : "no");
    printf("  outfile : %s\n",  outfile  ? outfile : "(not set)");
    printf("  number  : %d\n",  number);

    return 0;
}
