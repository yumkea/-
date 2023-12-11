#ifndef _FUNC_H_
#define _FUNC_H_

#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <windows.h>
#include "fun.h"

using namespace std;

/* 
��ȡ��Ϣ�鿴����
�˻���Ϣ�޸ĺ���
ע���û��˺ź���
���к���
��ȡ������Ϣ����
�ڶ��˵�
��ȡ�˻���Ϣ����
��ʼ��������
ע���û���Ϣ����
��¼����
��¼�˵�����
�����˻���Ϣ����

*/

//��ȡ��Ϣ�鿴����
void  help_take_information(LinkList& L){
    system("cls");
	cout << "\t***************��ȡ��Ϣ��ѯ****************" << endl;
	int sel = 0;
	Node* t = L;
	user tem;
	cout << "\n" << endl;

		int flag = 0;
		cout << "\t���������id��";
		cin >> tem.id;
		while (t->next)
		{
			t = t->next;
			if (t->data.id == tem.id)
			{
				int price,money;
				
				price=2;
				money=t->data.times*price; 
				system("cls"); 
				cout << "\t****************��ȡ��Ϣ���******************" << endl;
				cout<<"\n\n";
				cout << "\t----------------------------------------------" << endl;
	        	cout << "\t   ��ȡ��id: \t"<<t->data.id<<"\t\t"<<endl;
				cout << "\t----------------------------------------------" << endl;
	        	cout << "\t   ��ȡ����: \t"<<t->data.times<<"\t\t"<<endl;
				cout << "\t----------------------------------------------" << endl;
				cout << "\t   ��ȡ����: \t"<<price<<"\t\t"<<endl;
				cout << "\t----------------------------------------------" << endl;
				cout << "\t   ��ȡ����: \t"<<money<<"\t\t"<<endl;
				cout << "\t----------------------------------------------" << endl;
				system("pause");
				return;
				}

			}
		
		if (flag == 0) {
		
		cout << "\n\t\n";
		cout << "\tδ�ҵ���id�����ٴμ��id�Ƿ����"<< endl; 
		system("pause");
				
		}
		return;
}


/*�˻���Ϣ�޸ĺ���*/

void Modify_LinkList(LinkList& L)
{
	system("cls");
	cout << "\t **************�޸�ѧ����Ϣ****************" << endl;
	int sel = 0;
	Node* t = L;
	user tem;
	
	cout << "\t|------------------------------------------|" << endl;
	cout << "\t|           1        �޸�id                |" << endl;
	cout << "\t|------------------------------------------|" << endl;
	cout << "\t|           2       �޸�����               |" << endl;
	cout << "\t|------------------------------------------|" << endl;
	cout << "\t|           3       ע���˻�               |" << endl;
	cout << "\t|------------------------------------------|" << endl;
	cout << "\t|           0         ����                 |" << endl;
	cout << "\t|------------------------------------------|" << endl;
	
	cout << "\t��ѡ��0-3����";
	cin >> sel;
	while (sel < 0 || sel>3)
	{
		cout << "\t���벻�Ϸ�,���������롾0-3����";
		cin >> sel;
	}
	if (sel == 1)
	{
		int flag = 0;
		cout << "\t�����������޸ĵ�id��";
		cin >> tem.id;
		while (t->next)
		{
			t = t->next;
			if (t->data.id == tem.id)
			{ 
			    cout <<"\n"<<endl; 
				flag = 1;
				break;
			}
		}
		if (flag == 0) cout << "\t��ע����˻����޴�id���޷��޸ģ�" << endl;
		else
		{
			user tem1;
			cout << "\t����Ҫ�޸ĺ��id��";
			
			cin >> tem1.id;
		//	tem1.id=t->data.id;
			cout << "\tȷ���޸ģ���1 �� 0 ��" << endl;
			cout << "\t��ѡ��0-1����";
			cin >> sel;
			while (sel < 0 || sel>1)
			{
				cout << "\t���벻�Ϸ�,������ѡ��0-1����";
				cin >> sel;
			}
			if (sel == 0) cout<<"��ȡ��"<<endl; 
			else if (sel == 1)
			{
				t->data.id = tem1.id;
				cout << "\tid�޸ĳɹ���" << endl;
				Save_LinkList(L); //���Ķ��������ļ���
			}  
			
		}
		cout << "\n\t";
		system("pause");
		 
	}
	else if (sel == 2)
	{
		int flag = 0;
		cout << "\t����������id��";
		cin >> tem.id;
		while (t->next)
		{
			t = t->next;
			if (t->data.id == tem.id)
			{ 
			    cout <<"\t�������������룺"<<endl; 
			    cin>>tem.password ; 
			    if (t->data.password == tem.password) flag = 1;
			
				break;
			}
		}
		if (flag == 0) cout << "\t��ע����˻����޴�id���޷��޸ģ�" << endl;
		else
		{
			user tem;
			cout << "\t����Ҫ�޸ĺ�����룺" ;
			
			cin >> tem.password;
			
		//	tem.password=t->data.password;
			cout << "\tȷ���޸ģ���1 �� 0 ��" << endl;
			cout << "\t��ѡ��0-1����";
			cin >> sel;
			while (sel < 0 || sel>1)
			{
				cout << "\t���벻�Ϸ�,������ѡ��0-1����";
				cin >> sel;
			}
			if (sel == 0) cout<<"��ȡ��"<<endl;
			else if (sel == 1)
			{
				t->data.password = tem.password ;
				cout << "\t �����޸ĳɹ���" << endl;
			    Save_LinkList(L); //���Ķ��������ļ���
			}
		}
		cout << "\n\t";
		system("pause");
		
	}
	else if (sel == 3){
		
		Delete_LinkList(L);
				
	}else if (sel==0) return;
}



