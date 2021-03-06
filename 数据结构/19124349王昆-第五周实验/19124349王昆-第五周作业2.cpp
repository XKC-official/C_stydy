/*************************************************************
编写时间：2020-12-31
程序版本：V1.0
开发者：王昆

程序功能：利用链式栈结构，实现判定该字符串是否为回文
输入数据：跟随菜单指引输入
输出结果：输出判断结果
****************************************************************/

/*头文件*/
#include<iostream>
#include<cstdlib>
using namespace std;
typedef char ElemType;

/*链式栈存储结构*/
typedef struct SNode
{
	ElemType data;   /*链表存储数据元素*/
	struct SNode* next;  /*指向下一个节点的指针*/
}LinkSTACK;

/*初始化*/
void InitStack(LinkSTACK** top)
{
	*top = (LinkSTACK*)malloc(sizeof(LinkSTACK));
	(*top)->next = NULL;
}

// 入栈：键盘输入数据
//LinkSTACK** top 待加入数据的栈，ElemType x 待加入的数据
//返回值，输入数据后生成的栈
int Push(LinkSTACK** top, ElemType x)
{
	LinkSTACK* s;
	s = (LinkSTACK*)malloc(sizeof(LinkSTACK));
	s->data = x;
	s->next = (*top)->next;
	(*top)->next = s;
	return 1;
}

//判断为空
int Empty(LinkSTACK** top)
{
	return ((*top)->next == NULL ? 1 : 0);
}


//出栈
//LinkSTACK** top 待取出数据的栈，ElemType *x 取出数据的指针
//返回值，取出元素的数据，和栈
int Pop(LinkSTACK** top, ElemType* x)
{
	LinkSTACK* s;
	if (Empty(top)) {
		cout << "stack is free!";
		return 0;
	}
	s = (*top)->next;
	*x = s->data;
	(*top)->next = s->next;
	free(s);
	return 1;
}


//取栈顶元素
//LinkSTACK** top 待取出数据的栈
//返回值，取出元素的数据
int GetTop(LinkSTACK** top)
{
	if (Empty(top)) {
		cout << "stack is free!";
		return 0;
	}
	return (*top)->next->data;
}


/*主函数定义*/
int main()
{
	//变量定义
	int i, flag = 1;
	ElemType k;
	LinkSTACK *top;
	ElemType str[100];
	InitStack(&top);//初始化
	cout << "输入判断是否为回文的字符串：";
	cin >> str;
	int len = strlen(str);
	int mid = len / 2; //求字符串的中点
	for (i = 0; i < mid; i++)
	{
		Push(&top,str[i]);//入栈
	}

	if (len % 2 == 1)//判断奇偶
	{
		i += 1;
	}

	while (!Empty(&top))//判断回文
	{
		int temp = GetTop(&top);
		if (temp != str[i])//从中间开始向外比较
		{
			flag = 0;
			break;
		}
		else
		{
			i += 1;
			Pop(&top,&k);
		}
	}
	if (!flag)
	{
		cout << "字符串不是回文";
	}
	else
		cout << "字符串为回文";
	return 0;
}




