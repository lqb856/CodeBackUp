#include"DataList.h"
#include"Heap.h"
#include<time.h>
#include"AVLTree.h"
void generator();

clock_t start, end1;

int main()
{
	MiniHeap<int> M;
	Element1<int> E1;
	AVLTree<int, int> A;

	DataList<int, int> D;
	//D.reserver(10000000);
	DataList<int, int> D2;
	Element<int, int> E;
	for (int i = 10000000; i>=0; i--)
	{
		E1.key = i;
		E.key = i;
		D.insert(E);
		D2.insert(E);
		M.insert(E1);
		A.insert(i, i);

	}
	//D.print(0, 1000);
	M.random();
	//D.random();
	//D.quickSort(D, 0, D.length()-1);
	//D.hybridQuickSort(D, 0, D.length() - 1);
	//D.quickNonRecursion(D, 0, D.length() - 1);
	start = clock();
	//M.heapSort(M);
	//D.quickNonRecursion(D, 0, D.length() - 1);
	//D.quickSort(D, 0, D.length()-1);
	//D.hybridQuickSort(D, 0, D.length() - 1);
	//D.mergeSort(D, D2, 0, D.length() - 1);
	int i = 10;
	A.preOrder();
	end1 = clock();
	double per = (double)(end1 - start) / CLOCKS_PER_SEC;

	//M.output(100,200);
	
	//D.mergeSort(D, D2, 0, D.length() - 1);
	//D.mergeSortNonRecursion(D, D2,0,D.length()-1);

	//D.binaryInsert(D, 0, D.length() - 1);

	
	

	D.print(200, 300);
	cout << per << endl;
	return 0;
}


//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include"linearTable.h"
//#include<list>
//using namespace std;
//vector<int> v;
//List<int> L;
//int insert(vector<int>& temp, int left, int right)
//{
//	/*int mid = (left + right) / 2;
//	int mini = left;
//	if(temp[mini]<temp[])*/
//	int i, j, k;
//	if (left >= 0 && right < temp.size() && left <= right)
//	{
//		for (i = left + 1; i <= right; i++)
//		{
//			if (temp[i] < temp[i - 1]) 
//			{
//				j = temp[i];
//				k = i ;
//				for (; k >left&&j<temp[k]; k--)
//					temp[k] = temp[k - 1];
//				temp[k] = j;
//			}
//		}
//	}
//	else
//	{
//		return -1;
//	}
//}
//
//int insertL(List<int>& temp)
//{
//	/*int mid = (left + right) / 2;
//	int mini = left;
//	if(temp[mini]<temp[])*/
//	Node<int>* ptr = temp.GetHead();
//	Node<int>* pre = temp.GetHead();
//	Node<int>* p = pre;
//
//	ptr = pre->Next->Next;
//
//	while (ptr != NULL)
//	{
//		int t = ptr->Data;
//		for (pre; pre->Next->Data < t && pre != ptr; pre = pre->Next)
//		{
//			p = pre;
//		}
//
//		Node<int>* n = new Node<int>(t);
//		n->Next = p->Next;
//		p->Next = n;
//
//		Node<int>* tran = temp.GetHead();
//		for (tran; tran->Next != ptr; tran = tran->Next);
//		tran->Next = ptr->Next;
//		Node<int>* d = ptr;
//		ptr = ptr->Next;
//		delete d;
//		
//		ptr = ptr->Next;
//	}
//	return 0;
//}
//
//
//
//int main()
//{
//	for (int i = 10; i >= 0; i--)
//	{
//		v.push_back(i);
//		L.Add(i);
//	}
//	insert(v, 0, v.size() - 1);
//	insertL(L);
//	//L.Output();
//	return 0;
//}