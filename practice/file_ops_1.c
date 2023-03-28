#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "TestCode.h"
#include <stdbool.h>

// Refer to README.md for the problem instructions

int writeNames(const char **fnames, const char **lnames, int sz, const char *fileName)
{
    FILE *fPntr = fopen(fileName, "w+");

    if (fPntr == NULL) {
        return 0;
    }

    for (int i = 0; i < sz; i++) {
        int firstChar = true;
        while (*lnames[i] != '\0'){
            if (firstChar) {
                fputc(toupper(*lnames[i]), fPntr);
                firstChar = false;
            } else {
                fputc(*lnames[i], fPntr);
            }
            lnames[i]++;
        }
        fputs(", ", fPntr);
        firstChar = true;
        while (*fnames[i] != '\0') {
            if (firstChar) {
                fputc(toupper(*fnames[i]), fPntr);
                firstChar = false;
            } else {
                fputc(*fnames[i], fPntr);
            }
            fnames[i]++;
        }
        if (i < sz - 1 ) {
            fputs("\n", fPntr);
        }
    }

    fclose(fPntr);

    return 0;
}

int main() {
    const char *fnames[] = {"george", "john", "millard", "Theodore"};
    const char *lnames[] = {"Washington", "adams", "Filmore", "roosevelt"};

    int result = writeNames(fnames, lnames, sizeof(fnames) / sizeof(*fnames), "names.txt");

    return 0;
}
