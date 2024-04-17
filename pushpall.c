#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

void pall(stack_t **stack, unsigned int line_num)
{
    stack_t *h = *stack;
    (void)line_num;

    while (h)
    {
        printf("%d\n", h->n);
        h = h->next;
    }
}

void push(stack_t **stack, unsigned int line_num, int n)
{
    stack_t *new, *h = *stack;

    new = malloc(sizeof(stack_t));
    if (new == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    new->prev = NULL;
    new->n = n;
    new->next = *stack;
    if (*stack)
        (*stack)->prev = new;
    *stack = new;
}

void pop(stack_t **stack, unsigned int line_num)
{
    stack_t *h = *stack;

    if (!(*stack))
    {
        fprintf(stderr, "L%u: can't pop an empty stack\n", line_num);
        exit(EXIT_FAILURE);
    }

    *stack = (*stack)->next;
    free(h);
}

void swap(stack_t **stack, unsigned int line_num)
{
    stack_t *h = *stack, *ptr;

    if ((*stack) == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't swap, stack too short\n", line_num);
        exit(EXIT_FAILURE);
    }

    ptr = h->next;
    if (ptr->next)
        ptr->next->prev = h;
    h->next = ptr->next;
    ptr->prev = NULL;
    ptr->next = h;
    h->prev = ptr;
}
