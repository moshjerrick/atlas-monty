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




void op_push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_num);
void push(stack_t **stack, unsigned int line_num, int n);
void pop(stack_t **stack, unsigned int line_num);
void swap(stack_t **stack, unsigned int line_num);




#endif 