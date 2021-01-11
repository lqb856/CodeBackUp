#pragma once
#include<iostream>
#include<stack>
//#include "BSTree.h"
#include<string>
#include<vector>
#include<assert.h>
using namespace std;

//int strCmp(const string& str1, const string& str2)
//{
//	str1.
//}

template<class T, class K>
struct words {
	T word;
	K meaning;
	/*words():words(NULL),meaning(NULL){}*/
};


template<class T, class K>
struct AVLNode
{
	int bf;
	T data;
	K key;
	AVLNode<T, K>* left, * right;
	AVLNode() :left(NULL), right(NULL), bf(0) {}
	AVLNode(T d, K k, AVLNode<T, K>* l = NULL, AVLNode<T, K>* r = NULL)
	{
		data = d;
		key = k;
		right = r;
		left = l;
		bf = 0;
	}
	/*~AVLNode()
	{
		if (left)
			delete left;
		if (right)
			delete right;
	}*/
};

template<class T, class K>
class AVLTree
{

public:
	AVLTree() :root(nullptr), count(0) {}
	bool clear() { return clear(root); }
	bool insert(const K& key, const T& val) { return insert(key, val, root); }
	bool remove(const K& key, const T& val) { return remove(key, val, root); }
	bool search(const T& key, words<T, K>& result, int count) { return search(key, root, result, count); }
	AVLNode<T, K>* findPlace(const K& key) { return findPlace(key, root); }
	bool recommand(const T& key, vector<words<T, K>>& result, int num, int& count)
	{
		AVLNode<T, K>* AVL = root;
		while (key > AVL->key && AVL->right)
		{
			AVL = AVL->right;
			count++;
		}
		return recommand(key, result, AVL, num, count);
	}
	void preOrder() { preOrder(root); }
protected:
	bool search(const T& key, AVLNode<T, K>* root, words<T, K>& result, int count);
	bool recommand(const T& key, vector<words<T, K>>& result, AVLNode<T, K>* ptr, int num, int& count);
	bool insert(const K& key, const T& val, AVLNode<T, K>*& root);
	bool remove(const K& key, const T& val, AVLNode<T, K>*& root);
	AVLNode<T, K>* findPlace(const K& key, AVLNode<T, K>* root);
	bool clear(AVLNode<T, K>*& root);
	void rotateL(AVLNode<T, K>*& ptr);
	void rotateR(AVLNode<T, K>*& ptr);
	void rotateLR(AVLNode<T, K>*& ptr);
	void rotateRL(AVLNode<T, K>*& ptr);
	/*int height(AVLNode<T>* ptr);*/
	void preOrder(AVLNode<T, K>* ptr);
private:
	AVLNode<T, K>* root;
	int count;
};

template<class T, class K>
inline AVLNode<T, K>* AVLTree<T, K>::findPlace(const K& key, AVLNode<T, K>* root)
{
	/*if(root==nullptr)
		return NULL;
	for (int i = 0; i < key.length(); i++)
	{
		if (root == null)
		{
			return nullptr;
		}
		if (key[i] < root->key[i])
			root = root->left;
		else if (key[i] > root->key[i])
			root = root->right;
	}
	return root;*/

	if (root == nullptr)
	{
		return nullptr;
	}
	while (key > root->key && root->right)
	{
		root = root->right;
	}
	return root;
}

//template<class T, class K>
//inline bool AVLTree<T, K>::search(const T& key, AVLNode<T, K>* root, words<T, K>& result, int count)
//{
//	if (root == nullptr)
//	{
//		return false;
//	}
//	if (key == root->key)
//	{
//		/*str.meaning = root->data;
//		str.word = root->key;*/
//		/*recommand(key,result,root,3);*/
//		return true;
//	}
//	if (key > root->key && root->right)
//		return search(key, root->right, str);
//	if (key < root->key && root->left)
//		return search(key, root->left, str);
//}

template<class T, class K>
inline bool AVLTree<T, K>::insert(const K& key, const T& val, AVLNode<T, K>*& root)
{
	AVLNode<T, K>* ptr = root, * pre = nullptr, * temp = nullptr;
	int d;
	std::stack<AVLNode<T, K>*> track;

	while (ptr != nullptr)
	{
		if (ptr->key == key)
			return false;
		pre = ptr;
		track.push(pre);

		if (key > ptr->key)
			ptr = ptr->right;
		else
			ptr = ptr->left;
	}
	ptr = new AVLNode<T, K>(val, key);
	assert(ptr != nullptr);
	if (pre == nullptr)
	{
		root = ptr;
		return true;
	}
	else if (key > pre->key)
		pre->right = ptr;
	else if (key < pre->key)
		pre->left = ptr;

	while (!track.empty())
	{
		pre = track.top();
		track.pop();
		if (ptr == pre->left)
			pre->bf--;
		else if (ptr == pre->right)
			pre->bf++;

		if (pre->bf == 0)
			break;
		else if (pre->bf == 1 || pre->bf == -1)
			ptr = pre;
		else
		{
			d = (pre->bf < 0) ? -1 : 1;
			//右边高
			if (ptr->bf == d)
			{
				if (d == 1)	//RR
					rotateR(pre);
				else		//RL
					rotateL(pre);
			}
			else					//左边高
			{
				if (d == -1)	//LL
					rotateLR(pre);
				else		//LR
					rotateRL(pre);
			}
			break;
		}

	}
	if (track.empty())
		root = pre;
	else						//重新链接调整过的子树
	{
		temp = track.top();
		if (temp->key > pre->key)
			temp->left = pre;
		else
			temp->right = pre;
	}
	count++;
	return true;
}

