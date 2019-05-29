#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	struct node* left;
	struct node* right;
	int val;
	struct node* parent;
}node;
node* newnode(node* head,int data)
{
	node* child=malloc(sizeof(node));
	child->left=NULL;
	child->right=NULL;
	child->val=data;
	child->parent=head;
	return child;
}
void insert(node* head,int data)
{
	if (data<head->val)
		{
			if (head->left==NULL)
				head->left=newnode(head,data);
			else
				insert(head->left,data);
		}
	else if (data>=head->val)
		{
			if (head->right==NULL)
				head->right=newnode(head,data);
			else
				insert(head->right,data);
		}
}
void inorder(node* head)
{
	if (head==NULL)
		return;
	inorder(head->left);
	printf("%d\n",head->val);
	inorder(head->right);
}
void postorder(node* head)
{
	if (head==NULL)
		return;
	postorder(head->left);
	postorder(head->right);
	printf("%d\n",head->val);
}
int treemin(node* head)
{
	if (head->left==NULL)
		return head->val;
	treemin(head->left);
}
int successor(node* head)
{
	if (head->right==NULL)
		{
			while(head->parent!=NULL && (head->parent)->val<head->val)
			head=head->parent;
			if(head->parent!=NULL)
			return(head->parent->val);
			else
			return 0;	
		}
	else
	{
		treemin(head->right);
	}
}
node* searchnode(node* head,int data)
{
	if (head->val==data)
		return head;
	if (head->val<=data)
		searchnode(head->right,data);
	else if (head->val>data)
		searchnode(head->left,data);
}
int findsuccessor(node* head,int data)
{
	node* index=searchnode(head,data);
	return successor(index);
}
node* delete(node* head,int data)
{
	if (data<head->val)
		head->left=delete(head->left,data);
	else if (data>head->val)
		head->right=delete(head->right,data);
	else if (data==head->val)
	{
		//check if it has only one child
		if (head->right==NULL){
			node* temp=head->left;
			free(head);
			return temp;}
		if (head->left==NULL){
			node* temp=head->right;
			free(head);
			return temp;}
		else if (head->left!=NULL && head->right!=NULL){
		//when there r 2 children
		int suc=successor(head);
		head->val=suc;
		head->right=delete(head->right,suc);}
	}
	return head;
}
int main(){
	int n;
	scanf("%d",&n);
	node* head=malloc(sizeof(node));
	scanf("%d",&(head->val));
	for (int i=1;i<n;i++)
	{
		int d;
		scanf("%d",&d);
		insert(head,d);
	}
	//inorder(head);
	//postorder(head);
	printf("%d\n",treemin(head));
	//int p;
	//scanf("%d",&p);
	//printf("%d\n",findsuccessor(head,p));
	delete(head,3);
	inorder(head);
}