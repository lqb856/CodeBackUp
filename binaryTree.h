#pragma once
#include <graphics.h>
#include<vector>
#include <iostream>
#include<stack>
#include<queue>
typedef struct Node
{ 
	Node* parent;
	Node* leftchild;
	Node* rightchild;
	char value;
	Node() { leftchild = rightchild = parent=nullptr; }
	Node(Node& temp) { leftchild = temp.leftchild; rightchild = temp.rightchild; parent = temp.parent; value = temp.value; }
	Node(char val, Node* left = nullptr, Node* right = nullptr, Node* Parent = nullptr) { value = val; leftchild = left; rightchild = right; parent = Parent; }
	//~Node() { if (leftchild) { delete leftchild; } if (rightchild) { delete rightchild; } }
}node;

bool isoneTree(Node* p, Node* q)
{
	while (p->parent != nullptr)p = p->parent;
	while (q->parent != nullptr)q = q->parent;
	return p == q;
}

bool search(Node* root, Node* target)
{
	bool lf = false, ri = false;
	if (root == nullptr)
		return false;
	if (root == target)
		return true;
	if (root->leftchild != nullptr)
		lf = search(root->leftchild, target);
	if (root->rightchild != nullptr)
		ri = search(root->rightchild, target);
	return lf || ri;
}

int height(Node* node, std::vector<Node*>& que)
{

	/*std::stack<Node*> nodeStack;
	Node* p=root;


	while (!nodeStack.empty()||p)
	{
		while (p != nullptr)
		{
			nodeStack.push(p);
			p = p->leftchild;
			height++;
			if (p == node)
				break;
		}

		if (p == node)
			break;

		if (!nodeStack.empty())
		{
			p = nodeStack.top();
			nodeStack.pop();
			height--;
			p = p->rightchild;
		}
		if (p == node)
			break;
	}*/

	int height = 0;
	while (node->parent != nullptr)
	{
		node = node->parent;
		que.push_back(node);
		height++;
	}
	return height;
}

Node* CoParent(Node* p, Node* q)
{
	int tag = 0;
	if (p == nullptr || q == nullptr || p->parent == nullptr || q->parent == nullptr||!isoneTree(p,q))
		return nullptr;

	if (search(p, q) || search(q, p))
		tag = 0;
	else tag = 1;

	while (q->parent!=nullptr)
	{
		/*if (p == q)
			return p->parent;*/
		if (search(q, p)&&tag==0)
			return q->parent;
		else if (search(q, p)&&tag==1)
			return q;
		q = q->parent;
		
	}
	return q;
}

Node* Coparent(Node* p, Node* q)
{
	std::vector<Node*> quep;
	std::vector<Node*> queq;
	height(p, quep);
	height(q, queq);
	for (int i = 0; i < quep.size(); i++)
	{
		for (int j = 0; j < queq.size(); j++)
		{
			if (queq[j] == quep[i])
				return queq[j];
		}
	}
	return nullptr;
}




Node* LevelBuild(char* levelorder, int size)
{
	std::queue<Node*> Nodeque;

	Node* root = new Node(*levelorder);
	Node* result = root;
	root->parent = nullptr;
	Nodeque.push(root);

	outtextxy(850, 10, *levelorder);
	circle(855 , 20 , 20);

	int i = 1;
	int j = size-1;
	int k = 1;
	int m = 1;
	
	Node* leftChild, * rightChild;
	while (i < size)
	{

		Node *&p = Nodeque.front();
		Nodeque.pop();

		leftChild = new Node(*(levelorder + i));
		p->leftchild = leftChild;
		leftChild->parent = p;

		outtextxy(850 - (j / 2) * 40, k * 80, *(levelorder + i));
		circle(855 - (j / 2) * 40, k * 80 + 5, 20);
		
		if (i!=size-1)
		{
			rightChild = new Node(*(levelorder + i + 1));
			p->rightchild = rightChild;
			rightChild->parent = p;

			outtextxy(850 + (j / 2) * 40, k * 80, *(levelorder + i+1));
			circle(855 - (j / 2) * 40, k * 80 + 5, 20);
		}
		
		Nodeque.push(leftChild);
		
		Nodeque.push(rightChild);
		
		i+=2;
		j = size - i;
		if (i == 3 || i == 7 || i == 15 || i == 31)
			k += 1;
	}
	return result;
}

