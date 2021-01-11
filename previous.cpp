

//#include<iostream>
//using namespace std;
//int main()
//{
//	int n1, n2, i = 0, x = 0, n=0;
//	cin >> n1;
//	n2 = n1;
//	while (n1 > 0)
//	{
//		n++;
//		n1 /= 10;
//		
//		
//	}
//	for (;i < n; i++)
//	{
//		x = x * 10 + n2 % 10;//将求模后得到的余数换到前面
//		n2 /= 10;//将数向后推进
//	}
//	cout << x;
//	system("pause");
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int main()
//{
//	for (int i = 1; i < 10; i++)//外层循环，控制行
//	{
//		for ( int j = 1; j <= i;j++)//内层循环，控制每一行的
//		{
//			cout << j << "*" << i << "=" << i * j << '\t' ;
//		}
//		cout << endl;
//	}
//	system("pause");
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int main()
//{
//	for (int i = 1; i < 5; i++) 
//	{
//		for (int j = 1; j < i; j++)//控制空格
//			cout << " ";
//		for (int k = 1; k < 10; k++)//控制星号
//			cout << "*";
//		cout << endl;
//	}
//	system("pause");
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int main()
//{
//	int m = 0,n=0 ,i;
//	cin >> n;
//	for(m=2;m<n;m++)
//	{
//		for (int i = 2; i <= m ; i++)
//
//		{
//			if (m %i == 0)
//				break;
//
//			if (m%i != 0)
//				cout << m << endl;
//			break;;
//		}
//		
//	}
//
//			system("pause");
//			return 0;
//}

//#include<cmath>
//#include<iostream>
//using namespace std;
//int main()
//{
//	
//	
//	for (float y = 1.5; y >-1,5; y -= 0.1)
//	{
//		for (float x = -1.5; x < 1.5; x += 0.05)
//		{
//			float a = x * x + y * y - 1;
//			float b = x * x*y*y*y;
//			if (a*a*a - b <= 0)
//
//				cout << "L";
//			else
//				cout << " ";
//          
//		}
//		cout << endl;
//	}
//	system("pause");
//	return 0;
//}

//#include<iostream>
//int main()
//{
//	using namespace std;
//	const int size = 20;
//	char name[size];
//	char food[size];
//
//	cout << "Enter your name:" << endl;
//	cin.getline(name,20);
//	cout << "What`s your favourite dish ?" << endl;
//	cin .getline(food,20);
//	cout << "You are " << name << "," << "your favourite dish is:" << food << endl;
//	system("pause");
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int main()
//{
//	int i = 1;
//	for (; i <= 100; i++)
//	{
//		if (i % 2&&i%3)
//			cout << i<< '\t';
//		else
//			cout << " ";
//			continue;
//			cout << endl;
//	}
//	system("pause");
//	return 0;
//}

//#include<iostream>
//#include<cmath>
//using namespace std;
//int main()
//{
//	double step = 0.2;
//	double x = 0;
//	while (x < 12.56)
//	{
//		int val = 20* (sin(x) + 1);
//		for (int i = 0; i < val; ++i)
//		{
//			cout << " ";
//
//		}
//		cout<<"*"<<endl;
//		x += step;
//	}
//	system("pause");
//	return 0;
//}

//#include<iostream>
//#include<cmath>
//using namespace std;
//int main()
//{
//	int x, i, tmpX;
//	for (double y = 1; y > -1;y-=0.1)
//	{
//		tmpX = abs(asin(y)) * 10;
//		if (y >= 0)
//		{
//			for (x = 0; x < tmpX; x++)
//			{
//				cout << " ";
//			}
//				cout << "*";
//			
//				for (; x < 31 - tmpX; x++)
//				{
//					cout << " ";
//				}
//				cout << "*" << endl;
//			
//		}
//		else
//		{
//			for (x = 0; x <= 31 + tmpX; x++)
//			{
//				cout << " ";
//			}
//				cout << "*";
//			
//				for (; x <= 62 - tmpX; x++)
//				{
//					cout << " ";
//				}
//				cout << "*" << endl;
//			
//		}
//
//		
//	}
//	
//	system("pause");
//	return 0;
//}

