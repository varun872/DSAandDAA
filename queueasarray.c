#include<stdio.h>
#include<stdlib.h>
#define MAX 50

typedef struct queue
{
    int a[MAX];
    int f;
    int r;
}Queue;

void init(Queue *q)
{
    q->f=0;
    q->r=-1;
}

int isEmpty(Queue *q)
{
    return (q->r<q->f);
}

void enqueue(Queue *q,int e)
{
    if(q->r==MAX-1)
    {
        printf("Queue is full");
    }
    else
    {
        q->r+=1;
        q->a[q->r]=e;
    }
}

void dequeue(Queue *q,int *pe)
{
    if(isEmpty(q))
    {
        printf("Queue is empty");
    }
    else
    {
        *pe=q->a[q->f];
        q->f+=1;
    }
}

int seek(Queue *q)
{
    return (q->a[q->r]);
}

void display(Queue *q)
{
    for(int i=q->f;i<=q->r;i++)
    {
        printf("%d ",q->a[i]);
    }
}

int main()
{
    Queue q;
    int pe;
    init(&q);
    enqueue(&q,1);
    enqueue(&q,2);
    enqueue(&q,3);
    dequeue(&q,&pe); //SUS
    printf("%d\n",seek(&q));
    display(&q);
    printf("\n");
    return 0;
}
