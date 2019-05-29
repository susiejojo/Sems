#include<stdio.h>
#include<stdlib.h>
int arr[100000];
int front=-1;
int rear=-1;
void pushback(int data)
{
	rear++;
	arr[rear]=data;
	if(front==-1){
	front=0;
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
int popfront(){
    int c=front;
    front+=1;
    return arr[c];
}
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
	printf("%d ",head->val);
	inorder(head->right);
}
// node* search(node* head,int data)
// {
// 	node* current=head;
// 	if (current->val==data)
// 	return current;
// 	else{
// 		pushback(current->val);
// 		if (current->val<data)
// 			search(current->right,data);
// 		else
// 			search(current->left,data);
// 	}
// }
node* bstrev(node* root,int data){
	pushback(root->val);
	if(root->val<data)
	{
		root->right=bstrev(root->right,data);
		root->val=popfront();
		return root;
	}
	else if(root->val>data)
	{
		root->left=bstrev(root->left,data);
		root->val=popfront();
		return root;
	}
	else
	{
		root->val=popfront();
		return root;
	}
}
int main(){
	int k = 80; 
  	node* root=malloc(sizeof(node));
  	root->left=NULL;
  	root->right=NULL;
    insert(root, 50); 
    insert(root, 30); 
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 80); 
    inorder(root); 
    printf("\n");
    root=bstrev(root,k);
    // print inorder of reverse path tree 
    inorder(root); 
}