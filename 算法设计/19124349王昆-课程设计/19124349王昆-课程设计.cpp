/*************************************************************
编写时间：2021-5-30
程序版本：V1.0
开发者：19124349 王昆

程序功能：在棋盘中实现从初始布局到目标布局的转变
输入数据：用户键盘随机输入数据
输出结果：屏幕显示输入数据处理后的结果
****************************************************************/

#include <iostream>
#include "stdio.h"
#include <cstdlib>
#include <cmath>
#include<process.h>
using namespace std;

//结构体定义
typedef struct Node
{
	struct Node* parent;
	double f, g;
	int num[9];
	Node* next;
}QNode, * Lnode;

//OPEN CLOSED 表结构体
typedef struct Stack
{
	Node* npoint;
	struct Stack* next;
}Stack, * Lstack;



//判断两个数组的逆序数奇偶性，从而判断问题是否可解
int cansolve(int num1[], int num2[])
{

	int i, j;
	int sum1 = 0, sum2 = 0;

	for (i = 0; i < 9; i++)
		for (j = 0; j < i; j++)
		{
			if (num1[j] > num1[i] && num1[i] != 0) ++sum1;
			if (num2[j] > num2[i] && num2[i] != 0) ++sum2;
		}

	if (sum1 % 2 == sum2 % 2) return 1;
	else return 0;
}



//数据输入函数
void input(int num[])
{
	int i = 0, j = 0, flag = 0;
	char c;
	while (i < 9)
	{
		while (((c = getchar()) != 10))
		{
			if (c == ' ')
			{
				if (flag >= 0)flag = 0;
			}
			else if (c >= '0' && c <= '8')
			{
				if (flag == 0)
				{
					num[i] = (c - '0');
					flag = 1;
					for (j = 0; j < i; j++)
						if (num[j] == num[i])flag = -2;
					i++;
				}
			}
			else if (flag >= 0)flag = -1;
		}
		if (flag < 0 || i < 9)
		{
			if (flag < 0)
			{
				if (flag == -1) cout<<"含有非法字符或数字!\n请重新输入:\n";
				else if (flag == -2) cout<<"输入的数字有重复!\n请重新输入:\n";
			}
			else if (i < 9) cout<<"输入的有效数字不够!\n请重新输入:\n";
			i = 0;
			flag = 0;
		}
	}
}

//上移
int move_up(int num[])
{
	int i;

	for (i = 0; i< 9; i++)
		if (num[i] == 0) break;

	if (i == 0 || i == 1 || i == 2)
		return 0;
	else
	{
		num[i] = num[i - 3];
		num[i - 3] = 0;
		return 1;
	}
}

//下移
int move_down(int num[])
{
	int i;

	for (i = 0; i < 9; i++)
		if (num[i] == 0) break;

	if (i == 6 || i == 7 || i == 8)
		return 0;
	else
	{
		num[i] = num[i + 3];
		num[i + 3] = 0;
		return 1;
	}
}

//左移
int move_left(int num[])
{
	int i;

	for (i = 0; i < 9; i++)
		if (num[i] == 0) break;

	if (i == 0 || i == 3 || i == 6)
		return 0;
	else
	{
		num[i] = num[i - 1];
		num[i - 1] = 0;
		return 1;
	}
}

//右移
int move_right(int num[])
{
	int i;

	for (i = 0; i < 9; i++)
		if (num[i] == 0) break;

	if (i == 2 || i == 5 || i == 8)
		return 0;
	else
	{
		num[i] = num[i + 1];
		num[i + 1] = 0;
		return 1;
	}
}

//将节点中的数组获取出来
//获取到temp
void get_num(QNode* node, int temp[])
{
	int i;
	for (i = 0; i < 9; i++)
	{
		temp[i] = node->num[i];
	}
}

//设置节点中数组的数据
//temp数据进入QNode
void set_num(QNode* node, int temp[])
{
	int i;
	for (i = 0; i < 9; i++)
		node->num[i] = temp[i];
}

//打印
void print(QNode* node)
{
	int i;
	for (i = 0; i < 9; i++)
	{
		cout << node->num[i]<<" ";
		if ((i + 1) % 3 == 0)
			cout << endl;
	}
}

//判断目标节点数据与目标数组数据是否相等
int isequal(QNode* node, int target[])
{
	int i;
	int flag = 1;
	for (i = 0; i < 9 && flag; i++)
	{
		if (node->num[i] != target[i])
			flag = 0;
	}

	return flag;
}

//退出
int exist(QNode* node, int temp[])
{
	QNode* p;

	for (p = node; p != NULL; p = p->parent)
		if (isequal(node, temp))
			return 1;

	return 0;
}


//选取OPEN表上f值最小的节点，返回该节点地址
Node* Minf(Lstack* Open)
{
	Lstack temp = (*Open)->next, min = (*Open)->next, minp = (*Open);
	Node* minx;

	while (temp->next != NULL)
	{
		if ((temp->next->npoint->f) < (min->npoint->f))
		{
			min = temp->next;
			minp = temp;
		}
		temp = temp->next;
	}
	minx = min->npoint;
	temp = minp->next;
	minp->next = minp->next->next;
	free(temp);
	return minx;
}


