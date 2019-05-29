#include<stdio.h>
#include<stdlib.h>
struct node{
	int val;
	struct node *next;
}*front,*rear,*temp,*current,*newn;
int count=0;
void printq();
void enqueue(int value)
{
	if (rear==NULL)//for first node
	{
		rear= (struct node*)malloc(sizeof(struct node*));
		rear->val=value;
		rear->next=NULL;
		front=rear;
	}
	else//for any other node
	{
	newn= (struct node*)malloc(sizeof(struct node*));
	rear->next=newn;
	newn->val=value;
	newn->next=NULL;
	rear=newn;
	}
	count++;
}
void printq()
{
	current=front;
	if (front==NULL && rear==NULL)//initial empty queue
		return;
	while (current!=rear)//for other elements except the last
	{
		printf("%d\n",current->val);
		current=current->next;
	}
	if (current==rear)//for last element
	{
		printf("%d\n",current->val);
	}
}
int dequeue()
{
	int v=front->val;
	front=front->next;
	count--;
	return v;
}
int qsize()
{
	printf("qsize:%d\n",count);
}
int main()
{
	front=rear=NULL;
	enqueue(1);
	enqueue(2);
	enqueue(3);
	enqueue(4);
	enqueue(5);
	enqueue(6);
	printq();
	int a=dequeue();
	printf("#%d\n",a);
	printq();
	qsize();
}