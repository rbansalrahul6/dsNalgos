/*storing directed weighted graph*/
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main()
{
	int v,e;
	cout<<" no of vertices and edges"<<endl;
	cin>>v>>e;
	vector<pair<int,int> > a[v];
	int x,y,w;
	cout<<"enter edges with weights"<<endl;
	for(int i=0;i<e;i++)
	{
		cin>>x>>y>>w;
		a[x-1].push_back(make_pair(y,w));
	}
	cout<<"adjacency list"<<endl;
	for(int i=0;i<v;i++)
	{
		cout<<i+1<<"-> ";
		for(int j=0;j<a[i].size();j++)
			cout<<a[i][j].first<<"|"<<a[i][j].second<<" ";
		cout<<endl;
	}
	return 0;
}