//#include<iostream>
//int main()
//{ 
//	using namespace std;
//	int year; 
//	(cin >> year).get();
//	char adress[80];
//	cin.get(adress, 80);
//	cout << year;
//	cout << adress;
//	system("pause");
//	return 0;
//}

//#include<iostream>
//#include<cmath>
//using namespace std;
//int main()
//{
//	double x = 0,y=2;
//	double delta = 0.2;
//	for (x=0; x <= 4; x += delta)
//	{
//		double X = (x - 2)*(x - 2);
//		for (y=2; y >= -2; y -= 0.1)
//		{
//			if ((X + y * y - 4)>0)
//			{
//				cout << " ";
//			}
//			else
//				cout << "*";
//		}cout << endl;
//	}
//	system("pause");
//	return 0;
//}

//#include<iostream>
//#include<cmath>
//using namespace std;
//int main()
//{
//	double x=0, y=0, X;
//	X = 4 - (x - 2)*(x - 2) - y * y;
//	for (y = 2; y >= -2; y += 0.1)
//	{
//		if (y >= 0)
//		{
//			for (x = 0; x <= 4; x += 0.2)
//				if (X < 0)
//				{
//					cout << " ";
//				}
//			cout << "*";
//
//		}
//		else
//			if (X < 0)
//				cout << " ";
//		cout << "*";
//	}
//
//	system("pause");
//	return 0;
//}

//#include<iostream>
//#include<cmath>
//using namespace std;
//int main()
//{
//	int n = 0, x=0, y=0;
//	cin >> n;
//	for (int i = n; i >=1; i--)
//	{
//		for (int x = 1; x <n-i; x++)
//			cout << " ";
//		for (int y = 1; y <2*i-1; y++)
//			cout << "*";
//		
//		cout << endl;
//
//	}
//	system("pause");
//	return 0;
//}

//#include<iostream>
//#include<cmath>
//using namespace std;
//int main()
//{
//	int n = 0, x = 0, y = 0;
//	cin >> n;
//	for (int i = 1; i <=n;i++)
//	{
//		for (x =1; x<=n-i; x++)//从x=1开始，运行for循环，直到x=n-i-1
//			cout << " ";
//		for (y =1; y <2*i;y++ )//从y=1开始，运行for循环，直到y=2*i-2
//			cout << "*";
//		cout << endl;
//	}
//	system("pause");
//	return 0;
//}
//
//#include<iostream>
//using namespace std;
//int main()
//{
//	struct hat
//	{
//		char name[20];
//		int count;
//		double volume;
//	};
//	hat nike =
//	{
//		"superstar",
//		300,
//		30
//	};
//	hat adidas =
//	{
//		"yeeze",
//		1000,
//	50
//	};
//	cout<<"We have "<<nike.name<<'\t'<<nike.count<<"pairs."<<endl;
//	cout << "We have" << adidas.name << '\t' << adidas.count << "pairs." << endl;
//	system("pause");
//	return 0;
//
//
//}

//#include<iostream>
//#include<string>
//using namespace std;
//struct hat
//{
//	string name;
//	int count;
//};
//int main()
//{
//    hat kik[2]=
//	{
//		{ "hahaha",20},
//	    {"kakaka",30}
//	};
//	cout<<kik[0].name << kik[0].count << endl << kik[1].name << kik[1].count << endl;
//	system("pause");
//	return 0;
//}

//#include<iostream>
//#include<string>
//using namespace std;
//	struct hat
//	{
//		string name;
//		int count;
//		union volume
//		{
//			char volume_1 [20];
//			int volume_2;
//			double volume_3;
//		};
//	};
//	int main()
//	{
//		hat kik = { "kiki", 30 };
//		cout << kik.name << endl;
//		system("pause");
//		return 0;
//	}

