#pragma once
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
const int DefaultSize = 1000;
template<class T,class K>
class Element
{
public:
	//T data;
	K key;

	/*Element() :key(-1) {}*/

	/*Element(Element<T, K>& x)
	{
		key = x.key;
	}*/
	
	//void operator=(Element<T, K>& x)
	//{
	//	//data = x.data;
	//	key = x.key;
	//	//return *this;
	//}
	
	bool operator==(Element<T, K>& x)
	{
		return key == x.key;
	}
	bool operator<=(Element<T, K>& x)
	{
		return key <= x.key;
	}
	bool operator>(Element<T, K>& x)
	{
		return key > x.key;
	}
	bool operator<(Element<T, K>& x)
	{
		return key < x.key;
	}

};


template<class T,class K>
class DataList
{
public:
	DataList(int Size = DefaultSize)
	{
		//maxSize = Size;
		//size = 0;
	}
	void swap1(Element<T, K>& x1, Element<T, K>& x2)
	{
		Element<T, K> temp = x1;
		x1 = x2;
		x2 = temp;
	}
	int length() { return can.size(); }
	Element<T, K>& operator[](int i)
	{
		int s = can.size();
		if(i>=0&&i<s)
			return can[i];
	}
	int partition(const int low, const int high);
	Element<T, K>& median3(DataList<T, K>& L, const int left, const int right);
	int partitionWithMedian3(DataList<T, K>& L, const int left, const int right);
	void quickSort(DataList<T, K>& L, const int left, const int right);

	void quickSortWithMedian3(DataList<T, K>& L, const int left, const int right);
	void hybridQuickSort(DataList<T, K>& L, const int left, const int right);
	void quickNonRecursion(DataList<T, K>& L, int left, int right);

	void improvedMerge(DataList<T, K>& L1, DataList<T, K>& L2, const int left, const int mid, const int right);
	void doSort(DataList<T, K>& L, DataList<T, K>& L2, int left, int right);
	void mergeSort(DataList<T, K>& L, DataList<T, K>& L2, int left, int right)
	{
		doSort(L, L2, left, right);
		binaryInsert(L, left, right);
	}
	void mergeSortNonRecursion(DataList<T, K>& L, DataList<T, K>& L2, int left, int right);

	void binaryInsert(DataList<T, K>& L, const int left, const int right);

	void random()
	{
		std::random_shuffle(can.begin(), can.end());
	}
	void insert(Element<T, K>& E)
	{
		can.push_back(E);
		//size++;
	}
	void insertAt(Element<T, K>& E, int pos)
	{
		can.insert(can.begin() + pos - 1, E);
	}
	void reserver(const int i)
	{
		can.reserve(i);
	}
	void print(int left,int right)
	{
		int s = can.size();
		if(left>=0 && right<s && left<right)
			for (int i = left; i < right; i++)
				cout << can[i].key <<" ";
	}
private:
	vector<Element<T, K>>  can;
	//int maxSize;
	//int size;

};

template<class T, class K>
inline int DataList<T, K>::partition(const int low, const int high)
{
	int pivotPos = low;
	Element<T, K> pivot = can[low];
	for (int i =low + 1; i < high; i++)
	{
		if (can[i] < pivot)
		{
			pivotPos++;
			if (i != pivotPos)
				swap1(can[i], can[pivotPos]);
		}
	}
	can[low] = can[pivotPos];
	can[pivotPos] = pivot;

	return pivotPos;
}

template<class T, class K>
inline Element<T, K>& DataList<T, K>::median3(DataList<T, K>& L, const int left, const int right)
{
	int mid = (left + right) / 2;
	int k = left;
	if (L[mid] < L[k])
		k = mid;
	if (L[right] < L[k])
		k = right;
	if (k != left)
		swap1(L[k], L[left]);
	if (mid != right && L[mid] < L[right])
		swap1(L[mid], L[right]);
	
	return L[right];
}

template<class T, class K>
inline int DataList<T, K>::partitionWithMedian3(DataList<T, K>& L, const int left, const int right)
{
	int i = left;
	int j = right - 1;

	if (left < right)
	{
		Element<T, K> pivot = median3(L, left, right);
		for (;;)
		{
			while (i < j && L[i] < pivot)
				i++;
			while (i<j && L[j]>pivot)
				j--;
			if (i < j)
			{
				swap1(L[i], L[j]);
				i++;
				j--;
			}
			else
				break;
		}
		if (L[i] > pivot)
		{
			L[right] = L[i];
			L[i] = pivot;
		}
	}
	return i;
}

