#include <iostream>
using namespace std;
/*notes
*elements are represented as indices of array
*arr[i] is representative/parent of i i.e if i and j are  connected arr[i]=arr[j]
*at any stage parent nodes will have property a[i]=i i.e initial value
*/
/*naive approach
union is O(N^2) for N elements
*/
/* make-set*/
void initialize(int a[],int n)
{
	for(int i=0;i<n;i++)
		a[i]=i;
}
/*find - if two elements are connected*/
bool find(int a[],int i,int j)
{
	if(a[i]==a[j])
		return true;
	else
		return false;
}
void unite(int a[],int n,int p,int q)
{
	//consider q as new parent
	int prev_parent = a[p];
	int new_parent = a[q];
	for(int i=0;i<n;i++)
	{
		if(a[i]==prev_parent)
			a[i]=new_parent;
	}
}
/*approach-2
*use the basic fact that a[i]=i for root nodes
*no need to directly connect all children to (new) parent while doing union,
*just connect the parents of two sets OR parent of one set will become parent(master) of another set 
*/
void root(int a[],int i)
{
	while(a[i]!=i)
		i=a[i];
	return i;
}
bool modified_find(int a[],int u,int v)
{
	if(root(a,u)==root(a,v))
		return true;
	else
		return false;
}
void modified_union(int a[],int p,int q)
{
	//considering parent of q as master
	int root_p = root(a,p);
	int root_q = root(a,q);
	//setting parent of q to be parent of p 
	a[root_p] = root_q; 
}
/*approach-3
O(logN)
In the worst case, this idea will also take linear time in connecting 2 elements and determining (finding) whether two elements are
connected. Another disadvantage is that while connecting two elements, which subset has more elements is not checked. 
This may sometimes create a big problem because you will have to perform approximately linear time operations.
To avoid this, track the size of each subset and while connecting two elements connect the root of each subset that has a 
smaller number of elements to the root of each subset that has a larger number of elements.
*/
//modified initialize function for weighted union
void modified_initialize(int a[],int size[],int n)
{
	for(int i=0;i<n;i++)
	{
		a[i]=i;
		size[i]=1;
	}
}
//weighted union using size
void weighted_union(int a[],int size[],int p,int q)
{
	int root_p = root(a,p);
	int root_q = root(a,q);
	if(size[root_p]<size[root_q])
	{
		a[root_p] = root_q;
		size[root_q]+=size[root_p];
	}
	else
	{
		a[root_q] = root_p;
		size[root_p]+=size[root_q];
	}
}
/* O(log*N)
improving approach-3 further
*using pathcompression
While computing the root of A, set each i to point to its grandparent 
(thereby halving the length of the path), where i is the node that comes in the path while computing the root of A.
*/
	//modified root function using path compression
void modified_root(int a[],int i)
{
	while(a[i]!=i)
	{
		//make i point to its grandparent rather than parent
		a[i] = a[a[i]];
		i = a[i];
	}
}
