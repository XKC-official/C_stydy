/*************************************************************
��дʱ�䣺2020-12-10
����汾��V1.0
�����ߣ�����

�����ܣ�ʵ�����Ա����ݵ����ɣ����򣬲���
�������ݣ�����˵�ָ������
�����������ָ��������˳���
****************************************************************/
#include<iostream>
using namespace std;
#define MaxLen  100  
typedef int ElemType;
          
/*���Ա��˳��洢�ṹ*/
typedef struct
{
	ElemType data[MaxLen];/*����洢����Ԫ��*/
	int length;/*���Ա�ĵ�ǰ����*/
}SqList;


/*��ʼ��˳���*/
void initlist(SqList* L)
{
	L->length = 0;
}


//����˳���������������
//SqList* S �����ɵ����ݱ�
//����ֵ���������ݺ����ɵ����ݱ�
void KeyboardInput(SqList* S)
{
	int i, k, n;
	cout<<"��������Ҫ�����Ԫ�صĸ�����";
	cin >> n;
	S->length = n;
	for (i = 1; i <= n; i++)
	{
		cout << "�������"<<i<<"��Ԫ�أ�";
		cin >> k;
		S->data[i - 1] = k;
	}
}

//����
//SqList* L ����������ݱ�  ElemType x �����������
//����ֵ���������ݵ����ݱ�
void Inselem(SqList* L, ElemType x)
{	
	if (L->length == MaxLen)
	{
		cout << " overflow!"; 
		exit(0);
	}
	int j = L->length;
	L->data[j] = x;       	              //����x 
	L->length++;  		              //���ȼ�1 
}

//����
//SqList* S ����������ݱ�
//����ֵ�����������ݱ�
void InsertSort(SqList* S)
{
	for (int i = 0; i < S->length - 1; i++)
	{
		for (int j = 0; j < S->length - i - 1; j++)
		{
			if (S->data[j] > S->data[j + 1])
				std::swap(S->data[j], S->data[j + 1]);
		}
	}
	
}


/*��ӡ˳���*/
void display(SqList S)
{
	int i;
	if (S.length == 0)
		cout<<"˳���Ϊ�գ�\n";
	else
	{
		cout << "˳���������Ϊ��";
		for (i = 0; i < S.length; i++)
			cout<< S.data[i]<<" ";
		putchar('\n');
	}
}

//�˵�
void menu()
{
	cout << "�������ʵ�����Ա�����ɣ�����Ͳ���" << endl << "����������:" << endl << "0:�ٴβ鿴�˵�\n1������˳���\n2������˳���\n3��˳����������\n4����ӡ˳���\n5���˳�����" << endl;
}

/*����������*/
int main()
{
	//��������
	int i = 0;
	ElemType e;
	SqList S;
	initlist(&S);//��ʼ��
	while (i != 5)
	{
		switch (i)//��������ֵ��ִ�й���
		{
		case 0:menu(); break;//�˵�
		case 1:KeyboardInput(&S); break;//����
		case 2:InsertSort(&S); break;//����
		case 3:
			cout << "��������Ҫ�����Ԫ�أ�";
			cin>>e;
			Inselem(&S, e);//����
			InsertSort(&S);//����
			break;
		case 4:display(S); break;//��ʾ
		default:cout<<"�����ڸù���ѡ�\n"; break;
		}
		cin >> i;
	}
	cout << "��л����ʹ�ã�\n";
	return 0;
}




