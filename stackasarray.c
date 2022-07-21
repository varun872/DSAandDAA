#include<stdio.h>
#include<stdlib.h>
#define MAX 50

typedef struct stack
{
    int a[MAX];
    int top;
}Stack;

void init(Stack *s)
{
    s->top=-1;
}

int isEmpty(Stack *s)
{
    return (s->top==-1);
}

void push(Stack *s,int e)
{
    if(s->top==MAX-1)
    {
        printf("Stack is full cannot insert any more elements");
    }
    else
    {
        s->top+=1;
        s->a[s->top]=e;
    }
}

int pop(Stack *s)
{
    if(isEmpty(s))
    {
        printf("Stack is Empty and therefore no more elements can be deleted");
    }
    else
    {
        int pe;
        pe=s->a[s->top];
        s->top-=1;
        return pe;
    }
}

int peek(Stack *s)
{
    if(isEmpty(s))
    {
        printf("Underflow");
    }
    else
    {
        return s->a[s->top];
    }
}

void display(Stack *s)
{
    for(int i=0;i<=s->top;i++)
    {
        printf("%d ",s->a[i]);
    }
}

int main()
{
    Stack st;
    init(&st);
    push(&st,3);
    push(&st,8);
    push(&st,5);
    push(&st,1);
    printf("%d\n",pop(&st));
    printf("%d\n",peek(&st));
    display(&st);
    printf("\n");
    return 0;
}
