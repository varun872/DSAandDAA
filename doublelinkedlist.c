#include<stdio.h>
#include<stdlib.h>

typedef struct list
{
    int info;
    struct list *right;
    struct list *left;
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
        new_node->right=NULL;
        rt->head=new_node;
        new_node->left=NULL;
    }
    else
    {
        while(temp->right!=NULL)
        {
            temp=temp->right;
        }
        new_node->right=NULL;
        new_node->left=temp;
        temp->right=new_node;
    }
}

void delete(Root *rt,int e)
{
    Node *temp;
    temp=rt->head;
    if(temp->info==e)
    {
        rt->head=temp->right;
        free(temp);
    }
    else
    {
        while(temp->info<e)
        {
            temp=temp->right;
        }
        if(temp->right==NULL)
        {
            temp->left->right=NULL;
            free(temp);
        }
        else
        {
            temp->left->right=temp->right;
            temp->right->left=temp->left;
            free(temp);
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
        temp=temp->right;
    }
}

int main()
{
    Root rt;
    init(&rt);
    insert(&rt,1);
    insert(&rt,2);
    insert(&rt,3);
    delete(&rt,3);
    display(&rt);
    printf("\n");
    return 0;
}
