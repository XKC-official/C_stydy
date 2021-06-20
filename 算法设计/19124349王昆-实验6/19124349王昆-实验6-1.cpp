/*************************************************************
编写时间：2021-5-19
程序版本：V1.0
开发者：王昆

程序功能：基于分治法的算法实现约瑟夫斯问题
输入数据：用户键盘随机输入数据
输出结果：屏幕显示输入数据处理后的结果
****************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

//suevior 存活人数
//value 特殊报数值
//n 第几次淘汰 
//函数ysf返回第n次淘汰的人 
int ysf(int survior, int value, int n) {
	if (n == 1)
		return (survior + value - 1) % survior;
	else
		return (ysf(survior - 1, value, n - 1) + value) % survior;

}

int main() {
	int sum, spe, lucky;
	cout<<"总人数：";
	cin >> sum;
	cout<<"特殊数字：";
	cin >> spe;
	cout<<"要存活几人：";
	cin >> lucky;
	cout<<"幸存者：";
	for (int i = sum - lucky + 1; i <= sum; i++) {
		cout<<ysf(sum, spe, i) + 1 <<"号 ";
	}
	cout << endl;
	return 0;
}





