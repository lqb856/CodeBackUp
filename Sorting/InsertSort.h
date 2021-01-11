//#pragma once
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//vector<int> v;
//int insert(vector<int>& temp,int left,int right)
//{
//	/*int mid = (left + right) / 2;
//	int mini = left;
//	if(temp[mini]<temp[])*/
//	int i, j,k;
//	if (left >= 0 && right < temp.size() && left <= right)
//	{
//		for (i = left + 1; i < right; i++)
//		{
//			int t = temp[i];
//			int j = i - 1;
//			while(t < temp[j]&&j>=0)
//			{
//				j--;
//			}
//			for (k = temp.size(); k >= j; k--)
//				temp[k] = temp[k - 1];
//			temp[j - 1] = t;
//		}
//	}
//	else
//	{
//		return -1;
//	}
//}
//
//int main()
//{
//	for (int i = 1000; i >= 0; i--)
//	{
//		v.push_back(i);
//	}
//	insert(v, 0, v.size() - 1);
//	return 0;
//}