#include<stdio.h>
#include<stdlib.h>
int countl=0;
int leftedge=0;
typedef struct node{
	struct node* left;
	struct node* right;
	int val;
	struct node* parent;
	int leftno;
}node;
int treeht(struct node* root);
void Givenlevel(struct node* root,int level);
void levelOrder( struct node *root) {
    for (int i=1;i<=treeht(root);i++)
        Givenlevel(root,i);
}
node* newnode(node* head,int data)
{
	node* child=(node*)malloc(sizeof(node));
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
			head->leftno++;
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
void postorder(node* head)
{
	if (head==NULL)
		return;
	postorder(head->left);
	postorder(head->right);
	printf("%d\n",head->val);
}
int max(int a,int b)
{
    if (a>b)
    return a;
    else
    return b;
}
int treeht(struct node* root)
{
    if (root==NULL)
    return 0;
    else{
    int lheight=treeht(root->left);y
    int rheight=treeht(root->right);
    return max(lheight,rheight)+1;
}}
void Givenlevel(struct node* root,int level)
{
    if (level==0)
    return;
    if (level==1)
    printf("%d",root->data);
    else
    Givenlevel(root->left,level-1);
    Givenlevel(root->right,level-1);
}
int treemin(node* head)
{
	if (head->left==NULL)
		return head->val;
	leftedge++;
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
 int kthmin(node* head,int k)
 {
 	if(head->leftno==k-1)
 		return head->val;
 	else if(head->leftno<k)
 		kthmin(head->right,k-head->leftno-1);
 	else
 		kthmin(head->left,k);
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
	node* head=(node*)malloc(sizeof(node));
	scanf("%d",&(head->val));
	for (int i=1;i<n;i++)
	{
		int d;
		scanf("%d",&d);
		insert(head,d);
	}
	//inorder(head);
	//postorder(head);
	//printf("%d\n",treemin(head));
	//int p;
	//scanf("%d",&p);
	//printf("%d\n",findsuccessor(head,p));
	int k;
	scanf("%d",&k);
	//delete(head,3);
	inorder(head);
	int m=treemin(head);
	printf("%d\n",kthmin(head,k));
}