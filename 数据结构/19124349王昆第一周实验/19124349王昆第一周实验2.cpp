/*************************************************************
编写时间：2020-12-3
程序版本：V1.0
开发者：王昆

程序功能：实现回文判断
输入数据：用户键盘随机输入一串字符
输出结果：屏幕显示输入是否为回文
****************************************************************/

/*引用头文件*/
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

/*主函数定义*/
int main()
{
     string str;
     cout << "请输入一段字符" ;
     cin >> str;
     int len = str.length();//字符长度
     const char* p = str.c_str();//生成字符串数组
     int n = 0;
     for (int i = 0; i < len / 2; i++)
     {
         if (p[i] == p[len - 1 - i])//判断对应位置的字符
         {
             continue;
         }
         else { n = 1; break; }//出现不对应回文规则的字符跳出循环，n赋值为1
     }
     if (n == 1) //根据n的值输出结果
        { cout << "False" << endl; }
     else 
        { cout << "True" << endl; }
 }