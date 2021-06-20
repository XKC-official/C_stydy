/*************************************************************
编写时间：2020-12-17
程序版本：V1.0
开发者：王昆

程序功能：实现链表的生成
输入数据：跟随菜单指引输入
输出结果：输出链表
****************************************************************/

/*头文件*/
#include<iostream>
#include<cstdlib>
using namespace std;

/*链表的顺序存储结构*/
typedef struct LinkList
{
	char data;   /*链表存储数据元素*/
	struct LinkList* next;  /*指向下一个节点的指针*/
}LNode, LinkList;

/*初始化链表*/
void initlist(LinkList* L)
{
	L = (LinkList*)malloc(sizeof(LNode));
	L->next = NULL;
}


// 建立单链表
//LinkList* L 待生成的数据表
//int n 输入数据的个数
//返回值，输入数据后生成的数据表
void CreateList(LinkList* L, int n)
{
	LNode* p;

	for (int i = n; i > 0; --i) {
		p = (LinkList*)malloc(sizeof(LNode));
		cin >> (&p->data);    // 输入元素值
		p->next = L->next;
		L->next = p;//插入
	}
} // CreateList_L

//打印链表
void print(LinkList* L)
{
	if (L == NULL)
	{
		return;
	}

	LNode* p = L->next;
	cout << "链表打印：";
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;  //换行
}


/*主函数定义*/
int main()
{
	//变量定义
	int n;
	cout << "请输入需要键入的元素的个数：";
	cin >> n;
	LinkList L;
	initlist(&L);//初始化
	CreateList(&L, n);
	print(&L);
	return 0;
}




