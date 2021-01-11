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
		if (j < end && heap[j] > heap[j + 1])//�ҳ����ӽڵ���ֵС���Ǹ�
			j++;
		if (temp <= heap[j])//�ȶ�����С���Ǹ���С�����û���
			break;
		heap[i] = heap[j];
		i = j;
		j = 2 * j;
	}
	heap[i] = temp;
}

template<class T>                       //����һ������һ�Σ����ֻ����һ��
inline void MiniHeap<T>::siftup(int start)//����������ӽڵ��ظ��ڵ����ϱȽϣ�С�ڸ��ڵ�����ӽڵ㻻��ȥ
{
	int j = start, i = j / 2;//�����һ����ʼ���͸��ڵ�Ƚ�
	T temp = heap[j];//�����ӽ���ֵ
	while (j > 1)
	{
		if (heap[i] <= temp)//���ڵ��С
			break;
		heap[j] = heap[i];//���ӽڵ㻻��ȥ
		j = i;            //�Ƶ����ڵ�
		i = i / 2;        //�Ƶ����ڵ�ĸ��ڵ�
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
		cerr << '\n' << "��̬�����ڴ����";
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
		cerr << '\n' << "��̬�����ڴ����";
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
		cerr << '\n' << "������";
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
		cerr << '\n' << "��Ϊ�գ�";
		return false;
	}
	x = heap[1];
	heap[1] = heap[size];//��������Ľڵ㻻��ȥ��
	siftdown(1, size);//����бȻ���ȥ�Ľڵ��С�Ľڵ㣬��Ҫ����ȥ
	size--;
	return true;
}

template<class T>
inline void MiniHeap<T>::output()
{
	for (int i = 1; i <= size; i++)
		cout << heap[i] << endl;
}

