#include<stdio.h>
void selectionsort(int n,int a[n])
{
    for(int i=0;i<n-1;i++)
    {
        int pos=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[pos]>a[j])
            pos=j;
        }
        if(pos!=i)
        {
          int temp=a[i];
          a[i]=a[pos];
          a[pos]=temp;
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    selectionsort(n,a);
    return 0;
}
