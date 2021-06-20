/*************************************************************
编写时间：2021-5-27
程序版本：V1.0
开发者：王昆

程序功能：设计基于动态规划的算法实现0-1背包问题
输入数据：用户键盘随机输入数据
输出结果：屏幕显示输入数据处理后的结果
****************************************************************/


#include <iostream>
#define MAX_NUM 5
#define MAX_WEIGHT 10
using namespace std;

//动态规划求解
//输入 total_weight 背包重量，w 物品重量，v 物品价值，flag 标记数组，n 物品数量
//输出求解结果
int zero_one_pack(int total_weight, int w[], int v[], int flag[], int n) {
	int c[MAX_NUM + 1][MAX_WEIGHT + 1] = { 0 }; 
												
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= total_weight; j++) {
			if (w[i] > j) {
				// 说明第i件物品大于背包的重量，放不进去
				c[i][j] = c[i - 1][j];
			}
			else {
				//说明第i件物品的重量小于背包的重量，所以可以选择第i件物品放还是不放
				if (c[i - 1][j] > v[i] + c[i - 1][j - w[i]]) {
					c[i][j] = c[i - 1][j];
				}
				else {
					c[i][j] = v[i] + c[i - 1][j - w[i]];
				}
			}
		}
	}

	//哪个物品应该放进背包
	int i = n, j = total_weight;
	while (c[i][j] != 0) {
		if (c[i - 1][j - w[i]] + v[i] == c[i][j]) {

			flag[i] = 1;
			j -= w[i];
		}--i;
	}
	return c[n][total_weight];
}


int main() {
	int gg;
	int total_weight = 10;
	int w[6] = { 0, 2, 2, 6, 5 ,4 };
	int v[6] = { 0, 6,3,5,4,6 };
	int flag[5]; //flag[i][j]表示在容量为j的时候是否将第i件物品放入背包
	int total_value = zero_one_pack(total_weight, w, v, flag, 5);
	cout << "需要放入的物品如下" << endl;
	for (int i = 1; i <= 5; i++) {
		if (flag[i] == 1)
			cout << i << "重量为" << w[i] << ", 价值为" << v[i] << endl;
	}
	cout << "总的价值为: " << total_value << endl;
	cin >> gg;
	return 0;
}
