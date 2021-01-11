#include "pch.h"
#include "Trie.h"

bool Trie::insert(const std::string& key, const std::string& M)
{
    if(key.empty()||M.empty())
        return false;

    TrieNode* ptr = root;

    int i = 0;
    int branch;
    for (i; i < key.length(); i++)
    {
        branch = key[i] - 'a';
        if (branch < 0 || branch>25)
            continue;
        if (ptr->Child[branch] == nullptr)
        {
            ptr->Child[branch] = new TrieNode;//如果当前为空，则一路创建节点，直到该插入时对节点赋值
            ptr->Child[branch]->Nchild = branch;
        }
        ptr = ptr->Child[branch];
    }
        ptr->meanning = M;
        ptr->words = key;
        ptr->isWordEnd = true;
        count++;
        return true;
}

bool Trie::remove(const std::string key, std::string& S)
{
    TrieNode* ptr = root;
    TrieNode* pre = ptr;
    
    if (key.empty())
        return false;
    int branch = -1;
    for (int i = 0; i < key.length(); i++)
    {
        branch = key[i] - 'a';
        if (!ptr->Child[branch])
        {
            return false;
        }
        pre = ptr;
        ptr = ptr->Child[branch];
    }
    S = ptr->meanning;
    pre->Child[ptr->Nchild] = nullptr;
    delete ptr;
    return true;
}

bool Trie::search(const std::string key, vector<words<string,string>>& S,int num,int& count)
{
    if(key.empty())
        return false;
    TrieNode* ptr = root;
    int branch = -1;
    for (int i = 0; i < key.length(); i++)
    {
        branch = key[i] - 'a';
        if (ptr->Child[branch] == nullptr)
            return false;
        ptr = ptr->Child[branch];
        count++;
    }
    if (ptr && ptr->isWordEnd)
    {
        TrieNode* temp;
        int i = 0;
        words<string,string> word;
        queue<TrieNode*> st;
        /*while ((ptr||!st.empty())&& num>0 )
        {
            while (ptr)
            {
                st.push(ptr);
                ptr = ptr->Child[0];
            }
            if (!st.empty())
            {
                temp = st.front();
                st.pop();
                if (temp->isWordEnd)
                {
                    word.meaning = temp->meanning;
                    word.word = temp->words;
                    S.push_back(word);
                    num--;
                }
                
                if (i < 26)
                    ptr = temp->Child[i++];
                else
                {
                    ptr = nullptr;
                    i = 0;
                }
            }
            
        }
        return true;*/

        st.push(ptr);
        while (!st.empty())
        {
            i = st.size();
            //for (int j = 0; j < i; j++)
            //{
                temp = st.front();
                st.pop();
                if (temp->isWordEnd)
                {
                    word.meaning = temp->meanning;
                    word.word = temp->words;
                    S.push_back(word);
                    num--;
                }
                if (num == 0)
                    return true;
                for (int k = 0; k < 26; k++)
                    if (temp->Child[k])
                        st.push(temp->Child[k]);
            //}
        }
    }
    else
    {
        return false;
    }
}

void Trie::TrieFile(std::istream in)
{

}

bool Trie::clear(TrieNode* node)
{
    if (node == nullptr)
        return false;
    clear(node->Child[0]);
    clear(node->Child[1]);
    clear(node->Child[2]);
    clear(node->Child[3]);
    clear(node->Child[4]);
    clear(node->Child[5]);
    clear(node->Child[6]);
    clear(node->Child[7]);
    clear(node->Child[8]);
    clear(node->Child[9]);
    clear(node->Child[10]);
    clear(node->Child[11]);
    clear(node->Child[12]);
    clear(node->Child[13]);
    clear(node->Child[14]);
    clear(node->Child[15]);
    clear(node->Child[16]);
    clear(node->Child[17]);
    clear(node->Child[18]);
    clear(node->Child[19]);

}
