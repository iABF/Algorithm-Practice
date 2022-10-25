#ifndef BSTREE_H
#define BSTREE_H
#include<iostream>
using namespace std;
class BSNode
{
	int key;
	BSNode* left;
	BSNode* right;
	BSNode(int val) : key(val), left(NULL), right(NULL) {}
	BSNode(BSNode& n) : key(n.key), left(n.left), right(n.right) {}
	friend class BSTree;
};
class BSTree
{
private:
	int size;
	void Deletemax(BSNode* &node);
	void Deletemin(BSNode* &node);
	void destroy(BSNode* &node);
	void inorder(BSNode* node);
	BSNode* root;
public:
	~BSTree() { destroy(root); }
	BSTree() { root = NULL; size = 0; }
	void Insert(int val);
	bool Delete(int val);
	int getsize() { return size; }
	void inorder() { inorder(root); cout << endl; }
};
#endif // !BSTREE_H

