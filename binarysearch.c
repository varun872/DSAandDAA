// The elements in the array must be sorted
// Either in ascending or descending order
#include<stdio.h>
int binarysearch(int n,int a[n],int key)
{
    int low=0;
    int high=n-1;
    while(high>=low)
    {
        int mid=(low+high)/2;
        if(a[mid]==key)
        return mid;
        else if(a[mid]>key)
        high=mid-1;
        else
        low=mid+1;
    }
    return -1;
}
int main()
{
    int n,key,pos;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the element to be found: ");
    scanf("%d",&key);
    pos=binarysearch(n,a,key);
    printf("%d",pos);
    return 0;
}
