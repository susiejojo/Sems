
#include<iostream>
#include<vector> 
using namespace std; 

void addEdge(vector<int> adj[], int u, int v) 
{ 
	adj[u].push_back(v); 
	adj[v].push_back(u); 
} 

void DFSUtil(int u, vector<int> adj[], vector<bool> &visited) 
{ 
	visited[u] = true; 
	cout << u << " "; 
	for (int i=0; i<adj[u].size(); i++) 
		if (visited[adj[u][i]] == false) 
			DFSUtil(adj[u][i], adj, visited); 
} 

void prints(vector <int> adj[],int n)
{
	for (int j=0;j<n;j++)
	{
	for (auto i=adj[j].begin();i!=adj[j].end();i++)
		cout << adj[j].at(*i) << "*";
	}
}
void DFS(vector<int> adj[], int V) 
{ 
	vector<bool> visited;
	visited.assign(V,false); 
	for (int u=0; u<V; u++) 
		if (visited[u] == false) 
			DFSUtil(u, adj, visited); 
} 

int main() 
{ 
	int V = 5; 
	vector<int> adj[V]; 
	addEdge(adj, 0, 1); 
	addEdge(adj, 0, 4); 
	addEdge(adj, 1, 2); 
	addEdge(adj, 1, 3); 
	addEdge(adj, 1, 4); 
	addEdge(adj, 2, 3); 
	addEdge(adj, 3, 4); 
	prints(adj,5);
	cout << "\n";
	//DFS(adj, V); 
	return 0; 
} 
