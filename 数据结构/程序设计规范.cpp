/*************************************************************
编写时间：2020-12-3
程序版本：V1.0
开发者：David Yu

程序功能：实现顺序存储的线性表数据的逆转存储，并输出至屏幕
输入数据：用户键盘随机输入任意5个数据
输出结果：屏幕显示输入数据逆转存储后的结果
****************************************************************/

/*引用头文件*/
#include <iostream>
using namespace std;

/*定义顺序表存储数据类型*/
typedef struct 
{
	int elem[100];
	int length;
}SeqLst;



/*子函数insert定义*/
	//功能说明：实现在链表中的指定位置POS插入值X
	//接口形参说明：
        //x---待插入数据；值传递
		//pos---插入位置；值传递
		//lnk_Head---待插入链表;地址传递               
	//返回值说明：返回值2个；
		//return语句返回执行状态;1---成功；0---无效；
		//形参lnk_Head返回结果到主函数的实参*/

int insert(int x, int pos, Lnode *lnk_Head)
{
	int j;//循环控制变量j定义
	Lnode *p, *S;//遍历指针P定义，新节点指针S定义
	p = lnk_Head->next; j = 1;//所有变量初始化
	while (p&&j < pos - 1) { p = p->next; ++j; }//循环遍历，找到插入位置
	if (!p || j > pos - 1)return 0;//未找到指定位置，返回无效0
	S = (LinkList)malloc(sizeof(Lnode));//新节点生成
	S->data = x;
	S->next = p->next;//新节点插入
	p->next = S;
	return 1;//成功插入，返回1
}



/*主函数定义*/
void main()
{
	//变量定义
	SeqLst m_SeqLst;//定义顺序表变量m_SeqLst
	int i;//定义循环变量i
	int temp;//定义逆转用的临时中间变量

	//初始化顺序表
	m_SeqLst.length=0;
	for (i=0;i<=4;i++)
	{
		cin>>m_SeqLst.elem[i];
		m_SeqLst.length++; 
	}

	//进行逆转操作
	for(i=0;i<=m_SeqLst.length /2;i++)
	{
		temp=m_SeqLst.elem[i] ;
		m_SeqLst.elem[i]=m_SeqLst.elem[m_SeqLst.length- i-1];
		m_SeqLst.elem[m_SeqLst.length- i-1]=temp;	
	}

	//输出逆转后顺序表
	for (i=0;i<=4;i++)
	{
		cout<<m_SeqLst.elem[i];		
	}
}

