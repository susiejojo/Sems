#include<stdio.h>
#include<string.h>
char arr[1000000];
int count=0;
void push(char n)
{
	arr[count]=n;
	count++;
}
void pop()
{
	count--;
}
char top()
{
	return arr[count-1];
}
int main()
{
	char s[100000];
	scanf("%s",s);
	int wc=0;
	int len=strlen(s);
	for (int i=0;i<len;i++)
	{
		//printf("%c",s[i]);
	if (top()==s[i]){
		//printf("OK");
	pop();
	wc++;
	}
	else if (top()!=s[i])
	push(s[i]);
	}
	// for (int i=0;i<count;i++)
	// 	printf("%c\n",arr[i]);
	if (wc%2!=0)
		printf("Yes\n");
	else if (wc%2==0)
		printf("No\n"); 
}