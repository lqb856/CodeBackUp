#pragma once
#include<iostream>
#include "linearList.h"
using namespace std;

const int maxHead = 2;
template<class T>
struct Node
{
	T Data;
	Node<T> *Next;
	void operator=(Node<T>& N)
	{
		Data = N.Data;
	}
	Node(Node<T>* ptr=NULL) { Next = ptr; }
	Node(const T& data, Node<T>* next=NULL):Data(data),Next(next) {}
	Node(Node& node) { Data = node.Data; Next = node.Next; }
};
template <class T>
class List : public linearList<T>
{
private:
	Node<T>** First;
	
	int numHead;
public:
	List();
	~List();
	
	bool Add(T& x);
	
	Node<T>* FindPlace(int& p,const T& x,int len);
	
	bool Reverse(Node<T>* N);
	bool IsEmpty() const;
	
	void Output(Node<T>* F) const;
	
	Node<T>* GetHead(int i) { if (i >= 0 && i < numHead)return First[i]; else return NULL; }
	List<T>& operator=(List<T>& list);


	bool CreateCircle(T m, T n,int len);
	bool HasCircle(Node<T>* N,Node<T>*& Pos)
	{
		Node<T>* F=N->Next->Next, * S=N->Next, * Temp=N;
		
		while (F != S)
		{
			F = F->Next->Next;
			S = S->Next;
			
			if (F == NULL || S == NULL)
				return false;
		}
		
		F = N;
		while (S != F)
		{
			S = S->Next;
			F = F->Next;
		}
		Pos = S;
		return true;
	}
	Node<T>* Recover1(Node<T>* N, Node<T>*& Pos)
	{
		Node<T>* Tran = Pos->Next;
		while (Tran->Next != Pos)
			Tran = Tran->Next;
		
		Tran->Next = First[1]->Next;
		numHead--;
		
		Tran = First[1]->Next;
		while (Tran->Next != Pos)
			Tran = Tran->Next;
		Tran->Next = NULL;

		Node<T>* F = Tran = First[0]->Next;
		while (F != NULL && F->Next != NULL)
		{
			F = F->Next->Next;
			Tran = Tran->Next;
		}
		return Tran;
	}
	bool Recover2(Node<T>* N, Node<T>*& Pos)
	{
		Node<T>* Tran = Pos->Next;
		while (Tran->Next != Pos)
			Tran = Tran->Next;
		Tran->Next = NULL;
		return true;
	}
	Node<T>* IsIntersect(Node<T>* N1, Node<T>* N2)
	{
		if (!N1 || !N2)
			return NULL;
		Node<T>* Tran = N1;
		while (Tran->Next!=NULL)
		{
			Tran = Tran->Next;
		}
		Tran->Next = N2;
		Tran = N2->Next;
		while (Tran != N2)
		{
			Tran = Tran->Next;
			if (Tran->Next == NULL)
				return NULL;
		}
		Node<T>* pos;
		HasCircle(N1, pos);
		return pos;
	}
};

template <class T>
List<T>::List()
{
	First = new Node<T>*[maxHead];
	
	First[0] = new Node<T>(1000);
	First[1] = NULL;
	numHead = 1;
	
}

template <class T>
List<T>::~List()
{
	
}

template <class T>
bool List<T>::Add(T& x)//在链尾加
{
	Node<T>* newNode = new Node<T>(x);
	
	newNode->Next = First[0]->Next;
	First[0]->Next = newNode;

	return true;
}

template <class T>
Node<T>* List<T>::FindPlace(int& p,const T& x,int len)
{
	Node<T>* result = NULL;
	for (int i = 0; i < numHead; i++)
	{
		Node<T>* ptr = First[i]->Next;
		int count = 0;
		while (ptr != NULL)
		{
			
			count++;
			if (ptr->Data == x && ptr != NULL)
			{
				p = count;
				result = ptr;
				break;
			}
			ptr = ptr->Next;
			if (count > len)
				break;
		}
		if (ptr == NULL)
		{
			p = -1;
		}
	}
	return result;
}


template<class T>
inline bool List<T>::Reverse(Node<T>* N)
{
	Node<T> * L, * M, * R,* Last;
	R = N;
	M = N->Next;
	L = N->Next->Next;
	while (M !=L)
	{
		M->Next = R;
		R = M;
		M = L;
		if (L->Next)
		{
			L = L->Next;
		}
	}
	M->Next = R;
	

	if (N == First[0])
	{
		First[0]->Next = M;
		for (Last=First[0]; Last->Next != First[0]; Last = Last->Next);
		Last->Next = NULL;
	}
	else
	{
		First[numHead]->Next = M;
		for (Last = First[numHead]; Last->Next != First[numHead]; Last = Last->Next);
		Last->Next = NULL;
		numHead++;
	}
	
	return true;
}

template <class T>
bool List<T>::IsEmpty() const
{

	return First[0]->Next;
}

template <class T>
void List<T>::Output(Node<T>* F)  const
{
	int count = 20;
	
	if (F == NULL)
	{
		cout << "链表为空！" << endl;
	}
	else
	{
		Node<T>* ptr = F->Next;
		while (ptr != NULL&&count>=0)
		{
			cout << ptr->Data << ' ';
			ptr = ptr->Next;
			count--;
		}
	}
	cout << endl;
}


template<class T>
inline bool List<T>::CreateCircle(T m, T n,int len)
{
	int x, y;
	Node<T>* X=NULL, * Y=NULL, * Temp;

	X = FindPlace(x,m,len);
	Y = FindPlace(y,n,len);

	if(X==NULL||Y==NULL)
		return false;

	if (x >= y)
	{
		Temp = X->Next;
		X->Next = Y;
		
		if (Temp != NULL)
		{
			First[numHead] = new Node<T>(1000);
			First[numHead]->Next = Temp;
			numHead++;
			while (Temp->Next != NULL)
				Temp = Temp->Next;
			Temp->Next = Y;
		}
	}
	else
	{
		Temp = Y->Next;
		Y->Next = X;
		
		First[numHead] = new Node<T>();
		First[numHead]->Next = Temp;
		numHead++;
		while (Temp&&Temp->Next != NULL)
			Temp = Temp->Next;
		Temp->Next = X;
	}
}

