#include<stdio.h>
#include<stdlib.h>
#define MAX 6

typedef struct queue
{
    int a[MAX];
    int f;
    int r;
}Queue;

void init(Queue *q)
{
    q->f=0;
    q->r=0;
}

int isEmpty(Queue *q)
{
    return(q->f==q->r);
}

void enqueue(Queue *q,int e)
{
    if(((q->r)+1)%MAX==q->f)
    {
        printf("Queue is full");
    }
    else
    {
        q->a[q->r]=e;
        q->r=((q->r)+1)%MAX;
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
        q->f=((q->f)+1)%MAX;
        if(q->f==q->r)
        {
            init(q);
        }
    }
}

void display(Queue *q)
{
    for(int i=q->f;i<q->r;i++)
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
    enqueue(&q,4);
    dequeue(&q,&pe);
    dequeue(&q,&pe);
    dequeue(&q,&pe);
    dequeue(&q,&pe);
    enqueue(&q,1);
    enqueue(&q,2);
    enqueue(&q,3);
    enqueue(&q,4);
    display(&q);
    printf("\n");
    return 0;
}
