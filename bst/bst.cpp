#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
struct node
{
	int key;
	node* left;
	node* right;
};

void bst_insert(node** root,int key)
{
	node* parent = NULL;
	node* temp = *root;
	//create new node
	node* new_node = (node*)malloc(sizeof(node));
	new_node->key=key;new_node->left=NULL;new_node->right=NULL;
	//first thing is to find location to insert
	while(temp!=NULL)
	{
		parent = temp;
		if(key<temp->key)
			temp = temp->left;
		else
			temp = temp->right;
	}
	//now we know parent,next we need to check if key to be inserted is root,left child or right child
	if(parent==NULL)
		*root = new_node;
	else if(key<parent->key)
		parent->left=new_node;
	else
		parent->right=new_node;
}
node* construct_bst(int n,int a[])
{
	node* root = NULL;
	for(int i=0;i<n;i++)
		bst_insert(&root,a[i]);
	return root;
}
void inorder(node* root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<root->key<<" ";
	inorder(root->right);
}
int bst_min(node* root)
{
	node* temp=root;
	while(temp->left!=NULL && temp!=NULL)
	{
		temp = temp->left;
	}
	return temp->key;
}
int bst_max(node* root)
{
	node* temp=root;
	while(temp->right!=NULL && temp!=NULL)
	{
		temp = temp->right;
	}
	return temp->key;
}
node* search(node* root,int key)
{
	node* temp = root;
	while(temp!=NULL)
	{
		if(temp->key==key)
			return temp;
		else if(key<temp->key)
			temp = temp->left;
		else
			temp = temp->right;
	}
	return NULL;
}
int height(node* root)
{
	//considering height of empty tree as -1 
	if(root==NULL)
		return -1;
	else
		return max(height(root->left),height(root->right))+1;
}
int main()
{
	int n,k,h;
	cout<<"Enter no of elements"<<endl;
	cin>>n;
	int a[n];
	cout<<"Enter elements"<<endl;
	for(int i=0;i<n;i++)
		cin>>a[i];
	node* rt = construct_bst(n,a);
	inorder(rt);
	cout<<endl;
	cout<<"min in bst "<<bst_min(rt)<<endl;
	cout<<"max in bst "<<bst_max(rt)<<endl;
	h = height(rt);
	cout<<"Height of tree is "<<h<<endl;
	cout<<"Enter elememnt to search"<<endl;
	cin>>k;
	node* find = search(rt,k);
	cout<<"location is "<<find<<endl;
	return 0;
}