#pragma once
#include<iostream>
using namespace std;
const int n = 4;
const int m = 2 * n - 1;
const float MaxNum = 1000;
const int MaxN = 10;
typedef struct//Huffman树结构
{
	int weight;
	int parent, lchild, rchild;

}HFNode;

struct Code//用于记录编码
{
	int bit[MaxN];
	int start;
	int weight;
};

struct deC
{
	int weight;
	char ch;
	string code;
};

void CreateHFTree(HFNode T[], deC* dec, int n)						//T为Huffman树，dec为记录结构对象，n为待编码字符串的长度
{
	int i = 0;
	int m = 2 * n - 1;
	for (i = 0; i < n; i++)
		T[i].weight = dec[i].weight;
	for (i = 0; i < m; i++)
		T[i].parent = T[i].lchild = T[i].rchild = -1;
	for (i = n; i < m; i++)
	{
		int mini1 = MaxNum, mini2 = MaxNum, pos1=0, pos2=0;
		for (int j=0; j < i; j++)
		{
			if(T[j].parent==-1)
				if (T[j].weight < mini1)
				{
					pos2 = pos1;
					mini2 = mini1;
					pos1 = j;
					mini1 = T[j].weight;
				}
				else if (T[j].weight < mini2)
				{
					pos2 = j;
					mini2 = T[j].weight;
				}
			
		}
		T[i].lchild = pos1; T[i].rchild = pos2;			//新节点从n开始保存
		T[i].weight = T[pos1].weight + T[pos2].weight;
		T[pos1].parent = T[pos2].parent = i;
	}
}

void HFCode(HFNode* HFT, int n, Code HFC[],deC* dec)
{
	Code* cd = (Code*)malloc(sizeof(Code));
	int i = 0, j = 0, child = 0, parent = 0;
	for (i = 0; i < n; i++)
	{
		cd->start = n - 1;            //编码是逆序的
		cd->weight = HFT[i].weight;
		child = i;
		parent = HFT[child].parent;
		while (parent != -1)
		{
			if (HFT[parent].lchild == child)
			{
				cd->bit[cd->start] = 0;			//左子树，编码为0
			}
			else
			{
				cd->bit[cd->start] = 1;
			}
			cd->start--;
			child = parent;
			parent = HFT[child].parent;
		}
		for (j = cd->start + 1; j < n; j++)
			HFC[i].bit[j] = cd->bit[j];
		HFC[i].start = cd->start + 1;			//转移记录
		HFC[i].weight = cd->weight;
	}
	char ch[10];
	for (i = 0; i < n; i++) //输出每个叶结点的哈夫曼编码
	{
		cout << "Weight = " << HFC[i].weight << "   Code = ";
		for (j = HFC[i].start; j < n; j++) 
		{ 
			cout << HFC[i].bit[j]; 
			_itoa_s(HFC[i].bit[j], ch, 10);
			dec[i].code +=ch;
		}
		cout << endl;
	}
	free(cd);
	return ;
}



int getWeight(string s, deC* fr)
{
	int n = s.size(),c=0;
	deC* dec = new deC;
	for (int i = 0; i < n; i++)
	{
		if (s[i] != 32)								//为空格则不加入计数
		{
			dec->ch = s[i];							
			dec->weight = 1;

			for (int j = i + 1; j < n; j++)
			{
				if (s[j] == s[i])
				{
					s[j] = 32;						//计数过后，将所在值改为空格，以免重复计数
					dec->weight++;
				}
			}

			fr[c].ch = dec->ch;						//转移计数
			fr[c].weight = dec->weight;
			c++;									//记录数值个数
		}
	}
	delete dec;
	return c;										//返回数值个数
}

void HFDecode(HFNode* HFT,string S,deC *dec,int j)  //HFT为huffman数，S为编码，dec为数值编码记录，j为数值编码个数
{
	int n = S.size();
	int i = 0;
	string t;
	while(i<n)
	{
		int current = 2 * j - 2;										//t用于记录遍历路径，初始为“\0”
		t = "\0";
		while(HFT[current].rchild != -1&&HFT[current].lchild != -1)		//没有到叶节点
		{
			if (S[i] == '0')											//为0，向左走
			{
				current = HFT[current].lchild;
				t += '0';
				i++;
			}
			else
			{
				current = HFT[current].rchild;
				t += '1';
				i++;
			}
		}
			for (int k = 0; k < j; k++)									//将遍历路径与各数值编码比较，相同则输出
				if (dec[k].code == t)
				{
					cout << dec[k].ch << " ";
				}
				/*else
				{
					cout << endl << " 错误编码！" << endl;
					break;
				}*/
	}
}


int main(void)
{
	//int i, j, n = 5, weight[] = { 1,3,5,7,9 };
	//HFNode* myHaffTree = new HFNode[2 * n + 1];
	//Code* myHaffCode = new Code[n];
	//if (n > MaxN) { cout << "定义的n越界，修改MaxN! " << endl;  exit(0); }
	//CreateHFTree(myHaffTree, weight, n);
	//HFCode(myHaffTree, n, myHaffCode);
	//for (i = 0; i < n; i++) //输出每个叶结点的哈夫曼编码
	//{
	//	cout << "Weight = " << myHaffCode[i].weight << "   Code = ";
	//	for (j = myHaffCode[i].start; j < n; j++)	cout << myHaffCode[i].bit[j];
	//	cout << endl;
	//}
	//for (int i = 0; i < 2 * n - 1; i++)
	//	cout << myHaffTree[i].weight << " ";

	string s = "17396175992";
	int n = s.size();
	deC *dec=new deC[n];
	int l=getWeight(s, dec);

	HFNode* myHaffTree = new HFNode[2 * n + 1];
	Code* myHaffCode = new Code[n];
	CreateHFTree(myHaffTree, dec, l);
	HFCode(myHaffTree, l, myHaffCode, dec);

	for (int i = 0; i < l; i++)
		cout << " 数值: " << dec[i].ch <<" 权值: "<<dec[i].weight<< " 编码:" << dec[i].code << endl;
	cout << "整体编码: ";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < l; j++)
		{
			if (s[i] == dec[j].ch)
				cout << dec[j].code;
		}
	}
	cout << endl;
	string S = "110111000100011101110101010011";
	cout << "编码: " << S<<endl<<"译码: ";
	HFDecode(myHaffTree, S, dec, l);
	cin.get();
	return 0;
}