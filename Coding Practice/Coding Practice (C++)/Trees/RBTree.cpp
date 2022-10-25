#include "RBTree.h"

void RBTree::leftrotate(RBNode * node)
{
	if (node->right == NIL)return;
	RBNode* y = node->right;
	node->right = y->left;
	if (y->left != NIL)y->left->parent = node;
	y->parent = node->parent;
	if (node->parent == NIL)root = y;
	else if (node == node->parent->left)node->parent->left = y;
	else node->parent->right = y;
	y->left = node;
	node->parent = y;
}

void RBTree::rightrotate(RBNode * node)
{
	if (node->left == NIL)return;
	RBNode* y = node->left;
	node->left = y->right;
	if (y->right != NIL)y->right->parent = node;
	y->parent = node->parent;
	if (node->parent == NIL)root = y;
	else if (node == node->parent->left)node->parent->left = y;
	else node->parent->right = y;
	y->right = node;
	node->parent = y;
}

void RBTree::insertfix(RBNode * node)
{
	while (node->parent->color == RED)
	{
		if (node->parent == node->parent->parent->left)
		{
			RBNode*y = node->parent->parent->right;
			if (y->color == RED)
			{
				node->parent->color = BLACK;
				y->color = BLACK;
				y->parent->color = RED;
				node = y->parent;
			}
			else
			{
				if (node == node->parent->right)
				{
					node = node->parent;
					leftrotate(node);
				}
				node->parent->color = BLACK;
				node->parent->parent->color = RED;
				rightrotate(node->parent->parent);
			}
		}
		else
		{
			RBNode*y = node->parent->parent->left;
			if (y->color == RED)
			{
				node->parent->color = BLACK;
				y->color = BLACK;
				y->parent->color = RED;
				node = y->parent;
			}
			else
			{
				if (node == node->parent->left)
				{
					node = node->parent;
					rightrotate(node);
				}
				node->parent->color = BLACK;
				node->parent->parent->color = RED;
				leftrotate(node->parent->parent);
			}
		}
		//cout << "fixround:";
		//BFS();
	}
	root->color = BLACK;
}

void RBTree::transplant(RBNode * ori, RBNode * newboy)
{
	if (ori->parent == NIL)root = newboy;
	else if (ori == ori->parent->left)ori->parent->left = newboy;
	else ori->parent->right = newboy;
	newboy->parent = ori->parent;
}

RBNode * RBTree::minnode(RBNode * node)
{
	RBNode* cur = node;
	while (cur->left != NIL)cur = cur->left;
	return cur;
}

void RBTree::deletefix(RBNode * node)
{
	while (node != root && node->color == BLACK)
	{
		if (node == node->parent->left)
		{
			RBNode* bro = node->parent->right;
			if (bro->color == RED)
			{
				bro->color = BLACK;
				node->parent->color = RED;
				leftrotate(node->parent);
				bro = node->parent->right;//update brother after changing family structure
			}
			if (bro->left->color == BLACK && bro->right->color == BLACK)
			{
				bro->color = RED;
				node = node->parent;
			}
			else
			{
				if (bro->right->color == BLACK)
				{
					bro->left->color = BLACK;
					bro->color = RED;
					rightrotate(bro);
					bro = node->parent->right;
				}
				bro->color = node->parent->color;//color brother with parent's color
				node->parent->color = BLACK;
				bro->right->color = BLACK;
				leftrotate(bro->parent);
				node = root;//break in a way that will not disturb the last line of this function
			}
		}
		else
		{
			RBNode* bro = node->parent->left;
			if (bro->color == RED)
			{
				bro->color = BLACK;
				node->parent->color = RED;
				rightrotate(node->parent);
				bro = node->parent->left;
			}
			if (bro->left->color == BLACK && bro->right->color == BLACK)
			{
				bro->color = RED;
				node = node->parent;
			}
			else
			{
				if (bro->left->color == BLACK)
				{
					bro->right->color = BLACK;
					bro->color = RED;
					leftrotate(bro);
					bro = node->parent->left;
				}
				bro->color = node->parent->color;
				node->parent->color = BLACK;
				bro->left->color = BLACK;
				rightrotate(bro->parent);
				node = root;
			}
		}
	}
	node->color = BLACK;
}

void RBTree::preorder(RBNode * node)
{
	if (node == NIL)return;
	cout << node->key << (node->color == RED ? "(R)" : "(B)") << ' ';
	preorder(node->left);
	preorder(node->right);
}

void RBTree::Insert(int val)
{
	RBNode* newnode = new RBNode(val);
	newnode->left = newnode->right = NIL;
	RBNode* y = NIL;
	RBNode* x = root;
	while (x != NIL)
	{
		y = x;
		if (val < x->key)x = x->left;
		else x = x->right;
	}
	newnode->parent = y;
	if (y == NIL)root = newnode;
	else if (val < y->key)y->left = newnode;
	else y->right = newnode;
	size++;
	//BFS();
	insertfix(newnode);
}

RBNode * RBTree::Find(int val)
{
	RBNode* node = root;
	while (node != NIL && node->key != val)node = node->key > val ? node->left : node->right;
	return node;
}

bool RBTree::Delete(int val)
{
	RBNode* node = Find(val), *x, *y = node;
	if (node == NIL)return false;
	COLOR oricol = node->color;
	if (node->left == NIL) { x = node->right; transplant(node, node->right); }
	else if (node->right == NIL) { x = node->left; transplant(node, node->left); }
	else
	{
		y = minnode(node->right);
		oricol = y->color;
		x = y->right;
		if (y->parent == node)x->parent = y;
		else
		{
			transplant(y, y->right);
			y->right = node->right;
			node->right->parent = y;
		}
		transplant(node, y);
		y->left = node->left;
		node->left->parent = y;
		y->color = node->color;
	}
	if (oricol == BLACK)deletefix(x);
	delete node;
	size--;
	return true;
}

void RBTree::BFS()
{
	queue<RBNode*>q;
	q.push(root);
	while (!q.empty())
	{
		RBNode* de = q.front();
		cout << de->key << '(' << (de->color == RED ? "R" : "B") << ')' << ' ';
		if (de->left != NIL)q.push(de->left);
		if (de->right != NIL)q.push(de->right);
		q.pop();
	}
	cout << endl;
}

void RBTree::minmax()
{
	RBNode* node = root;
	while (node->left != NIL)node = node->left;
	cout << node->key << ' ';
	node = root;
	while (node->right != NIL)node = node->right;
	cout << node->key << endl;
}
