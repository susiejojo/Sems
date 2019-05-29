#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while (t--)
	{
	int n,b;
	scanf("%d %d",&n,&b);
	int maxar=0;
	int flag=1;
	for (int i=0;i<n;i++)
	{
		int w,h,p;
		scanf("%d %d %d",&w,&h,&p);
		if (p<=b){
			if (w*h>maxar)
				maxar=w*h;
			flag=0;
		}
	}
	if (flag==1)
		printf("no tablet\n");
	else
		printf("%d\n",maxar);
	}
}