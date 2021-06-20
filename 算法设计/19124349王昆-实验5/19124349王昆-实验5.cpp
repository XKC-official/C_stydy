/*************************************************************
��дʱ�䣺2021-5-10
����汾��V1.0
�����ߣ�����

�����ܣ����ڷ��η����㷨ʵ�ֹ�������������
�������ݣ��û����������������
����������Ļ��ʾ�������ݴ����Ľ��
****************************************************************/
#include <iostream>
using namespace std;

#define MAXCODELEN 100		//���������鳤��
#define MAXHAFF 100			//���ڵ�ṹ���������
#define MAXCODE 100			//������ṹ������ĸ���
#define MAXWEIGHT  10000;	//���Ȩֵ

//�ڵ�ṹ��
typedef struct Huffman {
	int weight;		//Ȩ��
	char ch;		//�ַ�
	int parent;		
	int leftChild;	
	int rightChild;	
}HuffmanNode;

//������ṹ��
typedef struct Code {
	int code[MAXCODELEN];	//�ַ��Ĺ���������Ĵ洢
	int start;				//���ĸ�λ�ÿ�ʼ
}HuffmanCode;

HuffmanNode huffman[MAXHAFF];
HuffmanCode code[MAXCODE];


//����Huffman��
//�����ַ���ch_num
//��������õ�Huffman��
void createHuffman(int ch_num) {
	//��ʼ��
	for (int i = 0; i < ch_num * 2 - 1; ++i) {
		huffman[i].weight = 0;
		huffman[i].parent = -1;
		huffman[i].leftChild = -1;
		huffman[i].rightChild = -1;
	}

	cout << "����������" << ch_num << "����Ҫ������������ַ���";
	for (int i = 0; i < ch_num; i++) {
		cin >> huffman[i].ch;
	}
	cout << "����������" << ch_num << "���ַ���Ӧ�ĵ�Ȩֵ��";
	for (int i = 0; i < ch_num; i++) {
		cin >> huffman[i].weight;
	}

	//ÿ��ѭ���ҳ�Ȩֵ��С�������ڵ㣬�����µĸ��׽ڵ㡣����Ҫ ch_num - 1 �κϲ�
	int x1, x2, w1, w2;	//w1��w2�ֱ�Ϊ��С�������ڵ�
	for (int i = 0; i < ch_num - 1; ++i) {
		x1 = x2 = -1;
		w1 = w2 = MAXWEIGHT;		//��ʼ����С�ڵ�Ȩֵ
		for (int j = 0; j < ch_num + i; ++j) {
			if (huffman[j].parent == -1 && huffman[j].weight < w1) { //�ҵ��޸��ڵ㲢��Ȩֵ��С
				w2 = w1;
				x2 = x1;
				x1 = j;
				w1 = huffman[j].weight;
			}
			else if (huffman[j].parent == -1 && huffman[j].weight < w2) { //�ҵ��ڶ�С���޸��׽ڵ�
				x2 = j;
				w2 = huffman[j].weight;
			}
		}
		//�������ҵ�����СȨֵ�ڵ�ϲ���һ���µĸ��׽ڵ�
		huffman[ch_num + i].leftChild = x1;
		huffman[ch_num + i].rightChild = x2;
		huffman[ch_num + i].weight = w1 + w2;
		huffman[x1].parent = ch_num + i;
		huffman[x2].parent = ch_num + i;
	}
}

//��ӡ
//�����ַ���ch_num
//����ַ��Ͷ�Ӧ�ı���
void printCode(int ch_num) {
	HuffmanCode hCode;//���浱ǰҶ�ӽڵ���ַ�����
	int curParent;	//��ǰ���ڵ�
	int c;			//�±��Ҷ�ӽڵ�ı��
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
		//�ѵ�ǰ��Ҷ�ӽڵ���Ϣ���浽����ṹ����
		for (int j = hCode.start + 1; j < ch_num; ++j) {
			code[i].code[j] = hCode.code[j];
		}
		code[i].start = hCode.start;
	}
	cout << endl;
	for (int i = 0; i < ch_num; ++i) {
		cout << huffman[i].ch << " �ַ��Ĺ����������ǣ�";
		for (int j = code[i].start + 1; j < ch_num; ++j) {
			cout << code[i].code[j];
		}
		cout << endl;
	}
}
int main() {
	int ch_num = 0;
	cout << "������������ַ�������";		
	cin >> ch_num;
	if (ch_num <= 0) {
		cout << "������ĸ�������" << endl;
		return -1;
	}
	createHuffman(ch_num);
	printCode(ch_num);
	return 0;
}
