/*************************************************************
编写时间：2021-5-6
程序版本：V1.0
开发者：王昆

程序功能：设计基于分治法的算法实现n个参赛人员的循环赛程安排
输入数据：用户键盘随机输入数据
输出结果：屏幕显示输入数据处理后的结果
****************************************************************/
#include <iostream>
#include <algorithm>
using namespace std;
#define C 50  //数组最大范围

//区块计算
//输入选手数目，和数组
//输出计算结果
void merger(int n, int a[C][C])
{
	int m = n / 2;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
		{  //由左上角小块的值算出对应的右上角小块的值
			a[i][j + m] = a[i][j] + m;
			//由右上角小块的值算出对应的左下角小块的值
			a[i + m][j] = a[i][j + m];
			//由左上角小块的值算出对应的右下角小块的值
			a[i + m][j + m] = a[i][j];
		}
}

//递归得出结果
//输入选手数目，和数组
//输出计算结果的数组
void arrangement(int n, int a[C][C])
{
	if (n == 1) { a[0][0] = 1;  return; }
	arrangement(n / 2, a);
	merger(n, a);
}


int main()
{
	int N, i, j;
	cout << "输入选手数目（2的整次方倍）:";
	cin >> N;
	int a[C][C] = { 0 };
	arrangement(N, a);
	cout << N << "名运动员比赛日程安排表" << endl << endl;  //打印安排表
	cout << "选手" << "\t";
	for (i = 1; i <= N - 1; i++)
	{
		cout << "第" << i << "天" << "\t";
	}
	cout << endl;
	for (i = 0; i <= N-1; i++)
	{
		for (j = 0; j <= N-1; j++)
			cout << a[i][j] << "\t";
		cout << endl;
	}
	return 0;
}
