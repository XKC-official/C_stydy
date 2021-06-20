/*************************************************************
编写时间：2020-12-10
程序版本：V1.0
开发者：王昆

程序功能：实现线性表数据的生成，排序，插入
输入数据：跟随菜单指引输入
输出结果：输出指定处理后的顺序表
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

//插入
//SqList* L 待插入的数据表  ElemType x 待插入的数据
//返回值，插入数据的数据表
void Inselem(SqList* L, ElemType x)
{	
	if (L->length == MaxLen)
	{
		cout << " overflow!"; 
		exit(0);
	}
	int j = L->length;
	L->data[j] = x;       	              //插入x 
	L->length++;  		              //表长度加1 
}

//排序
//SqList* S 待排序的数据表
//返回值，排序后的数据表
void InsertSort(SqList* S)
{
	for (int i = 0; i < S->length - 1; i++)
	{
		for (int j = 0; j < S->length - i - 1; j++)
		{
			if (S->data[j] > S->data[j + 1])
				std::swap(S->data[j], S->data[j + 1]);
		}
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

//菜单
void menu()
{
	cout << "程序可以实现线性表的生成，排序和插入" << endl << "请输入命令:" << endl << "0:再次查看菜单\n1：生成顺序表\n2：排序顺序表\n3：顺序表插入数据\n4：打印顺序表\n5：退出程序" << endl;
}

/*主函数定义*/
int main()
{
	//变量定义
	int i = 0;
	ElemType e;
	SqList S;
	initlist(&S);//初始化
	while (i != 5)
	{
		switch (i)//根据输入值，执行功能
		{
		case 0:menu(); break;//菜单
		case 1:KeyboardInput(&S); break;//生成
		case 2:InsertSort(&S); break;//排序
		case 3:
			cout << "请输入需要插入的元素：";
			cin>>e;
			Inselem(&S, e);//插入
			InsertSort(&S);//排序
			break;
		case 4:display(S); break;//显示
		default:cout<<"不存在该功能选项！\n"; break;
		}
		cin >> i;
	}
	cout << "感谢您的使用！\n";
	return 0;
}




