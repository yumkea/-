#ifndef _FUNC1_H_
#define _FUNC1_H_

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
����������Ϣ����
��ʼ������������
��ȡ��ʾ����
��ѯ��������
��ȡ����
��ȡ����
����������Ϣ����
*/

/*��ʼ������������*/
void Init_LinkList1(LinkList1& M)
{
	M = new Node1;
	M->next1 = NULL;
}



/*��ѯ��������*/
void Query_LinkList1( LinkList1& M,LinkList& L)
{
	system("cls");
	int flag=0;
	cout << "\t****************������Ϣ��ѯ******************" << endl;
	Node* t0 = L;
	Node1* t = M;
	tkout tem;
	cout << "\n" << endl;
	cout << "\t���������id: ";
	cin >> tem.id;
	
	while (t->next1)
		{
			t = t->next1;
			if (t->data1.id == tem.id)
			{
				flag=1;
				
				
				cout << "\t****************��ѯ�������******************" << endl;
				cout<<"\n";
				cout << "\t----------------------------------------------" << endl;
	        	cout << "\t   ��    ��: \t"<<t->data1.id<<endl;
				cout << "\t----------------------------------------------" << endl;
	        	cout << "\t   ��ϵ�绰: \t"<<t->data1.phonenum<<endl;
				cout << "\t----------------------------------------------" << endl;
				cout << "\t   ȡ �� ��: \t"<<t->data1.psword<<endl;
				cout << "\t----------------------------------------------" << endl;
						
						
						
						
			while (t0->next)
							{
			t0 = t0->next;
			if (t0->data.id == tem.id)
			{
				string pp;
				pp='0';
				if(pp==t0->data.helpnum){
				
					cout<<"\t   �绰���룺\t" <<t0->data.num<<endl;
					cout << "\t----------------------------------------------" << endl;
					cout<<"\t   ��ȡ��Ϣ��\t�޴�ȡ����Ϣ" <<endl;
					cout << "\t----------------------------------------------" << endl;
				} else {
					cout<<"\t   ��ȡ��id��\t" <<t0->data.helpnum<<endl;
					cout << "\t----------------------------------------------" << endl;
					
					
					int sit;
					cout<<"\n\n\n\t ����ȷ�ϴ�ȡ���Ƿ������ʹ0 �� or 1 �ǡ�:"; 
					cin>>sit;
					if (sit==0){
						system("pause");
						return; 
					}
					t0->data.helpnum='0';
					Save_LinkList(L);
					
				}
						
				break;
			}
						}
														
				break;
			}
		}
		if (flag == 0) cout << "\t����������û���ʹ�����ĵȴ�Ŷ" << endl;
		cout << "\n\t";
		system("pause");
}


/*��ȡ��ʾ����*/
void Print_LinkList1(LinkList1& M,LinkList& L)
{
	system("cls");
	int check=0;
	cout << "\t***************��Ҫ��ȡ��������Ϣ***************" << endl;
	Node1* t = M->next1;
	cout << "\t-----------------------------------------------------" << endl;
	cout << "\t id\t" << "�绰\t" << endl;
	cout << "\t-----------------------------------------------------" << endl;
	while (t)
	{   
	    if(t->data1.sign ==1) {
	    	cout << "\t" << t->data1.id << "\t" << t->data1.phonenum <<endl;
			check+=1;
		}
		
		t = t->next1;
	}
	cout << "\t-----------------------------------------------------" << endl;
	cout << "\n\n";
	
	if(check==0){
		
		system("cls");
		cout << "\t*****************��Ҫ��ȡ��������Ϣ******************" << endl;
		cout << "\t-----------------------------------------------------" << endl;
		cout << "\t*                                                   *" << endl; 
		cout << "\t*                ������Ҫ��ȡ������                 *" << endl; 
		cout << "\t*                                                   *" << endl; 
		cout << "\t-----------------------------------------------------" << endl;
		system("pause");
		return;
	}
	

	string temid;
	int a=0;
	int flagu=0;
	cout <<"\t����������Ҫ������ȡ���˵�id��"; 
	cin>>temid;
	    t=M;
		while (t->next1)
		{   
			t=t->next1;
		if(t->data1.id==temid) {
		a=1;			
		cout<<"\tΪ��ֹ������ʧ�����ǽ��Ǽ�������Ϣ��Ϊ���ɵ���";
		int aa=0;
		cout<<"����ȷ���Ƿ��ȡ��0 �� or 1 �ǡ���";
		cin>>aa;
		if(aa==0) 
		{
			break; 
			return;}
		Node* l = L;
		Node* l0 = L;
		user tem;
		int flag = 0;
		cout << "\t���������id��";
		cin >> tem.id;
		string temnum; 
	     
			
		while (l->next)
		{
			l = l->next;
			if (l->data.id == tem.id)
			{   flagu=1;
				cout<<"\t������Ϣ�ѳɹ��Ǽǣ�";
				temnum=l->data.num;
			  
			    
			    
			    
		 		Node* l0=L->next;
			    user tem0;
			    
			    while (l0){
			    	
			    	if (l0->data.id==temid){
			    		
			    		l0->data.helpnum=temnum;
			    		
			    		break;
					}
					l0=l0->next;
				}
				Save_LinkList(L);
			
			
			l->data.times=l->data.times+1;
		
			cout << "\n\t" <<temid<<"��ȡ����Ϊ��\t"<<t->data1.psword<<endl;
			cout<<"\t ���μǴ˴�ȡ�� ��" ; 
			break;
				
			} 
				
		}	
}   
	

			
	}	
	if(a==0||flagu==0) {
	cout<<"\t���޴�id,��������ԣ�";
	}
	system("pause");
}


