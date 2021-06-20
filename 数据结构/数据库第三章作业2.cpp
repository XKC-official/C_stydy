/*************************************************************
编写时间：2020-1-6
程序版本：V1.0
开发者：王昆

程序功能：判别读入的一个以‘@’为结束符的字符序列是否是“回文”
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
int STACKEmpty(LinkSTACK** top)
{
	return ((*top)->next == NULL ? 1 : 0);
}


//出栈
//LinkSTACK** top 待取出数据的栈，ElemType *x 取出数据的指针
//返回值，取出元素的数据，和栈
int Pop(LinkSTACK** top, ElemType* x)
{
	LinkSTACK* s;
	if (STACKEmpty(top))
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
	if (STACKEmpty(top))
	{
		cout << "stack is free!";
		return 0;
	}
	return (*top)->next->data;
}



//**************************************************************队列



/*链式队列存储结构*/
typedef struct QNode      //链队结点的类型 
{
	ElemType data;   /*链表存储数据元素*/
	struct QNode* next;  /*指向下一个节点的指针*/
}QTYPE;

typedef struct QPinter      //链队指针类型 
{
	QTYPE* front, * rear;
}SQUEUE;



/*初始化*/
void InitQueue(SQUEUE* LQ)
{
	QTYPE* p;
	p = (QTYPE*)malloc(sizeof(QTYPE));
	p->next = NULL;
	LQ->front = LQ->rear = p;
}


// 入队：键盘输入数据
//SQUEUE* LQ 待加入数据的队列，ElemType x 待加入的数据
//返回值，输入数据后生成的队列
int EnQueue(SQUEUE* LQ, ElemType x)
{
	QTYPE* s;
	s = (QTYPE*)malloc(sizeof(QTYPE));
	s->data = x;
	s->next = LQ->rear->next;
	LQ->rear->next = s;
	LQ->rear = s;
	return 1;
}


//判断为空
int SQUEUEEmpty(SQUEUE* LQ)
{
	return(LQ->front == LQ->rear ? 1 : 0);
}

int OutQueue(SQUEUE* LQ, ElemType* x)
{
	QTYPE* p;
	if (SQUEUEEmpty(LQ)) 
	{
		cout << "Queue is free";
		return 0;
	}
	p = LQ->front->next;
	*x = p->data;
	LQ->front->next = p->next;
	if (LQ->front->next == NULL)
		LQ->rear = LQ->front;
	free(p);
	return 1;
}

// 判断回文
//char* p用于判断的字符地址
//返回值，判断结果
int check(char* p)
{
	SQUEUE q;
	InitQueue(&q);
	LinkSTACK* s;
	InitStack(&s);
	ElemType e1, e2;
	while (*p == '@')//到@停止输入
	{
		Push(&s, *p);
		EnQueue(&q, *p);
		p++;
	}
	while (!STACKEmpty(&s))
	{
		Pop(&s, &e1);
		OutQueue(&q, &e2);
		if (e1 != e2) return 0;//利用栈和队列的特性进行数据比较
	}
	return 1;
}

/*主函数定义*/
int main()
{
	char p;
	cout << "请输入字符序列：";
	cin >> p;
	if ((check(&p))==1) cout << "是回文";
	else cout << "不是回文";
	return 0;
}




