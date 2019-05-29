#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int val;
	struct node* next;
}node;
void add(int val, node** ptr)
{
	node* last=*ptr;
	while (last->next!=NULL)
	{
		last=last->next;
	}
	node* new=(node*)malloc(sizeof(node));
	new->val=val;
	new->next=NULL;
	last->next=new;
}
void print(node *ptr)
{
	//node *last=*ptr;
	while (ptr!=NULL)
	{
		printf("%d\n",ptr->val);
		ptr=ptr->next;
	}
	printf("####\n");
}
void deletebyindex(int ind,node** head)
{
	node *last=*head;
	int count=0;
	while (last!=NULL)
	{
		if (count!=ind-1)
		{
			printf("%d\n",last->val);
			last=last->next;
			count++;
		}
		else
		{
		last->next=(last->next)->next;
		count++;
		}
	}
	// for(int i=0;i<ind-1;i++)
	// {
	// 	last=last->next;
	// }

}
void reverse(node** head)
{
	node* prev=NULL;
	node* next=NULL;
	node* current=*head;
	while (current!=NULL)
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	}
	*head=prev;
}
int main()
{
	node* head;
	scanf("%d",&head->val);
	head->next=NULL;
	add(5,&head);
	add(6,&head);
	add(9,&head);
	add(10,&head);
	add(56,&head);
	print(head);
	//deletebyindex(2,&head);
	//print(head);
	reverse(&head);
	print(head);
}