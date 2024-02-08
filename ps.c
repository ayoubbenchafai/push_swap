#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
typedef struct s_node
{
    int val_a;
    int val_b;
    int cost_a;
    int cost_b;
    int cost_ab;
    int move_a;
    int move_b;
    int move_ab;
}              t_node;
typedef struct s_stack
{
    int data;
    struct s_stack *next;
} t_stack;

int max_stack_a(t_stack *a)
{
    if(!(a))
        return (-1);
    int max = a->data;
    while(a)
    {
        if(max < a->data)
            max = a->data;
        a = a-> next;
    }
    return (max);
}


int main(int ac, char **av)
{
    
    return (0);
}
