#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector <vector <int>> graph;
vector <int> visited;
int cycle=0;
int flag=0;
int dfs(int node)
{
	visited[node]=1;
	for (int i=0;i<graph[node].size();i++)
	{
	if (visited[graph[node][i]]==1)
	{
	cycle=1;
	}
	else if (visited[graph[node][i]]==0)
	dfs(graph[node][i]);
	}
	visited[node]=2;
	return cycle;
}
void dfsrun(int n)
{
	for (int i=0;i<n;i++)
	{
	if (visited[i]!=2 || visited[i]!=1)
			cycle=dfs(i);
	if (cycle==1)
	{
		flag=1;
	}
	}
	if (flag==1){
		//??cout << "Cycle present" << endl;
		cout << "Cycle present" << endl;
	}
	else
		cout << "No cycle" << endl;
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
	}
	dfsrun(n);
}