/*ע���û��˺ź���*/
void Delete_LinkList(LinkList& L)
{
	system("cls");
	cout << "\t **************ע���û��˺�****************" << endl;
	int sel=0,sut=0; 
	int flag = 0;
	Node* p = L, * t = NULL;
	user tem;
	cout << "\n" << endl;
	cout << "\t|------------------------------------------|" << endl;
	cout << "\t|           1        ��ʼע��              |" << endl;
	cout << "\t|------------------------------------------|" << endl;
	cout << "\t|           0        ��    ��              |" << endl;
	cout << "\t|------------------------------------------|" << endl;
	cout << "\t��ѡ��0 or 1����";
	cin>>sut;
    while (sut < 0 || sut>1)
	{
		cout << "\t���벻�Ϸ�,������ѡ��0 or 1����";
		cin >> sut;
	}
	switch (sut){
		
	    case 1:
	    	
		
		cout << "\t�������ɾ���˺ŵ�id��";
		cin >> tem.id;
		while (p->next)
		{
			t = p->next;
			if (t->data.id == tem.id)
			{
				cout <<"\t�������������룺"; 
			    cin>>tem.password ; 
			    if (t->data.password == tem.password) flag = 1;
				
				break;
			}
			p = p->next;
		}
		if (flag == 0) cout << "\t��������޷�ɾ�����������" << endl;
		else
		{
			cout << "\tȷ��ɾ������1 �� 0 ��" << endl;
			cout << "\t��ѡ��0 or 1����";
			cin >> sel;
			while (sel < 0 || sel>1)
			{
				cout << "\t���벻�Ϸ�,������ѡ��0 or 1����";
				cin >> sel;
			}
			if (sel == 0);
			else if (sel == 1)
			{
				p->next = t->next;
				delete t;
				cout << "\tɾ���ɹ���" << endl;
				Save_LinkList(L); //�Ķ��������ļ���				
			}
		}
		cout << "\n\t";
		system("pause");
		if(sel==1)	menu1(L);	
		break;
		
		case 0:
			
		return;
		break;
	}
}

//���к��� 
int Line(){
	ifstream infile("Line_number.txt", ios::in);
	int len = 0;
	infile >> len;
	infile.close();
	return len;
}



/*��ȡ������Ϣ����*/
void Read_LinkList1(LinkList1& M,int len)
{
	Node1* p = M;
	
	
	ifstream infile("Take_Out.txt", ios::in);	
	tkout tem;
	while (len--)
	{
		infile >> tem.id >> tem.phonenum >> tem.psword>>tem.sign;
	
		Node1* t = new Node1;
		t->data1 = tem;
		t->next1 = NULL;
		p->next1 = t;
		p = p->next1;
	}
	infile.close();
}


//�ڶ��˵� 
void menu2(LinkList& L)
{
	
	char sel;
	system("cls");
    Init_LinkList1(M);
    
	Read_LinkList1(M,Line());
	
	cout << "\t************��ӭ����������Ϣ�û���***********" << endl;
	cout << "\t���ѵ�¼"<<endl; 
	cout << "\t����������ѡ���ܵĴ���" << endl;
	cout << "\t|------------------------------------------|" << endl;
	cout << "\t|           1      �鿴�������            |" << endl;
	cout << "\t|------------------------------------------|" << endl;
	cout << "\t|           2      ��ȡ����                |" << endl;
	cout << "\t|------------------------------------------|" << endl;
	cout << "\t|           3      �鿴��ȡ����            |" << endl;
	cout << "\t|------------------------------------------|" << endl;
	cout << "\t|           4      �˻���Ϣ�޸�            |" << endl;
	cout << "\t|------------------------------------------|" << endl;
	cout << "\t|           0      �˳���¼                |" << endl;
	cout << "\t|------------------------------------------|" << endl;
	cout << "\t��ѡ��0-4����";
	cin >> sel;
	while (sel < '0' || sel>'4')
	{
		cout << "\t����Ƿ�,������ѡ��0-4����";
		cin >> sel;
	}
	switch (sel)
	{
	case '1':
		
		Query_LinkList1(M,L); 
		menu2(L);
		break;
		
		
	case '2':
		help_take_LinkList1(M,L);
		menu2(L);
		break;
		
	case '3':
		help_take_information(L);
		menu2(L);		
		break;
		
	case '4':
		Modify_LinkList(L);
		menu2(L);
		break;
		
	case '0':
		return ;
	default:
		menu2(L);

}
}

