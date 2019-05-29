#include<iostream>
#include<stack>

vector <vector <int>> graph;
vector <int> visited;
int cycle=0;
void dfs(int node)
{
	visited[node]=1;
	for (int i=0;i<graph[node].size();i++)
	{
	if (visited[graph[node][i]]==1)
	cycle=1
	else if (visited[graph[node][i]]==0)
	dfs(graph[node][i]);
	}
	visited[node]=2;
}
void dfsrun(int n)
{
	for (int i=0;i<n;i++)
	{
	if (visited[i]!=2 || visited[i]!=1)
	dfsrun(i);
	}
}
int main()
{
	
}