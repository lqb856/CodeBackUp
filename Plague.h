#pragma once
#include<iostream>
#include<queue>
#include<cstdio>
#include<cstring>
#include<algorithm>
using std::sort;

//LCA 
long long f[51000][18];                                             //倍增的距离  f[i][j]表示 从 顶点i 向上走 j步 经过的距离 
int fa[51000][18];                                                  //倍增的位置   fa[i][j] 表示从 顶点i 向上走2^j步所到达的 顶点

int head[51000], ecnt = -1;                                          //head[i]用于存储第i个节点最后加入的出边(相当于链表表示法的每一行链表的最后一个)   ecnt表示边数


//链式前向星
struct edge                                                          //edge用于保存所有的边
{
    int to, weight, next;                                               //edge[i].to 表示第i条边的终点， next表示与第i条边相邻的下一条边
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
    e[++ecnt] = edge(to, head[from], v);                                //双向边，每条边存了两次    
    head[from] = ecnt;                                                  //更新head ,使其指向最近添加的边  由于head总是指向最后加入的邻接边
    e[++ecnt] = edge(from, head[to], v);                                //而各边的next又指向上一个邻接边，因此存储顺序和输入相反
    head[to] = ecnt;
}

void dfs(int x)                                    
{
    for (int i = head[x]; i!=-1; i = e[i].next)
        if (!fa[e[i].to][0])
        {
            fa[e[i].to][0] = x;                                             //记录各节点的父节点位置
            f[e[i].to][0] = e[i].weight;                                    //记录到父节点第一条的权重
            dfs(e[i].to);
        }
}

//void bfs()
//{
//    //memset(deepth, 0, sizeof(deepth));                                 1、所有军队向根节点移动  （记录最后到达的位置和所花费的时间 ，路径长度即为时间）
//    queue<int> Q;                                                             *最多走到根子节点
//    Q.push(1);                                                                *统计【走到根子节点的军队】，记录他们【剩余的时间】
//    deepth[1] = 1;                                                            *对于【没有走到】根子节点的军队，将他们最后停留的位置标记为 【已控制】（他们就不动了 ）
//    while (Q.size())                                                     2、遍历整棵树，统计【需要军队控制的城市】（如果沿着节点的子节点深度遍历能走到叶节点，说明没有被控制）
//    {                                                                    3、将【到根子节点的军队】和【需要军队的城市】分别按照【剩余时间】和【救援代价】 从小到大排列
//        int temp = Q.front();                                               【救援代价】即为该军队到根节点的距离
//        Q.pop();                                                         4、【空闲军队】（到根子节点且还有剩余时间的军队）开始对 【需要军队的城市】进行救援
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



void LCA(int n)                                                              //记录从每个节点向上走（最多2^16步）所到达的顶点和距离
{
   
    for (int i = 1; i <= 16; i++)                                            //倍增 跳 1、2、4、8.......2^j 步
        for (int j = 1; j <= n; j++)                                         //fa[i][j] 为从 顶点i 跳 2^j  步 所到的顶点。 
        {                                                                    //即为从顶点i 跳 2^(j-1)步（到达 顶点temp），再从 顶点temp  跳 2^(j-1)步。
              fa[j][i] = fa[fa[j][i - 1]][i - 1];                            //倍增向上跳
              f[j][j] = f[j][i - 1] + f[fa[j][i - 1]][i - 1];                //记录每一次倍增上跳的距离
        }
}

struct troop
{
    int pos;                                                                 //军队当前所在位置
    long long dis;                                                           //剩余时间 或距离
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
}troops[51000];                                                             //可用的军队



troop need[51000];                                                          //需要保护的儿子点
long long rh[51000];                                                        //第i个军队原始驻扎的城市
long long h[51000], up[51000];                                              // 第i个军队跳到了哪里    已经向上走了多少距离（花了多少时间）


int prot[51000];                                                            // is controlled


