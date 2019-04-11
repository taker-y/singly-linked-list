#include <stdio.h>
#include <stdlib.h>

FILE *open_file(const char *filename)
{
    FILE *fp;

    if ((fp = fopen(filename, "r")) == NULL) {
        printf("can't open file\n");
        exit(EXIT_FAILURE);
    }

    return fp;
}