//#include<iostream>
//#include<cmath>
//using namespace std;
//int main()
//{
//	int num[101];
//	int i = 0, x;
//	num[0] = 0;
//	num[1] = 1;
//	for (i = 2; i <= 100; i++)
//	{
//		num[i] = 1;
//
//		for (int k = 2; k*i < 101; k++)
//		{
//
//
//			num[i*k] = 0;
//
//
//		}
//	}
//	
//		for (x = 2; x < 101; x++)
//		{
//			if (num[x] = 1)
//			{
//				cout << x << endl;
//			}
//		}
//	
//	system("pause");
//	return 0;
//}

//#include<iostream>
//#include<math.h>
//using namespace std;
//int main()
//{
//	int num[101];
//	int i = 0;
//	while (i < 101)
//	{
//		num[i] = i;
//		i++;
//	}
//	for (i = 2; i <= 99; i++)
//	{
//		if (num[i] != 0)
//		{
//			for (int k = 2; k*i < 100; k++)
//			{
//				num[i*k] = 0;
//			}
//		}
//	}
//	for (int x = 0; x<99; x++)
//	{
//		if (num[x] != 0)
//		{
//			cout << x << endl;
//		}
//	}
//
//	system("pause");
//	return 0;
//}

//#include<iostream>
//#include<math.h>
//using namespace std;
//int ispre(int n)
//{
//	float n_sqrt;
//	if ( n == 3)
//		return 1;
//	if (n % 6 != 1 && n % 6 != 5)
//		return 0;
//	n_sqrt = floor(sqrt((float)n));
//	for (int i = 5; i <= n_sqrt; i += 6)
//	{
//		if (n % (i) == 0 | n % (i + 2) == 0)
//			return 0;
//	}
//	return 1;
//}
//int main()
//{
//	int n;
//	cin >> n;
//	int flag;
//	flag = ispre(n);
//	if (flag = 1)
//		cout << "是素数" << endl;
//	else
//		cout << "不是素数" << endl;
//	system("pause");
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int main()
//{
//	int hat = 10;
//	cout << "hat value=" << hat << "and hat adress=" << &hat << endl;
//	cin.get();
//		return 0;
//}

//#include<iostream>
//#include<cstring>
//struct food//声名结构
//{
//	char name[20];
//	double price;
//};
//int main()
//{
//	using namespace std;
//	int hat=10;
//	int* a_hat;
//	int* kik = new int;
//	int* jij = new int[10];
//	int i = 0;
//	while (i <= 9)
//	{
//		jij[i] = i;
//		i++;
//	}
//	*kik = 101;
//	a_hat = &hat;                                                                                                                                                  
//	cout << "hat value=" << *a_hat << ",hat adress=" << a_hat << endl;
//	*a_hat += 1;
//	cout << "hat=" << hat;
//	cout << "int value=" << *kik << ",location:" << kik << endl;
//	cout << "location of pointer kik is:" << &kik << endl;
//	delete kik;//释放内存，只能用于释放new分配的，只能释放一次，不能重复
//	for (i = 0; i <= 9; i++)
//	{
//		for (int k = 0; k <= i; k++)
//		{
//			cout << "*";
//		}
//		cout << *(jij+i);
//		cout << jij[i];
//		for (int j =10- i; j >= 0; j--)
//		{
//			cout << "*";
//		}
//		
//		cout << endl;
//	}
//	char flower[20] = "hjhjjhjh";
//	strncpy_s(flower, "hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh", 19);
//	flower[19] = '\0';
//	cout << flower << endl;
//	char* flow = new char[strlen(flower) + 1];
//	flow = flower;
//	cout << flow << endl;
//	food* cabbage = new food;//用new创建动态结构
//	cin.get(cabbage->name, 20);//访问动态结构的两种方法:pointer name->structure member;(*pointer name).structure member;
//	cin >> (*cabbage).price;
//	cout << cabbage->name << endl;
//	cout<<(*cabbage).price << endl;
//	delete cabbage;
//	cout << "I am a big\0 man";
//	system("pause");
//	return 0;
//}

