/*max-heap*/
#include <iostream>
#include <cmath>
using namespace std;
//helper functions
int parent(int i)
{
	return i/2;
}
int left(int i)
{
	return 2*i+1;
}
int right(int i)
{
	return 2*i+2;
}
/*MOST_IMP MAX-HEAPIFY operation,this is the core function for construction of heap
*it assumes that heap property is violated at only one place i.e i and hence rectifies it,
 by filtering the heap downward
*/
void max_heapify(int a[],int n,int i)
{
	int l = left(i); //index of left child
	int r = right(i); //index of right child
	int largest = i; //storing index of largest among (i,l,r)
	//make sure to validate the indices of children obtained
	if(l<n && a[l]>a[i])
		largest = l;
	if(r<n && a[r]>a[largest])
		largest = r;
	if(largest!=i)  //means heap property is being violated
	{
		//swap a[i] and a[largest]
		int temp = a[i];
		a[i] = a[largest];
		a[largest] = temp;
		//now heap property may get violated at index 'largest'
		max_heapify(a,n,largest);
	}
}
/*building max-heap using heapify operation
it builds the heap in bottom-up fashion
REMEMPER that n/2 onwards are leaf nodes and we don't worry about them
*/
void build_max_heap(int a[],int n)
{
	for(int i=n/2;i>=0;i--)
		max_heapify(a,n,i);
}
/*printing heap elements level-vise*/
void print_heap(int a[],int n)
{
	int count=0,level=0;
	while(count!=n)
	{
		int num = (int)pow(2,level);
		int i=0,j;
		for(j=i;j<i+num && j<n;j++)
		{
			count++;
			cout<<a[j]<<" ";
		}
		level++;
		i=j;
		cout<<endl;
	}
}
int main()
{
	int n;
	cout<<"enter no of elements"<<endl;
	cin>>n;
	cout<<"enter elements to make a max-heap"<<endl;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	//buid heap
	build_max_heap(a,n);
	cout<<"heap is"<<endl;
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	cout<<"print heap"<<endl;
	//print_heap(a,n);
	return 0;
}