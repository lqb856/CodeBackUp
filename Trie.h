#pragma once
#include<iostream>
#include<vector>
#include<queue>
#include "AVLTree.h"


using namespace std;


const int NofChildren= 26;

//struct word {
//	string word;
//	string meaning;
//	/*words():words(NULL),meaning(NULL){}*/
//};

struct TrieNode
{
	TrieNode* Child[NofChildren];
	bool isWordEnd;
	int Nchild;
	std::string meanning;
	string words;
	TrieNode()
	{
		for (int i = 0; i < 26; i++)
			Child[i] = nullptr;
		isWordEnd = false;
		Nchild = -1;
	}
	TrieNode(std::string M)
	{
		meanning = M;
		isWordEnd = false;
		Nchild = -1;
		for (int i = 0; i < 26; i++)
		{
			Child[i] = nullptr;
		}
	}
	std::string getMean() { return meanning; }
	~TrieNode() 
	{ 
		for (int i = 0; i < NofChildren; i++)
			if (!Child[i])
				delete Child[i];
	}
};


class Trie
{
private:
	TrieNode* root;
	int count;
public:
	Trie():count(0) { root = new TrieNode; }
	~Trie() {}
	bool insert(const std::string& key, const std::string& M);
	bool remove(const std::string key,std::string& S);
	bool search(const std::string key, vector<words<string,string>>& S,int num,int& count);
	void TrieFile(std::istream in);
	int getNum() { return count; }
protected:
	bool clear(TrieNode* node);
};