Node* PreInbuild(Node* parent, char* preorder, char* inorder, int size, int tag, int dx, int dy)
{
	if (size == 0)
		return nullptr;
	int pos = -1;
	for (int i = 0; i < size; i++)
	{
		if (*(preorder) == inorder[i])
		{
			pos = i;
			break;
		}
	}
	if (pos != -1)
	{
		
		Node* root = new Node;
		root->parent = parent;
		root->value = preorder[0];
		switch (tag)
		{
		case 0:
			outtextxy(850 +dx,10+dy,root->value);
			//Sleep(1000);
			circle(855 + dx, 20 + dy, 20);
			break;
		case 1:
			outtextxy(850 + dx, 10 + dy, root->value);
			//Sleep(1000);
			circle(855 + dx, 20 + dy, 20);
			//Sleep(1000);
			line(855 + dx, dy, (855 + dx - size * 40),dy-40);
			//Sleep(1000);
			line(855 + dx, dy, 855 + dx, dy - 40);
			line(855 + dx, dy - 40, (855 + dx - size * 40), dy - 40);
			break;
		case -1:
			outtextxy(850 + dx, 10 + dy, root->value);
			//Sleep(1000);
			circle(855 + dx, 20 + dy, 20);
			//Sleep(1000);
			line(855 + dx, dy, (855 + dx + size * 40), dy - 40);
			//Sleep(1000);
			line(855 + dx, dy, 855 + dx, dy - 40);
			line(855 + dx, dy - 40, (855 + dx + size * 40), dy - 40);
			break;
		}
		root->leftchild = PreInbuild(root, preorder + 1, inorder,pos,-1,dx-pos*40,dy+80);
		root->rightchild = PreInbuild(root, preorder + pos + 1, inorder + pos + 1, size - pos - 1, 1, dx + (size - pos - 1) * 40, dy + 80);
		return root;
	}
	else
	{
		outtextxy(630, 230, "输入序列不匹配！");
		return nullptr;
	}
	
}

Node* PostInbuild(Node* parent, char* postorder, char* inorder, int size,int tag,int dx,int dy)
{
	if (size == 0)
		return nullptr;
	int pos = -1;
	for (int i = 0; i < size; i++)
	{
		if (postorder[size-1] == *(inorder+i))
		{
			pos = i;
			break;
		}
	}
	if (pos != -1)
	{
		Node* root = new Node;
		root->parent = parent;
		root->value = postorder[size-1];
		switch (tag)
		{
		case 0:
			outtextxy(850 + dx, 10 + dy, root->value);
			Sleep(1000);
			circle(855 + dx, 20 + dy, 20);

			break;
		case 1:
			outtextxy(850 + dx, 10 + dy, root->value);
			Sleep(1000);
			circle(855 + dx, 20 + dy, 20);
			Sleep(1000);
			line(855 + dx, dy, (855 + dx - size * 40), dy - 40);
			Sleep(1000);
			line(855 + dx, dy, 855 + dx, dy - 40);
			line(855 + dx, dy - 40, (855 + dx - size * 40), dy - 40);
			break;
		case -1:
			outtextxy(850 + dx, 10 + dy, root->value);
			Sleep(1000);
			circle(855 + dx, 20 + dy, 20);
			Sleep(1000);
			line(855 + dx, dy, (855 + dx + size * 40), dy - 40);
			Sleep(1000);
			line(855 + dx, dy, 855 + dx, dy - 40);
			line(855 + dx, dy - 40, (855 + dx + size * 40), dy - 40);
			break;
		}
		root->leftchild = PostInbuild(root, postorder , inorder, pos,-1,dx - pos * 40, dy + 80);
		root->rightchild = PostInbuild(root, postorder + pos , inorder + pos + 1, size - pos - 1, 1, dx + (size - pos - 1) * 40, dy + 80);
		return root;
	}
	else
	{
		outtextxy(630, 230, "输入序列不匹配！");
		return nullptr;
	}

}

bool clearTree(Node* Node)
{
	if (Node == nullptr)
	{
		return true;
	}
	if(Node->leftchild)
		clearTree(Node->leftchild);
	if(Node->rightchild)
		clearTree(Node->rightchild);
	delete Node;
	
}

void check(char* order1, char* order2)
{

}
void preorder(Node* Node,std::vector<char>&ve)
{
	if (Node == nullptr)
		return;
	preorder(Node->leftchild,ve);
	preorder(Node->rightchild,ve);
	ve.push_back(Node->value);
}

