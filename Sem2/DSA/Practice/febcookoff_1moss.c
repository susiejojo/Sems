#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    int n,b;
	    scanf("%d%d",&n,&b);
	    int flag = 0;
	    int max = -1;
	    for(int i = 0 ;i<n;i++)
	    {
	        int w,h,p;
	        
	        scanf("%d%d%d",&w,&h,&p);
	        if(p <= b)
	        {
	            if( w*h > max)
	            {
	                max = w*h;
	                flag = 1;
	            }
	        }
	        
	    }
	    if(flag == 0)
	    {
	        printf("no tablet\n");
	    }
	    else
	    {
	        printf("%d\n",max);
	    }
	}
	return 0;
}