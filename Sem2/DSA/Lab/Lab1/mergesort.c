#include<stdio.h>
int arr[1000];
void merge(int arr[],int l,int r,int m)
{
	int i,j,k=0;
	int p=m-l+1;
	int q=r-m;
	int L[p];
	int R[q];
	for (i=0;i<p;i++)
	{
	L[i]=arr[i+l];
	}
	for (j=0;j<q;j++)
	{
	R[j]=arr[j+m+1];
	}
	i=0;
	j=0;
	k=l;
	while (i<p && j<q)
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
	while (i<p)
	{
	arr[k]=L[i];
	k++;
	i++;
	}
	while (j<q)
	{
	arr[k]=R[j];
	k++;
	j++;
	}

}
void mergesort(int arr[],int l,int r)
{
	if (l<r)
	{
		int m=(l+r)/2;
		mergesort(arr,l,m);
		mergesort(arr,m+1,r);
		merge(arr,l,r,m);
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