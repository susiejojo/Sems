#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int val;
	struct node* next;
}node;
void enqueue(node** head,int value)
{
	node* current= *head;
	while (current->next!=NULL)
	{
		current=current->next;
	}
	node* newn= (node*)malloc(sizeof(node*));
	newn->val=value;
	newn->next=NULL;
	current->next=newn;

}
void printq(node **head)
{
	node* current=*head;
	while (current!=NULL)
	{
		printf("%d\n",current->val);
		current=current->next;
	}
}
void dequeue(node** head)
{
	*head=(*head)->next;
	node* current= *head;
	while (current->next!=NULL)
	{
		current=current->next;
	}
}
int main()
{
	node* head= (node*)malloc(sizeof(node*));
	head->val=1;
	head->next=NULL;
	enqueue(&head,2);
	enqueue(&head,3);
	enqueue(&head,4);
	enqueue(&head,5);
	enqueue(&head,6);
	printq(&head);
	dequeue(&head);
	dequeue(&head);
	printq(&head);
}