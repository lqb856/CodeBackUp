#include<string>
#include<iostream>
struct MyStruct
{
	int times;
	int pos;
}FFS1, FS1;
using namespace std;
void FastFind(string& pat, string& T, int k, int* next, MyStruct& FFS);
void Find(string& pat, string& T, int k, MyStruct &FS);
int* getNext(string& pat);



void main()
{
	string T = "abcabaacaasaaxas";
	string pat = "as";
	int* next = getNext(pat);
	for(int i=0;i<pat.size();i++)
	cout << next[i] <<" ";
	cout << endl;

	FastFind(pat, T, 0,next,FFS1);
	Find(pat, T, 0,FS1);
	cout << " FF:" << FFS1.pos << "  FFT:" << FFS1.times << '\t' << "F:" << FS1.pos << "  FT:" << FS1.times << endl;;
	cin.get();
}

void FastFind(string& pat, string& T, int k, int* next,MyStruct& FFS)
{

	int posP = 0, posT = k, lenP = pat.length(), lenT = T.length();
	while (posP < lenP && posT < lenT)
	{
		if (posP == -1 || pat[posP] == T[posT])
		{
			posP++;
			posT++;
		}
		else
		{
			posP = next[posP];
		}
		FFS.times++;
	}
	if (posP < lenP) { FFS.pos = -1; }
	else
	{
		FFS.pos == posT - lenP;
	}
}

void Find(string& pat, string& T, int k,MyStruct& FS)
{
	int i = 0, j = 0, len = T.length() - pat.length();
	for (i = k; i < T.length(); i++)
	{
		for (j = 0; j < pat.length(); j++)
		{
			if (pat[j] != T[j + i])
				break;
			FS.times++;
		}
		if (j == pat.length())
		{
			FS.pos = i;
		}
	}
	FS.pos = -1;
}

int* getNext(string& pat)
{
	int* next = new int[pat.size()+1];
	int j = 0, k = -1;
	next[0] = -1;
	while (j < pat.size() - 1)
	{
		if (k == -1 || pat[j] == pat[k])
		{
			if (pat[j + 1] == pat[k + 1])
				next[++j] = next[++k];
			else
			{
				next[++j] = ++k;
			}
		}
		else 
		{
			k = next[k];
		}
	}
	return next;
}
