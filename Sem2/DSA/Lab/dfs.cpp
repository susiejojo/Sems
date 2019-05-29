#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//1 represents black
//0 represents white
vector <vector <int> > graph; 
vector <int> node;
vector <int> visited;
vector <int> dfsnewArr;
vector <int> cycletracker;
int checkifcycle(int vertex) {
	int flag=0;
            visited[vertex] = 1;
            dfsnewArr[vertex] = 1;
            for (int i = 0; i < graph[vertex].size(); i++) {
                int adjVertex = graph[vertex][i];
                if (!visited[adjVertex] && checkifcycle(adjVertex)) 
                {
                	cycletracker[adjVertex]=1;
                    flag=1;
                } 
                else if (dfsnewArr[adjVertex])
                {
                	cycletracker[adjVertex]=1;
                    flag=1;
                }
            }
           if (flag==1)
           	return 1;
           else{
            dfsnewArr[vertex] = 0;
            return 0;}
        }

int dfsfind(int n) {
            for (int i = 0; i < n; i++) {
                if (checkifcycle(i))
                    return 1;
            }
            return 0;
        }

 void printarr()
 {
 	for (int i=0;i<cycletracker.size();i++)
 	{
 		cout << cycletracker[i] << endl;
 	}
 }

int main()
{
	int n,e;
	cin >> n >> e;
	node.assign(n,0);
	graph.assign(n,vector<int>());
	cycletracker.assign(n,0);
	//dfsvisit.assign(n,0);
	visited.assign(n,0);
	dfsnewArr.assign(n,0);

	//bfschecker.assign(n,0);
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
	if (dfsfind(n)==1){
		cout << "Cycle" << endl;
		printarr();
	}

	else{
		cout << "No Cycle" << endl;
		printarr();
	}
	

}