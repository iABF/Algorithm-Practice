#ifndef RBTREE_H
#define RBTREE_H
#include<iostream>
#include<queue>
#include<algorithm>
#define INF 0x7fffffff
using namespace std;
enum COLOR { RED, BLACK };
class RBNode
{
	int key;
	RBNode* left;
	RBNode* right;
	RBNode* parent;
	COLOR color;
	RBNode() :left(NULL), right(NULL), parent(NULL), color(BLACK), key(INF) {}
	RBNode(int val) :key(val), left(NULL), right(NULL), color(RED), parent(NULL) {}
	RBNode(RBNode& node) :key(node.key), left(node.left), right(node.right), parent(node.parent), color(node.color) {}
	RBNode& operator=(RBNode& node)
	{
		this->key = node.key;
		this->parent = node.parent;
		this->right = node.right;
		this->left = node.left;
		this->color = node.color;
	}
	friend class RBTree;
};
class RBTree
{
private:
	RBNode* root;
	RBNode* NIL;
	int size;
	void leftrotate(RBNode* node);
	void rightrotate(RBNode* node);
	void insertfix(RBNode* node);
	void transplant(RBNode* ori, RBNode* newboy);
	RBNode* minnode(RBNode* node);
	void deletefix(RBNode* node);
	void preorder(RBNode* node);
public:
	RBTree() { size = 0; NIL = new RBNode; root = NIL, root->parent = root->left = root->right = NIL; }
	void Insert(int val);
	RBNode* Find(int val);
	bool Delete(int val);
	void printpreorder() { preorder(root); cout << endl; }
	void BFS();
	void minmax();
	int SSize() { return size; }
};
#endif // !RBTREE_H
