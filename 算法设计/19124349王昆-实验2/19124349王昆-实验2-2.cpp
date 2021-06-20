/*************************************************************
编写时间：2020-4-12
程序版本：V1.0
开发者：王昆

程序功能：手动输入点集，计算并给出最近点对和距离
输入数据：跟随菜单指引输入
输出结果：最近点对和距离
****************************************************************/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<math.h>
#define MaxNumber 100 //点的最大数量
using namespace std;

//计算最短距离的平方
//x[],  y[]是存放点集，x和y坐标的数组，n为点的个数
//返回(输出)最近两点的坐标，以及距离的平方
void closestPoints(double x[], double y[], int n) {  
	double x1, x2, y1, y2;                     
	double distance, min = 999999;   //手动给出最大距离的平方
	for (int i = 0; i<n; i++)
		for (int j = i + 1; j<n; j++) {
			distance = (x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]);     //计算距离
			if (distance<min) {
				min = distance;      //比较
				x1 = x[i]; y1 = y[i];
				x2 = x[j]; y2 = y[j];
			}
		}
	cout << "最近点对为：(" << x1 << "," << y1 << ") (" << x2 << "," << y2 << ")"<<endl;    //输出坐标
	cout << "其距离为：" << sqrt(min);    //输最短距离
}



//创建点集：键盘输入数据
// x[],  y[], 即将存放点集，x和y坐标的数组
//返回值，生成的数组和点的个数
int creat(double x[], double y[]) {   
	int n;
	cout << "输入点的个数：\n";
	cin >> n;
	cout << "输入点的坐标：\n";
	for (int i = 1; i <= n; i++) {
		cout << "点" << i << "坐标为";
		cin >> x[i] >> y[i];
	}
	return n;
}

int main() {
	double x[MaxNumber], y[MaxNumber];
	int n;
	n=creat(x, y);
	closestPoints(x, y, n);
	return 0;
}
