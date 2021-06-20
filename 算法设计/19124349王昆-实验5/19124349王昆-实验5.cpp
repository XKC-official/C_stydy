/*************************************************************
编写时间：2021-5-10
程序版本：V1.0
开发者：王昆

程序功能：基于分治法的算法实现哈夫曼编码问题
输入数据：用户键盘随机输入数据
输出结果：屏幕显示输入数据处理后的结果
****************************************************************/
#include <iostream>
using namespace std;

#define MAXCODELEN 100		//最大编码数组长度
#define MAXHAFF 100			//最大节点结构体数组个数
#define MAXCODE 100			//最大编码结构体数组的个数
#define MAXWEIGHT  10000;	//最大权值

//节点结构体
typedef struct Huffman {
	int weight;		//权重
	char ch;		//字符
	int parent;		
	int leftChild;	
	int rightChild;	
}HuffmanNode;

//最大编码结构体
typedef struct Code {
	int code[MAXCODELEN];	//字符的哈夫曼编码的存储
	int start;				//从哪个位置开始
}HuffmanCode;

HuffmanNode huffman[MAXHAFF];
HuffmanCode code[MAXCODE];


//创建Huffman树
//输入字符数ch_num
//输出创建好的Huffman树
void createHuffman(int ch_num) {
	//初始化
	for (int i = 0; i < ch_num * 2 - 1; ++i) {
		huffman[i].weight = 0;
		huffman[i].parent = -1;
		huffman[i].leftChild = -1;
		huffman[i].rightChild = -1;
	}

	cout << "请依次输入" << ch_num << "个需要哈夫曼编码的字符：";
	for (int i = 0; i < ch_num; i++) {
		cin >> huffman[i].ch;
	}
	cout << "请依次输入" << ch_num << "个字符对应的的权值：";
	for (int i = 0; i < ch_num; i++) {
		cin >> huffman[i].weight;
	}

	//每次循环找出权值最小的两个节点，生成新的父亲节点。共需要 ch_num - 1 次合并
	int x1, x2, w1, w2;	//w1、w2分别为最小的两个节点
	for (int i = 0; i < ch_num - 1; ++i) {
		x1 = x2 = -1;
		w1 = w2 = MAXWEIGHT;		//初始化最小节点权值
		for (int j = 0; j < ch_num + i; ++j) {
			if (huffman[j].parent == -1 && huffman[j].weight < w1) { //找到无父节点并且权值最小
				w2 = w1;
				x2 = x1;
				x1 = j;
				w1 = huffman[j].weight;
			}
			else if (huffman[j].parent == -1 && huffman[j].weight < w2) { //找到第二小的无父亲节点
				x2 = j;
				w2 = huffman[j].weight;
			}
		}
		//将上面找到的最小权值节点合并成一个新的父亲节点
		huffman[ch_num + i].leftChild = x1;
		huffman[ch_num + i].rightChild = x2;
		huffman[ch_num + i].weight = w1 + w2;
		huffman[x1].parent = ch_num + i;
		huffman[x2].parent = ch_num + i;
	}
}

//打印
//输入字符数ch_num
//输出字符和对应的编码
void printCode(int ch_num) {
	HuffmanCode hCode;//保存当前叶子节点的字符编码
	int curParent;	//当前父节点
	int c;			//下标和叶子节点的编号
	for (int i = 0; i < ch_num; ++i) {
		hCode.start = ch_num - 1;
		c = i;
		curParent = huffman[i].parent;
		while (curParent != -1) {
			if (huffman[curParent].leftChild == c) { hCode.code[hCode.start] = 0; }
			else { hCode.code[hCode.start] = 1; }
			hCode.start--;
			c = curParent;
			curParent = huffman[c].parent;
		}
		//把当前的叶子节点信息保存到编码结构体里
		for (int j = hCode.start + 1; j < ch_num; ++j) {
			code[i].code[j] = hCode.code[j];
		}
		code[i].start = hCode.start;
	}
	cout << endl;
	for (int i = 0; i < ch_num; ++i) {
		cout << huffman[i].ch << " 字符的哈夫曼编码是：";
		for (int j = code[i].start + 1; j < ch_num; ++j) {
			cout << code[i].code[j];
		}
		cout << endl;
	}
}
int main() {
	int ch_num = 0;
	cout << "请输入哈夫曼字符个数：";		
	cin >> ch_num;
	if (ch_num <= 0) {
		cout << "您输入的个数有误" << endl;
		return -1;
	}
	createHuffman(ch_num);
	printCode(ch_num);
	return 0;
}