//#include<array>
//#include<vector>
//#include<iostream>
//#include<cstring>
//using namespace std;
//char* getname();
//int main()
//{
//	char* Name;
//	Name = getname();
//	cout << "Name=" << Name << endl;
//	cout << "Name at " << (int*)Name << endl;
//	delete Name;
//	cout << "Name=" << Name << endl;
//	cout << "Name at " << (int*)Name << endl;
//	array<int, 10>pi = { 0,1,2,3 };
//	vector<int> po(8);
//	po[0] = 0;
//	cout << pi[3]<< '\t' << po[7];
//	system("pause");
//	return 0;
//}
//char* getname()
//{
//	char name[100];
//	cin >> name;
//	char* pn = new char[strlen(name) + 1];
//	pn = name;
//	cin.get();
//	return pn;
//}

//#include<iostream>
//using namespace std;
//int main()
//{
//	long long factorials[16];
//	factorials[0] = factorials[1] = 1;
//	for (int o = 2; o< 16; o++)
//		factorials[o] = o * factorials[o - 1];
//	for (int o = 0; o < 16; o++)
//		cout << factorials[o] << endl;
//	for (int i = 0; i < 20; i++)
//	{
//		for (int j = 0; j < 33; j++)
//			for (int k = 0; k < 300; k++)
//				if ((i+j+k=100) &&( i * 5 + j * 3 + k / 3 = 100))
//					cout << i << j << k << endl;
//	}
//	system("pause");
//	return 0;
//}


//#include<iostream>
//using namespace std;
//int main()
//{
//	int num1 = 0, num2 = 0;
//	cin >> num1, num2;
//	while (1)
//	{
//		int read = num1 % num2;
//		if (read = 0)
//			break;
//		num1 = num2; 
//		num2 = read;
//
//	}
//	cout << num2;
//	system("pause");
//	return 0;
//}

//#include<iostream>
//#include<cmath>
//using namespace std;
//int main()
//{
//	long x = 0, t = 1,sinx=0,n=1;
//	cin >> x;
//	do
//	{
//		sinx+= x * t;
//		n++;
//		t = -x * x / n * (n + 1);
//	} while (fabs(t) > 1e-4);
//	cout << "sinx=" << sinx;
//	system("pause");
//	return 0;
//}

//#include<iostream> 
//#include<string>
//int main()
//{
//	std::string word;
//	std::cin >> word;
//	for (int i = word.size(); i >= 0; i--)
//		std::cout << word[i];
//	system("pause");
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int main()
//{
//	int nmu[3][4]=
//	{
//		{11,1,2,3},
//	    {1,5,8,6},
//	    {2,5,4,1},
//	};
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 4; j++)
//			cout << nmu[i][j] << '\t';//it`s necessary to point out the element,the array-name 'nmu' is an adress.
//	
//		cout << endl;
//	}
//	char ch;
//	int spaces = 0;
//	int total = 0;
//	cin.get(ch);
//	while (ch !='.')
//	{
//	if (ch == '\n ')
//			cout << ch;
//		else
//			cout << ++ch;
//		cin.get(ch);
//	}cout << spaces << endl;
//	cout << total;
//	system("pause");
//	return 0;
//}

//#include<iostream>
//#include<fstream>
//using namespace std;
//int main()
//{
//	int a = 1,b=0;
//	ofstream outfile;
//	outfile.open("lqb.txt");
//	outfile << a;
//	outfile.close();
//	ifstream infile;
//	infile.open("lqb.txt");
//	infile >> b;
//	infile.close();
//	cout << b;
//	system("pause");
//	return 0;
//}

//#include <iostream>
//using namespace std;
//int main()
//{
//	int a = 2, b = 9, c = 0,e=0;
//	int i = a;
//	for (; i <= b; i++)
//		c += i;
//	cout << c << endl;
//	    c = 0;
//	while (1)
//	{
//        cin >> e;
//		if (cin.get() != 0)
//		{
//			c += e;
//			cout << c << endl;
//		}
//
//	}
//	cout << "circular end!"<<endl;
//	system("pause");
//	return 0;


