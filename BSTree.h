#pragma once
#include"AVLTree.h"
#include<iostream>
#include<stdlib.h>
#include<assert.h>

template<class T,class K>
struct BSTNode
{
	T data;
	K key;
	BSTNode<T,K>* left, * right;
	BSTNode():left(nullptr),right(nullptr){}
	BSTNode(const T& val, const K& val2) { left = right = nullptr; data = val; key = val2; }
	BSTNode(BSTNode<T,K>& node) { data = node.data; left = node.left; right = node.right; }
	~BSTNode(){}
	BSTNode<T,K>& operator=(BSTNode<T,K>& node) 
	{ 
		data = node.data; left = node.left; right = node.right;
		return node;
	}
	bool operator==(BSTNode<T,K>& node) { return this->data == node.data; }
	bool operator>(BSTNode<T,K>& node) { return this->data > node.data; }
	bool operator>=(BSTNode<T,K>& node) { return this->data >= node.data; }
	bool operator<(BSTNode<T,K>& node) { return this->data < node.data; }
	bool operator<=(BSTNode<T,K>& node) { return this->data <= node.data; }

};

template<class T,class K>
class BST
{
private:
	
	BSTNode<T,K>* root;
	void makeEmpty(BSTNode<T,K>* node);
	T findMin(BSTNode<T,K>* node);
	T findMax(BSTNode<T,K>* node);
	bool insert(const T& val,const K& key, BSTNode<T,K>*& node);
	bool search(const K& key, BSTNode<T, K>* root, vector<words<T, K>>& result, int num,int & count);
	
	bool remove(const T& val, BSTNode<T,K>*& node);
	bool isinTree(const T& val, BSTNode<T,K>* node);
	void preOrder(BSTNode<T,K>* node);
public:
	BST()  { root = new BSTNode<T,K>(); }
	~BST() { makeEmpty(root); root = nullptr; }
	T findMin() { findMin(root); }
	T findMax() { findMax(root); }
	bool insert(const T& val,const K& key) { return insert(val,key, root); }
	bool search(const K& key, vector<words<T, K>>& result, int num,int& count) { return search(key, root, result, num,count); }
	bool remove(const T& val) { return remove(val, root); }
	bool isinTree(const T& val) { return isinTree(val, root); }
	void preOrder() { preOrder(root); }
	void makeEmpty() { makeEmpty(root); root = nullptr; }
};

template<class T,class K>
inline void BST<T,K>::makeEmpty(BSTNode<T,K>* node)
{
	if (node == nullptr)
		return;
	if (node->left)
		makeEmpty(node->left);
	if (node->right)
		makeEmpty(node->right);
	delete node;
}

template<class T, class K>
inline T BST<T,K>::findMin(BSTNode<T,K>* node)
{
	if(node->left==nullptr)
	return node->data;
	return findMin(node->left);
}

template<class T, class K>
inline T BST<T,K>::findMax(BSTNode<T,K>* node)
{
	assert(node != nullptr);
	if(node->right==nullptr)
		return node->data;
	return findMax(node->right);
}

template<class T, class K>
inline bool BST<T,K>::insert(const T& val,const K &key, BSTNode<T,K>*& node)
{
	if (node == nullptr)
	{
		node = new BSTNode<T,K>(val,key);
		assert(node != nullptr);
		return true;
	}
	if (val > node->data)
		insert(val,key, node->right);
	if (val < node->data)
		insert(val,key, node->left);
	else
		return false;				//找到相等的就不插入
}

template<class T, class K>
inline bool BST<T,K>::remove(const T& val, BSTNode<T,K>*& node)
{
	BSTNode<T>* temp = node->left;
	if (node == nullptr)
    	return false;
	if (val < node->data)
		remove(val, node->left);
	else if (val > node->data)
		remove(val, node->right);
	else
	{
		if (!node->left && !node->right)
		{
			
			while (temp->right != nullptr)temp = temp->right;
			node->data = temp->data;
			remove(node->data, node->left);
		}
		else if (!node->left)
		{
			temp = node;
			node = node->right;
			delete temp;
			return true;
		}
		else if (!node->right)
		{
			temp = node;
			node = node->left;
			delete temp;
			return true;
		}
	}
}

template<class T, class K>
inline bool BST<T,K>::isinTree(const T& val, BSTNode<T,K>* node)
{
	if(node==nullptr)
		return false;
	if (node->data == val)
		return true;
	if (node->left)
		isinTree(val, node->left);
	if (node->right)
		isinTree(val, node->right);
}

template<class T, class K>
inline void BST<T,K>::preOrder(BSTNode<T,K>* node)
{
	if (node == nullptr)
		return;
	std::cout << node->data << " ";
	if (node->left)
		preOrder(node->left);
	if (node->right)
		preOrder(node->right);
}

template<class T, class K>
inline bool BST<T, K>::search(const K& key, BSTNode<T, K>* root, vector<words<T, K>>& result,int num,int& count)
{
	if (root == nullptr || num == 0)
		return false;

	BSTNode<string, string>* temp;
	string st;
	stack<BSTNode<T, K>*> Stack;
	words<string, string>word;

	while (root || !Stack.empty())
	{
		while (root)
		{

			Stack.push(root);
			root = root->left;
			count++;

		}
		if (!Stack.empty())
		{
			
			temp = Stack.top();
			Stack.pop();
			st = temp->key.substr(0, key.size());
			if (st == key)
			{
				
				word.meaning = temp->data;
				word.word = temp->key;
				result.push_back(word);
				num--;
			}
			root = temp->right;
		}
		if (num == 0)
			return true;
	}
	return false;
}
