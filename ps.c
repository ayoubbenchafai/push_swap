#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_node
{
    int data;
    struct s_node *next;
} node;

typedef struct s_stack
{
    int size;
    node *top;
} Stack;

int isEmpty(Stack *stack)
{
    return (stack->top == NULL && stack->size == 0);
}

node *create_node(int data)
{
    node *p;
    p = (node *)malloc(sizeof(node));
    if(!p)
        return (NULL);
    p->data = data;
    p->next = NULL;
    return (p);
}

Stack *create_stack()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if(!stack)
        return (NULL);
    stack->top = NULL;
    stack->size = 0;
    return (stack);
}

void push_to_stack(Stack *stack,int data)
{
    node *p = create_node(data);
    if(!p)
        return ;
    if(isEmpty(stack))
    {
        stack->top = p;
        // p->next = NULL;
        stack->size++;
    }
    else
    {
        p ->next = stack->top;
        stack -> top = p;
        stack->size++;
    }
}

void display_stack(Stack *stack)
{
    node *a;

    a = stack->top;
    printf("----stack a-----\n");
    while(a)
    {
        printf("        %d\n", a->data);
        a = a->next;
    }
}

void	ft_putstr(char *s)
{
    while (*s != '\0')
        write(1, s++, 1);
}

int get_top(Stack *stack)
{
    int res;
    Stack *a = stack;
    if(isEmpty(a))
        return (0);
    else
        res = a->top->data;
    return (res);
}

int get_arguments(Stack *stack, int ac, char **av)
{
    int i;
    int n;

    i = 0;
    n = 0;
    if(ac == 1)
    {
        printf("Arguments not exists.\n");
        return (1);
    }
    while(++i < ac)
    {
        n = atoi(av[i]);
        push_to_stack(stack, n);
    }
    return (0);
}

int main(int ac, char **av)
{
    Stack *stack = create_stack();
    if(!stack)
        return (1);
    Stack *a = stack;
    get_arguments(a, ac, av);
    printf("top1 : %d\n",get_top(a));

    display_stack(a);
    printf("top2 : %d\n",get_top(stack));
    return (0);
}