template<class T, class K>
inline void DataList<T, K>::quickSort(DataList<T, K>& L, const int left, const int right)
{
	if (right - left < 25)
		binaryInsert(L, left, right);
	else
	{
		int pivotPos = partition(left, right);
		quickSort(L, left, pivotPos - 1);
		quickSort(L, pivotPos + 1, right);
	}
}

template<class T, class K>
inline void DataList<T, K>::quickSortWithMedian3(DataList<T, K>& L, const int left, const int right)
{
	if (right - left <= 25)
		return;
	int pivotPos = partitionWithMedian3(L, left, right);
	quickSortWithMedian3(L, left, pivotPos - 1);
	quickSortWithMedian3(L, pivotPos + 1, right);
}

template<class T, class K>
inline void DataList<T, K>::hybridQuickSort(DataList<T, K>& L, const int left, const int right)
{
	quickSortWithMedian3(L, left, right);
	binaryInsert(L, left, right);
}

template<class T, class K>
inline void DataList<T, K>::quickNonRecursion(DataList<T, K>& L, int left, int right)
{
	if (left >= 0 && right < can.size() && left <= right)
	{
		stack<int> S;
		int l, r, pivotPos;
		S.push(right);
		S.push(left);
		
		while (!S.empty())
		{
			l = S.top();
			S.pop();
			r = S.top();
			S.pop();

			if (r - l <= 16)
				binaryInsert(L, l, r);
			else
			{
				pivotPos = partitionWithMedian3(L, l, r);
				if (pivotPos < r)
				{
					S.push(r);
					S.push(pivotPos + 1);
				}
				if (pivotPos > l)
				{
					S.push(pivotPos - 1);
					S.push(l);
				}
			}
		}
		
	}

}

template<class T, class K>
inline void DataList<T, K>::improvedMerge(DataList<T, K>& L1, DataList<T, K>& L2, const int left, const int mid, const int right)
{
	int s1 = left, s2 = right, t = left, k;
	for (k = left; k <= mid; k++)
	{
		/*L2.insertAt(L1[k], k);*/
		L2[k] = L1[k];
	}
	for (k = mid + 1; k <= right; k++)
	{/*L2.insertAt(L1[k],right + mid + 1 - k);*/
		L2[right + mid + 1 - k] = L1[k];
	}
	while (t <= right)
		if (L2[s1] <= L2[s2])
			L1[t++] = L2[s1++];
		else
			L1[t++] = L2[s2--];
}

template<class T, class K>
inline void DataList<T, K>::doSort(DataList<T, K>& L, DataList<T, K>& L2, int left, int right)
{
	if (left >= right)
		return;
	if (right - left < 16)
		return;
	int mid = (right + left) / 2;
	doSort(L, L2, left, mid);
	doSort(L, L2, mid + 1, right);
	improvedMerge(L, L2, left, mid, right);
}

template<class T, class K>
inline void DataList<T, K>::mergeSortNonRecursion(DataList<T, K>& L, DataList<T, K>& L2, int left, int right)
{
	if (left<0 || left>right || right >= can.size())
		return;
	int l, r, mid=-1;
	stack<int>S;
	S.push(right);
	S.push(left);

	while (!S.empty())
	{
		l = S.top();
		S.pop();
		r = S.top();
		S.pop();

		
		/*if ((r - l) < 16)
		{
			binaryInsert(L, l, r);
		}
		else*/
		{
			mid = (r + l) / 2;
			improvedMerge(L, L2, l, mid, r);

			if (mid > l)
			{
				S.push(mid - 1);
				S.push(l);
			}

			if (mid < r)
			{
				S.push(r);
				S.push(mid + 1);
			}
		}
		
	}

}

template<class T, class K>
inline void DataList<T, K>::binaryInsert(DataList<T, K>& L, const int left, const int right)
{
	Element<T, K> temp;
	int high, low, middle;
	for (int i = left + 1; i < right; i++)
	{
		temp = L[i];
		low = left;
		high = i - 1;
		while (low<=high)
		{
			middle = (low + high) / 2;
			if (temp > L[middle])
				low = middle + 1;
			else
				high = middle - 1;
		}
		for (int j = i - 1; j >= low; j--)
			L[j + 1] = L[j];
		L[low] = temp;
	}
}