/*��ȡ����*/ 
void Need_help(LinkList1& M){
	system("cls");
	int flag=0;
	cout << "\t*********************�����ȡҳ��*******************" << endl;
	
	Node1* t = M;
	tkout tem;
	cout << "\n" << endl;
	cout << "\t�������������ȡ������ȡ����: ";
	cin >> tem.psword;
	
	while (t->next1)
		{
			t = t->next1;
			if (t->data1.psword == tem.psword)
			{
				flag=1;
				
				
				cout << "\t************����Ҫȡ��������Ϣ����************" << endl;
				cout<<"\n";
				cout << "\t----------------------------------------------" << endl;
	        	cout << "\t   ��    ��: \t"<<t->data1.id<<endl;
				cout << "\t----------------------------------------------" << endl;
	        	cout << "\t   ��ϵ�绰: \t"<<t->data1.phonenum<<endl;
				cout << "\t----------------------------------------------" << endl;			
				int sel0=0;
				
				cout<<"\t��ȷ�����Ƿ���Ҫ��ȡ��0 �� or 1 �ǡ�";
				cin>>sel0;
				 if(sel0){
				 	
				 	t->data1.sign =1;
				 	
				 	Save_LinkList1(M); 
				 	
				 	cout<<"\t���Ĵ�ȡ�����Ѿ������������ĵȴ�Ŷ��";
				 	system("pause"); 
				 		}
				 	
					 return;
				     break;
			}
			
		}
		if (flag == 0) cout << "\t����������û���ʹ�����ĵȴ�Ŷ" << endl;
		cout << "\n\t";
		system("pause");
}


//��ȡ����
void help_take_LinkList1( LinkList1& M,LinkList& L){
	system("cls");
	
	cout << "\t****************������ȡ*****************\n" <<endl;
    cout << "\t����������ѡ���ܵĴ���" << endl;
	cout << "\t|------------------------------------------|" << endl;
	cout << "\t|           1   ����Ҫ��ȡ����             |" << endl;
	cout << "\t|------------------------------------------|" << endl;
	cout << "\t|           2   �����ṩ��ȡ����           |" << endl;
	cout << "\t|------------------------------------------|" << endl;
	cout << "\t|           0        ����                  |" << endl;
	cout << "\t|------------------------------------------|" << endl;
	int sel = 0;
	cout << "\t��ѡ��0~2��"; 
	cin >> sel; 
	switch (sel)
	{
	case 1:		
          Need_help(M);
		  break;
	case 2:
		Print_LinkList1(M,L); 	
		break;
    case 0:
    	return;
    	break;
	}
	
	
}



/*����������Ϣ����*/
void Save_LinkList1(LinkList1& M)
{
	Node1* t = M; //* cnt = M;
	ofstream outfile("Take_Out.txt", ios::out);
	int len ;
	len=Line();	
	while (t)
	{
		if (t != M)
			outfile << t->data1.id << "\t" << t->data1.phonenum << "\t"<< t-> data1.psword<<"\t"<<t->data1.sign <<endl;
		t = t->next1;
	}
	outfile.close();
}


#endif















