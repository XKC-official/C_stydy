/*************************************************************
��дʱ�䣺2020-12-3
����汾��V1.0
�����ߣ�David Yu

�����ܣ�ʵ��˳��洢�����Ա����ݵ���ת�洢�����������Ļ
�������ݣ��û����������������5������
����������Ļ��ʾ����������ת�洢��Ľ��
****************************************************************/

/*����ͷ�ļ�*/
#include <iostream>
using namespace std;

/*����˳���洢��������*/
typedef struct 
{
	int elem[100];
	int length;
}SeqLst;



/*�Ӻ���insert����*/
	//����˵����ʵ���������е�ָ��λ��POS����ֵX
	//�ӿ��β�˵����
        //x---���������ݣ�ֵ����
		//pos---����λ�ã�ֵ����
		//lnk_Head---����������;��ַ����               
	//����ֵ˵��������ֵ2����
		//return��䷵��ִ��״̬;1---�ɹ���0---��Ч��
		//�β�lnk_Head���ؽ������������ʵ��*/

int insert(int x, int pos, Lnode *lnk_Head)
{
	int j;//ѭ�����Ʊ���j����
	Lnode *p, *S;//����ָ��P���壬�½ڵ�ָ��S����
	p = lnk_Head->next; j = 1;//���б�����ʼ��
	while (p&&j < pos - 1) { p = p->next; ++j; }//ѭ���������ҵ�����λ��
	if (!p || j > pos - 1)return 0;//δ�ҵ�ָ��λ�ã�������Ч0
	S = (LinkList)malloc(sizeof(Lnode));//�½ڵ�����
	S->data = x;
	S->next = p->next;//�½ڵ����
	p->next = S;
	return 1;//�ɹ����룬����1
}



/*����������*/
void main()
{
	//��������
	SeqLst m_SeqLst;//����˳������m_SeqLst
	int i;//����ѭ������i
	int temp;//������ת�õ���ʱ�м����

	//��ʼ��˳���
	m_SeqLst.length=0;
	for (i=0;i<=4;i++)
	{
		cin>>m_SeqLst.elem[i];
		m_SeqLst.length++; 
	}

	//������ת����
	for(i=0;i<=m_SeqLst.length /2;i++)
	{
		temp=m_SeqLst.elem[i] ;
		m_SeqLst.elem[i]=m_SeqLst.elem[m_SeqLst.length- i-1];
		m_SeqLst.elem[m_SeqLst.length- i-1]=temp;	
	}

	//�����ת��˳���
	for (i=0;i<=4;i++)
	{
		cout<<m_SeqLst.elem[i];		
	}
}

