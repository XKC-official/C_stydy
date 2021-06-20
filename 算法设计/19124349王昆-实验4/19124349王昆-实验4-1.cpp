/*************************************************************
��дʱ�䣺2021-5-6
����汾��V1.0
�����ߣ�����

�����ܣ���ƻ��ڷ��η����㷨ʵ��2�������strassen���
�������ݣ��û����������������
����������Ļ��ʾ�������ݴ����Ľ��
****************************************************************/

#include <iostream>
using namespace std;

/*����˳���洢��������*/
class Matrix   //�������
{
public:
	int elem[8][8]; //�������˽�
	int len;//����Ľ���
	Matrix M_plus(Matrix b)//����ļӷ����㣬
	{
		Matrix c;
		if (len != b.len) { cout << "�������a��b������ͬ�������"; exit(0); }
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
	Matrix M_minus(Matrix b)//����ļ�������
	{
		Matrix c;
		if (len != b.len) { cout << "�������a��b������ͬ�������"; exit(0); }
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
	Matrix M_get(int n) {//����ȡ���Ͽ飬���Ͽ飬���¿飬���¿������
		Matrix c;
		int x, y;
		c.len = len / 2;

		if (n == 1)x = y = 0;
		else if (n == 2) { x = len / 2; y = 0; }
		else if (n == 3) { x = 0; y = len / 2; }
		else if (n == 4) { x = len / 2; y = len / 2; }
		else {
			cout << "����n����"; exit(0);
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
	void M_merge(Matrix a, Matrix b, Matrix c, Matrix d) {//���Ŀ����ϳ�һ����������
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
	void show() {//�����չʾ
		cout << "�˾������Ϊ" << len << endl;
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

void initial(Matrix* x) //����ĳ�ʼ��
{
	cout << "������������(������ҪΪ2�����η���";
	cin >> x->len;
	cout << "���������������";
	for (int i = 0; i < x->len; i++)
	{
		for (int j = 0; j < x->len; j++)
		{
			cin >> x->elem[i][j];
		}
	}
}
void M_calculation(Matrix a, Matrix b, Matrix* c) {  //һ����׾���ļ���
	c->elem[0][0] = a.elem[0][0] * b.elem[0][0] + a.elem[0][1] * b.elem[1][0];
	c->elem[0][1] = a.elem[0][0] * b.elem[0][1] + a.elem[0][1] * b.elem[1][1];
	c->elem[1][0] = a.elem[1][0] * b.elem[0][0] + a.elem[1][1] * b.elem[1][0];
	c->elem[1][1] = a.elem[1][0] * b.elem[0][1] + a.elem[1][1] * b.elem[1][1];
}
void strassen(int n, Matrix a, Matrix b, Matrix* c)//strassen�����������
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

/*����������*/
int main()
{
	//��������
	Matrix A, B, C;
	initial(&A);
	initial(&B);
	strassen(A.len, A, B, &C);
	cout << "�������ΪC";
	C.show();
	return 1;
	system("pause");
}

