#ifndef MONTY_H
#define MONTY_H

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;



typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_num);
} instruction_t;




void pint(stack_t **stack, unsigned int line_num);
void free_stack(stack_t *head);
int pushint(char *list, int ln);
int _strcmp(char *opcode, char *list);
void add(stack_t **stack, unsigned int line_num);
void swap(stack_t **stack, unsigned int line_num);
void pop(stack_t **stack, unsigned int line_num);
void push(stack_t **stack, unsigned int line_number, int n);
void pall(stack_t **stack, unsigned int line_num);
void execute(char *string[], stack_t *stack);
int nlfind(char *list);
void free_list(char *a[]);
int combfind(char *list, int ln);


#endif 