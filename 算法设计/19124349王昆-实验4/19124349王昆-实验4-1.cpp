/*************************************************************
编写时间：2021-5-6
程序版本：V1.0
开发者：王昆

程序功能：设计基于分治法的算法实现2个矩阵的strassen相乘
输入数据：用户键盘随机输入数据
输出结果：屏幕显示输入数据处理后的结果
****************************************************************/

#include <iostream>
using namespace std;

/*定义顺序表存储数据类型*/
class Matrix   //定义矩阵
{
public:
	int elem[8][8]; //矩阵最大八阶
	int len;//矩阵的阶数
	Matrix M_plus(Matrix b)//矩阵的加法运算，
	{
		Matrix c;
		if (len != b.len) { cout << "计算错误，a与b阶数不同不能相加"; exit(0); }
		else
		{
			for (int i = 0; i < len; i++)
			{
				for (int j = 0; j < len; j++)
				{
					c.elem[i][j] = elem[i][j] + b.elem[i][j];

				}
			}
			c.len = len;
			return c;
		}
	}
	Matrix M_minus(Matrix b)//矩阵的减法运算
	{
		Matrix c;
		if (len != b.len) { cout << "计算错误，a与b阶数不同不能相减"; exit(0); }
		else
		{
			for (int i = 0; i < len; i++)
			{
				for (int j = 0; j < len; j++)
				{
					c.elem[i][j] = elem[i][j] - b.elem[i][j];

				}
			}
			c.len = len;
			return c;
		}
	}
	Matrix M_get(int n) {//矩阵取左上块，右上块，左下块，右下块的运算
		Matrix c;
		int x, y;
		c.len = len / 2;

		if (n == 1)x = y = 0;
		else if (n == 2) { x = len / 2; y = 0; }
		else if (n == 3) { x = 0; y = len / 2; }
		else if (n == 4) { x = len / 2; y = len / 2; }
		else {
			cout << "输入n错误"; exit(0);
		}
		for (int i = 0; i < len / 2; i++)
		{
			for (int j = 0; j < len / 2; j++)
			{
				c.elem[i][j] = elem[i + x][j + y];

			}
		}
		return c;
	}
	void M_merge(Matrix a, Matrix b, Matrix c, Matrix d) {//由四块矩阵合成一块矩阵的运算
		len = a.len * 2;
		for (int i = 0; i < a.len; i++)
		{
			for (int j = 0; j < a.len; j++)
			{
				elem[i][j] = a.elem[i][j];
				elem[i + a.len][j] = b.elem[i][j];
				elem[i][j + a.len] = c.elem[i][j];
				elem[i + a.len][j + a.len] = d.elem[i][j];

			}
		}

	}
	void show() {//矩阵的展示
		cout << "此矩阵阶数为" << len << endl;
		for (int i = 0; i < len; i++)
		{
			for (int j = 0; j < len; j++)
			{
				cout << elem[i][j] << " ";
			}
			cout << endl;
		}
	}

};

void initial(Matrix* x) //矩阵的初始化
{
	cout << "请输入矩阵阶数(阶数需要为2的整次方倍";
	cin >> x->len;
	cout << "请输入矩阵内数字";
	for (int i = 0; i < x->len; i++)
	{
		for (int j = 0; j < x->len; j++)
		{
			cin >> x->elem[i][j];
		}
	}
}
void M_calculation(Matrix a, Matrix b, Matrix* c) {  //一般二阶矩阵的计算
	c->elem[0][0] = a.elem[0][0] * b.elem[0][0] + a.elem[0][1] * b.elem[1][0];
	c->elem[0][1] = a.elem[0][0] * b.elem[0][1] + a.elem[0][1] * b.elem[1][1];
	c->elem[1][0] = a.elem[1][0] * b.elem[0][0] + a.elem[1][1] * b.elem[1][0];
	c->elem[1][1] = a.elem[1][0] * b.elem[0][1] + a.elem[1][1] * b.elem[1][1];
}
void strassen(int n, Matrix a, Matrix b, Matrix* c)//strassen方法矩阵计算
{

	c->len = a.len;
	if (n == 2) M_calculation(a, b, c);
	else {
		Matrix m[8];
		strassen(n / 2, a.M_get(1), b.M_get(2).M_minus(b.M_get(4)), &m[1]);
		strassen(n / 2, a.M_get(1).M_plus(a.M_get(2)), b.M_get(4), &m[2]);
		strassen(n / 2, a.M_get(3).M_plus(a.M_get(4)), b.M_get(1), &m[3]);
		strassen(n / 2, a.M_get(4), b.M_get(3).M_minus(b.M_get(1)), &m[4]);
		strassen(n / 2, a.M_get(1).M_plus(a.M_get(4)), b.M_get(1).M_plus(b.M_get(4)), &m[5]);
		strassen(n / 2, a.M_get(3).M_minus(a.M_get(4)), b.M_get(3).M_plus(b.M_get(4)), &m[6]);
		strassen(n / 2, a.M_get(1).M_minus(a.M_get(3)), b.M_get(1).M_plus(b.M_get(3)), &m[7]);
		Matrix q[4];
		q[0] = m[5].M_plus(m[4]).M_plus(m[6]).M_minus(m[2]);
		q[1] = m[1].M_plus(m[2]);
		q[2] = m[3].M_plus(m[4]);
		q[3] = m[5].M_plus(m[1]).M_minus(m[3]).M_minus(m[7]);
		c->M_merge(q[0], q[1], q[2], q[3]);
	}
}

/*主函数定义*/
int main()
{
	//变量定义
	Matrix A, B, C;
	initial(&A);
	initial(&B);
	strassen(A.len, A, B, &C);
	cout << "结果矩阵为C";
	C.show();
	return 1;
	system("pause");
}

