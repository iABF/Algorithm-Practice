#include "AVLTree.h"

void AVLTree::LLrotate(AVLNode *& node)
{
	AVLNode* orileft = node->left;
	node->left = orileft->right;
	orileft->right = node;
	orileft->height = max(getheight(orileft->left), getheight(orileft->right)) + 1;
	node->height = max(getheight(node->left), getheight(node->right)) + 1;
	node = orileft;
}

void AVLTree::RRrotate(AVLNode *& node)
{
	AVLNode* oriright = node->right;
	node->right = oriright->left;
	oriright->left = node;
	oriright->height = max(getheight(oriright->left), getheight(oriright->right)) + 1;
	node->height = max(getheight(node->left), getheight(node->right)) + 1;
	node = oriright;
}

void AVLTree::LRrotate(AVLNode *& node)
{
	RRrotate(node->left);
	LLrotate(node);
}

void AVLTree::RLrotate(AVLNode *& node)
{
	LLrotate(node->right);
	RRrotate(node);
}

void AVLTree::Insert(AVLNode *& node, int val)
{
	if (!node)size++, node = new AVLNode(val);
	else if (val < node->key)
	{
		Insert(node->left, val);
		if (getheight(node->left) - getheight(node->right) == 2)
		{
			if (!node->left || val < node->left->key)LLrotate(node);
			else LRrotate(node);
		}
	}
	else if (val > node->key)
	{
		Insert(node->right, val);
		if (getheight(node->left) - getheight(node->right) == -2)
		{
			if (!node->right || val > node->right->key)RRrotate(node);
			else RLrotate(node);
		}
	}
	else return;
	node->height = max(getheight(node->left), getheight(node->right)) + 1;
}

void AVLTree::Delete(AVLNode *& node, int val)
{
	if (!node)
	{
		cout << "Failure" << endl;
		return;
	}
	if (val > node->key)
	{
		Delete(node->right, val);
		if (getheight(node->left) - getheight(node->right) == 2)
		{
			if (getheight(node->left->left) > getheight(node->left->right))LLrotate(node);
			else LRrotate(node);
		}
	}
	else if (val < node->key)
	{
		Delete(node->left, val);
		if (getheight(node->left) - getheight(node->right) == -2)
		{
			if (getheight(node->right->right) > getheight(node->right->left))RRrotate(node);
			else RLrotate(node);
		}
	}
	else if (val == node->key&&node->left != NULL && node->right != NULL)
	{
		AVLNode *leftmax = node->left;
		while (leftmax->right)leftmax = leftmax->right;
		node->key = leftmax->key;
		Delete(node->left, leftmax->key);
	}
	else
	{
		AVLNode *newnode = node->left ? node->left : node->right;
		delete node;
		node = newnode;
		size--;
	}
	if (node)node->height = max(getheight(node->left), getheight(node->right)) + 1;
}

bool AVLTree::BFS(AVLNode * node)
{
	bool flag = false, NOCBT = false;
	if (node == NULL)return false;
	queue<AVLNode*>q;
	q.push(node);
	while (!q.empty())
	{
		AVLNode* tmp = q.front();
		if (!tmp->left)flag = true;
		else
		{
			q.push(tmp->left);
			if (flag)NOCBT = true;
		}
		if (!tmp->right)flag = true;
		else
		{
			q.push(tmp->right);
			if (flag)NOCBT = true;
		}
		cout << tmp->key;
		printf("%c", q.size() == 1 ? '\n' : ' ');
		q.pop();
	}
	return NOCBT;
}
