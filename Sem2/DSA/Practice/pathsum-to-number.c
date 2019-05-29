#include<stdio.h> 
#include<stdlib.h> 
#define bool int 

/* A binary tree node has data, pointer to left child 
and a pointer to right child */
typedef struct node 
{ 
int val; 
struct node* left; 
struct node* right; 
}node; 

/* 
Given a tree and a sum, return true if there is a path from the root 
down to a leaf, such that adding up all the values along the path 
equals the given sum. 

Strategy: subtract the node value from the sum when recurring down, 
and check to see if the sum is 0 when you run out of tree. 
*/
int flag=0;
void checksum(node* head,int sum){
		if (head->left==NULL && head->right==NULL){
			if (sum-head->val==0)
			flag=1;
          	//printf("%d " , sum);
          	return;
		}
		if (head->left!=NULL)
		{
			sum-=head->val;
			checksum(head->left,sum);
		}
		if (head->right!=NULL)
		{
			sum-=head->val;
			checksum(head->right,sum);
		}
}

/* UTILITY FUNCTIONS */
/* Helper function that allocates a new node with the 
given data and NULL left and right pointers. */
struct node* newnode(int data) 
{ 
struct node* node = (struct node*) 
					malloc(sizeof(struct node)); 
node->val = data; 
node->left = NULL; 
node->right = NULL; 

return(node); 
} 

/* Driver program to test above functions*/
int main() 
{ 

int sum = 21; 

/* Constructed binary tree is 
			10 
		/ \ 
		8	 2 
	/ \ / 
	3	 5 2 
*/
struct node *root = newnode(10); 
root->left	 = newnode(8); 
root->right	 = newnode(2); 
root->left->left = newnode(3); 
root->left->right = newnode(5); 
root->right->left = newnode(2); 
checksum(root,sum);
if(flag) 
	printf("There is a root-to-leaf path with sum %d", sum); 
else
	printf("There is no root-to-leaf path with sum %d", sum); 

getchar(); 
return 0; 
} 