//判断节点是否相等
//输入两个节点
//返回相等<1>，不相等<0>
int Equal(Node* suc, Node* goal)
{
	for (int i = 0; i < 9; i++)
		if (suc->num[i] != goal->num[i])return 0;
	return 1;
}

//判断节点是否属于OPEN表或CLOSED表，是则返回节点地址，否则返回空地址
//输入节点地址<Node* suc>，表地址<Lstack* list>
Node* Belong(Node* suc, Lstack* list)
{
	Lstack temp = (*list)->next;
	if (temp == NULL)return NULL;
	while (temp != NULL)
	{
		if (Equal(suc, temp->npoint))return temp->npoint;
		temp = temp->next;
	}
	return NULL;
}

//把节点放入OPEN 或CLOSED 表中
//输入节点地址<Node* suc>，表地址<Lstack* list>
void Putinto(Node* suc, Lstack* list)
{
	Stack* temp;
	temp = (Stack*)malloc(sizeof(Stack));
	temp->npoint = suc;
	temp->next = (*list)->next;
	(*list)->next = temp;
}

//计算方格的错位距离
//输入初始节点<Node suc>和目标节点 <Node goal>,i节点数
double Distance(Node suc, Node goal, int i)
{
	int k, h1, h2;
	for (k = 0; k < 9; k++)
	{
		if (suc.num[k] == i)h1 = k;
		if (goal.num[k] == i)h2 = k;
	}
	return double(fabs(h1 / 3 - h2 / 3) + fabs(h1 % 3 - h2 % 3));
}

//计算f值
//输入初始节点<Node suc>和目标节点 <Node goal>,speed搜索速度
double Fvalue(Node suc, Node goal, float speed)
{
	double Distance(Node, Node, int);
	double h = 0;
	for (int i = 1; i <= 8; i++)
		h = h + Distance(suc, goal, i);
	return h * speed + suc.g; //(speed值增加时搜索过程以找到目标为优先因此可能不会返回最优解)                                       
}



//*******************扩展后继节点部分的函数-以下****************//

//判断子节点是否属于OPEN或CLOSED表并作出相应的处理
//输入节点地址<Lnode* suc>，表地址<Lstack* Open> <Lstack* Closed> 目标节点 <Node goal>,speed搜索速度
int BelongProgram(Lnode* suc, Lstack* Open, Lstack* Closed, Node goal, float speed)
{
	Node* temp = NULL;
	int flag = 0;
	if ((Belong(*suc, Open) != NULL) || (Belong(*suc, Closed) != NULL))
	{
		if (Belong(*suc, Open) != NULL) temp = Belong(*suc, Open);
		else temp = Belong(*suc, Closed);
		if (((*suc)->g) < (temp->g))
		{
			temp->parent = (*suc)->parent;
			temp->g = (*suc)->g;
			temp->f = (*suc)->f;
			flag = 1;
		}
	}
	else
	{
		Putinto(*suc, Open);
		(*suc)->f = Fvalue(**suc, goal, speed);
	}
	return flag;
}


//判断空格可否向该方向移动，表示空格向上向下向左向右移
//输入节点<node suc>, i节点数
int Canspread(Node suc, int n)
{
	int i, flag = 0;
	for (i = 0; i < 9; i++)
		if (suc.num[i] == 0)break;
	switch (n)
	{
	case 1:
		if (i / 3 != 0)flag = 1; break;
	case 2:
		if (i / 3 != 2)flag = 1; break;
	case 3:
		if (i % 3 != 0)flag = 1; break;
	case 4:
		if (i % 3 != 2)flag = 1; break;
	default:break;
	}
	return flag;
}


//扩展child节点的子节点
//n表示方向 , 表示空格向上向下向左向右移
void Spreadchild(Node* child, int n)
{
	int i, loc, temp;
	for (i = 0; i < 9; i++)
		child->num[i] = child->parent->num[i];
	for (i = 0; i < 9; i++)
		if (child->num[i] == 0)break;
	if (n == 0)
		loc = i % 3 + (i / 3 - 1) * 3;
	else if (n == 1)
		loc = i % 3 + (i / 3 + 1) * 3;
	else if (n == 2)
		loc = i % 3 - 1 + (i / 3) * 3;
	else
		loc = i % 3 + 1 + (i / 3) * 3;
	temp = child->num[loc];
	child->num[i] = temp;
	child->num[loc] = 0;
}


