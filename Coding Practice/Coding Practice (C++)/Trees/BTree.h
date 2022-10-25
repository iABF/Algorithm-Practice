#ifndef BTREE_H
#define BTREE_H
#include<iostream>
#include<cassert>
using namespace std;
class BNode
{
	int *data;
	int Mindegree;//so the order of this tree is 2*Mindegree (This algorithm only makes even-order-B-Tree)
	BNode **next;
	int count;
	bool isleaf;
public:
	BNode(int mindeg, bool leaf);
	BNode *Search(int x);

	//Insertion functions
	void Split(int index, BNode* node);
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
	BNode *root;
	int Mindegree;//so the order of this tree is 2*Mindegree (This algorithm only makes even-order-B-Tree)
public:
	BTree(int Order) :root(NULL), Mindegree((Order + 1) / 2) {}
	BNode *Search(int x) { return root ? root->Search(x) : NULL; }
	void Insert(int x);
	void Delete(int x);
	void Print() { if (root)root->Print(); cout << endl; }
};
#endif // !BTREE_H
