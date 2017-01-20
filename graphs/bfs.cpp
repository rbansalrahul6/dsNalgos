/*directed graph
nodes are labeled from 1
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int v,e,s;
	queue<int> q;
	cout<<"vertices and edges"<<endl;
	cin>>v>>e;
	vector<int> a[v];
	int dist[v]; //distances from source
	bool vis[v]; //status of nodes i.e visited or unvisited
	int par[v]; //parent of node on shortest path
	cout<<"enter edges"<<endl;
	int x,y;
	for(int i=0;i<e;i++)
	{
		cin>>x>>y;
		a[x-1].push_back(y);
	}
	cout<<"source"<<endl;
	cin>>s;
	//initialization
	for(int i=0;i<v;i++)
	{
		dist[i]=-1;  //unreachable
		vis[i]=false;
		par[i]=-1;
	}
	par[s-1]=-1; //no parent
	vis[s-1]=true;
	dist[s-1]=0;
	q.push(s);
	while(!q.empty())
	{
		int cnode = q.front()-1;
		q.pop();
		//traverse adjList of cnode for unvisited nodes
		for(int j=0;j<a[cnode].size();j++)
		{
			if(!vis[a[cnode][j]-1])
			{
				q.push(a[cnode][j]);
				vis[a[cnode][j]-1]=true;
				par[a[cnode][j]-1]=cnode+1; //since numbering starts from 1
				dist[a[cnode][j]-1] = dist[cnode]+1;
				cout<<a[cnode][j]<<" "; //debugging
			}
		}
		cout<<endl; //debugging
	}
	cout<<"shortest distances"<<endl;
	for(int i=0;i<v;i++)
		cout<<dist[i]<<" ";
	cout<<endl;
	return 0;

}