/*��ȡ�˻���Ϣ����*/
void Read_LinkList(LinkList& L)
{
	Node* p = L;
	ifstream infile("infomation.txt", ios::in);
	int len = 0;
	infile >> len;
	user tem;
	while (len--)
	{
		infile >> tem.id >> tem.password >> tem.times >> tem.helpnum >> tem.num;
		Node* t = new Node;
		t->data = tem;
		t->next = NULL;
		p->next = t;
		p = p->next;
	}
	infile.close();
}



/*�����˻���Ϣ����*/
void Save_LinkList(LinkList& L)
{
	Node* t = L, * cnt = L;
	ofstream outfile("infomation.txt", ios::out);
	int len = 0;
	while (cnt->next)
	{
		len++;
		cnt = cnt->next;
	}
	outfile << len << endl;
	while (t)
	{
		if (t != L)
			outfile << t->data.id << "\t" << t->data.password << "\t"<< t-> data.times<<"\t"<< t-> data.helpnum <<"\t"<<t->data.num<<endl;
		t = t->next;
	}
	outfile.close();
}

/*��ʼ��������*/
void Init_LinkList(LinkList& L)
{
	L = new Node;
	L->next = NULL;
}

/*ע���û���Ϣ����*/
void Create_LinkList(LinkList& L)
{
	system("cls");
	cout << "\t**************�û�ע��***************" << endl;
	Node* t = L;
	int i = 1, flag = 1;
	while (t->next)
	{
		i++;
		t = t->next;
	}
	
		Node* p = new Node;
		cout<<"\t���������id��"; 
		cin>>p-> data.id;
		cout << "\t������������룺";
		cin >> p->data.password;
		cout<<"\t��������ĵ绰���룺";
		cin >> p->data.num;
		p->data.times=0;
		p->data.helpnum='0';
		p->next = NULL;
		t->next = p;
		t = t->next;
		Save_LinkList(L); //���Ķ��������ļ���
		
}

/*��¼����*/
int Log(LinkList& L)
{
	system("cls");
	cout << "\t***************��¼****************" << endl;
	int sel = 0;
	Node* t = L;
	user tem;
	cout << "\t-----------------" << endl;

		int flag = 0;
		cout << "\t���������id��";
		cin >> tem.id;
		while (t->next)
		{
			t = t->next;
			if (t->data.id == tem.id)
			{
				
				int tem1;
				int tem= t->data.password;
				cout<<"\t������������룺";
				cin>> tem1;
				if(tem1==tem){
					cout<<"\t��¼�ɹ���"<<endl; 
					cout << "\t "; 
					system("pause");
						flag = 1;
				        break;
				} else { 
				flag = 1;
				cout<<"\t�������!"<<endl;
				cout << "\t "; 
				system("pause");
				return 0;
				}
			
			}
		}
		if (flag == 0) {
		
		cout << "\n\t\n";
		cout << "\t��ע����ٵ�¼"<< endl; 
		cout << "\t "; 
		system("pause");
				
		}
		return flag;
		
	}


/*��¼�˵�����*/
void menu1(LinkList& L)
{
	char sel;
	system("cls");
	cout << "\t************��ӭ����������Ϣ�û���**********" << endl;
	cout << "\t����������ѡ���ܵĴ���" << endl;
	cout << "\t|------------------------------------------|" << endl;
	cout << "\t|             1      �� ¼                 |" << endl;
	cout << "\t|------------------------------------------|" << endl;
	cout << "\t|             2      ע ��                 |" << endl;
	cout << "\t|------------------------------------------|" << endl;
	cout << "\t|             0      �� ��                 |" << endl;
	cout << "\t|------------------------------------------|" << endl;
	cout << "\t��ѡ��0-2����";
	cin >> sel;
	while (sel < '0' || sel>'2')
	{
		cout << "\t����Ƿ�,������ѡ��0-2����";
		cin >> sel;
	}
	switch (sel)
	{
	case '1':
		int t;
		t=Log(L);
		
		if (t==1) menu2(L);
		menu1(L);
		
		break;
	case '2':
		Create_LinkList(L);
		menu1(L);
		break;
	case '0':
		exit(0);
	default:
		menu1(L);
	}
} 


#endif




