
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>


  int main(void){ 
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "error: cannot open file 'input.txt'\n");
        exit (1);
    }

    char *line = NULL; // for getline
    size_t len = 0;
    ssize_t read;

    //donamic array for storing lines
    char **lines = NULL; 
    size_t capacity = 0;
    size_t count = 0;



    while ((read = getline(&line, &len, file)) != -1) {
      if (count == capacity){
        capacity = (capacity == 0) ? 10 : capacity * 2;
        lines = realloc(lines, capacity * sizeof(char *));
        if (lines == NULL) {
          fprintf(stderr, "malloc failed\n");
          free(line);
          fclose(file);
          exit(1);
}}
 // Allocate space for line and copy 
        lines[count] = malloc(strlen(line) + 1);
        if (lines[count] == NULL) {
            fprintf(stderr, "malloc failed for line\n");
            free(line);
            fclose(file);
            exit(1);
        }
        strcpy(lines[count], line);
        count++;
    }
    fclose(file);
    free(line);

// Open output file for w
    FILE *outfile = fopen("output.txt", "w");
    if (outfile == NULL) {
        fprintf(stderr, "error: cannot open file 'output.txt'\n");
        for (size_t i = 0; i < count; i++)
          free(lines[i]);
        free(lines);
        exit(1);
    }

    // print in revers order 
    for (ssize_t i = count - 1; i >= 0; i--) {
        fprintf(outfile, "%s", lines[i]);
        free(lines[i]);
    }


    free(lines);
    fclose(outfile);
    return 0;
}
  

