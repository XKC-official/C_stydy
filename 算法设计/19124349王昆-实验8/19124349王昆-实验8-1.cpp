/*************************************************************
编写时间：2021-5-26
程序版本：V1.0
开发者：王昆

程序功能：设计基于贪心法的算法实现活动安排问题
输入数据：用户键盘随机输入数据
输出结果：屏幕显示输入数据处理后的结果
****************************************************************/

#include <iostream>
#include<stdio.h>
using namespace std;


//创建结构体
void swap(int ar_a[], int a, int b)
{
	int temp = ar_a[a];
	ar_a[a] = ar_a[b];
	ar_a[b] = temp;
}


//冒泡排序
//输入数组，以及排序头尾
//输出排序后的数组
void bubble_sort(int ar_f[], int ar_s[], int left, int right)
{
	for (int i = left; i < right; i++){
		for (int j = left + 1; j <= right; j++){
			if (ar_f[j] < ar_f[j - 1]){
				swap(ar_s, j, j - 1);
				swap(ar_f, j, j - 1);
			}
		}
	}
}

//贪婪算法解决活动安排问题
//输入数组，以及数组长度
//输出安排结果
void  GreedySelect(int ar_s[], int ar_f[], bool ar_a[], int lenght_ar_s)
{
	int n = lenght_ar_s - 1;
	ar_a[1] = true;
	int j = 1, count = 1;
	cout << "1";
	for (int i = 2; i <= n; i++){
		if (ar_s[i] >= ar_f[j]){
			ar_a[i] = true;
			j = i;
			count++;
			cout << i << endl;
		}
		else{
			ar_a[i] = false;
		}
	}
	cout << "count=" << count << endl;
}

int main()
{	
	int ar_s[] = { 1,3,0,5,3,5,6,8,8,2,12 };
	int ar_f[] = { 4,5,6,7,8,9,10,11,12,13,14 };

	const int length_ar_f = sizeof(ar_f) / sizeof(ar_f[0]);
	const int length_ar_s = sizeof(ar_s) / sizeof(ar_s[0]);
	bool ar_a[length_ar_f] = {};
	bubble_sort(ar_f, ar_s, 1, length_ar_f - 1);
	GreedySelect(ar_s, ar_f, ar_a, length_ar_s);

	return 0;
}






