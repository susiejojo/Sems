#include<stdio.h>
int top=-1;
int arr[10000];
void push(int val,int n)
{
	if (top==n-1)
	{
	printf("Stack overflow!!");
	return;
	}
	else{
	top++;
	arr[top]=val;
	}
}
void pop(int n)
{
	if (top==-1)
	{
		printf("Stack underflow!!");
		return;
	}
	else
	{
		int k=arr[top];
		top--;
		printf("##%d\n",k);
	}
}
void prints()
{
	for (int i=0;i<=top;i++)
		printf("%d\n",arr[i]);
}
int main()
{
	int n;
	scanf("%d",&n);
	push(1,n);
	push(2,n);
	push(3,n);
	push(4,n);
	push(5,n);
	push(6,n);
	prints();
	pop(n);
	pop(n);
	prints();
}