#include<stdio.h>
#include<stdlib.h>
int queue[100000];
int front=0;
int rear=0;
int dequeue(int n);
int front1();
int isfull(int n);
int isempty();
int printq(int n);
int enqueue(int e,int n)
{
	if (isfull(n)){
		printf("Full queue!!");
		return 0;}
	else{
	queue[rear]=e;
	rear=(rear+1)%n;}
}
int dequeue(int n)
{
	if (isempty()){
		printf("Empty queue!!");
		exit(0);
		}
	else{
	int el=queue[front];
	front=(front+1)%n;
	return el;}
}
int front1()
{
	if (isempty()){
		printf("Empty queue!!");}
	else
	return queue[front];
}
int isfull(int n)
{
	int size=(n+rear-front)%n;
	if (size==(n))
		return 1;
	else
		return 0;
}
int isempty()
{
	if (front==rear)
		return 1;
	else
		return 0;
}
int printq(int n)
{
	int size=(n+rear-front)%n;
	for (int i=front;i<=size+1;i++)
		printf("%d\n",queue[i%n]);
}
int main()
{
	int n;
	scanf("%d",&n);
	queue[0]=2;
	rear=1;
	enqueue(6,n);
	enqueue(7,n);
	enqueue(9,n);
	enqueue(10,n);
	int a=dequeue(n);
	printf("%d",a);
	int b=dequeue(n);
	printf("%d",b);
	printf("%d",dequeue(n));
	printf("%d",dequeue(n));
	printf("%d",dequeue(n));
	printf("%d\n",dequeue(n));
	printf("%d",front1());
	printq(n);
}