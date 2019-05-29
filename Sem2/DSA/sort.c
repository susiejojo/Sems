#include<stdio.h>
int arr[1000];
void selecsort(int n){
    for (int i=0;i<n;i++)
    {
        for (int j=i+1;j<n;j++)
        {
        if (arr[j]<arr[i])
        {
            int temp=arr[j];
            arr[j]=arr[i];
            arr[i]=temp;
        }
        }
    }
    }
void bubblesort(int n)
{
    for (int i=0;i<n-1;i++)
    {
    int flag=0;//to optimise and check if the array is partly or fully sorted
    for (int j=0;j<n-i-1;j++)
    {
        if (arr[j+1]<arr[j])
        {
            flag=1;
            int temp=arr[j+1];
            arr[j+1]=arr[j];
            arr[j]=temp;
        }
    } 
    if (flag==0)
    {
        break;
    }
    }
}
void insertsort(int n)
{
    for (int i=1;i<n;i++)
    {
    int k=arr[i];
    int j=i-1;
    while (j>=0 && arr[j]>k)
    {
        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1]=k;
    }
}
void merge(int arr[],int l,int r,int m)
{
    int p=m-l+1;
    int q=r-m;
    int i,j,k;
    int L[p],R[q];
    for (i=0;i<p;i++)//Left array initiation
    {
    L[i]=arr[i+l];
    }
    for (j=0;j<q;j++)//Right array initiation
    {
    R[j]=arr[m+j+1];
    }
    i=0;
    j=0;
    k=l;
    while (i<p && j<q)//merge after comparing each element of left array with elements of right array
    {
    if (L[i]<R[j])
    {
    arr[k]=L[i];
    i++;
    }
    else if (L[i]>R[j])
    {
    arr[k]=R[j];
    j++;
    }
    k++;
    }
    //to add remaining elements
    while (i<p)//adds remaining elements of left array
    {
    arr[k]=L[i];
    i++;
    k++;
    }  
    while (j<q)//adds remaining elements of right array
    {
    arr[k]=R[j];
    j++;
    k++;
    }    
    
}
void mergesort(int arr[],int l,int r)
{
    if (l<r)
    {
    int m=(l+r)/2;
    mergesort(arr,l,m);//sort Left array
    mergesort(arr,m+1,r);//sort Right array
    merge(arr,l,r,m);//merge the 2 arrays
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
    mergesort(arr,0,n-1);
    for (int k=0;k<n;k++)
    {
    printf("%d",arr[k]);
}
}
