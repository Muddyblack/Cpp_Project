//Beispiel fuer ein optionales getopt shortopt
// -O  -> OK ... option '-O' without argument
// -O5 -> OK ... option -O with argument '5'
#include <stdio.h>
#include <getopt.h>
#include <ctype.h>

int main (int argc, char *argv[]) {
    int c;
    opterr = 0;
    while ((c = getopt (argc, argv, "O::c")) != -1)
        switch (c)
        {
        case 'O':
            printf("OK ... option -%c with argument '%p'\n", c, optarg);
            break;
        case 'c':
            printf("Option c gesetzt.\n");
            break;
        case '?':
            if(optopt == 'O' && isprint(optopt))
            {
                printf("OK ... option '-O' without argument \n");
                break;
            }
            else if (isprint (optopt))
                fprintf (stderr, "ERR ... Unknown option `-%c'.\n", optopt);
            else
                fprintf (stderr, "ERR ... Unknown option character `\\x%x'.\n", optopt);
            return -1;

        default:
            ;
        }
        
        return 0;
}

