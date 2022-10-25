#include<iostream>
#include<cassert>
using namespace std;
class BTreeNode
{
	int *data;
	int Mindegree;//so the order of this tree is 2*Mindegree (This algorithm only makes even-order-B-Tree)
	BTreeNode **next;
	int count;
	bool isleaf;
public:
	BTreeNode(int mindeg, bool leaf);
	BTreeNode *Search(int x);

	//Insertion functions
	void Split(int index, BTreeNode* node);
	void EasyInsert(int x);

	//Deletion functions
	void Delete(int x);
	int GetIndex(int x);//return the index of the first data >= x
	void DeleteFromLeaf(int index);
	void DeleteFromNonLeaf(int index);
	void Fill(int index);//Fill next[index]: if borrow is ok then borrow, else merge
	int FindMinGreater(int index);
	int FindMaxLess(int index);
	void Merge(int index);//Merge (next[index] && data[index] && next[index + 1]) to next[index]
	void BorrowFromLeft(int index);//Borrow one data from leftbrother
	void BorrowFromRight(int index);//Borrow one data from rightbrother

	void Print()
	{
		int cur;
		for (cur = 0; cur < count; cur++)
		{
			if (!isleaf)next[cur]->Print();
			cout << " " << data[cur];
		}
		if (!isleaf)next[cur]->Print();
	}
	friend class BTree;
};
class BTree
{
	BTreeNode *root;
	int Mindegree;//so the order of this tree is 2*Mindegree (This algorithm only makes even-order-B-Tree)
public:
	BTree(int Order) :root(NULL), Mindegree((Order + 1) / 2) {}
	BTreeNode *Search(int x) { return root ? root->Search(x) : NULL; }
	void Insert(int x);
	void Delete(int x);
	void Print() { if (root)root->Print(); cout << endl; }
};


BTreeNode::BTreeNode(int mindeg, bool leaf)
{
	Mindegree = mindeg, isleaf = leaf, count = 0;
	data = new int[2 * Mindegree - 1];
	next = new BTreeNode *[2 * Mindegree];
}

BTreeNode * BTreeNode::Search(int x)
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
		root = new BTreeNode(Mindegree, true);
		root->data[0] = x;
		root->count = 1;
	}
	else
	{
		if (root->count == 2 * Mindegree - 1)
		{
			BTreeNode *node = new BTreeNode(Mindegree, false);
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
		BTreeNode *tmp = root;
		if (root->isleaf)root = NULL;
		else root = root->next[0];
		delete tmp;
	}
}

void BTreeNode::Split(int index, BTreeNode * node)//node split: (Mindegree - 1)<still>; 1<to this' (index)th position>; (Mindegree - 1)<to new brother>
{
	assert(node->count == 2 * Mindegree - 1);//only called when (node->count == 2 * Mindegree - 1)
	BTreeNode *newnode = new BTreeNode(node->Mindegree, node->isleaf);
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

void BTreeNode::EasyInsert(int x)
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

void BTreeNode::Delete(int x)
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

int BTreeNode::GetIndex(int x)
{
	int index = 0;
	while(index < count&&data[index] < x)index++;
	return index;
}

void BTreeNode::DeleteFromLeaf(int index)
{
	for (int i = index + 1; i < count; i++)data[i - 1] = data[i];
	count--;
}

void BTreeNode::DeleteFromNonLeaf(int index)
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

void BTreeNode::Fill(int index)
{
	if (index&&next[index - 1]->count >= Mindegree)BorrowFromLeft(index);//if leftbrother is able
	else if (index&&next[index + 1]->count >= Mindegree)BorrowFromRight(index);//if rightbrother is able
	else if (index != count)Merge(index);
	else Merge(index - 1);
}

int BTreeNode::FindMinGreater(int index)
{
	BTreeNode *cur = next[index + 1];
	while (!cur->isleaf)cur = cur->next[0];
	return cur->data[0];
}

int BTreeNode::FindMaxLess(int index)
{
	BTreeNode *cur = next[index];
	while (!cur->isleaf)cur = cur->next[cur->count];
	return cur->data[cur->count - 1];
}

void BTreeNode::Merge(int index)
{
	BTreeNode *left = next[index];
	BTreeNode *right = next[index + 1];
	left->data[Mindegree - 1] = data[index];
	for (int i = 0; i < right->count; i++)left->data[i + Mindegree] = right->data[i];
	if (!left->isleaf)for (int i = 0; i <= right->count; i++)left->next[i + Mindegree] = right->next[i];
	for (int i = index + 1; i < count; i++)data[i - 1] = data[i];//fill the gap
	for (int i = index + 2; i <= count; i++)next[i - 1] = next[i];
	left->count += right->count + 1;
	count--;
	delete right;
}

void BTreeNode::BorrowFromLeft(int index)
{
	BTreeNode *left = next[index - 1];
	BTreeNode *right = next[index];
	for (int i = right->count - 1; i >= 0; i--)right->data[i + 1] = right->data[i];
	if (!right->isleaf)for (int i = right->count; i >= 0; i--)right->next[i + 1] = right->next[i];
	right->data[0] = data[index - 1];
	if (!right->isleaf)right->next[0] = left->next[left->count];
	data[index - 1] = left->data[left->count - 1];
	right->count += 1;
	left->count -= 1;
}

void BTreeNode::BorrowFromRight(int index)
{
	BTreeNode *left = next[index];
	BTreeNode *right = next[index + 1];
	left->data[left->count] = data[index];
	if (!left->isleaf)left->next[left->count + 1] = right->next[0];
	data[index] = right->data[0];
	for (int i = 1; i < right->count; i++)right->data[i - 1] = right->data[i];
	if (!right->isleaf)for (int i = 1; i <= right->count; i++)right->next[i - 1] = right->next[i];
	left->count += 1;
	right->count -= 1;
}

int main()
{
	BTree Tree(4);
	int a[] = { 1,3,7,10,11,13,14,15,18,16,19,24 };
	for (int i = 0; i < 12; i++) {
		Tree.Insert(a[i]);
		Tree.Print();
	}
	Tree.Delete(1);
	Tree.Print();
	Tree.Delete(11);
	Tree.Print();
}
