#include<stdio.h>
#include<stdlib.h>

typedef struct list
{
    int info;
    struct list *next;
}Node;

typedef struct root
{
    Node *head;
}Root;

void init(Root *rt)
{
    rt->head=NULL;
}

void insert(Root *rt,int e)
{
    Node *temp,*new_node;
    temp=rt->head;
    new_node=(Node*)malloc(sizeof(Node));
    new_node->info=e;
    if(rt->head==NULL)
    {
        rt->head=new_node;
        new_node->next=rt->head;
    }
    else
    {
        while(temp->next!=rt->head)
        {
            temp=temp->next;
        }
        temp->next=new_node;
        new_node->next=rt->head;
    }
}

void delete(Root *rt,int e)
{
    Node *temp,*last;
    temp=rt->head;
    last=rt->head;
    if(temp->info==e)
    {
        while(last->next!=rt->head)
        {
            last=last->next;
        }
        rt->head=temp->next;
        free(temp);
        last->next=rt->head;
    }
    else
    {
        while(temp->next->info!=e)
        {
            temp=temp->next;
        }
        if(temp->next->next==NULL)
        {
            Node *var=temp->next;
            temp->next=rt->head;
            free(var);
        }
        else
        {
            Node *var=temp->next;
            temp->next=temp->next->next;
            free(var);
        }
    }
}

void display(Root *rt)
{
    Node *temp;
    temp=rt->head;
    while(temp->next!=rt->head)
    {
        printf("%d ",temp->info);
        temp=temp->next;
    }
    printf("%d ",temp->info);
}

int main()
{
    Root rt;
    init(&rt);
    insert(&rt,4);
    insert(&rt,2);
    insert(&rt,5);
    insert(&rt,3);
    delete(&rt,4);
    display(&rt);
    printf("\n");
    return 0;
}
