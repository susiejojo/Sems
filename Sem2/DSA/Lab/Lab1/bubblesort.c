#include<stdio.h>
int arr[1000];
void bubblesort(int n)
{
for (int i=0;i<n;i++)
{
int flag=0;
    for (int j=0;j<n-i-1;j++)
    {
    if (arr[j+1]<arr[j]){
    flag=1;
    int temp=arr[j+1];
    arr[j+1]=arr[j];
    arr[j]=temp;
    }
    }
    if (flag==0)
        break;
    }
    
}
int main()
{
   int n;
   scanf("%d",&n);
   for (int k=0;k<n;k++)
    {
    scanf("%d",&arr[k]);
    } 
    bubblesort(n);
    for (int k=0;k<n;k++)
    {
    printf("%d",arr[k]);
    } 
}


