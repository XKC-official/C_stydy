/*************************************************************
编写时间：2020-4-12
程序版本：V1.0
开发者：王昆

程序功能：先生成顺序表，再进行简单选择排序
输入数据：跟随菜单指引输入
输出结果：排序后的顺序表
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


/*打印顺序表*/
void display(SqList L)
{
	int i;
	if (L.length == 0)
		cout << "顺序表为空！\n";
	else
	{
		cout << "顺序表中数据为：";
		for (i = 0; i < L.length; i++)
			cout << L.r[i] << " ";
		cout << endl;
	}
}



//简单选择排序
//L是顺序表的地址
//返回排序后的顺序表
void SelectionSort(SqList &L)
{
	int i, j, k, t;
	for (i = 0; i < L.length-2; i++){
		k = i;
		for (j = i + 1; j <= L.length-1; j++) 
			if (L.r[j] < L.r[k])
				k = j;
		if (k != i) {
			t = L.r[i];
			L.r[i] = L.r[k];
			L.r[k] = t;
		}
	}
}


/*主函数定义*/
int main()
{
	SqList L;
	initlist(&L);
	KeyboardInput(&L);
	SelectionSort(L); 
	display(L); 
	return 0;
}




