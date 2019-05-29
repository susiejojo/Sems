#include<stdio.h>
#include<string.h>
char arr[1000];
int count=0;
char seq[1000];
void push(int data)
{
	arr[count++]=data;
}
void pop(){
	count--;
}
void top(){
	return arr[count];
}
int isempty(){
	if (count==0)
	return 1;
	else
	return 0;
}
int balbrack(char seq[]){
	if (strlen(seq)%2==1)
		return 0;
	else
		for (int i=0;i<strlen(seq);i++)
		{
			if (!isempty() && seq[i]==")")
			{
				if (top()=="(")
					pop();
			}
			if (!isempty() && seq[i]=="}")
			{
				if (top()=="{")
					pop();
			}
			if (!isempty() && seq[i]=="]")
			{
				if (top()=="[")
					pop();
			}
			if (isempty() && seq[i]=="(")
				push(seq[i]);
			if (isempty() && seq[i]=="{")
				push(seq[i]);
			if (isempty() && seq[i]=="[")
				push(seq[i]);
		}
		if (isempty())
			return 1;
		else
			return 0;
}
int main(){
	int n;
	scanf("%d",&n);
	while (n--)
	{
		scanf("%s",seq);
		int res=balbrack(seq);
		if (res==1)
			printf("TRUE\n");
		else
			printf("FALSE\n");
	}
}
