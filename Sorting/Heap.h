#pragma once
//#define defaul 20;
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

template<class T>
struct Element1
{
	T key;
	/*Element1(T t = 0) :key(0) {}*/
	/*Element1<T>& operator=(Element1<T>& x)
	{
		key = x.key;
		
		return *this;
	}*/
	
	bool operator==(Element1<T>& x)
	{
		return key == x.key;
	}
	bool operator<(Element1<T>& x)
	{
		return key < x.key;
	}
	bool operator>=(Element1<T>& x)
	{
		return key >= x.key;
	}
	/*bool operator<(Element1<T>& x)
	{
		return key < x.key;
	}*/
};

template<class T>
class MiniHeap
{
private:
	vector<Element1<T>> heap;
	/*int size;
	int maxsize;*/
	void siftdown(int start, int end);
	//void siftup(int start);
public:
	MiniHeap(/*int size =50*/);
	//MiniHeap(Element1<T>* array, int asize);
	~MiniHeap() { /*delete[]heap;*/ }
	bool insert( Element1<T>& x);
	bool remove(Element1<T>& x);
	bool isempty()const { return heap.size() == 0; }
	//bool isfull()const { return size == maxsize - 1; }
	void empty() { heap.clear(); }
	void output(int start,int end);
	void random()
	{
		std::random_shuffle(heap.begin(), heap.end());
	}
	void swap(const int i , const int j)
	{
		Element1<T> temp = heap[i];
		heap[i] = heap[j];
		heap[j]= temp;
	}
	void heapSort(MiniHeap<T>& H)
	{
		for (int i = (heap.size()-2)/ 2; i >= 0; i--)
			siftdown(i, heap.size()-1);
		for (int i = heap.size()-1; i >= 0; i--)
		{
			swap(0, i);
			siftdown(0, i-1);
		}
	}

	/*void MiniHeap<T>::adjustHeap(MiniHeap<T>& A, int idx, int n);
	int MiniHeap<T>::heapSortNonRecursive(MiniHeap<T>& A, int n);*/
};



template<class T>
inline void MiniHeap<T>::siftdown(int start, int end)
{
	int i = start, j = 2 * i+1;
	Element1<T> temp = heap[start];
	while (j <= end)
	{
		if (j < end && heap[j] < heap[j + 1])//找出儿子节点中值大的那个
			j++;
		if (temp >= heap[j])//比儿子中小的那个还小，不用换了
			break;
		heap[i] = heap[j];
		i = j;
		j = 2 * j+1;
	}
	heap[i] = temp;
}

//template<class T>                       //插入一个进行一次，因此只考虑一个
//inline void MiniHeap<T>::siftup(int start)//从最下面的子节点沿父节点向上比较，小于父节点则把子节点换上去
//{
//	int j = start, i = (j-1 )/ 2;//从最后一个开始，和父节点比较
//	Element1<T> temp = heap[j];//保存子结点的值
//	while (j > 0)
//	{
//		if (heap[i] >= temp)//父节点更大
//			break;
//		heap[j] = heap[i];//把子节点换上去
//		j = i;            //移到父节点
//		i = i / 2;        //移到父节点的父节点
//	}
//	heap[j] = temp;
//}

template<class T>
inline MiniHeap<T>::MiniHeap(/*int size*/)
{
	/*maxsize = ( size >50 ) ? size : 50;*/
	/*heap = new T[maxsize+1];*/
	/*if (NULL == heap)
	{
		cerr << '\n' << "动态分配内存出错！";
		exit(1);
	}
	size = 0;*/
	
}

//template<class T>
//inline MiniHeap<T>::MiniHeap(Element1<T>* array, int asize)
//{
//	//maxsize = (size > asize) ? size : asize;
//	///*heap = new Element<T>[maxsize+1];*/
//	//if (NULL == heap)
//	//{
//	//	cerr << '\n' << "动态分配内存出错！";
//	//	exit(1);
//	//}
//	for (int i = 1; i <asize; i++)
//		heap[i] = array[i];
//	//size = asize;
//	int curPostion = (size-2) / 2;
//	while (curPostion >= 1)
//	{
//		siftdown(curPostion, curPostion - 1);
//		curPostion--;
//	}
//}

template<class T>
inline bool MiniHeap<T>::insert( Element1<T>& x)
{
	/*if (size == maxsize - 1)
	{
		cerr << '\n' << "堆已满";
		return false;
	}*/

	heap.push_back(x);
	//siftup(heap.size());
	

	/*heap.push_back(x);*/
	return true;
}

template<class T>
inline bool MiniHeap<T>::remove(Element1<T>& x)
{
	if (heap.size() == 0)
	{
		cerr << '\n' << "堆为空！";
		return false;
	}
	x = heap[0];
	heap[0] = heap[heap.size()-1];//把最下面的节点换上去了
	siftdown(1, heap.size()-1);//如果有比换上去的节点更小的节点，就要换上去
	//size--;
	return true;
}

template<class T>
inline void MiniHeap<T>::output(int start,int end)
{
	if (start >= 0 && end < heap.size() && end >= start)
		for (int i = start; i <= end; i++)
			cout << heap[i].key <<" ";
}

//template<class T>
//inline void MiniHeap<T>::adjustHeap(MiniHeap<T>& A, int idx, int n)
//{
//	int ldx = 2 * idx + 1;
//	int rdx = 2 * idx + 2;
//	int maxdx = idx;
//	if (idx <= n / 2)
//	{
//		if (ldx < n && A.heap[ldx] > A.heap[maxdx])
//		{
//			maxdx = ldx;
//		}
//		if (rdx < n && A.heap[rdx] > A.heap[maxdx])
//		{
//			maxdx = rdx;
//		}
//		// 说明要交换
//		if (maxdx != idx)
//		{
//			//swap(A + idx, A + maxdx);
//			swap(idx, maxdx);
//			adjustHeap(A, maxdx, n);
//		}
//	
//}
//}

//template<class T>
//inline int MiniHeap<T>::heapSortNonRecursive(MiniHeap<T>& A, int n)
//{
//	for (int i = n - 1; i > -1; --i)
//	{
//		//swap(A, A + i);
//		swap(0, i);
//		adjustHeap(A, 0, i);
//	}
//	return 0;
//}

