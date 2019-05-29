#include<stdio.h> 
#include<stdlib.h> 
   
typedef struct node 
{ 
    int val; 
    struct node *left, *right; 
    int height;
}node; 
node* newNode(int item) 
{ 
    node *temp =(node *)malloc(sizeof(node)); 
    temp->val = item; 
    temp->left = temp->right = NULL; 
    temp->height=0;
    return temp; 
} 
int max(int a,int b)
{
    if (a>b)
        return a;
    else
        return b;
}
int getheight(node* root)
{
    if (root==NULL)
        return 0;
    return root->height;
} 
void updateheight(node* root)
{
    root->height=max(getheight(root->left),getheight(root->right))+1;
} 

void inorder(node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        printf("%d ", root->val); 
        inorder(root->right); 
    } 
} 
void preorder(node *root) 
{ 
    if (root != NULL) 
    {  
        printf("%d\n", root->val);
        preorder(root->left); 
        preorder(root->right); 
    } 
} 
node* rightrotation(node* root)
{
    node* temp=root->left;
    root->left=temp->right;
    temp->right=root;
    updateheight(root);
    updateheight(temp);
    return temp;

}  
node* leftrotation(node* root)
{
    node* temp=root->right;
    root->right=temp->left;
    temp->left=root;
    updateheight(root);
    updateheight(temp);
    return temp;

}  
node* insert(node* node, int data) 
{ 
    if (node == NULL) 
        return newNode(data); 
    if (data < node->val) 
        node->left  = insert(node->left, data); 
    else if (data > node->val) 
        node->right = insert(node->right, data); 
    updateheight(node);
    int diffheight=getheight(node->left)-getheight(node->right);
    if (diffheight<-1)//right disbalance
        {
            if (data>node->right->val)//right
            return leftrotation(node);
            else if (data<node->right->val)//left
            {
                node->right=rightrotation(node->right);
                return leftrotation(node);
            }
        }
    if (diffheight>1)//left disbalance
    {
        if (data<node->left->val)//left
            return rightrotation(node);
        else if (data>node->left->val)//right
            {
                node->left=leftrotation(node->left);
                return rightrotation(node);
            }  
    }
    return node;
} 
int main()
{
node *head=NULL;
head=insert(head,6);
head=insert(head,5);
head=insert(head,4);
head=insert(head,3);
head=insert(head,2);
inorder(head);
preorder(head);
}
