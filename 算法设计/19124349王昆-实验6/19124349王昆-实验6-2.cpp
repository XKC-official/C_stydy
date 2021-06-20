/*************************************************************
编写时间：2021-5-19
程序版本：V1.0
开发者：王昆

程序功能：基于分治法的算法实现八枚假币问题
输入数据：用户键盘随机输入数据
输出结果：屏幕显示输入数据处理后的结果
****************************************************************/

#include<iostream>
#include<cstdio>
#include<cctype>
#define MAXNUM 30
using namespace std;

//寻找假币位置
//输入值：硬币数组，寻找的起始位置
//输出值，假币位置
int Find_coins(int coin[], int low, int high) {
    int sum1, sum2, sum3;
    int fake_coins;
    sum1 = sum2 = sum3 = 0;
    if (low + 1 == high) {
        if (coin[low] < coin[high]) {
            fake_coins = low + 1;
            return fake_coins;
        }
        else {
            fake_coins = high + 1;
            return fake_coins;
        }
    }
    
    if ((high - low + 1) % 2 == 0) {
        for (int i = low; i <= low + (high - low) / 2; i++) {
            sum1 = sum1 + coin[i];
        }
        for (int i = low + (high - low) / 2 + 1; i <= high; i++) {
            sum2 = sum2 + coin[i];
        }

        if (sum1 > sum2) {
            fake_coins = Find_coins(coin, low + (high - low) / 2 + 1, high);
            return fake_coins;
        }
        else if (sum1 < sum2) {
            fake_coins = Find_coins(coin, low, low + (high - low) / 2);
            return fake_coins;
        }
        else {
        }
    }
    else {
        for (int i = low; i <= low + (high - low) / 2 - 1; i++) {
            sum1 = sum1 + coin[i];
        }
        for (int i = low + (high - low) / 2 + 1; i <= high; i++) {
            sum2 = sum2 + coin[i];
        }
        sum3 = coin[low + (high - low) / 2];
        if (sum1 > sum2) {
            fake_coins = Find_coins(coin, low + (high - low) / 2 + 1, high);
            return fake_coins;
        }
        else {
        }
        if (sum1 + sum3 == sum2 + sum3) {
            fake_coins = low + (high - low) / 2 + 1;
            return fake_coins;
        }
    }
}

int main() {
    int coin[MAXNUM];
    int i, n;
    int pos;
    cout << "请输入硬币总数目： ";
    cin >> n;
    cout << "请输入硬币的真假<真为5；假为4>：";
    for (i = 0; i < n; i++) {
        cin >> coin[i];
    }
    pos = Find_coins(coin, 0, n - 1);
    cout << "在上述" << n << " 个硬币中，第" << pos << "个硬币是假的" << endl;
    return 0;
}



