#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *filename = argv[1];
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Unable to open file %s\n", filename);
        return EXIT_FAILURE;
    }

    char line[MAX_LINE_LENGTH];
    int line_number = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        line_number++;

        if (line[strlen(line) - 1] == '\n') {
            line[strlen(line) - 1] = '\0';
        }

        char *opcode = strtok(line, " ");
        if (opcode == NULL) {
            continue;
        }


        printf("Line %d: Opcode: %s\n", line_number, opcode);
        char *arg = strtok(NULL, " ");
        if (arg != NULL) {
            printf("Line %d: Argument: %s\n", line_number, arg);
        }
    }

    fclose(file);
    return EXIT_SUCCESS;
}
