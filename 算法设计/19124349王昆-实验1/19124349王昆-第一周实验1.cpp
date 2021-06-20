/*************************************************************
编写时间：2020-4-1
程序版本：V1.0
开发者：王昆

程序功能：先生成顺序表，确定它们中是否存在两个相等的元素
输入数据：跟随菜单指引输入
输出结果：判断结果
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


//判断函数
//L是顺序表的地址
//判断结果
int Sort(SqList& L) {
	int i, j;
	for (i = 0; i < L.length - 1; i++) {
		for (j = i + 1; j <= L.length - 1; j++) {
			if (L.r[i] == L.r[j])
				return 1;
		}
	}
	return 0;
}



/*主函数定义*/
int main()
{
	SqList L;
	initlist(&L);
	KeyboardInput(&L);
	if (Sort(L)) cout << "有两个相同结果";
	else cout << "没有两个相同结果";
	return 0;
}




