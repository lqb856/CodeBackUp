#pragma once
//#define defaul 20;
#include<iostream>
using namespace std;
template<class T>
class MiniHeap
{
private:
	T* heap;
	int size;
	int maxsize;
	void siftdown(int start, int end);
	void siftup(int start);
public:
	MiniHeap(int size =50);
	MiniHeap(T* array, int asize);
	~MiniHeap() { delete[]heap; }
	bool insert(const T& x);
	bool remove(T& x);
	bool isempty()const { return size == 0; }
	bool isfull()const { return size == maxsize - 1; }
	void empty() { size = 0; }
	void output();

};



template<class T>
inline void MiniHeap<T>::siftdown(int start, int end)
{
	int i = start, j = 2 * i;
	T temp = heap[start];
	while (j <= end)
	{
		if (j < end && heap[j] > heap[j + 1])//找出儿子节点中值小的那个
			j++;
		if (temp <= heap[j])//比儿子中小的那个还小，不用换了
			break;
		heap[i] = heap[j];
		i = j;
		j = 2 * j;
	}
	heap[i] = temp;
}

template<class T>                       //插入一个进行一次，因此只考虑一个
inline void MiniHeap<T>::siftup(int start)//从最下面的子节点沿父节点向上比较，小于父节点则把子节点换上去
{
	int j = start, i = j / 2;//从最后一个开始，和父节点比较
	T temp = heap[j];//保存子结点的值
	while (j > 1)
	{
		if (heap[i] <= temp)//父节点更小
			break;
		heap[j] = heap[i];//把子节点换上去
		j = i;            //移到父节点
		i = i / 2;        //移到父节点的父节点
	}
	heap[j] = temp;
}

template<class T>
inline MiniHeap<T>::MiniHeap(int size)
{
	maxsize = ( size >50 ) ? size : 50;
	heap = new T[maxsize+1];
	if (NULL == heap)
	{
		cerr << '\n' << "动态分配内存出错！";
		exit(1);
	}
	size = 0;
}

template<class T>
inline MiniHeap<T>::MiniHeap(T* array, int asize)
{
	maxsize = (size > asize) ? size : asize;
	heap = new T[maxsize+1];
	if (NULL == heap)
	{
		cerr << '\n' << "动态分配内存出错！";
		exit(1);
	}
	for (int i = 1; i <asize; i++)
		heap[i] = array[i];
	size = asize;
	int curPostion = size / 2;
	while (curPostion >= 1)
	{
		siftdown(curPostion, curPostion - 1);
		curPostion--;
	}
}

template<class T>
inline bool MiniHeap<T>::insert(const T& x)
{
	if (size == maxsize - 1)
	{
		cerr << '\n' << "堆已满";
		return false;
	}
	heap[size+1] = x;
	siftup(size+1);
	size++;
	return true;
}

template<class T>
inline bool MiniHeap<T>::remove(T& x)
{
	if (size == 0)
	{
		cerr << '\n' << "堆为空！";
		return false;
	}
	x = heap[1];
	heap[1] = heap[size];//把最下面的节点换上去了
	siftdown(1, size);//如果有比换上去的节点更小的节点，就要换上去
	size--;
	return true;
}

template<class T>
inline void MiniHeap<T>::output()
{
	for (int i = 1; i <= size; i++)
		cout << heap[i] << endl;
}

