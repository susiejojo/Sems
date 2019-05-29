#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
//1 represents black
//0 represents white
vector <vector <int> > graph;
vector <vector <int> > grapht;  
vector <int> node;
vector <int> bfschecker;
vector <int> visitedddfs;
vector <int> visited;//for scc
vector <int> visitedcycle;
int count=1;//for scc
int answerarr[100011];
int cycle=0;
int flag=0;
int dfsforcycle(int node)
{
	visitedcycle[node]=1;
	for (int i=0;i<graph[node].size();i++)
	{
	if (visitedcycle[graph[node][i]]==1)
	{
	cycle=1;
	}
	else if (visitedcycle[graph[node][i]]==0)
	dfsforcycle(graph[node][i]);
	}
	visitedcycle[node]=2;
	return cycle;
}
void dfsrunforcycle(int n)
{
	for (int i=0;i<n;i++)
	{
	if (visitedcycle[i]!=2 || visitedcycle[i]!=1)
			cycle=dfsforcycle(i);
	if (cycle==1)
	{
		flag=1;
	}
	}
	if (flag==1){
		cout << "Cycle present" << endl;
	}
	else
		cout << "No cycle" << endl;
}
void bfs(int node)
{
	queue <int> bfsq;
	bfsq.push(node);
	bfschecker[node]=1;
	while (!bfsq.empty())
	{
	int val=bfsq.front();
	cout << val << " ";
	bfsq.pop();
	for (int i=0;i<graph[val].size();i++)
	{
		if (bfschecker[graph[val][i]]!=1)
		{
			bfsq.push(graph[val][i]);
			bfschecker[graph[val][i]]=1;
		}
	} 
	}
}
void bfsrun(int n)
{
	//cout << graph[0].size() << endl;
	for (int i=0;i<n;i++)
	{
	if (bfschecker[i]!=1)
	bfs(i);
	}
}

void dfs(int node)
{
	visitedddfs[node]=1;
	cout << node << " ";
	for (int i=0;i<graph[node].size();i++)
	{
	if (visitedddfs[graph[node][i]]==0)
	dfs(graph[node][i]);
	}
}
void dfsrun(int n)
{
	for (int i=0;i<n;i++)
	{
	if (visitedddfs[i]!=1)
			dfs(i);
	}
}

int dfsontrans(int v)
{
    visited[v]=1;
    for (int i=0;i<grapht[v].size();i++)
    {
        if (visited[grapht[v][i]]!=1)//unvisited
        {
            count++;
            if (count>=2)
                answerarr[grapht[v][i]]=1;
            dfsontrans(grapht[v][i]);
        }
    }
    //Stk.push(v);
    if (count>=2)
            answerarr[v]=1;
    return count;
}
void orderafterdfs(int v,stack <int> &Stk)//creates a stack of ordering after dfs
{
    visited[v]=1;
    for (int i=0;i<graph[v].size();i++)
    {
        if (!visited[graph[v][i]])
        {
            orderafterdfs(graph[v][i],Stk);
        }
    }
    Stk.push(v);
}

void sccchecker(int n)
{
    stack <int> Stk;
    visited.assign(n,0);
    node.assign(n,0);
    visitedcycle.assign(n,0);
    visited.assign(n,0);//for scc
    node.assign(n,0);
    for (int i=0;i<n;i++)
    {
        if (visited[i]==0)
            orderafterdfs(i,Stk);
    }
    while (!Stk.empty())
    {
        int v=Stk.top();
        Stk.pop();
        if (visited[v]==0)
        {
            count=dfsontrans(v);
        }
        else
            continue;
        count=1;
    }
}
int main()
{
	int n,e;
	cin >> n >> e;
	node.assign(n,0);
	graph.assign(n,vector<int>());
	grapht.assign(n,vector<int>());
	bfschecker.assign(n,0);
	visitedddfs.assign(n,0);
	visited.assign(n,0);
	for (int i=0;i<n;i++)//for scc
        answerarr[i]=0;
	for (int i=0;i<e;i++)
	{
		int a,b;
		cin >> a >> b;
		graph[a].push_back(b);
		grapht[b].push_back(a);
	}
	for (int i=0;i<n;i++)//for printing the graph
	{
		cout << i << ":";
		for (int j=0;j<graph[i].size();j++)
		{
			cout << graph[i][j] << " ";
		}
		cout << "\n";
	}
	bfsrun(n);
	cout << endl;
	dfsrun(n);
	cout << endl;
	sccchecker(n);
	for (int i=0;i<n;i++)
        cout << answerarr[i] <<" ";
    dfsrunforcycle(n);
}