bool Dfs(int x)
{
    if (prot[x])                                                            //被保护了，那么就不用深入了
        return true;                      
    bool isLeaf = true;

    for (int i = head[x]; ~i; i = e[i].next)
    {
        if (e[i].to != fa[x][0])                                            //判断是否为父节点，不向父节点走             
        {
            isLeaf = false;                                                 //存在子节点，一定不是叶子
            if (!Dfs(e[i].to))                                              //深入查看子节点有没有被保护
                return false;
        }
    }
    if (isLeaf)
        return false;                                                       //走到了叶子节点，说明一路上没有军队，没有被保护
    else
        return true;
}


int to[51000];                                                                //在i号城市驻扎的军队去了哪里保护
int needisprocted[51000];                                                     //编号为i的城市是否已被保护


bool check(long long x,int m)
{
    for (int i = 1; i <= m; i++)
        h[i] = rh[i];

    //memset(buffer,value,size)
    memset(needisprocted, 0, sizeof(needisprocted));
    memset(to, 0, sizeof(to));
    memset(prot, 0, sizeof(prot));
    memset(up, 0, sizeof(up));

    int cnt = 0, cnt1 = 0;                                                  //有多少个军队，有多少需要保护的节点
    for (int j = 1; j <= m; j++)
    {
        for (int i=0;i<16;i++)
        {
            if (fa[h[j]][i] != 1 && f[h[j]][i] + up[j] <= x)                  //所有军队 向根节点调度，倍增地走 ，最多走到根子节点
            {
                up[j] += f[h[j]][i];                                           //up 记录每个军队在给定时间内走过的距离
                h[j] = fa[h[j]][i];                                           //倍增地跳
            }
        }
        if (fa[h[j]][0] == 1 && up[j] + f[h[j]][0] <= x)                      //看哪些 军队跳到根子节点了   d如果时间还有剩余（还能走）
        {
            troops[++cnt] = troop(h[j], x - up[j] - f[h[j]][0]);              //记录剩余时间(还能走多远)
        }
        else
        {
            prot[h[j]] = 1;                                                   //对于没有走到根子节点的军队  走到哪里就停在那里，并将其所在节点置为已控制
        }
    }


    for (int i = head[1]; ~i; i = e[i].next)                                   //遍历整棵树，看哪些节点需要保护
    {
        if (!Dfs(e[i].to))
        {
            need[++cnt1] = troop(e[i].to, f[e[i].to][0]);                      //需要保护的节点
        }
    }

    if (cnt1 > cnt)                                                                 //军队不够
        return false;

    std::sort(troops + 1, troops + 1 + cnt);                                     //将军队按剩余时间排序 从小到大

    std::sort(need + 1, need + 1 + cnt1);                                        //将需保护节点按到父节点的距离排序 从小到大
    int tt = 1;                                                                  //需要保护中被保护了的                     


    for (int i = 1; i <= cnt; i++)                                               //对所有空闲的军队
    {
        if (tt > cnt1)                                                           //已经保护完了
            return true;
        while (needisprocted[need[tt].pos])                                      //如果被通过某种途径保护，就继续
            tt++;
        if (troops[i].dis >= need[tt].dis)                                       //如果该军队还能移动的距离大于需要帮助的节点到根节点的距离
        {
            to[i] = need[tt].pos;                                                 //那就去帮助
            needisprocted[need[tt].pos] = 1;                                      //该节点已有军队帮助
            tt++;                                                                 //转到下一个需要帮助的节点  
        }
        else
        {
            if (to[need[tt].pos])                                                  //编号为need[tt].pos的城市的军队走了  而它现在需要保护 
            {                                                                      //那么就让当前军队去保护它   原先军队能走的距离一定是小于现在军队的（排序了）
                needisprocted[need[tt].pos] = 1;
                tt++;
            }
            else
                needisprocted[troops[i].pos] = 1;                                   //军队不能走到其他任何需要帮助节点了，就只保护自己所在的
        }
    }
    while (needisprocted[need[tt].pos])                                             //可能会有后面几个全部被前面的保护
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