//#include<iostream>
//using namespace std;
//double daphne(double);
//double cleo(double);
//int main()
//{
//	double i = 1;
//	for (; daphne(i) < cleo(i); i++)
//		cout << daphne(i) << '\n' << cleo(i) << '\n' << i << endl;
//	system("pause");
//	return 0;
//}
//double daphne(double i)
//{
//	double a = 100 * 0.1*i;
//	return a;
//}
//double cleo(double i)
//{
//	double c = 100;
//	double t = 0;
//	for (int b = 0; b <= i; b++)
//	{
//		c = 100 + t;
//		t = c * 0.05;
//	}
//	return 100;
//}



//#include<iostream>
//using namespace std;
//void circulation(char ch, int time);
//int fill_arry(double ar[], int limit);
//void  show_arry(const double ar[], int n);
//const int arsize = 5;
//int sum_arr(int* arr, int n);
//int main()
//{
//	int time;
//	cin >>time;
//	char ch='t';
//	while (ch != 'q')
//	{
//		cin >>ch;
//		circulation(ch, time);
//	}
//	int cookies[arsize];
//	for (int i = 0; i < arsize; i++)
//	{
//		int x = 0;
//		cin.get();
//		cin >> x;
//		cookies[i] = x;
//	}
//	int sum = sum_arr( cookies, arsize);
//	double property[arsize];
//	int limit;
//	cin >> limit;
//	int m =fill_arry(property, limit);
//	show_arry(property, limit);
//	cout << "sum=" << sum;
//	system("pause");
//	return 0;
//}
//void circulation(char ch, int time)
//{
//	for (time; time > 0; time--)
//		cout << ch << '\t' << endl;
//}
//int sum_arr(int arr[], int n)
//{
//	int total = 0;
//	for (int i = 0; i < n; i++)
//		total = total + arr[i];
//	return total;
//}
//int fill_arry(double ar[], int limit)
//{
//	using namespace std;
//	double temp;
//	int i;
//	for (i = 0; i < limit; i++)
//	{
//		cout << "Enter value#" << i + 1 << ":";
//		cin >> temp;
//		if (!cin)
//		{
//			cin.clear();
//			while (cin.get() != '\n')
//				continue;
//			cout << "Bad input!" << endl;
//			break;
//		}
//		else if (temp < 0)
//			break;
//		ar[i] = temp;
//	}
//	return i;
//}
//void show_arry(const double ar[], int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		cout << "property#" << i + 1 << ":";
//		cout << ar[i]<< endl;
//	}
//}

//#include<iostream>
//using namespace std;
//const int ar = 8;
//int main()
//{
//	int que[ar] = { 0 };
//	int i = 0;
//		while (i >= 0)//check
//	{
//		int k = 0;
//		while (k < i)//compare with rows 
//		{
//			if (que[k] != que[i] &&( abs(que[k] - que[i]) != abs(k - i)))
//				k++;
//			else
//				break;
//		}
//		if (k < i)
//		{
//			++que[i];
//			while (que[i] == ar)
//			{
//				que[i] = 0;
//				--i;
//				if (i < 0)
//					break;
//				++que[i];
//			}
//			continue;
//		}
//		else
//		{
//			++i;
//			if (i < ar)
//				continue;
//			cout << "find out a solution!" << endl;
//
//			for (k = 0; k < ar; ++k)
//				cout << que[k];
//			cout << endl;
//			break;
//		}
//	}
//			system("pause");
//			return 0;
//}

//#include<iostream>
//using namespace std;
//const int ar = 3;
//int sum(int arr[][ar], int n);
//int fill_arr(int arr[][ar], int n);
//int main()
//{
//	int arr[3][ar];
//	cout<< fill_arr(arr, ar);
//
//}
//int fill_arr(int arr[][ar], int n)
//{
//	for(int i=0;i<n;i++)
//		for (int j = 0; i < ar; i++)
//		{
//			int x = 0;
//			cin >> x;
//			arr[i][j] = x;
//
//			return arr[i][j];
//		}
//}