template<class T, class K>
inline bool AVLTree<T, K>::remove(const K& key, const T& val, AVLNode<T, K>*& root)
{
	AVLNode<T, K>* pr = nullptr, * p = root, * q, * ppr = nullptr;
	std::stack<AVLNode<T, K>*> track;
	int d, dd = 0;
	while (p != nullptr)
	{
		if (p->key == key)
			break;
		pr = p;
		track.push(pr);
		if (key > p->key)
			p = p->right;
		else
			p = p->left;
	}
	if (p == nullptr)
		return false;

	if (p->left && p->right)
	{
		pr = p;
		track.push(pr);
		q = p->left;
		while (q->right != nullptr)
		{
			pr = q;
			track.push(pr);
			q = q->right;
		}
		p->data = q->data;
		p->key = q->key;
		p = q;
	}
	else if (p->left != nullptr)
		q = p->left;
	else
		q = p->right;
	if (pr == nullptr)
		root = q;
	else
	{
		if (pr->left == p)
			pr->left = q;
		else
			pr->right = q;
		while (!track.empty())
		{
			pr = track.top();
			track.pop();
			if (pr->left == q)
				pr->bf++;
			else
				pr->bf--;
			if (!track.empty())
			{
				ppr = track.top();
				dd = (ppr->left == pr) ? -1 : 1;

			}
			else
				dd = 0;
			if (pr->bf == 1 || pr->bf == -1)
				break;
			if (pr->bf != 0)
			{
				if (pr->bf < 0)
				{
					d = -1;
					q = pr->left;

				}
				else
				{
					d = 1;
					q = pr->right;

				}
				if (q->bf == 0)
				{
					if (d == -1)
					{
						rotateL(pr);
						pr->bf = 1;
						pr->left->bf = -1;
					}
					else
					{
						rotateR(pr);
						pr->bf = -1;
						pr->right->bf = 1;
					}
					break;
				}
				if (q->bf == d)
				{
					if (d == -1)
						rotateL(pr);
					else
						rotateR(pr);

				}
				else
				{
					if (d == -1)
						rotateRL(pr);
					else
						rotateLR(pr);

				}
				if (d == -1)
					ppr->left = pr;
				else if (d == 1)
					ppr->right = pr;
			}
			q = pr;
		}
		if (track.empty())
			root = pr;
	}

	delete p;
	return true;

}

template<class T, class K>
inline bool AVLTree<T, K>::clear(AVLNode<T, K>*& root)
{
	if (root == nullptr)
		return false;
	if (root->left)
		clear(root->left);
	if (root->right)
		clear(root->right);
	delete root;
}

template<class T, class K>
inline void AVLTree<T, K>::rotateL(AVLNode<T, K>*& ptr)
{
	AVLNode<T, K>* subR = ptr;
	ptr = subR->left;
	/*AVLNode<T>* subL = ptr->left;*/

	subR->left = ptr->right;
	ptr->right = subR;
	ptr->bf = subR->bf = 0;
}

template<class T, class K>
inline void AVLTree<T, K>::rotateR(AVLNode<T, K>*& ptr)
{
	AVLNode<T, K>* subL = ptr;
	ptr = subL->right;
	/*AVLNode<T>* subR = ptr->right;*/

	subL->right = ptr->left;
	ptr->left = subL;
	subL->bf = ptr->bf = 0;
}

template<class T, class K>
inline void AVLTree<T, K>::rotateLR(AVLNode<T, K>*& ptr)
{
	AVLNode<T, K>* subR = ptr;
	AVLNode<T, K>* subL = ptr->left;
	ptr = subL->right;

	subL->right = ptr->left;
	ptr->left = subL;
	if (ptr->bf > 0)
		subL->bf = -1;
	else
		subL->bf = 0;

	subR->left = ptr->right;
	ptr->right = subR;
	if (ptr->bf == -1)
		subR->bf = 1;
	else subR->bf = 0;

	ptr->bf = 0;
}

template<class T, class K>
inline void AVLTree<T, K>::rotateRL(AVLNode<T, K>*& ptr)
{
	AVLNode<T, K>* subL = ptr;
	AVLNode<T, K>* subR = subL->right;
	ptr = subR->left;

	subL->right = ptr->left;
	ptr->left = subL;
	if (ptr->bf == 1)
		subL->bf = -1;
	else
		subL->bf = 0;

	subR->left = ptr->right;
	ptr->right = subR;
	if (ptr->bf < 0)
		subR->bf = 1;
	else
		subR->bf = 0;

	ptr->bf = 0;
}

template<class T, class K>
inline void AVLTree<T, K>::preOrder(AVLNode<T, K>* ptr)
{
	if (ptr == nullptr)
		return;

	if (ptr->right)
		preOrder(ptr->right);
	std::cout << /*ptr->key << */ptr->data << std::endl;
	
	if (ptr->left)
		preOrder(ptr->left);
}

template<class T, class K>
inline bool AVLTree<T, K>::recommand(const T& key, vector<words<T, K>>& result, AVLNode<T, K>* ptr, int num, int& count)
{
	if (ptr == nullptr || num == 0)
		return false;


	stack<AVLNode<T, K>*> Stack;

	while (ptr || !Stack.empty())
	{
		while (ptr)
		{

			//if (ptr->key != key)
				count++;
			Stack.push(ptr);
			ptr = ptr->left;
			
		}
		if (!Stack.empty())
		{
			ptr = Stack.top();
			Stack.pop();
			string temp = ptr->key.substr(0, key.size());
			if (temp == key)
			{
				words<string, string>word;
				word.meaning = ptr->data;
				word.word = ptr->key;
				result.push_back(word);
				num--;
			}
			ptr = ptr->right;
		}
		if (num == 0)
			return true;
	}
}
