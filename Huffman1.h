#pragma once
#include<iostream>
using namespace std;
const int n = 4;
const int m = 2 * n - 1;
const float MaxNum = 1000;
const int MaxN = 10;
typedef struct//Huffman���ṹ
{
	int weight;
	int parent, lchild, rchild;

}HFNode;

struct Code//���ڼ�¼����
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

void CreateHFTree(HFNode T[], deC* dec, int n)						//TΪHuffman����decΪ��¼�ṹ����nΪ�������ַ����ĳ���
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
		T[i].lchild = pos1; T[i].rchild = pos2;			//�½ڵ��n��ʼ����
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
		cd->start = n - 1;            //�����������
		cd->weight = HFT[i].weight;
		child = i;
		parent = HFT[child].parent;
		while (parent != -1)
		{
			if (HFT[parent].lchild == child)
			{
				cd->bit[cd->start] = 0;			//������������Ϊ0
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
		HFC[i].start = cd->start + 1;			//ת�Ƽ�¼
		HFC[i].weight = cd->weight;
	}
	char ch[10];
	for (i = 0; i < n; i++) //���ÿ��Ҷ���Ĺ���������
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
		if (s[i] != 32)								//Ϊ�ո��򲻼������
		{
			dec->ch = s[i];							
			dec->weight = 1;

			for (int j = i + 1; j < n; j++)
			{
				if (s[j] == s[i])
				{
					s[j] = 32;						//�������󣬽�����ֵ��Ϊ�ո������ظ�����
					dec->weight++;
				}
			}

			fr[c].ch = dec->ch;						//ת�Ƽ���
			fr[c].weight = dec->weight;
			c++;									//��¼��ֵ����
		}
	}
	delete dec;
	return c;										//������ֵ����
}

void HFDecode(HFNode* HFT,string S,deC *dec,int j)  //HFTΪhuffman����SΪ���룬decΪ��ֵ�����¼��jΪ��ֵ�������
{
	int n = S.size();
	int i = 0;
	string t;
	while(i<n)
	{
		int current = 2 * j - 2;										//t���ڼ�¼����·������ʼΪ��\0��
		t = "\0";
		while(HFT[current].rchild != -1&&HFT[current].lchild != -1)		//û�е�Ҷ�ڵ�
		{
			if (S[i] == '0')											//Ϊ0��������
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
			for (int k = 0; k < j; k++)									//������·�������ֵ����Ƚϣ���ͬ�����
				if (dec[k].code == t)
				{
					cout << dec[k].ch << " ";
				}
				/*else
				{
					cout << endl << " ������룡" << endl;
					break;
				}*/
	}
}


int main(void)
{
	//int i, j, n = 5, weight[] = { 1,3,5,7,9 };
	//HFNode* myHaffTree = new HFNode[2 * n + 1];
	//Code* myHaffCode = new Code[n];
	//if (n > MaxN) { cout << "�����nԽ�磬�޸�MaxN! " << endl;  exit(0); }
	//CreateHFTree(myHaffTree, weight, n);
	//HFCode(myHaffTree, n, myHaffCode);
	//for (i = 0; i < n; i++) //���ÿ��Ҷ���Ĺ���������
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
		cout << " ��ֵ: " << dec[i].ch <<" Ȩֵ: "<<dec[i].weight<< " ����:" << dec[i].code << endl;
	cout << "�������: ";
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
	cout << "����: " << S<<endl<<"����: ";
	HFDecode(myHaffTree, S, dec, l);
	cin.get();
	return 0;
}