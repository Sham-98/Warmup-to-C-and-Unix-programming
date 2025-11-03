#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {


if (argc > 3) {
    fprintf(stderr, "usage: reverse <input> <output>\n");
    exit(1);
}

FILE *inf = fopen(argv[1], "r");
if (!inf) {
    fprintf(stderr, "error: cannot open file '%s'\n", argv[1]);
    exit(1);
}
    printf("File opened successfully: %s\n", argv[1]);

    fclose(inf);
    return 0;
}

