#ifndef AVLTREE_H
#define AVLTREE_H
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
class AVLNode
{
	int key;
	AVLNode* left;
	AVLNode* right;
	int height;
	AVLNode() : key(0), left(NULL), right(NULL), height(0) {}
	AVLNode(int val) : key(val), left(NULL), right(NULL), height(0) {}
	AVLNode(AVLNode& n) : key(n.key), left(n.left), right(n.right), height(n.height) {}
	friend class AVLTree;
};
class AVLTree
{
private:
	int size;
	
	int getheight(AVLNode* node) { return node ? node->height : -1; }
	void LLrotate(AVLNode* &node);
	void RRrotate(AVLNode* &node);
	void LRrotate(AVLNode* &node);
	void RLrotate(AVLNode* &node);
	void Insert(AVLNode* &node, int val);
	void Delete(AVLNode* &node, int val);
	bool BFS(AVLNode* node);
	AVLNode* root;
public:
	AVLTree() : root(NULL), size(0) {}
	void Insert(int val) { Insert(root, val); }
	void Delete(int val) { Delete(root, val); }
	int getsize() { return size; }
	bool BFS() { return BFS(root); }
};
#endif // !AVLTREE_H