//#include<iostream>
//using namespace std;
//void hanoi(int n, char sour, char mid, char tar);
//void hanoi(int n,char sour,char mid,char tar)
//{
//	if (n == 1)
//		cout << sour << "-->" << tar << '\t';
//	else 
//	{
//		hanoi(n - 1, sour, tar, mid);
//		cout << sour << "-->" << tar << '\t';
//		hanoi(n - 1, mid, sour, tar);
//	}
//}
//int main()
//{
//	int n;
//	cin >> n;
//	hanoi(n, 'A', 'B', 'C');
//	system("pause");
//	return 0;
//}

//#include<iostream>
//using namespace std;
//int sum(int n);
//int main()
//{
//	int n = 0;
//	cin >> n;
//	cout << sum(n);
//	system("pause");
//	return 0;
//}
//int sum(int n)
//{
//	if (n == 0)
//		return 0;
//	return sum(n - 1) + n;
//}

//#include<iostream>
//using namespace std;
//long sum(long n);
//int main()
//{
//	long n=6;
//	cin >> n;
//	cout << sum(n) << '\t';
//	system("pause");
//	return 0;
//}
//long sum(long n)
//{
//	if (n<2)
//		return 1;
//	else
//	return sum(n - 1) + sum(n - 2);
//}

//#include<iostream>
//#include<cmath>
//using namespace std;
//void divert(int& m, int& n);
//int main()
//{
//	int stu[10];
//	for (int n = 0; n < 10; n++)
//	{
//		int c = 0;
//		cin >> c;
//		stu[n] = c;
//	}
//	for(int n=0;n<10;n++)
//		for(int j=9;j>n;j--)
//		{
//			if (stu[j] < stu[j-1])
//				divert(stu[j],stu[j-1]);
//		}
//	for (int n = 0; n < 10; n++)
//		cout << stu[n] << '\n';
//	system("pause");
//	return 0;
//}
//void divert(int& m, int& n)
//{
//	int t = m;
//	m = n;
//	n = t;
//
//	
//}

//#include<iostream>
//using namespace std;
//char* str(char n, int time);
//int main()
//{
//	int time = 10;
//	char n = 'v';
//	char *pr = str(n, time);
//	cout << pr;
//	system("pause");
//	return 0;
//}
//char* str(char n, int time)
//{
//		char* pr = new char[time + 1];
//		while(time)
//		{
//		pr[time] = n;
//		time--;
//	}
//	return pr;
//}

//#include<iostream>
//using namespace std;
//void countdown(int);
//int main()
//{
//	int n = 0;
//	cin >> n;
//	countdown(n);
//	system("pause");
//	return 0;
//}
//void countdown(int b)
//{
//	cout << "count down" << b << endl;
//	if (b > 0)
//		 countdown(b - 1);
//	cout << b << ":lqb\n";
//
//}

//#include<iostream>
//using namespace std;
//void sub(char ar[], int high, int low, int level);
//const int dvi = 6;
//const int len = 66;
//int main()
//{
//	char rule[len];
//	int i = 0;
//	for ( i = 0; i < len - 2; i++)
//		rule[i] = ' ';
//	rule[len - 1] = '\0';
//	rule[0] = rule[len - 2] = '|';
//	int min = 0, max = len - 2;
//	cout << rule << endl;
//	for (int j = 1; j < dvi; j++)
//	{
//		sub(rule, max, min,j );
//		cout << rule << endl;
//		cout << endl;
//		for (int n = 0; n < len - 2; n++)
//			rule[n] = ' ';
//
//	}
//	system("pause");
//	return 0;
//}
//void sub(char ar[], int high, int low, int level)
//{
//	if (level == 0)
//		return;
//	int mid = (high + low) / 2;
//	ar[mid] = '|';
//	sub(ar, mid, low, level - 1);
//	sub(ar, high, mid, level - 1);
//}

//#include<iostream>
//using namespace std;
//int main()
//{
//	int i = 0;
//	int j = 0;
//	int k = 3;
//	for (i = 1; i<5; i++)
//	{ 
//		
//			for (j = 1; j<5-i; j++)
//				cout << " ";
//			for (int a = 0; a < (2*i-1); a++)
//				cout << "*";
//		cout << endl;
//	}for (i = 3; i >0; i--)
//	{
//		for (j = 0; j <4-i; j++)
//			cout << " ";
//		for (j = 0; j < 2 * i - 1; j++)
//			cout << "*";
//		cout << endl;
//	}
//	system("pause");
//	return 0;
//} 


