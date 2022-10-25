#include"BTree.h"

BNode::BNode(int mindeg, bool leaf)
{
	Mindegree = mindeg, isleaf = leaf, count = 0;
	data = new int[2 * Mindegree - 1];
	next = new BNode *[2 * Mindegree];
}

BNode * BNode::Search(int x)
{
	int cur = 0;
	while (cur < count&&data[cur] < x)cur++;//find the first data >= x
	if (data[cur] == x)return this;
	if (isleaf)return NULL;
	return next[cur]->Search(x);//just in this child
}

void BTree::Insert(int x)
{
	if (!root)
	{
		root = new BNode(Mindegree, true);
		root->data[0] = x;
		root->count = 1;
	}
	else
	{
		if (root->count == 2 * Mindegree - 1)
		{
			BNode *node = new BNode(Mindegree, false);
			node->next[0] = root;
			node->Split(0, root);//Split root and move the middle data of root to node's 0th position
			node->next[node->data[0] < x ? 1 : 0]->EasyInsert(x);
			root = node;
		}
		else root->EasyInsert(x);
	}
}

void BTree::Delete(int x)
{
	if (!root)
	{
		cout << "This tree is already empty" << endl;
		return;
	}
	root->Delete(x);
	if (!root->count)
	{
		BNode *tmp = root;
		if (root->isleaf)root = NULL;
		else root = root->next[0];
		delete tmp;
	}
}

void BNode::Split(int index, BNode * node)//node split: (Mindegree - 1)<still>; 1<to this' (index)th position>; (Mindegree - 1)<to new brother>
{
	assert(node->count == 2 * Mindegree - 1);//only called when (node->count == 2 * Mindegree - 1)
	BNode *newnode = new BNode(node->Mindegree, node->isleaf);
	newnode->count = Mindegree - 1;
	for (int i = 0; i < Mindegree - 1; i++)newnode->data[i] = node->data[i + Mindegree];//Copy the last (Mindegree - 1) data
	if (!node->isleaf)for (int i = 0; i < Mindegree; i++)newnode->next[i] = node->next[i + Mindegree];//Copy the last Mindegree children
	node->count = Mindegree - 1;
	for (int i = count - 1; i >= index; i--)data[i + 1] = data[i];
	data[index] = node->data[Mindegree - 1];
	for (int i = count; i > index; i--)next[i + 1] = next[i];
	next[index + 1] = newnode;
	count++;
}

void BNode::EasyInsert(int x)
{
	assert(count < Mindegree * 2 - 1);//only called when this node is not full
	int cur = count - 1;
	if (isleaf)//insert in this node
	{
		while (cur >= 0 && data[cur] > x)data[cur + 1] = data[cur], cur--;//find a place and move greater data right
		data[cur + 1] = x, count++;
	}
	else//insert in a child
	{
		while (cur >= 0 && data[cur] > x)cur--;//find a place
		if (next[cur + 1]->count == 2 * Mindegree - 1)
		{
			Split(cur + 1, next[cur + 1]);
			if (data[cur + 1] < x)cur++;//after split, find the place for x (leftchild or rightchild)
		}
		next[cur + 1]->EasyInsert(x);
	}
}

void BNode::Delete(int x)
{
	int index = GetIndex(x);
	if (index < count&&data[index] == x)//Main Deletion
	{
		if (isleaf)DeleteFromLeaf(index);
		else DeleteFromNonLeaf(index);
	}
	else//Return false or Delete in the child
	{
		if (isleaf)
		{
			cout << "The data does not exist" << endl;
			return;
		}
		bool isinLastChild = (index == count ? true : false);
		if (next[index]->count < Mindegree)Fill(index);//give it more data
		if (isinLastChild&&count < index)next[index - 1]->Delete(x);//if islast && merged
		else next[index]->Delete(x);
	}
}

int BNode::GetIndex(int x)
{
	int index = 0;
	while (index < count&&data[index] < x)index++;
	return index;
}

void BNode::DeleteFromLeaf(int index)
{
	for (int i = index + 1; i < count; i++)data[i - 1] = data[i];
	count--;
}

void BNode::DeleteFromNonLeaf(int index)
{
	int x = data[index];
	if (next[index]->count >= Mindegree)//if leftchild is ok then replace and delete in the leftchild
	{
		int MaxLess = FindMaxLess(index);
		data[index] = MaxLess;
		next[index]->Delete(MaxLess);
	}
	else if (next[index + 1]->count >= Mindegree)//if rightchild is ok then replace and delete in the rightchild
	{
		int MinGreater = FindMinGreater(index);
		data[index] = MinGreater;
		next[index + 1]->Delete(MinGreater);
	}
	else//both not ok, then merge. So the new node has ((Mindegree - 1) + 1 + (Mindegree - 1)) data, then delete x
	{
		Merge(index);
		next[index]->Delete(x);
	}
}

void BNode::Fill(int index)
{
	if (index&&next[index - 1]->count >= Mindegree)BorrowFromLeft(index);//if leftbrother is able
	else if (index != count && next[index + 1]->count >= Mindegree)BorrowFromRight(index);//if rightbrother is able
	else if (index != count)Merge(index);
	else Merge(index - 1);
}

int BNode::FindMinGreater(int index)
{
	BNode *cur = next[index + 1];
	while (!cur->isleaf)cur = cur->next[0];
	return cur->data[0];
}

int BNode::FindMaxLess(int index)
{
	BNode *cur = next[index];
	while (!cur->isleaf)cur = cur->next[cur->count];
	return cur->data[cur->count - 1];
}

void BNode::Merge(int index)
{
	BNode *left = next[index];
	BNode *right = next[index + 1];
	left->data[Mindegree - 1] = data[index];
	for (int i = 0; i < right->count; i++)left->data[i + Mindegree] = right->data[i];
	if (!left->isleaf)for (int i = 0; i <= right->count; i++)left->next[i + Mindegree] = right->next[i];
	for (int i = index + 1; i < count; i++)data[i - 1] = data[i];//fill the gap
	for (int i = index + 2; i <= count; i++)next[i - 1] = next[i];
	left->count += right->count + 1;
	count--;
	delete right;
}

void BNode::BorrowFromLeft(int index)
{
	BNode *left = next[index - 1];
	BNode *right = next[index];
	for (int i = right->count - 1; i >= 0; i--)right->data[i + 1] = right->data[i];
	if (!right->isleaf)for (int i = right->count; i >= 0; i--)right->next[i + 1] = right->next[i];
	right->data[0] = data[index - 1];
	if (!right->isleaf)right->next[0] = left->next[left->count];
	data[index - 1] = left->data[left->count - 1];
	right->count += 1;
	left->count -= 1;
}

void BNode::BorrowFromRight(int index)
{
	BNode *left = next[index];
	BNode *right = next[index + 1];
	left->data[left->count] = data[index];
	if (!left->isleaf)left->next[left->count + 1] = right->next[0];
	data[index] = right->data[0];
	for (int i = 1; i < right->count; i++)right->data[i - 1] = right->data[i];
	if (!right->isleaf)for (int i = 1; i <= right->count; i++)right->next[i - 1] = right->next[i];
	left->count += 1;
	right->count -= 1;
}