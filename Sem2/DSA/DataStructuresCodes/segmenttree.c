#include<stdio.h>
int tree[1000000];
int arr[10000];
void build(int start,int end,int node)
{
	if (start==end)
	{
		tree[node]=arr[start];
	}
	else
	{
	int mid=(start+end)/2;
	build (start,mid,node*2+1);
	build (mid+1,end,node*2+2);
	tree[node]=tree[node*2+1]+tree[node*2+2];
	}
}
void update(int start,int end,int node,int ind,int val)
{
    if (start==end)
    {
        tree[node]+=val;
        arr[ind]+=val;
    }
    else
    {
        int mid=(start+end)/2;
        if (start<=ind && ind<=mid)
        {
            update(start,mid,2*node+1,ind,val);
        }
        else if (ind>mid && ind<=end)
        {
            update(mid+1,end,2*node+2,ind,val);
        }
        tree[node]=tree[node*2+1]+tree[node*2+2];
    }
}
int query(int start,int end,int node,int l,int r)
{
    if (end<l || r<start)
    return 0;
    if (l<=start && end<=r)
    {
        return tree[node];
    }
    else
    {
        int mid=(start+end)/2;
        int start1=query(start,mid,2*node+1,l,r);
        int start2=query(mid+1,end,2*node+2,l,r);
        return (start1+start2);
    }
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	for (int i=0;i<n;i++)
	{
		build(0,n-1,0);
	}
	for (int i=0;i<(4*n);i++)
	{
		printf("%d ",tree[i]);
	}
	update(0,n-1,0,4,1);
	printf("\n");
	for (int i=0;i<(4*n);i++)
	{
		printf("%d ",tree[i]);
	}
	int ans=query(0,n-1,0,0,2);
	printf("\n%d",ans);

}