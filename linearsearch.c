#include<stdio.h>
void linearsearch(int n,int a[n],int key)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]==key)
        printf("%d",i);
    }
    printf("Element not found!!");
}
int main()
{
    int n,key,pos;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the element to be found: ");
    scanf("%d",&key);
    linearsearch(n,a,key);
    return 0;
}
