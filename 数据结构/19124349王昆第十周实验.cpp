/*************************************************************
编写时间：2020-3-11
程序版本：V1.0
开发者：王昆

程序功能：先生成顺序表，再进行快速排序或冒泡排序
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


//快速排序
//L是顺序表的地址
//返回排序后的顺序表
void Quick_Sort(int R[], int left, int right)
{
	if (left >= right)
		return;
	int i, j, base, temp;
	i = left, j = right;
	base = R[left];  //取最左边的数为基准数
	while (i < j)
	{
		while (R[j] >= base && i < j)
			j--;
		while (R[i] <= base && i < j)
			i++;
		if (i < j)
		{
			temp = R[i];
			R[i] = R[j];
			R[j] = temp;
		}
	}

	R[left] = R[i];
	R[i] = base;
	Quick_Sort(R,left, i - 1);//递归左边
	Quick_Sort(R,i + 1, right);//递归右边
}


//冒泡排序
//L是顺序表的地址
//返回排序后的顺序表
void BubbleSort(SqList& L){	
	int i, j, t, flag;
	for (i = 0; i <= L.length-2; i++){
		flag = 0;
		for (j = 0; j <= L.length-2 - i; j++)
			if (L.r[j] > L.r[j + 1]){
				t = L.r[j]; 
				L.r[j] = L.r[j + 1];
				L.r[j + 1] = t;
				flag = 1;
			}
		if (flag == 0) return;
	}
}

//菜单
void menu()
{
	cout << "请输入命令:" << endl << "0:再次查看菜单\n1：快速排序\n2：冒泡排序\n3：退出程序" << endl;
}


/*主函数定义*/
int main()
{
	int i = 0, left = 0, right;
	SqList L;
	initlist(&L);
	KeyboardInput(&L);
	right = L.length-1;
	int* R = L.r;
	while (i != 3) {
		switch (i)//根据输入值，执行功能
		{
		case 0:menu(); break;
		case 1:Quick_Sort(R,left,right); display(L); break;
		case 2:BubbleSort(L); display(L); break;
		}
		cin >> i;
	}
	return 0;
}




