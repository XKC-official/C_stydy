/*************************************************************
编写时间：2020-4-22
程序版本：V1.0
开发者：王昆

程序功能：先生成顺序表，再进行基于分治法的折半查找
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
		L->r[i] = k;
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



//基于分治法的折半查找
//a[]为数据数组,low high为查找区间范围，k为待查找值
//返回查找结果

int BinSearch(int a[],int low, int high,int k)
{
	int mid;
	if (low <= high)		
	{
		mid = (low + high) / 2;	
		if (a[mid] == k)		
			return mid;
		if (a[mid]>k)		
			return BinSearch(a,low,mid - 1,k);
		else			
			return BinSearch(a,mid + 1,high,k);
	}
	else return -1;		
}



/*主函数定义*/
int main()
{
	SqList L;
	int low, high;
	int e;
	initlist(&L);
	KeyboardInput(&L);

	high = L.length;
	low = 1;
	while(1){
		cout << "输入待查找的值";
		cin >> e;
		if (BinSearch(L.r, low, high, e) != -1)
			cout << "位置为" << BinSearch(L.r, low, high, e) << endl;
		else
			cout << "查找区间无此值" << endl;
	}
	return 0;
}




