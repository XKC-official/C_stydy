/*************************************************************
编写时间：2020-12-31
程序版本：V1.0
开发者：王昆

程序功能：实现顺序式队列的基本操作
输入数据：跟随菜单指引输入
输出结果：存储后的队列的前三个数据出队在屏幕显示
****************************************************************/
#include<iostream>
using namespace std;
#define MaxLen  100  
typedef int ElemType;

/*队列的顺序存储结构*/
typedef struct
{
	ElemType data[MaxLen];/*数组存储数据元素*/
	int front, rear;/*队列头，尾*/
}SQUEUE;


/*初始化*/
void initSqueue(SQUEUE* SQ)
{
	SQ->rear = SQ->front = 0;
}

//判断为空
int Empty(SQUEUE* SQ)
{
	return(SQ->rear == SQ->front) ? 1 : 0;
}


//入队：键盘输入数据
//SQUEUE* SQ 待加入数据的队列，ElemType x 待加入的数据
//返回值，输入数据后生成的栈
int EnQueue(SQUEUE* SQ, ElemType x)
{
	if ((SQ->rear + 1) % MaxLen == SQ->front)
	{
		cout << "Queue is full!";
		return 0;
	}
	SQ->rear = (SQ->rear + 1) % MaxLen;
	SQ->data[SQ->rear] = x;
	return 1;
}


//出队
//SQUEUE* SQ 待取出数据的队列，ElemType *x 取出数据的指针
//返回值，取出元素的数据
int OutQueue(SQUEUE* SQ, ElemType* x)
{
	if (Empty(SQ)) {
		cout << "Queue is free";
		return 0;
	}
	SQ->front = (SQ->front + 1) % MaxLen;
	*x = SQ->data[SQ->front];
	return 1;
}



/*主函数定义*/
int main()
{
	//变量定义
	int n, k;
	SQUEUE SQ;
	initSqueue(&SQ);//初始化
	cout << "请输入需要键入的元素的个数：";
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cout << "请输入第" << i << "个元素：";
		cin >> k;
		EnQueue(&SQ, k);//入队
	}
	for (int i = 1; i <= 3; i++)
	{
		OutQueue(&SQ, &k);//出队
		cout << k;
	}
	cout << endl;
	return 1;
}




