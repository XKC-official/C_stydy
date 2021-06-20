/*************************************************************
编写时间：2021-1-5
程序版本：V1.0
开发者：王昆

程序功能：利用链式栈结构，软席车厢都被调整到硬席车厢之前
输入数据：跟随菜单指引输入
输出结果：输出改变后的栈
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
	if (Empty(top)) 
	{
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
	if (Empty(top))
	{
		cout << "stack is free!";
		return 0;
	}
	return (*top)->next->data;
}


/*主函数定义*/
int main()
{
	LinkSTACK* s;
	char lst[80];
	int i = 0, j = 0;
	InitStack(&s);
	cout << "请输入硬席(H)和软席车厢(S)序列：";
	cin >> lst;
	cout << lst << endl;
	while (lst[i])
	{
		if (lst[i] == 'S') //软席暂置
		{
			lst[j] = lst[i];
			j++;
		}
		else Push(&s, lst[i]);//硬席入栈
		i++;
	}
	while (lst[j])//剩下的（软席）入栈
	{
		Pop(&s, &lst[j]);
		j++;
	}
	cout << lst << endl;
	return 0;
}




