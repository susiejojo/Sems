#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//1 represents black
//0 represents white
vector <vector <int> > graph; 
vector <int> node;
vector <int> bfschecker;
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
		//if(val==0)	cout << graph[val].size() << " " << graph[val][i] << " " << bfschecker[] << endl;

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
	cout << graph[0].size() << endl;
	for (int i=0;i<n;i++)
	{
	if (bfschecker[i]!=1)
	bfs(i);
	}
}
int main()
{
	int n,e;
	cin >> n >> e;
	node.assign(n,0);
	graph.assign(n,vector<int>());
	bfschecker.assign(n,0);
	for (int i=0;i<e;i++)
	{
		int a,b;
		cin >> a >> b;
		graph[a].push_back(b);
	}
	for (int i=0;i<n;i++)
	{
		cout << i << ":";
		for (int j=0;j<graph[i].size();j++)
		{
			cout << graph[i][j] << " ";
		}
		cout << "\n";
	}
	bfsrun(n);

}