#include<stdio.h>
#include<string.h>
char str[1000000];
int arr[100000];
int hash=0;
int hash_f(int hash,int i)
{
		hash=hash*29+(int)str[i];
		arr[i]=hash;
		return hash;
}
int main(){
	scanf("%s",str);
	hash=(int)str[0];
	arr[0]=hash;
	//printf("%d",hash);
	for (int i=1;i<strlen(str);i++)
	{
		hash=hash_f(hash,i);
	}
	for (int i=0;i<strlen(str);i++)
	{
		printf("%d ",arr[i]);
	}
}