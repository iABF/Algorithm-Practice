#include "BSTree.h"

void BSTree::Deletemax(BSNode *& node)
{
	if (!node->right)
	{
		BSNode* tmp = node;
		node = node->left;
		delete tmp;
		tmp = NULL, size--;
	}
	else Deletemax(node->right);
}

void BSTree::Deletemin(BSNode *& node)
{
	if (!node->left)
	{
		BSNode* tmp = node;
		node = node->right;
		delete tmp;
		tmp = NULL, size--;
	}
	else Deletemin(node->left);
}



void BSTree::destroy(BSNode *& node)
{
	if (node)
	{
		destroy(node->left);
		destroy(node->right);
		delete node;
		node = NULL;
		size--;
	}
}

void BSTree::inorder(BSNode * node)
{
	if (node)
	{
		inorder(node->left);
		cout << node->key << ' ';
		inorder(node->right);
	}
}

void BSTree::Insert(int val)
{
	BSNode* node = root;
	BSNode* f = NULL;
	while (node != NULL)
	{
		f = node;
		if (val > node->key)node = node->right;
		else if (val < node->key)node = node->left;
		else return;
	}
	if (f == NULL)root = new BSNode(val);
	else if (f->key > val)f->left = new BSNode(val);
	else f->right = new BSNode(val);
	size++;
}

bool BSTree::Delete(int val)
{
	if (root == NULL)return false;
	if (root->left == NULL && root->right == NULL)
	{
		if (root->key == val)
		{
			delete root;
			root = NULL;
			size--;
			return true;
		}
		return false;
	}
	BSNode *parent = NULL;
	BSNode *cur = root;
	while (cur)
	{
		BSNode* del = NULL;
		if (cur->key > val)
		{
			parent = cur;
			cur = cur->left;
		}
		else if (cur->key < val)
		{
			parent = cur;
			cur = cur->right;
		}
		else//此时删除cur
		{
			if (cur->left == NULL)
			{
				if (parent == NULL)//此时cur为根节点，删除根节点
				{
					root = cur->right;
					delete cur;
					cur = NULL;
					size--;
					return true;
				}
				if (parent->key > cur->key)
				{
					del = cur;
					parent->left = cur->right;
					delete del;
					size--;
					return true;
				}
				else if (parent->key < cur->key)
				{
					del = cur;
					parent->right = cur->right;
					delete cur;
					size--;
					return true;
				}
			}
			else if (cur->right == NULL)
			{
				if (parent == NULL)
				{
					root = cur->left;
					delete cur;
					cur = NULL;
					size--;
					return true;
				}
				if (parent->key > cur->key)
				{
					del = cur;
					parent->left = cur->left;
					delete del;
					size--;
					return true;
				}
				else if (parent->key < cur->key)
				{
					del = cur;
					parent->right = cur->left;
					delete del;
					size--;
					return true;
				}
			}
			else
			{
				BSNode*del = cur;
				BSNode*parent = NULL;
				BSNode*Right = cur->right;
				if (Right->left == NULL)
				{
					swap(Right->key, cur->key);
					del = Right;
					cur->right = Right->right;
					delete del;
					size--;
					return true;
				}
				while (Right->left)//寻找右边最小元
				{
					parent = Right;
					Right = Right->left;
				}
				swap(Right->key, cur->key);
				del = Right;
				cur->right = Right->right;
				delete del;
				size--;
				return true;
			}
		}
	}
	return false;
}
