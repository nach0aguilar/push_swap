#include "../includes/pushswap.h"

void push_a(t_stack *a, t_stack *b)
{
    t_stack *temp;

    temp = b;
    b = b->next;
    a = temp;    
}

void push_b(t_stack *a, t_stack *b)
{
    t_stack *temp;

    temp = a;
    a = a->next;
    b = temp;    
}