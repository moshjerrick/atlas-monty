#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 100

int stack[STACK_SIZE];
int top = -1;

void push(int value, int line_number) {
    if (top >= STACK_SIZE - 1) {
        fprintf(stderr, "L%d: Error: Stack overflow\n", line_number);
        exit(EXIT_FAILURE);
    }
    stack[++top] = value;
}

void pall() {
    printf("Stack: ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    char line[100];
    int line_number = 0;

    while (fgets(line, sizeof(line), stdin) != NULL) {
        line_number++;

        if (line[strlen(line) - 1] == '\n') {
            line[strlen(line) - 1] = '\0';
        }

        char *opcode = strtok(line, " ");
        if (opcode == NULL) {
            continue; // Empty line
        }

        if (strcmp(opcode, "push") == 0) {
            char *arg = strtok(NULL, " ");
            if (arg == NULL) {
                fprintf(stderr, "L%d: Error: Usage: push integer\n", line_number);
                exit(EXIT_FAILURE);
            }
            int value = atoi(arg);
            push(value, line_number);
        } else if (strcmp(opcode, "pall") == 0) {
            pall();
        } else {
            fprintf(stderr, "L%d: Error: Unknown opcode: %s\n", line_number, opcode);
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}

