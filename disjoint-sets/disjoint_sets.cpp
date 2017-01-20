#include <iostream>
#include <vector>
using namespace std;

class DisjSets
{
public:
	explicit DisjSets(int numElements);
	int find(int x) const;
	int find(int x);
	void unionSets(int root1,int root2);
private:
	vector<int> s;        //s[i] is parent of i,-1(a default value) indicates self-loop or representative node
}
/*Construct the disjoint sets object.
*numElements is the initial number of disjoint sets
*/
DisjSets::DisjSets(int numElements) : s{numElements,-1}    //-1 is the default value for singleton set and represent parent node
{

}
/*
*union of two disjoint sets
*let root1 is root of set-1
*let root2 is root of set-2
*/
void DisjSets::unionSets(int root1,int root2)
{
	s[root2] = root1;  //parent of set-2 points to root1
}
/*perform find operation
*return set containing x i.e representative element
*/
int DisjSets::find(int x) const
{
	if(s[x]<0)      //-1 
		return x;
	else
		return find(s[x]);
}