//#include<iostream>
//int main()
//{
//	using namespace std;
//	int m = 20;
//	int n = 30;
//	swap(n, m);
//	cout << "m=" << m << "\n n=" << n;
//	system("pause");
//	return 0;
//}
//template<typename T>
//void swap(T &a, T &b)
//{
//	T temp = a;
//	a = b;
//	b = temp;
//}

//#include<iostream>
//int main()//插入排序法
//{
//	using namespace std;
//	int array[10] = { 0,3,6,9,8,5,2,1,4,7 };
//	cout << array[9];
//	for (int i = 1; i < 10; i++)
//	{
//		int intval = array[i];
//		int j = i - 1;
//		for (j; j >=0&&array[j]>intval; j--)
//		{
//			array[j + 1] = array[j];
//		}
//		array[j + 1] = intval;
//	}
//	for (int i = 0; i < 10; i++)
//		cout << array[i] << endl;
//	system("pause");
//	return 0;
//}





//#include<iostream>
//#include<vector>
//#include<string>
//#include<fstream> 
//using namespace std ;                                                
//class Student
//{
//	friend bool readFile(fstream &);
//	friend bool edit(string &);
//	friend bool deleteStudent(string &);
//	friend bool saveFile(ofstream &);
//public:
//	Student(fstream &);
//	Student(string, long, int, int, string);
//private:
//	string name;
//	long StuID;
//	int sex;
//	int age;
//	string addres;
//}
//
// Student::Student(fstream &infile)
// {	
//infile>>name ;	
//infile>>StuID ;	
//infile>>sex ;	
//infile>>age ;	
//infile>>addres ;
// } 
//Student::Student(string name ,long StuID ,int sex ,int age ,string addres)
//{	
//this->name = name ;	
//this->StuID = StuID ;	
//this->age = age ;	
//this->sex = sex ;	
//this->addres = addres ;
//}  
//vector<Student> vec ;
//vector<Student> ::iterator it ;
//
//
//bool readFile(fstream &infile)
//{	
//	while (!infile.eof())	
//	{		
//vec.push_back(Student(infile)) ;
//	}	
//	return true ;
//}  
///**bool dispaly(){	it = vec.begin() ;	while (it != vec.end())	{		cout<<it->name <<endl ;		it ++ ;	}	return true ;}**/ 
//
//bool add()
//{	
//string name ;	
//long StuID ;	
//int sex ;	
//int age ;	
//string addres ;  	
//cout<<"please input the new student's data:"<<endl ;	
//cout<<"the name:"<<endl ;	
//cin>>name ;	
//cout<<"the student's id:"<<endl ;	
//cin>>StuID ;	
//cout<<"the sex:(0/1)"<<endl ;	
//cin>>sex ;	
//cout<<"the age:"<<endl ;	
//cin>>age ;	
//cout<<"the addres:"<<endl ;	
//cin>>addres ;  	
//vec.push_back(Student(name ,StuID ,sex ,age ,addres)) ;
//return true ;
//} 
//
//
//bool edit(string & name)
//{
//	it = vec.begin();
//	while (it != vec.end())
//	{
//		if (it->name == name)
//		{
//			break;
//
//		}
//		it++;
//	}
//	if (it == vec.end())
//	{
//		cout << "there is no such a person!" << endl;
//	}
//	else
//	{
//		int ch;
//		long StuID;
//		int sex;
//		int age;
//		string addres;
//		switch (ch)
//		{
//		case 'a':
//			cin >> name;
//			it->name = name;
//			break;
//		case 'b':
//			cin >> StuID;
//			it->StuID = StuID;
//			break;
//		case 'c':
//			cin >> sex;
//			it->sex = sex;
//			break;
//		case 'd':
//			cin >> age;
//			it->age = age;
//			break;
//		case 'e':
//			cin >> addres;
//			it->addres = addres;
//			break;
//		default:
//			break;
//		}
//	}
//	return true;
//}
//           
// 
//
//
//bool deleteStudent(string & name)
//{	
//	it = vec.begin() ;	
//	while (it != vec.end())	
//	{		
//		if(it->name == name)
//		{			
//			vec.erase(it) ;			
//			cout<<"erase success!"<<endl ;			
//			break ;		} 		
//		it ++ ;
//	} 	
//	return true ;
//} 
//
//
//bool saveFile(ofstream &outfile)
//{	
//	it = vec.begin() ;	
//	while (it != vec.end())	
//	{		
//		outfile<<
//			it->name<<" "<<
//			it->StuID<<" "<<
//			it->sex<<" "<<
//			it->age<<" "<<
//			it->addres<<endl ;		
//		it ++ ;	
//	}	return true ;
//}  
//int main()
//{	
//	string str_1 ;	
//	cout<<"A:read from a data;B:make a new data;"<<endl ; 	
//	cin>>str_1 ;	
//	//dispaly() ; 	
//	if(str_1 == "A")
//	{		
//		cout<<"please input the location of the data:"<<endl ;		
//		string str_2 ;		
//		cin>>str_2 ; 		
//		fstream infile(str_2) ;		
//		readFile(infile) ;		
//		cout<<"A:add a new student B:edit a student's data: C:delete a student's data"<<endl ;		
//		string str_3 ;		
//		cin>>str_3 ;		
//		if(str_3 == "A")			
//			add() ;		
//		else if(str_3 == "B")
//		{			
//			cout<<"please input the name of student:"<<endl ;			
//			string str_4 ;			
//			cin>>str_4 ;			
//			edit(str_4) ;		
//		}
//		else if(str_3 == "C")
//		{			
//			string str_5;			
//			cout<<"please input the person you wantna delete:" ;			
//			cin>>str_5 ;			
//			deleteStudent(str_5) ;		
//		}
//		else			
//			cout<<"error" ;				
//		    infile.close() ;	
//	}					
//	else if(str_1 == "B")
//	{		
//		cout<<"please input the student number:"<<endl ;		
//		int  n;		
//		cin>>n ;		
//		for(int i = 0 ;i < n ;i ++)			add() ;	
//	}  	
//	cout<<"do you wanna save the new data:(Y/N)"<<endl ;	
//	string str_2 ;	
//	cin>>str_2 ;	
//	if(str_2 == "Y")
//	{		
//		cout<<"the location of new data:"<<endl ;		
//		string str_3 ;		
//		cin>>str_3 ;		
//		ofstream outFile ;		
//		outFile.open(str_3 ,fstream::trunc | fstream::out) ;		
//		saveFile(outFile) ;		
//		cout<<"save success!!!"<<endl ;		
//		outFile.close() ;	
//	}		 	
//	return 0 ;
//}
//
//blog.csdn.net/rq8684/article/details/8119849



#include<afxwin.h>//mfc头文件



class MyApp :public CWinApp
{
public:
	virtual BOOL InitInstance(); //mfc程序入口地址
};



class MyFrame :public CFrameWnd//框架类
{
public:
	MyFrame();
	DECLARE_MESSAGE_MAP();

	afx_msg void OnLButtonDown(UINT, CPoint);
};


MyApp app;
BOOL MyApp::InitInstance()
{
	//创建窗口
	MyFrame * Frame = new MyFrame;

	//显示和更新
	Frame->ShowWindow(SW_SHOWNORMAL);

	//更新
	Frame->UpdateWindow();

	m_pMainWnd = Frame;//使用此数据成员可以存储指向线程的主窗口对象的指针。

	return true;//正常初始化
}


BEGIN_MESSAGE_MAP(MyFrame, CFrameWnd)
END_MESSAGE_MAP()
MyFrame::MyFrame()
{
	Create(NULL, TEXT("MFC")); //创建窗口
}

void MyFrame::OnLButtonDown(UINT, CPoint point)
{
	TCHAR buf[1024];
	wsprintf(buf, TEXT("x=%d,y=%d"), point.x, point.y);
	MessageBox(buf);
}
