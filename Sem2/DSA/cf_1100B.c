#include<stdio.h>
int sample[100000];
int arr[100000];
int count=0;
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for (int i=0;i<m;i++)
	{
	scanf("%d",&sample[i]);
	}
	for (int i=0;i<n;i++)
	{
	arr[i]=i+1;
	}
	int wc=0;
	int count=0;
	int i=count;
	while (count<m && i<m){
	for (i=count+1;i<m;i++){
		if (wc==n){
			count=i;
			printf("1");
			break;}
		if (arr[sample[i]]!=0){
				arr[sample[i]]=0;
				wc++;}
		else
				continue;
			printf("0");}
	}
	printf("\n");
}