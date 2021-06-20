/*************************************************************
编写时间：2020-12-31
程序版本：V1.0
开发者：王昆

程序功能：将输入的数据以链式队列方式存储，并将存储后的队列依次在屏幕打印输出
输入数据：跟随菜单指引输入
输出结果：输出队列
****************************************************************/

/*头文件*/
#include<iostream>
#include<cstdlib>
using namespace std;
typedef char ElemType;

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
int Empty(SQUEUE* LQ)
{
	return(LQ->front == LQ->rear ? 1 : 0);
}



//打印队列
void Display(SQUEUE* LQ)
{
	if (Empty(LQ)) {
		cout << "Queue is free";
	}

	else 
	{
		QTYPE *temp = NULL;
		while (temp != LQ->rear) {
			temp = LQ->front->next;
			cout << temp->data;
			LQ->front = temp;
		}
	}
}



/*主函数定义*/
int main()
{
	int n;
	ElemType k;
	SQUEUE LQ;
	InitQueue(&LQ);
	cout << "请输入需要键入的元素的个数：";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cout << "请输入第" << i << "个元素：";
		cin >> k;
		EnQueue(&LQ, k);//入队
	}
	Display(&LQ);//打印
	return 0;
}




