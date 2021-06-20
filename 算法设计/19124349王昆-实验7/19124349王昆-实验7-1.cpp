/*************************************************************
编写时间：2021-5-19
程序版本：V1.0
开发者：王昆

程序功能：基于变治法的算法实现堆排序问题
输入数据：用户键盘随机输入数据
输出结果：屏幕显示输入数据处理后的结果
****************************************************************/

#include<stdio.h>
#include <iostream>
#include<iomanip>
using namespace std;

//输入数组，和数组内数据数目，继续运行的下标数
//返回排序后的数组
void SiftHeap(int r[], int k, int n) {
	int i, j, temp;
	i = k;
	j = 2 * i + 1;    
	while (j < n) {
		if (j < n - 1 && r[j] < r[j + 1])
			j++;
		if (r[i] > r[j])
			break;
		else {
			temp = r[i]; r[i] = r[j]; r[j] = temp;
			i = j; j = 2 * i + 1;
		}
	}
}
//输入数组，和数组内数据数目
//返回排序后的数组
void HeadSort(int r[], int n) {
	int i, temp;
	for (i = (n - 1) / 2; i >= 0; i--)
		SiftHeap(r, i, n);      //初建堆，最后一个分支的下标是(n-1)/2

	for (i = 1; i <= n - 1; i++) {      //重建堆
		temp = r[0]; r[0] = r[n - i]; r[n - i] = temp;
		SiftHeap(r, 0, n - i);
	}
}

int main() {
	int r[100];
	int num;
	cout << "输入数据的数目：";
	cin >> num;
	cout << "输入数据：";
	for (int i = 0; i < num; i++) {

		cin >> r[i];
	}
	HeadSort(r, num);
	for (int i = 0; i < num; i++)
		cout << r[i]<<" ";
	cout << endl;
	return 0;
}





