#include<stdio.h>
int arr[100000];
int front=-1;
int rear=-1;
void pushback(int data,int n)
{
	if (rear==n-1)
	return;
	else{
	arr[rear]=data;
	if(front==-1)
	front=0;
	rear++;
	}
}
void popback()
{
	if (front==-1 && rear==-1)
	return;
	else{
	rear-=1;
	if (rear==front)
	front=-1;
	}
}
void popfront(){
	front+=1;
}
int main(){
	int n;
	scanf("%d",&n);
	while (n--)
	{
	pushback(8);
	pushback(9);
	pushback(7);
	pushback(3);
	popfront();
	popback();
	pushback(2);
	pushback(4);
	popfront();
	for (int i=front;i<=rear;i++)
		printf("%d ",arr[i]);
	}
}