#include<stdio.h>
#include<stdlib.h>

typedef struct stack
{
    int info;
    struct stack *next;
}Stack;

typedef struct top
{
    Stack *top;
}Root;

void init(Root *rt)
{
    rt->top=NULL;
}

int IsEmpty(Root *rt)
{
    return (rt->top==NULL);
}

void push(Root *rt,int e)
{
    Stack *s,*temp;
    temp=rt->top;
    s=(Stack*)malloc(sizeof(Stack));
    s->info=e;
    if(IsEmpty(rt))
    {
        rt->top=s;
        s->next=NULL;
    }
    else
    {
        s->next=rt->top;
        rt->top=s;
    }
}

int pop(Root *rt,int *pe)
{
    Stack *temp;
    temp=rt->top;
    if(IsEmpty(rt))
    {
        return -1;
    }
    else
    {
        rt->top=temp->next;
        *pe=temp->info;
        free(temp);
        return *pe;
    }
}

int peek(Root *rt)
{
    return(rt->top->info);
}

void display(Root *rt)
{
    Stack *temp;
    temp=rt->top;
    while(temp!=NULL)
    {
        printf("%d ",temp->info);
        temp=temp->next;
    }
}

int main()
{
    Root rt;
    int *pe;
    init(&rt);
    push(&rt,1);
    push(&rt,3);
    push(&rt,2);
    printf("%d\n",pop(&rt,pe));
    printf("%d\n",peek(&rt));
    display(&rt);
    return 0;
}
