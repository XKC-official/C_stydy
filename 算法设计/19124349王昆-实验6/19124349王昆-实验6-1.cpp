/*************************************************************
��дʱ�䣺2021-5-19
����汾��V1.0
�����ߣ�����

�����ܣ����ڷ��η����㷨ʵ��Լɪ��˹����
�������ݣ��û����������������
����������Ļ��ʾ�������ݴ����Ľ��
****************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

//suevior �������
//value ���ⱨ��ֵ
//n �ڼ�����̭ 
//����ysf���ص�n����̭���� 
int ysf(int survior, int value, int n) {
	if (n == 1)
		return (survior + value - 1) % survior;
	else
		return (ysf(survior - 1, value, n - 1) + value) % survior;

}

int main() {
	int sum, spe, lucky;
	cout<<"��������";
	cin >> sum;
	cout<<"�������֣�";
	cin >> spe;
	cout<<"Ҫ���ˣ�";
	cin >> lucky;
	cout<<"�Ҵ��ߣ�";
	for (int i = sum - lucky + 1; i <= sum; i++) {
		cout<<ysf(sum, spe, i) + 1 <<"�� ";
	}
	cout << endl;
	return 0;
}





