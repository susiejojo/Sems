#include<stdio.h>
int stack[100000];
int top=0;
int len=0;
void push(int data)
{
    top++;
    stack[top]=data;
}
void pop()
{
    top--;
}
int peek()
{
   return stack[top]; 
}
void isempty(){
    if (top==0)
    return 1;
    else 
    return 0;
}
int main(){
    int t;
    scanf("%d",&t);
    while (t--)
    {
    int n,d;
    scanf("%d %d",&n,&d);
    while (n>0)
    {
    int dig=n%10;
    if (dig<=d)
    {
    if (dig>=peek())
    push(dig);
    else
    {
    while (dig<peek())
    pop();
    }
    }
    n=n/10;
    len++;
    }
    int c=len-top-1;
    for (int i=0;i<=top;i++)
        printf("%d",stack[i]);
    for (int i=0;i<c;i++)
        printf("%d",d);
    }
}