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

void insert(Root *rt,int key)
{
    Node *temp,*new_node;
    temp=rt->head;
    new_node=(Node*)malloc(sizeof(Node));
    if(temp==NULL)
    {
        new_node->info=key;
        new_node->next=NULL;
        rt->head=new_node;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        new_node->info=key;
        new_node->next=NULL;
        temp->next=new_node;
    }
}

void orderedinsert(Root *rt,int e)
{
    Node *temp,*new_node;
    temp=rt->head;
    new_node=(Node*)malloc(sizeof(Node));
    new_node->info=e;
    if(temp==NULL)
    {
        new_node->next=NULL;
        rt->head=new_node;
    }
    else
    {
        if(temp->info>e)
        {
            new_node->next=temp;
            rt->head=new_node;
        }
        else
        {
            while(temp->next!=NULL && temp->next->info<e)
            {
                temp=temp->next;
            }
            if(temp->next==NULL)
            {
                new_node->next=NULL;
                temp->next=new_node;
            }
            else
            {
                new_node->next=temp->next;
                temp->next=new_node;
            }
        }
    }
}

void delete(Root *rt,int e)
{
    Node *temp;
    temp=rt->head;
    if(temp->info==e)
    {
        rt->head=temp->next;
        free(temp);
    }
    else
    {
        while(temp->next->info!=e) //OP
        {
            temp=temp->next;
        }
        if(temp->next->next==NULL)
        {
            Node *dumb=temp->next;
            free(dumb);
            temp->next=NULL;
        }
        else
        {
            Node *dumb=temp->next;
            temp->next=temp->next->next;
            free(dumb);
        }
    }
}

void display(Root *rt)
{
    Node *temp;
    temp=rt->head;
    while(temp!=NULL)
    {
        printf("%d ",temp->info);
        temp=temp->next;
    }
}

int main()
{
    Root rt;
    init(&rt);
    orderedinsert(&rt,3);
    orderedinsert(&rt,1);
    orderedinsert(&rt,2);
    orderedinsert(&rt,4);
    // delete(&rt,3);
    display(&rt);
    printf("\n");
    return 0;
}