//扩展后继节点总函数
//输入节点地址<Lnode* suc>，表地址<Lstack* Open> <Lstack* Closed> 目标节点 <Node goal>,speed搜索速度
int Spread(Lnode* suc, Lstack* Open, Lstack* Closed, Node goal, float speed)
{
	int i;
	Node* child;

	for (i = 0; i < 4; i++)
	{
		if (Canspread(**suc, i + 1))                               //判断某个方向上的子节点可否扩展
		{
			child = (Node*)malloc(sizeof(Node));          //扩展子节点
			child->g = (*suc)->g + 1;                        //算子节点的g值
			child->parent = (*suc);                         //子节点父指针指向父节点
			Spreadchild(child, i);                          //向该方向移动空格生成子节点
			if (BelongProgram(&child, Open, Closed, goal, speed)) //	判断子节点是否属于OPEN或CLOSED表并作出相应的处理
				free(child);
		}
	}
	return 1;
}
//**********************扩展后继节点部分的函数-以上*****************************//


//总执行函数
//输入节点地址<Lnode* org>，表地址<Lstack* Open> <Lstack* Closed> 目标节点 <Lnode* goal>,speed搜索速度
Node* Process(Lnode* org, Lnode* goal, Lstack* Open, Lstack* Closed, float speed)
{
	while (1)
	{
		if ((*Open)->next == NULL)return NULL;                    //判断OPEN表是否为空，为空则失败退出
		Node* minf = Minf(Open);                                //从OPEN表中取出f值最小的节点
		Putinto(minf, Closed);                                   //将节点放入CLOSED表中
		if (Equal(minf, *goal))return minf;                       //如果当前节点是目标节点，则成功退出
		Spread(&minf, Open, Closed, **goal, speed);
		//当前节点不是目标节点时扩展当前节点的后继节点
	}
}

//启发式搜索
//初始表数组<init[9]>,目标表数组<target[9]>
void qf(int init[9], int target[9])
{
	Lstack Open = (Stack*)malloc(sizeof(Stack));
	Open->next = NULL;
	Lstack Closed = (Stack*)malloc(sizeof(Stack));
	Closed->next = NULL;
	Node* org = (Node*)malloc(sizeof(Node));
	Node* p;
	org->parent = NULL;                                        //初始状态节点

	org->f = 1;
	org->g = 1;
	int count = 0;
	Node* goal = (Node*)malloc(sizeof(Node));               //目标状态节点

	Node* result;
	set_num(org, init);
	set_num(goal, target);
	float speed = 1000;//speed搜索速度

	Putinto(org, &Open);
	result = Process(&org, &goal, &Open, &Closed, speed);  //进行剩余的操作print(result)
	for (p = result; p != NULL; p = p->parent)
	{
		print(p);
		cout<<"------\n";
		count++;
	}
	cout << "得出最优解共需" << count << "个节点\n";
	cout<<endl;
	cout<<"Press Enter key to exit!";

}



//广度优先搜索
//初始表数组<init[]>,目标表数组<target[]>
int bfs(int init[], int target[])
{

	int  temp[9];
	int find = 0;
	int step = 1, count = 1;

	QNode* front, * rear, * new_node, * p;

	if (!cansolve(init, target))
	{
		cout<<"不能实现\n";
		return 0;
	}

	front = (QNode*)malloc(sizeof(QNode));
	set_num(front, init);
	front->parent = NULL;
	front->next = NULL;
	rear = front;


	while (front != NULL && !find)
	{
		if (isequal(front, target))
		{
			find = 1;
			break;
		}

		get_num(front, temp);
		if (move_up(temp) && !exist(front, temp))
		{
			new_node = (QNode*)malloc(sizeof(QNode));
			set_num(new_node, temp);
			new_node->parent = front;
			new_node->next = NULL;
			rear->next = new_node;
			rear = new_node;
			step++;

		}
		get_num(front, temp);
		if (move_left(temp) && !exist(front, temp))
		{
			new_node = (QNode*)malloc(sizeof(QNode));
			set_num(new_node, temp);
			new_node->parent = front;
			new_node->next = NULL;
			rear->next = new_node;
			rear = new_node;
			step++;

		}
		get_num(front, temp);
		if (move_down(temp) && !exist(front, temp))
		{
			new_node = (QNode*)malloc(sizeof(QNode));
			set_num(new_node, temp);
			new_node->parent = front;
			new_node->next = NULL;
			rear->next = new_node;
			rear = new_node;
			step++;
		}
		get_num(front, temp);
		if (move_right(temp) && !exist(front, temp))
		{
			new_node = (QNode*)malloc(sizeof(QNode));
			set_num(new_node, temp);
			new_node->parent = front;
			new_node->next = NULL;
			rear->next = new_node;
			rear = new_node;
			step++;

		}   front = front->next;
		count++;

	}

	if (find)
	{
		count = 0;
		for (p = front; p != NULL; p = p->parent)
		{
			print(p);
			cout<<"------\n";
			count++;
		}
		cout<<"得出最优解共需"<<count<<"个节点\n";
	}
}


int main()
{
	int init[9], target[9];
	cout << "输入初始状态:" << endl;
	input(init);
	cout << "输入目标状态:" << endl;
	input(target);

	if (cansolve(init, target))
	{
		cout << "使用广度优先进行搜索:" << endl;
		bfs(init, target);

		cout << endl;

		cout << "使用启发式进行搜索:" << endl;
		qf(init, target);
	}
	else {
		cout << "无解" << endl;
	}

	return 0;
}
