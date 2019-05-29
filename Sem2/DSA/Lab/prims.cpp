 #include <bits/stdc++.h> 

using namespace std; 

priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq; //min heap creation with edge weights
vector <pair<int,int>> graph[500011];
vector <int> dist;//array to store distances of each vertex from source
vector<int> parent; 
vector<bool> inMST; 
vector<int> key; 
void relax(int u,int v,int w)
{
	if (dist[v]>dist[u]+w)
	{
		dist[v]=dist[u]+w;
	pq.push(make_pair(dist[v],v));//pushes minimum distance vertex into pq
	}
}
void primMST(int n) 
{   
    int src = 0;    
    pq.push(make_pair(0, src)); 
    key[src] = 0; 
  
    while (!pq.empty()) 
    {  
        int u = pq.top().second; 
        pq.pop(); 
  		inMST[u] = true;  
        for (int i=0;i<graph[u].size();i++)//look through neighbours of min
		{
			int v=graph[u][i].first;
			int weight=graph[u][i].second;
			if (inMST[v]==false && key[v]>weight)
			{
				key[v]=weight;
				pq.push(make_pair(key[v],v));
				parent[v]=u;
			}	
		}
    } 
  
    for (int i = 1; i < n; ++i) 
        printf("%d - %d\n", parent[i], i); 
} 
int main () 
{ 
	int n,e;
	cin >> n >> e;
	dist.assign(n,INT_MAX);
	parent.assign(n,-1);
	key.assign(n,INT_MAX);
	inMST.assign(n,false);
	for (int i=0;i<e;i++)
	{
		int a,b,w;
		cin >> a >> b >> w;
		graph[a].push_back(make_pair(b,w));
		graph[b].push_back(make_pair(a,w));
	}
	// int source;
	// cin >> source;
	primMST(n);
	return 0; 
} 
