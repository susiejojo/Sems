#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector <vector <int>> graph;
vector <vector <int>> grapht;
vector <int> visited;
stack <int> stk;
int cycle=0;
int flag=0;
int count=0;
void dfs(int node)
{
	visited[node]=1;
	for (int i=0;i<graph[node].size();i++)
	{
	if (visited[graph[node][i]]==0)
	dfs(graph[node][i]);
	}
	stk.push(node);
}
int dfst(int node)
{
	visited[node]=1;
	//cout << node << endl;
	for (int i=0;i<grapht[node].size();i++)
	{
	if (visited[graph[node][i]]==0)
	dfst(grapht[node][i]);
	}
}
void dfsrun(int n)
{
	for (int i=0;i<n;i++)
	{
	if (visited[i]!=2 || visited[i]!=1)
			dfs(i);
	}
}
void dfsrunt(int n)
{
	for (int i=0;i<n;i++)
	{
	if (visited[i]!=2 || visited[i]!=1)
			dfst(i);
	}
}
void sccchecker(int n)
{
	visited.assign(n,0);
	dfsrun(n);
	visited.assign(n,0);
	while (!stk.empty())
	{
		int val=stk.top();
		stk.pop();
		cout << val << endl;
		if (visited[val]==0)
			dfst(val);
	}
}
int main()
{
	int n,e;
	cin >> n >> e;
	graph.assign(n,vector <int> ());
	visited.assign(n,0);
	for (int i=0;i<e;i++)
	{
		int a,b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	sccchecker(n);
}