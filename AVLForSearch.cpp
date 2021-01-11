#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<Windows.h>
#include<string>
#include<io.h>
#include<wchar.h>
#include<vector>
#include"AVLTree.h"

using namespace std;
#include"include/cppjieba/Jieba.hpp"
struct weight
{
    int file;
    int line;
    double wei;
    weight(int f=0, int w=0, int l=0)
    {
        file = f;
        wei = w;
        line = l;
    }
    bool operator<(weight w)
    {
        return wei < w.wei;
    }
};
vector<weight> W;
AVLTree<int, string> AVL;
vector<file>pos;
vector<string> filePath;
vector<string> words;
string temp;




//GB2312到UTF-8的转换
char* G2U(const char* gb2312)
{
    int len = MultiByteToWideChar(CP_ACP, 0, gb2312, -1, NULL, 0);
    wchar_t* wstr = new wchar_t[len + 1];
    memset(wstr, 0, len + 1);
    MultiByteToWideChar(CP_ACP, 0, gb2312, -1, wstr, len);
    len = WideCharToMultiByte(CP_UTF8, 0, wstr, -1, NULL, 0, NULL, NULL);
    char* str = new char[len + 1];
    memset(str, 0, len + 1);
    WideCharToMultiByte(CP_UTF8, 0, wstr, -1, str, len, NULL, NULL);
    if (wstr) delete[] wstr;
    return str;
}
//UTF-8到GB2312的转换
char* U2G(const char* utf8)
{
    int len = MultiByteToWideChar(CP_UTF8, 0, utf8, -1, NULL, 0);
    wchar_t* wstr = new wchar_t[len + 1];
    memset(wstr, 0, len + 1);
    MultiByteToWideChar(CP_UTF8, 0, utf8, -1, wstr, len);
    len = WideCharToMultiByte(CP_ACP, 0, wstr, -1, NULL, 0, NULL, NULL);
    char* str = new char[len + 1];
    memset(str, 0, len + 1);
    WideCharToMultiByte(CP_ACP, 0, wstr, -1, str, len, NULL, NULL);
    if (wstr) delete[] wstr;
    return str;
}

void getFiles(const std::string& path, std::vector<std::string>& files)
{
    //文件句柄  
    long long hFile = 0;
    //文件信息，_finddata_t需要io.h头文件  
    struct _finddata_t fileinfo;
    std::string p;
    int i = 0;
    if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1)
    {
        do
        {
            //如果是目录,迭代之  
            //如果不是,加入列表  
            if ((fileinfo.attrib & _A_SUBDIR))
            {
                if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
                    getFiles(p.assign(path).append("\\").append(fileinfo.name), files);
            }
            else
            {
                files.push_back(p.assign(path).append("\\").append(fileinfo.name));
            }
        } while (_findnext(hFile, &fileinfo) == 0);
        _findclose(hFile);
    }
}


int main()
{
    const char* const DICT_PATH = "dict/jieba.dict.utf8";
    const char* const HMM_PATH = "dict/hmm_model.utf8";
    const char* const USER_DICT_PATH = "dict/user.dict.utf8";
    const char* const IDF_PATH = "dict/idf.utf8";
    const char* const STOP_WORD_PATH = "dict/stop_words.utf8";

    cppjieba::Jieba jieba(DICT_PATH, HMM_PATH, USER_DICT_PATH, IDF_PATH, STOP_WORD_PATH);
   
    vector<cppjieba::Word> jiebawords;
    
    string s = "\\answer";
    
    getFiles(s, filePath);
    string str, temp;

    for (int i = 0; i <5; i++)
    {
        ifstream fin(filePath[i]);
        if (fin.good())
        {
            int count = 1;
            while (getline(fin, str))
            {
                if (str == " ")
                    continue;
                str = G2U(str.c_str());
                jieba.CutForSearch(str, words, true);
                for (int j = 0; j < words.size(); j++)
                {
                    temp = words[j];
                    temp = U2G(temp.c_str());
                    
                    AVL.insert(temp, i,count);
                   
                    cout << temp << " ";
                }
                count++;
            }
        }
        cout << endl;
        fin.close();
    }
   /* bool ii = false;
    ii = AVL.search("THERMAL", pos);*/

    string S;
    cin >> S;

    vector<string> query;
    S = G2U(S.c_str());
    jieba.CutForSearch(S, query, true);
    for (int i = 0; i < query.size(); i++)
    {
        temp = query[i];
        temp = U2G(temp.c_str());
        pos.clear();
        AVL.search(temp, pos);
        for (int j = 0; j < pos.size(); j++)
        {
            int k = 0;
            for (; k < W.size(); k++)
            {
                if (pos[j].data == W[k].file)
                {
                    W[k].wei += double(1) / double(pos.size());
                    break;
                }
            }
            if (k == W.size())
                W.push_back(weight(pos[j].data, double(1) / double(pos.size()),pos[j].line));
        }
    }
    sort(W.begin(), W.end());

    ifstream in(filePath[W[W.size()-1].file]);
    if (in.good())
    {
        int count1 = W[W.size() - 1].line;
        while (count1--)
        {
            getline(in, str);
        }
        cout << str;
    }


    return 0;
};

