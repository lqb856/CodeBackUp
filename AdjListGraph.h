#pragma once
#include"Graph.h"
#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<assert.h>

#include "Heap.h"
#include<fstream>
#include<sstream>
#include<string>
#include"AVLTree.h"

using namespace std;

const int maxWeight = 100000;

bool contain(int K,int Kp[][34], int p[34])
{
	int i = p[0];
	bool S = true;
	for (int j = 0; j < K; j++)
	{
		S = true;
		for (int k = 0; k <= i; k++)
		{
			if (Kp[j][k] != p[k])
				S=false;

		}
		if (S == true)
			return true;
	}
	return false;
}

template<class T, class K>
class Element
{
public:
	T data;
	K key;

	
	bool operator==(Element<T, K>& x)
	{
		return key == x.key;
	}
	Element<T,K> operator =(Element<T, K>& x)
	{
		key = x.key;
		data = x.data;
		return *this;
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

struct node
{
	string s;
	int x; int y;
	node() :x(0), y(0) {}
	node(int X, int Y) { x = X; y = Y; }
};

template<class T,class K>
struct Edge
{
	int dest;
	K weight;
	Edge<T, K>* link;
	Edge() { link = nullptr; }
	Edge(int des, K wei) :dest(des), weight(wei) ,link(nullptr){}
	bool operator!=(Edge<T, K>& E)
	{
		return !(this->dest == E.dest);
	}
};

template<class T,class K>
struct Vertex
{
	T data;
	bool escape;
	int x, y;
	Edge<T, K>* adj;
};

template<class T,class K>
class AdjListGraph :public Graph<T, K>
{
public:
	
	AdjListGraph(int sz = defaultSize);
	~AdjListGraph();
	void buildGraph();

	int numOfVertices() { return numVertices; }
	int numOfEdges() { return numEdges; }

	T getValue(int i)
	{
		if (i >= 0 && i < numVertices)
			return nodeTable[i].data;
		else return "";
	}
	K getWeight(int v1, int v2);
	int getPos(const T ch);
	int getFirstNeighbour(int v) ;
	int getNextNeighbour(int v, int w) ;

	void escape(const T node);
	void donotEscape(const T node);

	bool insertVertex(const T& vertex) ;
	bool insertEdge(int v1, int v2, const K& weight) ;
	
	void Dijkstra(Graph<T,K>&G,T str,int mode);
	void Dijkstra(T str);
	void GetKthPath_YEN(Graph<T, K>& G, T str,T dist, int k);
	void Set_Edge(int path[], int endnode);
	void Recover_Edge(int endnode);


	void GetAllPath(T start, T end ,int k);
	void allPath(int k);
	void GetAllpathNon(T start, T end, int resultpath[][10]);
	
	void route(int C,T str="0");
	void froute(T str,T str1);
	void clearRoute()
	{
		for (int i = 0; i < 34; i++)
		{
			DjDist[i] = -1;
			path[i] = -1;
			dest[i] = maxWeight;
			for (int j = 0; j < 34; j++)
			{
				DjPtah[i][j] = 0;
			}
		}

	}

	void Floyd(Graph<T, K>& G,T str,T str1);

	int partitionWithMedian3(const int left, const int right);
	Element<int, int>& median3(const int left, const int right);
	void quickNonRecursion(int left, int right);
	void swap1(Element<int, int>& x1, Element<int, int>& x2)
	{
		Element<int, int> temp = x1;
		x1 = x2;
		x2 = temp;
	}

	void sortFile();

private:
	int maxVertices;
	int numEdges;
	int numVertices;
	Vertex<T, K>* nodeTable;
	
	string cities[34];
	int adj[34][34];

	int column[34];						//递归入口
	int distance[34][34];
	bool visited[34];

	int resultpath[1000][11];			//所有可能路径
	int result[34];						//每次计算出的路径
	int npos, pathnum;					//当前路径节点    已算出的路径条数

	int adj_temp[34][34];
	int Kpathsize;
	int DjPtah[34][34];   //存放Dijkstra 计算出的路径。
	int DjDist[34];		//存放各路径长
	int Kpath[34][34];	//存放K个最短路径

	int dest[34];			//Dijkstra原始路径
	int path[34];

	int fdist[34][34];
	int fpath[34][34];

	int Devsize;
	int Dev_path[100][34];

	vector<Element<int, int>> L;
	int getVertexPos(T vertex)
	{
		for (int i = 0; i < numVertices; i++)
			if (vertex == nodeTable[i].data)
				return i;
		return -1;
	}
	
};

template<class T, class K>
inline AdjListGraph<T, K>::AdjListGraph(int sz)
{
	maxVertices = sz;
	numEdges = 0;
	numVertices = 0;
	nodeTable = new Vertex<T, K>[maxVertices];

	npos = 0;
	pathnum = 0;

	Devsize = 0;
	Kpathsize = 0;
	assert(nodeTable != nullptr);
	for (int i = 0; i < maxVertices; i++)
	{
		nodeTable[i].adj = nullptr;
		nodeTable[i].escape = false;
		column[i] = 0;
		visited[i] = false;
	}

	/*for (int i = 0; i < 34; i++)
		for (int j = 0; j < 34; j++)
			Kpath[i][j] = -1;
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 34; j++)
			Dev_path[i][j] = -1;*/
	
}

template<class T, class K>
inline AdjListGraph<T, K>::~AdjListGraph()
{
	for (int i = 0; i < numVertices; i++)
	{
		Edge<T, K>* temp = nodeTable[i].adj;
		while (temp!=nullptr)
		{
			nodeTable[i].adj = temp->link;
			delete temp;
			temp = nodeTable[i].adj;
		}

	}
	delete[] nodeTable;
}

template<class T, class K>
inline void AdjListGraph<T, K>::buildGraph()
{
	int j = 0, i = 0, k = 0;
	string str;
	string temp;
	

	ifstream fin("Adj.txt");
	if (fin.good())
	{

		getline(fin, str);
		stringstream ss(str);
		while (getline(ss, temp, ','))
		{
			if (temp != "")
			{
				cities[i] = temp;
				i++;
			}
		}
		while (getline(fin, str))
		{
			stringstream ss1(str);
			getline(ss1, temp, ',');
			for (k = 0; k < 34; k++)
			{
				getline(ss1, temp, ',');
				adj[j][k] = std::stoi(temp);
			}
			j++;
		}
	}
	fin.close();

	j = k = 0;
	fin.open("Distance.txt");
	if (fin.good())
	{
		getline(fin, str);
		while (getline(fin, str))
		{
			stringstream ss2(str);
			getline(ss2, temp, ',');
			for (k = 0; k < 34; k++)
			{
				getline(ss2, temp, ',');
				if (temp != "")
					distance[j][k] =std::stoi(temp);
				else
					distance[j][k] = 0;
			}
			j++;
		}
	}
	fin.close();

	for (i = 0; i < 34; i++)
		insertVertex(cities[i]);

	for (k = 0; k < 34; k++)
		for (j = 0; j < 34; j++)
		{
			if (adj[k][j] != 0 && k != j)
				insertEdge(k, j, distance[j][k]);
		}
}

template<class T, class K>
inline K AdjListGraph<T, K>::getWeight(int v1, int v2)//从v1到v2边的权值
{
	if (v1 >= 0 && v2 >= 0 && v1 < numVertices && v2 < numVertices && v1 != v2)
	{
		Edge<T, K>* temp = nodeTable[v1].adj;
		while (temp != nullptr && temp->dest != v2)
			temp = temp->link;
		if (temp != nullptr)
			return temp->weight;
	}
	return maxWeight;
}

template<class T, class K>
inline int AdjListGraph<T, K>::getPos(const T ch)
{
	for (int i = 0; i < numVertices; i++)
	{
		if (ch ==nodeTable[i].data)
			return i;
	}
	return -1;
}

template<class T, class K>
inline int AdjListGraph<T, K>::getFirstNeighbour(int v)
{
	if (v >= 0 && v < numVertices)
	{
		if(nodeTable[v].adj)
		return nodeTable[v].adj->dest;
	}
	return -1;
}

template<class T, class K>
inline int AdjListGraph<T, K>::getNextNeighbour(int v, int w)
{
	if (v >= 0 && v < numVertices)
	{
		Edge<T, K>* temp = nodeTable[v].adj;
		while (temp && temp->dest != w)
			temp = temp->link;
		if (temp != nullptr && temp->link != nullptr && temp->weight != maxWeight)
		{
			
			return temp->link->dest;
		}
	}
	return -1;
}

template<class T, class K>
inline void AdjListGraph<T, K>::escape(const T node)
{
	int p=getPos(node);
	nodeTable[p].escape = true;
}

template<class T, class K>
inline void AdjListGraph<T, K>::donotEscape(const T node)
{
	int p = getPos(node);
	nodeTable[p].escape = false;
}

template<class T, class K>
inline bool AdjListGraph<T, K>::insertVertex(const T& vertex)
{
	if(numVertices==maxVertices)
		return false;
	nodeTable[numVertices].data = vertex;
	numVertices++;
	return true;

}

template<class T, class K>
inline bool AdjListGraph<T, K>::insertEdge(int v1, int v2, const K& weight)
{
	if (v1 >= 0 && v2 >= 0 && v1 < numVertices && v2 < numVertices && v1 != v2)
	{
		Edge<T, K>* e1 = nodeTable[v1].adj, * e2 = nodeTable[v2].adj;
		while (e1 && e1->dest != v2)
			e1 = e1->link;
		if (e1!=nullptr)
			return false;

		if (weight < maxWeight)
		{
			e1 = new Edge<T, K>(v2, weight);
			e1->link = nodeTable[v1].adj;
			nodeTable[v1].adj = e1;

			e2 = new Edge<T, K>(v1, weight);
			e2->link = nodeTable[v2].adj;
			nodeTable[v2].adj = e2;
			numEdges++;
		}
		return true;
	}
	return false;
}


template<class T, class K>
inline void AdjListGraph<T, K>::Dijkstra(Graph<T,K>&G,T str,int mode)
{
	int v = getPos(str);
	if (nodeTable[v].escape != true)
	{
		int nv = G.numOfVertices();
		bool* s = new bool[nv];
		int i, j, k;
		K w, min;
		for (i = 0; i < nv; i++)
		{
			dest[i] = getWeight(v, i);
			s[i] = false;
			if (i != v && dest[i] < maxWeight)
			{
				path[i] = v;

				if (mode == 0)   //跳数还是距离
					dest[i] = 1;
			}
			else
				path[i] = -1;
		}
		s[v] = true;
		dest[v] = 0;
		for (int i = 0; i < nv - 1; i++)
		{
			min = maxWeight;
			int u = v;
			for (j = 0; j < nv; j++)
				if (s[j] == false && dest[j] < min)		// find the minimum,add to already routed list
				{
					u = j;
					min = dest[j];
				}
			s[u] = true;

			for (k = 0; k < nv; k++)
			{
				w = G.getWeight(u, k);
				if (s[k] == false && w < maxWeight && dest[u] + w < dest[k]&&nodeTable[u].escape!=true)
				{
					if (mode == 0)
						w = 1;

					dest[k] = dest[u] + w;
					path[k] = u;
				}
			}
		}
	}
}

template<class T, class K>
inline void AdjListGraph<T, K>::Dijkstra(T str)
{
		int v = getPos(str);
	
		bool* s = new bool[34];
		int i, j, k;
		K w, min;
		for (i = 0; i < 34; i++)
		{
			
			s[i] = false;
			if (i != v && adj_temp[i][v]!=0 )
			{
				path[i] = v;
				dest[i] = (distance[v][i] > distance[i][v]) ? distance[v][i] : distance[i][v];
			}
			else
			{
				path[i] = -1;
				dest[i] = maxWeight;
			}
		}
		s[v] = true;
		dest[v] = 0;
		for (int i = 0; i <33 ; i++)
		{
			min = maxWeight;
			int u = v;
			for (j = 0; j < 34; j++)
				if (s[j] == false && dest[j] < min)		// find the minimum,add to already routed list
				{
					u = j;
					min = dest[j];
				}
			s[u] = true;

			for (k = 0; k < 34; k++)
			{
				
				if (adj_temp[u][k] != 0)
					w = (distance[u][k] > distance[k][u]) ? distance[u][k] : distance[k][u];
				else
					w = maxWeight;
				if (s[k] == false && w < maxWeight && dest[u] + w < dest[k])
				{
					dest[k] = dest[u] + w;
					path[k] = u;
				}
			}
		}
	
}

template<class T, class K>
inline void AdjListGraph<T, K>::GetKthPath_YEN(Graph<T, K>& G, T str,T dist,int k)
{
	int s = getPos(str);
	int d = getPos(dist);


	for (int i = 0; i < 34; i++)
		for (int j = 0; j < 34; j++)
			adj_temp[i][j] = adj[i][j];
	clearRoute();
	Dijkstra(str);
	route(1,"0");
	int i = DjPtah[d][0];				//最短路,即迭代路径
	int Path[34];
	Path[0] = i;
	for (int j = 1; j <= i; j++)
		Path[j] = DjPtah[d][j];
	
	Kpathsize = 0;
	while (k-->=0)
	{
		if (!contain(Kpathsize, Kpath, Path))
		{
			int i = Path[0];
			for (int j=0; j <= i; j++)
			{
					Kpath[Kpathsize][j] = Path[j];
					if(j!=0)
					cout << cities[Path[j]] << " ";
			}
			cout << endl;
			Kpathsize++;
		}
		

		int len = Path[0];
		int Path_temp[34];

		Path_temp[0] = 0;
		Devsize = 0;
		for (int i = 1; i+1 < len; i++)
		{
			Path_temp[i] = Path[i];
			Path_temp[0] += 1;
			adj_temp[Path[i]][Path[i+1]]=adj_temp[Path[i + 1]][Path[i]] = 0;
			Set_Edge(Path_temp, Path[i]);

			clearRoute();
			Dijkstra(cities[Path[i]]);
			route(1,"0");

			adj_temp[Path[i]][Path[i + 1]]= adj_temp[Path[i + 1]][Path[i]] = adj[Path[i]][Path[i + 1]];
			Recover_Edge(Path[i]);
		

			if (dest[d] >= maxWeight)
				continue;

			int PPath[34];

			int num = 1;
			for (int n = 1; n < i; n++)
			{
				PPath[num] = Path[n];
				num++;
			}

			int j = DjPtah[d][0];
			for (int n = 1; n <= j; n++)
			{
				PPath[num] = DjPtah[d][n];
				num++;
			}
			PPath[0] = Path_temp[0] + DjPtah[d][0] - 1;

			if (!contain(Devsize, Dev_path, PPath))
			{
				j = DjPtah[d][0];
				for (int n = 0; n <= j; n++)
					Dev_path[Devsize][n] = PPath[n];
				Devsize++;
			}
		}

		Element<int, int>E;
		L.clear();
		for (int i = 0; i < Devsize; i++)
		{
			int j = Dev_path[i][0];
			int m = 0;
			int t = 0;
			for (int k1 = 1; k1 + 1 <= j; k1++)
			{
				int m = distance[Dev_path[i][k1]][Dev_path[i][k1 + 1]];
				if (m != 0)
					t += m;
				else
					t += distance[Dev_path[i][k1 + 1]][Dev_path[i][k1]];
			}
			E.data = i;
			E.key = t;
			L.push_back(E);
		}
		if (!L.size())
		{
			break;
		}
		quickNonRecursion(0, Devsize- 1);

		int m = Dev_path[L[0].data][0];
		for (int i = 0; i <= m; i++)
			Path[i]=Dev_path[L[0].data][i];
	}

}

template<class T, class K>
inline void AdjListGraph<T, K>::Set_Edge(int path[], int endnode)
{
	int i = 0, j = 0, k = 0;
	bool flag = true;
	int len = Kpathsize;
	int len_p = path[0];
	for ( i = 0; i < len; i++) 
	{
		
		int path2[34];
		j = Kpath[i][0];
		
		for (k = 0; k <= j; k++)
		{
			path2[k] = Kpath[i][k];
		}
		if (len_p >=j) 
			continue;
		flag = true;
		for (int j = 1; j <= len_p; ++j) 
		{
			if (path[j]!= path2[j]) 
				flag = false;
		}
		if (flag == false)			//前面的path一样,然后就看扩展结点的了
			continue;		
		
		for (int k = 0; k < 34; k++) 
		{
			if (k != endnode && adj_temp[endnode][k] != 0)	//从s_node扩展结点k
			{
				if (k == path2[len_p+1])					//匹配成功，需将s_node->k 设置为INF
				{
					adj_temp[endnode][k]= adj_temp[k][endnode] = 0;
				}
			}
		}
	}


}

template<class T, class K>
inline void AdjListGraph<T, K>::Recover_Edge(int endnode)
{
		for (int j = 0; j < 34; j++)
			adj_temp[endnode][j]=adj_temp[j][endnode] = adj[endnode][j];
}

template<class T, class K>
inline void AdjListGraph<T, K>::GetAllPath(T start, T end ,int k)
{

	result[npos] = getPos(start);
	visited[getPos(start)] = 1;
	npos++;
	
	while (npos>=0)			//回退到开始节点
	{
		int tempPos = result[npos-1];
		if (tempPos == getPos(end))
		{
			if (npos<k)
			{
				resultpath[pathnum][0] = npos;
				for (int i = 1; i < npos+1; i++)
				{
					resultpath[pathnum][i] = result[i-1];
				}
				pathnum++;
			}

			npos--;
			result[npos] = -1;
			visited[getPos(end)] = false;
			break;
		}
		while (column[getPos(start)] != 34)
		{
			if (adj[tempPos][column[getPos(start)]] == 1 && visited[column[getPos(start)]] == false&&tempPos!=column[getPos(start)])
			{
				string temp = cities[column[getPos(start)]];
				GetAllPath(temp, end ,k);
			}
			column[getPos(start)]++;
			if (npos > k)
			{
				column[getPos(start)] = 34;
			}
		}
		
		if (column[getPos(start)] == 34)
		{
			npos--;
			result[npos] = -1;
			visited[getPos(start)] = false;
			column[getPos(start)] = 0;
			break;
		}

	}

}

template<class T, class K>
inline void AdjListGraph<T, K>::allPath( int k)
{
	cout << "小于"<<k<<"个城市的总路径：" << pathnum << endl;
	for (int i = 0; i < pathnum; i++)
	{
		int j = resultpath[i][0];
		for (int k = 1; k <= j; k++)
			cout << cities[resultpath[i][k]] << " ";
		cout << endl;
	}
}

template<class T, class K>
inline void AdjListGraph<T, K>::GetAllpathNon(T start, T end, int resultpath[][10])
{
	stack<int> path;
	stack<int> route;
	stack<int> temp;
	
	bool contain=false;
	int container[10];
	int i = 0, j = 0, k = 0,n=0, pathnum = 0, num = 0;

	path.push(getPos(start));
	

	while (!path.empty())
	{
		int tempPo1 = path.top();
		if (path.size() < 5)			//辅栈中加入邻接点，如果路径长度已经大于10就不用深入了
		{
			k = 0;

			n = 0;
			while (!path.empty())
			{
				temp.push(path.top());
				path.pop();
			}
			while (!temp.empty())
			{
				path.push(temp.top());
				container[n] = temp.top();
				n++;
				temp.pop();
			}

			for (i = 0; i < 34; i++)		//找邻接点
			{
				if (adj[tempPo1][i] == 1)
				{
					
					contain = false;
					for (n = 0; n < path.size(); n++)
					{
						if (i == container[n])
							contain = true;
					}

					if (contain == false)
					{
						route.push(i);
						k++;
					}				//记录是否有未访问过的邻接点
				}
			}
			if (k == 0)
			{
				route.push(-1);				//没有未访问过的邻接点，需退回
			}
		}
		else
			route.push(-1);			

		
		if (tempPo1== getPos(end))	//走到目标点，保存路径
		{
			
			while (!path.empty())
			{
				temp.push(path.top());
				
				path.pop();
			}
			while (!temp.empty())
			{
				resultpath[pathnum][num] = temp.top();
				path.push(temp.top());
				temp.pop();
				num++;
			}
			pathnum++;
			num = 0;
			path.pop();						//抛出终点
											//终点重标记为未访问
		}
		
		int tempPo2 = route.top();
		if (tempPo2 != -1)
		{
			
			path.push(tempPo2);
			route.pop();
		}
		else
		{
			j = path.top();
			path.pop();
			route.pop();
		}

	}
}

template<class T, class K>
inline void AdjListGraph<T, K>::route(int C,T str)		//C=0 时输出 str为终点城市
{
	
	int temp;
	stack<int> S;
	for (int i = 0; i < 34; i++)
	{
		int j = i;
		while (path[j] != -1)
		{
			S.push(j);
			j = path[j];
		}
		S.push(j);

		DjPtah[i][0] = S.size();

		if(C==0)
		cout <<nodeTable[i].data<<" "<< "distance: " << dest[i]<<'\t';
		
		DjDist[i] = dest[i];
		int d = 1;
		while (!S.empty())
		{
			temp = S.top();
			DjPtah[i][d] =temp;
			d++;
			S.pop();
			
			if (C == 0)
			{
				cout << nodeTable[temp].data;
				if (S.size() >= 1)
					cout << " -> ";
			}
		}

		if (C == 0)
			cout << endl;
	}

	if (str != "0")
	{
		int temp = getVertexPos(str);
		int j = DjPtah[temp][0];
		cout << "diatance: " << DjDist[temp] << "	";
		for (int k = 1; k <= j; k++)
		{
			cout << cities[DjPtah[temp][k]] << " ";
		}
		cout << endl;
		return;
	}

}

template<class T, class K>
inline void AdjListGraph<T, K>::froute(T str,T str1)
{
	int i = getPos(str);
	int j = getPos(str1);
	
	stack<int> S;
	S.push(j);
	cout << "distance: " << fdist[i][j] << " ";
	while (fpath[i][j] !=i)
	{
		S.push(fpath[i][j]);
		
		j = fpath[i][j];
		
	}
	S.push(i);
	
	while (!S.empty())
	{
		int k = S.top();
		cout << cities[k] << " ";
		S.pop();
	}
	cout << endl;
}

template<class T, class K>
inline void AdjListGraph<T, K>::Floyd(Graph<T, K>& G,T str,T str1)
{
	int i, j, k, nv = G.numOfVertices();
	for(i=0;i<nv;i++)
		for (j = 0; j < nv; j++)
		{
			fdist[i][j] = G.getWeight(i, j);
			if (i != j && fdist[i][j] < maxWeight)
				fpath[i][j] = i;
			else
				fpath[i][j] = -1;
		}
	for(k=0;k<nv;k++)
		for(i=0;i<nv;i++)
			for(j=0;j<nv;j++)
				if (fdist[i][k] + fdist[k][j] < fdist[i][j])
				{
					fdist[i][j] = fdist[i][k] + fdist[k][j];
					fpath[i][j] = fpath[k][j];
				}
	froute(str, str1);
}

template<class T, class K>
inline int AdjListGraph<T, K>::partitionWithMedian3(const int left, const int right)
{
	int i = left;
	int j = right - 1;

	if (left < right)
	{
		Element<int, int> pivot = median3( left, right);
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
inline Element<int, int>& AdjListGraph<T, K>::median3( const int left, const int right)
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
inline void AdjListGraph<T, K>::quickNonRecursion( int left, int right)
{
	if (left >= 0 && right < L.size() && left <= right)
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

			
			pivotPos = partitionWithMedian3( l, r);
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

template<class T, class K>
inline void AdjListGraph<T, K>::sortFile()
{
	int i = 0, j = 0, k = 0, d = 0, t = 0;
	Element<int, int>E;
	L.clear();
	for (i = 0; i < pathnum; i++)
	{
		j = resultpath[i][0];
		d = 0;
		t = 0;
		for (k = 1; k+1 <= j; k++)
		{
			d = distance[resultpath[i][k]][resultpath[i][k + 1]];
			if (d != 0)
				t += d;
			else
				t+= distance[resultpath[i][k + 1]][resultpath[i][k]];
		}
		E.data = i;
		E.key = t;
		L.push_back(E);
	}
	quickNonRecursion(0, pathnum - 1);

	ofstream fout;
	fout.open("F:path.txt");
	if (fout.good())
	{
		for (i = 0; i < pathnum; i++)
		{
			j = L[i].data;
			k = resultpath[j][0];
			fout <<i<<'\t'<< "distance:" << L[i].key << " ";
			for (d = 1; d <= k; d++)
			{
				fout << cities[resultpath[j][d]] << " ";
			}
			fout << endl;
		}
	}
}

