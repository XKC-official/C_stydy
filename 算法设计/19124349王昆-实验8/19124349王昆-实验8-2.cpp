/*************************************************************
编写时间：2021-5-26
程序版本：V1.0
开发者：王昆

程序功能：设计基于贪心法的算法实现哈夫曼编码问题
输入数据：用户键盘随机输入数据
输出结果：屏幕显示输入数据处理后的结果
****************************************************************/

#include<iostream>
#include<string>
using namespace std;

#define MaxNum 1000

//哈夫曼树结构体
typedef struct
{
	int weight;
	int flag;
	int parent;
	int lchild;
	int rchild;
}hnodetype;

//编码记录
typedef struct
{
	int bit[10];
	int start;
	char leaf;
}hcodetype;

//哈夫曼树生成
//cha:当前输入字符，m:每种字符出现的次数,n:字符总个数
//输出字符频率，以及每个字符的哈夫曼编码
void huf(char cha[], int m[], int n)

{
	int c, i, j, m1, m2, x1, x2, p;
	hnodetype* huffnode = new hnodetype[2 * n - 1];
	hcodetype* huffcode = new hcodetype[n], cd;
	//初始化哈夫曼树
	for (i = 0; i < 2 * n - 1; i++){
		huffnode[i].flag = 0;
		huffnode[i].lchild = -1;
		huffnode[i].rchild = -1;
		huffnode[i].parent = 0;
		huffnode[i].weight = 0;
	}

	for (i = 0; i < n; i++){
		huffnode[i].weight = m[i];
		huffcode[i].leaf = cha[i];
	}

	//遍历寻找左右子树,用x1,x2记录
	for (i = 0; i < n - 1; i++){
		m1 = m2 = INT_MAX;
		x1 = x2 = 0;
		for (j = 0; j < n + i; j++){
			if (huffnode[j].weight <= m1 && huffnode[j].flag == 0){
				x2 = x1;
				x1 = j;
				m2 = m1;
				m1 = huffnode[j].weight;
			}
			else if (huffnode[j].weight <= m2 && huffnode[j].flag == 0){
				x2 = j;
				m2 = huffnode[j].weight;
			}
		}

		huffnode[x1].parent = n + i;
		huffnode[x2].parent = n + i;
		huffnode[x1].flag = 1;
		huffnode[x2].flag = 1;
		huffnode[n + i].weight = huffnode[x1].weight + huffnode[x2].weight;
		huffnode[n + i].lchild = x1;
		huffnode[n + i].rchild = x2;
	}
	//生成哈夫曼树的编码
	for (i = 0; i < n; i++){
		cd.start = n - 1;
		c = i;
		p = huffnode[c].parent;
		while (p != 0){
			if (huffnode[p].lchild == c) cd.bit[cd.start] = 0;
			else cd.bit[cd.start] = 1;
			cd.start--;
			c = p;
			p = huffnode[c].parent;
		}

		cout << huffcode[i].leaf << ":";
		for (j = cd.start + 1; j < n; j++){
			huffcode[i].bit[j] = cd.bit[j];
			cout << cd.bit[j];
		}
		cout << endl;
		huffcode[i].start = cd.start;
	}
	delete[] huffcode;
	delete[] huffnode;
}


int main()
{
	string str;
	int i = 0, j, n, m[MaxNum], h, k = 0;
	char cha[MaxNum];
	cout << "输入一个字符串:" << endl;
	cin >> str;
	n = str.length();
	cout << "字符串共有" << n << "个字符" << endl;

	for (i = 0; i < n; i++){
		j = 0;
		h = 0;

		while (str[j] != str[i]) j++;

		if (i == j){
			cout << "字符" << str[i] << "出现";
			cha[k] = str[i];
		}
		else continue;

		for (j = i; j < n; j++){
			if (str[i] == str[j])
				h++;
		}

		cout << h << "次" << endl;
		m[k] = h;
		k++;
	}

	cout << "每个字符的哈夫曼编码是:" << endl;
	huf(cha, m, k);

	return 0;
}







