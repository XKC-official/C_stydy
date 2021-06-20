/*************************************************************
编写时间：2020-12-17
程序版本：V1.0
开发者：王昆

程序功能：实现线性表数据的生成，逆序
输入数据：跟随菜单指引输入
输出结果：输出逆序处理后的顺序表
****************************************************************/
#include<iostream>
using namespace std;
#define MaxLen  100  
typedef int ElemType;
          
/*线性表的顺序存储结构*/
typedef struct
{
	ElemType data[MaxLen];/*数组存储数据元素*/
	int length;/*线性表的当前长度*/
}SqList;


/*初始化顺序表*/
void initlist(SqList* L)
{
	L->length = 0;
}


//创建顺序表：键盘输入数据
//SqList* S 待生成的数据表
//返回值，输入数据后生成的数据表
void KeyboardInput(SqList* S)
{
	int i, k, n;
	cout<<"请输入需要键入的元素的个数：";
	cin >> n;
	S->length = n;
	for (i = 1; i <= n; i++)
	{
		cout << "请输入第"<<i<<"个元素：";
		cin >> k;
		S->data[i - 1] = k;
	}
}


//逆序顺序表
//SqList* S 待处理的数据表
//返回值，逆序后的数据表
void reverse(SqList* S)
{
	for (int i = 0, j = S->length - 1; i < S->length / 2; i++, j--)
	{
		int temp = S->data[i];
		S->data[i] = S->data[j];
		S->data[j] = temp;
	}
}

/*打印顺序表*/
void display(SqList S)
{
	int i;
	if (S.length == 0)
		cout<<"顺序表为空！\n";
	else
	{
		cout << "顺序表中数据为：";
		for (i = 0; i < S.length; i++)
			cout<< S.data[i]<<" ";
		putchar('\n');
	}
}


/*主函数定义*/
int main()
{
	//变量定义
	int i = 0;
	SqList S;
	initlist(&S);//初始化
	KeyboardInput(&S);
	reverse(&S);
	display(S);//显示
	return 0;
}




