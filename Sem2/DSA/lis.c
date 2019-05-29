#include<stdio.h>
#include<stdio.h>
int arr[10000];
int maxj=0;
int dp(int j,int n,int flag)
{
	if (j==(n-1))
	{
	return 1;
	}
	// else if (j==0 && flag==1)
	// {
	// return maxj+1;
	// }
	else if (j==0)
	{
		return maxj+1;
	}
	else{
	for (int k=j+1;k<n;k++)
	{
	if (arr[k]>=arr[j])
	{
	maxj=dp(k,n,flag)+1;
	return maxj;
	}
	}
}
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
	scanf("%d",&arr[i]);
	}
	int flag=0;
	int min=arr[0];
	for (int i=0;i<n;i++)
	{
		if (arr[i]<min)
			min=arr[i];
	}
	if (min==arr[0])
		flag=1;
	int c=0;
	for (int j=n-1;j>=0;j--)
	{
	c=dp(j,n,flag);
	}
	printf("%d\n",c);
}