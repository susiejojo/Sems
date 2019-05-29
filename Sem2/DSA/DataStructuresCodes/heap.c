#include<stdio.h>
int arr[100000];
int count=0;
int siftup(int index);
void reheap(int i);
void insert(int data);
int max(int a,int b)
{
	if (arr[a]>arr[b])
		return a;
	else
		return b;
}
void swap(int a,int b)
{
	int t=arr[a];
	arr[a]=arr[b];
	arr[b]=t;
}
void insert(int data)
{
	arr[count]=data;
	int ind=count;
	while (ind!=0)
	{
		ind=siftup(ind);
	}
	count++;
}
int siftup(int index)
{
	if (arr[index]>arr[(index-1)/2]){
		swap(index,(index-1)/2);
		return (index-1)/2;}
	else
		return 0;
}
int siftdown(int index,int index1)
{
	if (arr[index1]>arr[index]){
		swap(index1,index);
		return index1;}
}
void pop()
{
	swap(0,count-1);
	count--;
	reheap(0);
}
void reheap(int i)
{
	int ind=i;
	if (ind*2+1>count)
		return;
	else{
		int ind1=max(2*ind+1,2*ind+2);
		int id=siftdown(ind,ind1);
		reheap(id);
	}
}
void printarr()
{
	for (int i=0;i<count;i++)
		printf("%d\n",arr[i]);
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		int a;
		scanf("%d",&a);
		insert(a);
	}
	//printarr();
	pop();
	printarr();
}