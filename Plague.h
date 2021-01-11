#pragma once
#include<iostream>
#include<queue>
#include<cstdio>
#include<cstring>
#include<algorithm>
using std::sort;

//LCA 
long long f[51000][18];                                             //�����ľ���  f[i][j]��ʾ �� ����i ������ j�� �����ľ��� 
int fa[51000][18];                                                  //������λ��   fa[i][j] ��ʾ�� ����i ������2^j��������� ����

int head[51000], ecnt = -1;                                          //head[i]���ڴ洢��i���ڵ�������ĳ���(�൱�������ʾ����ÿһ����������һ��)   ecnt��ʾ����


//��ʽǰ����
struct edge                                                          //edge���ڱ������еı�
{
    int to, weight, next;                                               //edge[i].to ��ʾ��i���ߵ��յ㣬 next��ʾ���i�������ڵ���һ����
    edge(int to, int next, int w)
    {
        this->to = to;
        this->next = next;
        this->weight = w;
    }
    edge() 
    { 
        next = -1; 
    }

}e[101000];

void add(int from, int to, int v)
{
    e[++ecnt] = edge(to, head[from], v);                                //˫��ߣ�ÿ���ߴ�������    
    head[from] = ecnt;                                                  //����head ,ʹ��ָ�������ӵı�  ����head����ָ����������ڽӱ�
    e[++ecnt] = edge(from, head[to], v);                                //�����ߵ�next��ָ����һ���ڽӱߣ���˴洢˳��������෴
    head[to] = ecnt;
}

void dfs(int x)                                    
{
    for (int i = head[x]; i!=-1; i = e[i].next)
        if (!fa[e[i].to][0])
        {
            fa[e[i].to][0] = x;                                             //��¼���ڵ�ĸ��ڵ�λ��
            f[e[i].to][0] = e[i].weight;                                    //��¼�����ڵ��һ����Ȩ��
            dfs(e[i].to);
        }
}

//void bfs()
//{
//    //memset(deepth, 0, sizeof(deepth));                                 1�����о�������ڵ��ƶ�  ����¼��󵽴��λ�ú������ѵ�ʱ�� ��·�����ȼ�Ϊʱ�䣩
//    queue<int> Q;                                                             *����ߵ����ӽڵ�
//    Q.push(1);                                                                *ͳ�ơ��ߵ����ӽڵ�ľ��ӡ�����¼���ǡ�ʣ���ʱ�䡿
//    deepth[1] = 1;                                                            *���ڡ�û���ߵ������ӽڵ�ľ��ӣ����������ͣ����λ�ñ��Ϊ ���ѿ��ơ������ǾͲ����� ��
//    while (Q.size())                                                     2��������������ͳ�ơ���Ҫ���ӿ��Ƶĳ��С���������Žڵ���ӽڵ���ȱ������ߵ�Ҷ�ڵ㣬˵��û�б����ƣ�
//    {                                                                    3�����������ӽڵ�ľ��ӡ��͡���Ҫ���ӵĳ��С��ֱ��ա�ʣ��ʱ�䡿�͡���Ԯ���ۡ� ��С��������
//        int temp = Q.front();                                               ����Ԯ���ۡ���Ϊ�þ��ӵ����ڵ�ľ���
//        Q.pop();                                                         4�������о��ӡ��������ӽڵ��һ���ʣ��ʱ��ľ��ӣ���ʼ�� ����Ҫ���ӵĳ��С����о�Ԯ
//        for (int i = head[temp]; i != -1; i = e[i].next)                      
//        {
//            int y = e[i].to;
//            if (deepth[y])
//                continue;
//            deepth[y] = deepth[temp] + 1;
//            f[y][0] = e[i].weight;
//            fa[y][0] = temp;
//
//            for (int j = 0; j < 16; j++)
//            {
//                fa[y][j] = fa[fa[y][j - 1]][j - 1];
//                f[y][j] = f[y][j - 1] + f[fa[y][j - 1]][j - 1];
//            }
//            Q.push(y);
//        }
//    }
//
//}



void LCA(int n)                                                              //��¼��ÿ���ڵ������ߣ����2^16����������Ķ���;���
{
   
    for (int i = 1; i <= 16; i++)                                            //���� �� 1��2��4��8.......2^j ��
        for (int j = 1; j <= n; j++)                                         //fa[i][j] Ϊ�� ����i �� 2^j  �� �����Ķ��㡣 
        {                                                                    //��Ϊ�Ӷ���i �� 2^(j-1)�������� ����temp�����ٴ� ����temp  �� 2^(j-1)����
              fa[j][i] = fa[fa[j][i - 1]][i - 1];                            //����������
              f[j][j] = f[j][i - 1] + f[fa[j][i - 1]][i - 1];                //��¼ÿһ�α��������ľ���
        }
}

struct troop
{
    int pos;                                                                 //���ӵ�ǰ����λ��
    long long dis;                                                           //ʣ��ʱ�� �����
    troop(int n, long long dis)
    {
        this->pos = n;
        this->dis = dis;
    }
    troop() {}
    friend bool operator <(troop a, troop b)
    {
        return a.dis < b.dis;
    }
}troops[51000];                                                             //���õľ���



