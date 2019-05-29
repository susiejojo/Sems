 #include <bits/stdc++.h> 

using namespace std; 

priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq; //min heap creation with edge weights
vector <pair<int,int>> graph[500011];
vector <int> dist;//array to store distances of each vertex from source
vector <int> visited;
void relax(int u,int v,int w)
{
	if (dist[v]>dist[u]+w)
	{
		dist[v]=dist[u]+w;
	pq.push(make_pair(dist[v],v));//pushes minimum distance vertex into pq
	}
}
void djikstra(int source)
{
	pq.push(make_pair(0,source));//always start with source
	dist[source]=0;
	while (!pq.empty())
	{
		int min=pq.top().second;//extract min distance wala vertex
		pq.pop();
		visited[min]=1;//visit this vertex
		for (int i=0;i<graph[min].size();i++)//look through neighbours of min
		{
			if (visited[graph[min][i].first]==0)
			{
			relax(min,graph[min][i].first,graph[min][i].second);
			}	
		}
	}
	for (int i=0;i<dist.size();i++)
		cout << dist[i] << endl;
}
int main () 
{ 
	int n,e;
	cin >> n >> e;
	dist.assign(n,INT_MAX);
	visited.assign(n,0);
	for (int i=0;i<e;i++)
	{
		int a,b,w;
		cin >> a >> b >> w;
		graph[a-1].push_back(make_pair(b-1,w));
		graph[b-1].push_back(make_pair(a-1,w));
	}
	// int source;
	// cin >> source;
	djikstra(0);
	return 0; 
} 
