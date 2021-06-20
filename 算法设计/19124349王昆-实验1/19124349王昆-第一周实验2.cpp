/*************************************************************
编写时间：2020-4-1
程序版本：V1.0
开发者：王昆

程序功能：先生成顺序表，分成两个子集S1和S2，使得：每个新的集合中含有n/2个元素，且S1中的所有元素的和与S2中的所有元素的和的差最大。
输入数据：跟随菜单指引输入
输出结果：两个子集
****************************************************************/

#include<iostream>
#include<cstdlib>
using namespace std;
#define MaxLen  100 
typedef int ElemType;

/*线性表的顺序存储结构*/
typedef struct
{
	ElemType r[MaxLen];/*数组存储数据元素*/
	int length;/*线性表的当前长度*/
}SqList;

//初始化
void initlist(SqList* L)
{
	L->length = 0;
}

//创建顺序表：键盘输入数据
//SqList* S 待生成的数据表
//返回值，输入数据后生成的数据表
void KeyboardInput(SqList* L)
{
	int i, k, n;
	cout << "请输入需要键入的元素的个数：";
	cin >> n;
	L->length = n;
	for (i = 1; i <= n; i++)
	{
		cout << "请输入第" << i << "个元素：";
		cin >> k;
		L->r[i - 1] = k;
	}
}

//冒泡排序
//L是顺序表的地址
//返回排序后的顺序表
void BubbleSort(SqList& L) {
	int i, j, t, flag;
	for (i = 0; i <= L.length - 2; i++) {
		flag = 0;
		for (j = 0; j <= L.length - 2 - i; j++)
			if (L.r[j] > L.r[j + 1]) {
				t = L.r[j];
				L.r[j] = L.r[j + 1];
				L.r[j + 1] = t;
				flag = 1;
			}
		if (flag == 0) return;
	}
}


//分离算法
//L是顺序表的地址
//返回两个子集
void  divide(SqList& L) {
	int S1[MaxLen], S2[MaxLen],i;
	BubbleSort(L);//冒泡排序
	for (i = L.length / 2 ; i < L.length; i++) {
		S2[i - L.length / 2] = L.r[i];
	}
	for (i = 0; i < L.length / 2; i++) {
		S1[i] = L.r[i];
	}
	cout << "S1为";
	for (i = 0; i < L.length / 2; i++) {
		cout << S1[i];
	}
	cout << endl << "S2为";
	for (i = 0; i < L.length/2; i++) {
		cout << S2[i];
	}
	cout << endl;
}



/*主函数定义*/
int main()
{
	SqList L;
	initlist(&L);
	KeyboardInput(&L);
	divide(L);
	return 0;
}




