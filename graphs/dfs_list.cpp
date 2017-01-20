#include <iostream>
#include <vector>
using namespace std;
int col[1000];
void dfs_visit(vector<int> a[],int u)
{
	col[u-1] = 1;
	for(int i=0;i<a[u-1].size();i++)
	{
		if(col[a[u-1][i]-1]==0)
			dfs_visit(a,a[u-1][i]);
	}
	col[u-1]=2;
	cout<<u<<" ";
}
void dfs(vector<int> a[],int v)
{
	// 0 = white,1 = gray,2 = black
	for(int i=0;i<v;i++)
	{
		if(col[i]==0)
			dfs_visit(a,i+1);
	}
	cout<<endl;
}

int main()
{
	int v,e;
	cout<<"Enter number of vertices and edges"<<endl;
	cin>>v>>e;
	vector<int> a[v];
	for(int i=0;i<v;i++)
		col[i]=0;
	cout<<"Enter edges"<<endl;
	int p,q;
	for(int i=0;i<e;i++)
	{
		cin>>p>>q;
		a[p-1].push_back(q);
	}
	//printing adjacency list
	cout<<"Adjacency list is:"<<endl;
	for(int i=0;i<v;i++)
	{
		cout<<i+1<<"-> ";
		for(int j=0;j<a[i].size();j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
	cout<<"DFS traversal is "<<endl;
	dfs(a,v);
	return 0;
}