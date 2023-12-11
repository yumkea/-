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
保存外卖信息函数
初始化外卖链表函数
代取显示函数
查询外卖函数
代取请求
代取外卖
保存外卖信息函数
*/

/*初始化外卖链表函数*/
void Init_LinkList1(LinkList1& M)
{
	M = new Node1;
	M->next1 = NULL;
}



/*查询外卖函数*/
void Query_LinkList1( LinkList1& M,LinkList& L)
{
	system("cls");
	int flag=0;
	cout << "\t****************外卖信息查询******************" << endl;
	Node* t0 = L;
	Node1* t = M;
	tkout tem;
	cout << "\n" << endl;
	cout << "\t请输入你的id: ";
	cin >> tem.id;
	
	while (t->next1)
		{
			t = t->next1;
			if (t->data1.id == tem.id)
			{
				flag=1;
				
				
				cout << "\t****************查询外卖表格******************" << endl;
				cout<<"\n";
				cout << "\t----------------------------------------------" << endl;
	        	cout << "\t   姓    名: \t"<<t->data1.id<<endl;
				cout << "\t----------------------------------------------" << endl;
	        	cout << "\t   联系电话: \t"<<t->data1.phonenum<<endl;
				cout << "\t----------------------------------------------" << endl;
				cout << "\t   取 餐 码: \t"<<t->data1.psword<<endl;
				cout << "\t----------------------------------------------" << endl;
						
						
						
						
			while (t0->next)
							{
			t0 = t0->next;
			if (t0->data.id == tem.id)
			{
				string pp;
				pp='0';
				if(pp==t0->data.helpnum){
				
					cout<<"\t   电话号码：\t" <<t0->data.num<<endl;
					cout << "\t----------------------------------------------" << endl;
					cout<<"\t   代取信息：\t无代取人信息" <<endl;
					cout << "\t----------------------------------------------" << endl;
				} else {
					cout<<"\t   代取人id：\t" <<t0->data.helpnum<<endl;
					cout << "\t----------------------------------------------" << endl;
					
					
					int sit;
					cout<<"\n\n\n\t 请您确认代取人是否将外卖送达【0 否 or 1 是】:"; 
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
		if (flag == 0) cout << "\t您的外卖还没有送达，请耐心等待哦" << endl;
		cout << "\n\t";
		system("pause");
}


/*代取显示函数*/
void Print_LinkList1(LinkList1& M,LinkList& L)
{
	system("cls");
	int check=0;
	cout << "\t***************需要代取的外卖信息***************" << endl;
	Node1* t = M->next1;
	cout << "\t-----------------------------------------------------" << endl;
	cout << "\t id\t" << "电话\t" << endl;
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
		cout << "\t*****************需要代取的外卖信息******************" << endl;
		cout << "\t-----------------------------------------------------" << endl;
		cout << "\t*                                                   *" << endl; 
		cout << "\t*                暂无需要代取的外卖                 *" << endl; 
		cout << "\t*                                                   *" << endl; 
		cout << "\t-----------------------------------------------------" << endl;
		system("pause");
		return;
	}
	

	string temid;
	int a=0;
	int flagu=0;
	cout <<"\t请输入您想要帮助代取的人的id："; 
	cin>>temid;
	    t=M;
		while (t->next1)
		{   
			t=t->next1;
		if(t->data1.id==temid) {
		a=1;			
		cout<<"\t为防止外卖丢失，我们将登记您的信息后为您派单！";
		int aa=0;
		cout<<"请您确认是否代取【0 否 or 1 是】：";
		cin>>aa;
		if(aa==0) 
		{
			break; 
			return;}
		Node* l = L;
		Node* l0 = L;
		user tem;
		int flag = 0;
		cout << "\t请输入你的id：";
		cin >> tem.id;
		string temnum; 
	     
			
		while (l->next)
		{
			l = l->next;
			if (l->data.id == tem.id)
			{   flagu=1;
				cout<<"\t您的信息已成功登记！";
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
		
			cout << "\n\t" <<temid<<"的取餐码为：\t"<<t->data1.psword<<endl;
			cout<<"\t 请牢记此代取码 ！" ; 
			break;
				
			} 
				
		}	
}   
	

			
	}	
	if(a==0||flagu==0) {
	cout<<"\t查无此id,请检查后重试！";
	}
	system("pause");
}


/*代取请求*/ 
void Need_help(LinkList1& M){
	system("cls");
	int flag=0;
	cout << "\t*********************请求代取页面*******************" << endl;
	
	Node1* t = M;
	tkout tem;
	cout << "\n" << endl;
	cout << "\t请输入你请求代取的外卖取餐码: ";
	cin >> tem.psword;
	
	while (t->next1)
		{
			t = t->next1;
			if (t->data1.psword == tem.psword)
			{
				flag=1;
				
				
				cout << "\t************您将要取的外卖信息如下************" << endl;
				cout<<"\n";
				cout << "\t----------------------------------------------" << endl;
	        	cout << "\t   姓    名: \t"<<t->data1.id<<endl;
				cout << "\t----------------------------------------------" << endl;
	        	cout << "\t   联系电话: \t"<<t->data1.phonenum<<endl;
				cout << "\t----------------------------------------------" << endl;			
				int sel0=0;
				
				cout<<"\t请确认您是否需要代取【0 否 or 1 是】";
				cin>>sel0;
				 if(sel0){
				 	
				 	t->data1.sign =1;
				 	
				 	Save_LinkList1(M); 
				 	
				 	cout<<"\t您的代取请求已经发布，请耐心等待哦！";
				 	system("pause"); 
				 		}
				 	
					 return;
				     break;
			}
			
		}
		if (flag == 0) cout << "\t您的外卖还没有送达，请耐心等待哦" << endl;
		cout << "\n\t";
		system("pause");
}


//代取外卖
void help_take_LinkList1( LinkList1& M,LinkList& L){
	system("cls");
	
	cout << "\t****************外卖代取*****************\n" <<endl;
    cout << "\t请输入你所选择功能的代号" << endl;
	cout << "\t|------------------------------------------|" << endl;
	cout << "\t|           1   我需要代取服务             |" << endl;
	cout << "\t|------------------------------------------|" << endl;
	cout << "\t|           2   我想提供代取服务           |" << endl;
	cout << "\t|------------------------------------------|" << endl;
	cout << "\t|           0        返回                  |" << endl;
	cout << "\t|------------------------------------------|" << endl;
	int sel = 0;
	cout << "\t请选择【0~2】"; 
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



/*保存外卖信息函数*/
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















