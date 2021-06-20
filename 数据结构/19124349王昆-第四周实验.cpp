/*************************************************************
编写时间：2020-12-16
程序版本：V1.0
开发者：王昆

程序功能：实现顺序栈的基本操作：入栈、出栈、栈初始化、读栈顶元素
输入数据：跟随菜单指引输入
输出结果：输出指定处理后的栈
****************************************************************/
#include<iostream>
using namespace std;
#define MaxLen  100  
typedef int ElemType;

/*栈的顺序存储结构*/
typedef struct
{
	ElemType data[MaxLen];/*数组存储数据元素*/
	int top;/*线性表的当前长度*/
}STACK;


/*初始化*/
void initStack(STACK* S)
{
	S->top = -1;
}


int Empty(STACK* S)
{
	return (S->top == -1 ? 1 : 0);
}



//入栈：键盘输入数据
//STACK* S 待压入数据的栈
//返回值，输入数据后生成的栈
int Push(STACK* S)
{
	int i, k, n;
	if (S->top == MaxLen - 1)
	{
		cout << " 栈已满!";
		return 0;
	}
	cout << "输入数n, 再输入n个元素，入栈：";
	cin >> n;
	cout << endl;
	for (i = 1; i <= n; i++)
	{
		cin >> k;
		S->top++;
		S->data[S->top] = k;
	}
	return 1;
}

//出栈
//STACK *S 待处理的栈, ElemType *x 待取出的数据的指针
//返回值，取出数据的栈和数据
int Pop(STACK *S, ElemType *x)
{
	if (Empty(S)) {
		cout << "栈为空!";
		return 0;
	}
	*x = S->data[S->top];
	S->top--;
	return 1;
}

//读栈顶元素
//STACK *S 待处理的栈, ElemType *x 待取出的数据的指针
//返回值，取出的数据
int GetTop(STACK* S, ElemType* x)
{
	if (Empty(S)) 
	{
		cout << "栈为空!";
		return 0;
	}
	*x = S->data[S->top];
	return 1;
}


//打印
void display(STACK S)
{
	int i;
	if (Empty(&S))
		cout << "栈为空!\n";
	else
	{
		cout << "栈中数据为：";
		for (i = 0; i <= S.top; i++)
			cout << S.data[i] << " ";
		putchar('\n');
	}
}


//菜单
void menu()
{
	cout << "***************************************\n";
	cout << "*       1：元素进栈                   *\n";
	cout << "*       2：元素出栈                   *\n";
	cout << "*       3：读栈顶元素                 *\n";
	cout << "*       4：打印栈中元素               *\n";
	cout << "*       5：退出程序                   *\n";
	cout << "***************************************\n";
}

/*主函数定义*/
int main()
{
	//变量定义
	int i = 0,t,x;
	STACK S;
	initStack(&S);//初始化
	while (i != 5)
	{
		
		switch (i)//根据输入值，执行功能
		{
		case 0:menu(); break;//菜单
		case 1:Push(&S); break;//入栈
		case 2:
			Pop(&S,&x); //出栈
			cout << x << endl;
			break;
		case 3:
			GetTop(&S,&x);//读栈顶元素
			cout << x << endl;
			break;
		case 4:display(S); break;//显示
		default:cout << "不存在该功能选项！\n"; break;
		}
		if (i != 0)
		{
			cout << "继续运行吗Y<1>/N<0>: ";
			cin >> t;
			if (t == 0) break;
		}
		cout << "请选择1-5: ";
		cin >> i;
		cout << endl;
	}
	cout << "感谢您的使用！\n";
	return 1;
}