troop need[51000];                                                          //��Ҫ�����Ķ��ӵ�
long long rh[51000];                                                        //��i������ԭʼפ���ĳ���
long long h[51000], up[51000];                                              // ��i����������������    �Ѿ��������˶��پ��루���˶���ʱ�䣩


int prot[51000];                                                            // is controlled


bool Dfs(int x)
{
    if (prot[x])                                                            //�������ˣ���ô�Ͳ���������
        return true;                      
    bool isLeaf = true;

    for (int i = head[x]; ~i; i = e[i].next)
    {
        if (e[i].to != fa[x][0])                                            //�ж��Ƿ�Ϊ���ڵ㣬���򸸽ڵ���             
        {
            isLeaf = false;                                                 //�����ӽڵ㣬һ������Ҷ��
            if (!Dfs(e[i].to))                                              //����鿴�ӽڵ���û�б�����
                return false;
        }
    }
    if (isLeaf)
        return false;                                                       //�ߵ���Ҷ�ӽڵ㣬˵��һ·��û�о��ӣ�û�б�����
    else
        return true;
}


int to[51000];                                                                //��i�ų���פ���ľ���ȥ�����ﱣ��
int needisprocted[51000];                                                     //���Ϊi�ĳ����Ƿ��ѱ�����


bool check(long long x,int m)
{
    for (int i = 1; i <= m; i++)
        h[i] = rh[i];

    //memset(buffer,value,size)
    memset(needisprocted, 0, sizeof(needisprocted));
    memset(to, 0, sizeof(to));
    memset(prot, 0, sizeof(prot));
    memset(up, 0, sizeof(up));

    int cnt = 0, cnt1 = 0;                                                  //�ж��ٸ����ӣ��ж�����Ҫ�����Ľڵ�
    for (int j = 1; j <= m; j++)
    {
        for (int i=0;i<16;i++)
        {
            if (fa[h[j]][i] != 1 && f[h[j]][i] + up[j] <= x)                  //���о��� ����ڵ���ȣ��������� ������ߵ����ӽڵ�
            {
                up[j] += f[h[j]][i];                                           //up ��¼ÿ�������ڸ���ʱ�����߹��ľ���
                h[j] = fa[h[j]][i];                                           //��������
            }
        }
        if (fa[h[j]][0] == 1 && up[j] + f[h[j]][0] <= x)                      //����Щ �����������ӽڵ���   d���ʱ�仹��ʣ�ࣨ�����ߣ�
        {
            troops[++cnt] = troop(h[j], x - up[j] - f[h[j]][0]);              //��¼ʣ��ʱ��(�����߶�Զ)
        }
        else
        {
            prot[h[j]] = 1;                                                   //����û���ߵ����ӽڵ�ľ���  �ߵ������ͣ��������������ڽڵ���Ϊ�ѿ���
        }
    }


    for (int i = head[1]; ~i; i = e[i].next)                                   //����������������Щ�ڵ���Ҫ����
    {
        if (!Dfs(e[i].to))
        {
            need[++cnt1] = troop(e[i].to, f[e[i].to][0]);                      //��Ҫ�����Ľڵ�
        }
    }

    if (cnt1 > cnt)                                                                 //���Ӳ���
        return false;

    std::sort(troops + 1, troops + 1 + cnt);                                     //�����Ӱ�ʣ��ʱ������ ��С����

    std::sort(need + 1, need + 1 + cnt1);                                        //���豣���ڵ㰴�����ڵ�ľ������� ��С����
    int tt = 1;                                                                  //��Ҫ�����б������˵�                     


    for (int i = 1; i <= cnt; i++)                                               //�����п��еľ���
    {
        if (tt > cnt1)                                                           //�Ѿ���������
            return true;
        while (needisprocted[need[tt].pos])                                      //�����ͨ��ĳ��;���������ͼ���
            tt++;
        if (troops[i].dis >= need[tt].dis)                                       //����þ��ӻ����ƶ��ľ��������Ҫ�����Ľڵ㵽���ڵ�ľ���
        {
            to[i] = need[tt].pos;                                                 //�Ǿ�ȥ����
            needisprocted[need[tt].pos] = 1;                                      //�ýڵ����о��Ӱ���
            tt++;                                                                 //ת����һ����Ҫ�����Ľڵ�  
        }
        else
        {
            if (to[need[tt].pos])                                                  //���Ϊneed[tt].pos�ĳ��еľ�������  ����������Ҫ���� 
            {                                                                      //��ô���õ�ǰ����ȥ������   ԭ�Ⱦ������ߵľ���һ����С�����ھ��ӵģ������ˣ�
                needisprocted[need[tt].pos] = 1;
                tt++;
            }
            else
                needisprocted[troops[i].pos] = 1;                                   //���Ӳ����ߵ������κ���Ҫ�����ڵ��ˣ���ֻ�����Լ����ڵ�
        }
    }
    while (needisprocted[need[tt].pos])                                             //���ܻ��к��漸��ȫ����ǰ��ı���
        tt++;
    return tt > cnt1;
}


void binaryDetect(long long T,int m)
{
    long long l=0, r=T+1;
    while (l < r)
    {
        long long mid = (l + r) / 2;
        if (check(mid,m))
        {
            r=mid;
        }
        else
            l=mid+1;
    }
    cout << l;
}
