#include "binaryTree.h"
int main()
{
	char* A = new char[20]{ 'a','b','d','g','j','h','k','e','i','l','c','f'/*'d','b','e','h','a','f','c','g'*/ /*'1','2','3','4','5'*/ /*'1','2','3'*/ /* '4','5','2','6','7','3','1'*/};
	char* B = new char[20]{'j','g','d','h','k','b','e','i','l','a','c','f'/*'d','h','e','b','f','g','c','a'*/ /*'1','2','3','4','5'*/  /*'2','1','3'*/ /*'4','6','5','1','2','3','7'*/};
	Node* node = new Node;

	/*std::vector<char>ch;
	node = LevelBuild(A,7 );
	preorder(node, ch);*/

	

	char J[2]{'P'};
	initgraph(1920, 1080);

	int i = 0;
	while (A[i] != '\0')i++;
	node = PreInbuild(nullptr, A, B, i, 0, 0, 0);
	//int h = height(node->rightchild->rightchild->leftchild->rightchild);
	//bool f = search(node->rightchild->leftchild, node->rightchild->rightchild);
	//bool lk = isoneTree(node->rightchild->rightchild, node->rightchild);

	Node* p = CoParent(node->rightchild->rightchild, node->rightchild);
	Node* q = Coparent(node->rightchild->rightchild, node->rightchild);

	/*inputbox_getline("请输入前或后序！","输入完成请回车！",A,20);
	inputbox_getline("请输入中序！", "输入完成请回车！", B, 20);
	inputbox_getline("请输入序列类型！", "PI:前中序 SI:中后序 LI:", J, 2);*/
	
	/*int i = 0;
	switch (J[0])
	{
	case 'P':
	{
		int i = 0;
		while (A[i] != '\0')i++;
		node=PreInbuild(nullptr,A, B, i,0,0,0);
		break;
	}
	case 'S':
	{
		int i = 0;
		while (A[i] != '\0')i++;
		node=PostInbuild(nullptr,A, B, i,0,0,0);
		break;
	}*/
	/*case 'L':
	{
		int i = 0;
		while (A[i] != '\0')i++;
		node = LevelBuild(A,i);
	}*/
	//}
	/*std::vector<char>ch;
	preorder(node, ch);*/
	delete[]A;
	delete[]B;
	clearTree(node);
	getch();
	closegraph();
	return 0;
}