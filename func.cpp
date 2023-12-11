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
代取信息查看函数
账户信息修改函数
注销用户账号函数
读行函数
读取外卖信息函数
第二菜单
读取账户信息函数
初始化链表函数
注册用户信息函数
登录函数
登录菜单函数
保存账户信息函数

*/

//代取信息查看函数
void  help_take_information(LinkList& L){
    system("cls");
	cout << "\t***************代取信息查询****************" << endl;
	int sel = 0;
	Node* t = L;
	user tem;
	cout << "\n" << endl;

		int flag = 0;
		cout << "\t请输入你的id：";
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
				cout << "\t****************代取信息表格******************" << endl;
				cout<<"\n\n";
				cout << "\t----------------------------------------------" << endl;
	        	cout << "\t   代取人id: \t"<<t->data.id<<"\t\t"<<endl;
				cout << "\t----------------------------------------------" << endl;
	        	cout << "\t   代取单数: \t"<<t->data.times<<"\t\t"<<endl;
				cout << "\t----------------------------------------------" << endl;
				cout << "\t   代取单价: \t"<<price<<"\t\t"<<endl;
				cout << "\t----------------------------------------------" << endl;
				cout << "\t   代取收益: \t"<<money<<"\t\t"<<endl;
				cout << "\t----------------------------------------------" << endl;
				system("pause");
				return;
				}

			}
		
		if (flag == 0) {
		
		cout << "\n\t\n";
		cout << "\t未找到该id，请再次检查id是否错误！"<< endl; 
		system("pause");
				
		}
		return;
}


/*账户信息修改函数*/

void Modify_LinkList(LinkList& L)
{
	system("cls");
	cout << "\t **************修改学生信息****************" << endl;
	int sel = 0;
	Node* t = L;
	user tem;
	
	cout << "\t|------------------------------------------|" << endl;
	cout << "\t|           1        修改id                |" << endl;
	cout << "\t|------------------------------------------|" << endl;
	cout << "\t|           2       修改密码               |" << endl;
	cout << "\t|------------------------------------------|" << endl;
	cout << "\t|           3       注销账户               |" << endl;
	cout << "\t|------------------------------------------|" << endl;
	cout << "\t|           0         返回                 |" << endl;
	cout << "\t|------------------------------------------|" << endl;
	
	cout << "\t请选择【0-3】：";
	cin >> sel;
	while (sel < 0 || sel>3)
	{
		cout << "\t输入不合法,请重新输入【0-3】：";
		cin >> sel;
	}
	if (sel == 1)
	{
		int flag = 0;
		cout << "\t请输入您想修改的id：";
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
		if (flag == 0) cout << "\t已注册的账户中无此id，无法修改！" << endl;
		else
		{
			user tem1;
			cout << "\t输入要修改后的id：";
			
			cin >> tem1.id;
		//	tem1.id=t->data.id;
			cout << "\t确认修改？（1 是 0 否）" << endl;
			cout << "\t请选择【0-1】：";
			cin >> sel;
			while (sel < 0 || sel>1)
			{
				cout << "\t输入不合法,请重新选择【0-1】：";
				cin >> sel;
			}
			if (sel == 0) cout<<"已取消"<<endl; 
			else if (sel == 1)
			{
				t->data.id = tem1.id;
				cout << "\tid修改成功！" << endl;
				Save_LinkList(L); //将改动保存至文件中
			}  
			
		}
		cout << "\n\t";
		system("pause");
		 
	}
	else if (sel == 2)
	{
		int flag = 0;
		cout << "\t请输入您的id：";
		cin >> tem.id;
		while (t->next)
		{
			t = t->next;
			if (t->data.id == tem.id)
			{ 
			    cout <<"\t请输入您的密码："<<endl; 
			    cin>>tem.password ; 
			    if (t->data.password == tem.password) flag = 1;
			
				break;
			}
		}
		if (flag == 0) cout << "\t已注册的账户中无此id，无法修改！" << endl;
		else
		{
			user tem;
			cout << "\t输入要修改后的密码：" ;
			
			cin >> tem.password;
			
		//	tem.password=t->data.password;
			cout << "\t确认修改？（1 是 0 否）" << endl;
			cout << "\t请选择【0-1】：";
			cin >> sel;
			while (sel < 0 || sel>1)
			{
				cout << "\t输入不合法,请重新选择【0-1】：";
				cin >> sel;
			}
			if (sel == 0) cout<<"已取消"<<endl;
			else if (sel == 1)
			{
				t->data.password = tem.password ;
				cout << "\t 密码修改成功！" << endl;
			    Save_LinkList(L); //将改动保存至文件中
			}
		}
		cout << "\n\t";
		system("pause");
		
	}
	else if (sel == 3){
		
		Delete_LinkList(L);
				
	}else if (sel==0) return;
}



/*注销用户账号函数*/
void Delete_LinkList(LinkList& L)
{
	system("cls");
	cout << "\t **************注销用户账号****************" << endl;
	int sel=0,sut=0; 
	int flag = 0;
	Node* p = L, * t = NULL;
	user tem;
	cout << "\n" << endl;
	cout << "\t|------------------------------------------|" << endl;
	cout << "\t|           1        开始注销              |" << endl;
	cout << "\t|------------------------------------------|" << endl;
	cout << "\t|           0        返    回              |" << endl;
	cout << "\t|------------------------------------------|" << endl;
	cout << "\t请选择【0 or 1】：";
	cin>>sut;
    while (sut < 0 || sut>1)
	{
		cout << "\t输入不合法,请重新选择【0 or 1】：";
		cin >> sut;
	}
	switch (sut){
		
	    case 1:
	    	
		
		cout << "\t请输入待删除账号的id：";
		cin >> tem.id;
		while (p->next)
		{
			t = p->next;
			if (t->data.id == tem.id)
			{
				cout <<"\t请输入您的密码："; 
			    cin>>tem.password ; 
			    if (t->data.password == tem.password) flag = 1;
				
				break;
			}
			p = p->next;
		}
		if (flag == 0) cout << "\t密码错误，无法删除！请检查后尝试" << endl;
		else
		{
			cout << "\t确认删除？（1 是 0 否）" << endl;
			cout << "\t请选择【0 or 1】：";
			cin >> sel;
			while (sel < 0 || sel>1)
			{
				cout << "\t输入不合法,请重新选择【0 or 1】：";
				cin >> sel;
			}
			if (sel == 0);
			else if (sel == 1)
			{
				p->next = t->next;
				delete t;
				cout << "\t删除成功！" << endl;
				Save_LinkList(L); //改动保存至文件中				
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

//读行函数 
int Line(){
	ifstream infile("Line_number.txt", ios::in);
	int len = 0;
	infile >> len;
	infile.close();
	return len;
}



/*读取外卖信息函数*/
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


//第二菜单 
void menu2(LinkList& L)
{
	
	char sel;
	system("cls");
    Init_LinkList1(M);
    
	Read_LinkList1(M,Line());
	
	cout << "\t************欢迎来到外卖信息用户端***********" << endl;
	cout << "\t您已登录"<<endl; 
	cout << "\t请输入你所选择功能的代号" << endl;
	cout << "\t|------------------------------------------|" << endl;
	cout << "\t|           1      查看外卖情况            |" << endl;
	cout << "\t|------------------------------------------|" << endl;
	cout << "\t|           2      代取外卖                |" << endl;
	cout << "\t|------------------------------------------|" << endl;
	cout << "\t|           3      查看代取单数            |" << endl;
	cout << "\t|------------------------------------------|" << endl;
	cout << "\t|           4      账户信息修改            |" << endl;
	cout << "\t|------------------------------------------|" << endl;
	cout << "\t|           0      退出登录                |" << endl;
	cout << "\t|------------------------------------------|" << endl;
	cout << "\t请选择【0-4】：";
	cin >> sel;
	while (sel < '0' || sel>'4')
	{
		cout << "\t输入非法,请重新选择【0-4】：";
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

/*读取账户信息函数*/
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



/*保存账户信息函数*/
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

/*初始化链表函数*/
void Init_LinkList(LinkList& L)
{
	L = new Node;
	L->next = NULL;
}

/*注册用户信息函数*/
void Create_LinkList(LinkList& L)
{
	system("cls");
	cout << "\t**************用户注册***************" << endl;
	Node* t = L;
	int i = 1, flag = 1;
	while (t->next)
	{
		i++;
		t = t->next;
	}
	
		Node* p = new Node;
		cout<<"\t请输入你的id："; 
		cin>>p-> data.id;
		cout << "\t请输入你的密码：";
		cin >> p->data.password;
		cout<<"\t请输入你的电话号码：";
		cin >> p->data.num;
		p->data.times=0;
		p->data.helpnum='0';
		p->next = NULL;
		t->next = p;
		t = t->next;
		Save_LinkList(L); //将改动保存至文件中
		
}

/*登录函数*/
int Log(LinkList& L)
{
	system("cls");
	cout << "\t***************登录****************" << endl;
	int sel = 0;
	Node* t = L;
	user tem;
	cout << "\t-----------------" << endl;

		int flag = 0;
		cout << "\t请输入你的id：";
		cin >> tem.id;
		while (t->next)
		{
			t = t->next;
			if (t->data.id == tem.id)
			{
				
				int tem1;
				int tem= t->data.password;
				cout<<"\t请输入你的密码：";
				cin>> tem1;
				if(tem1==tem){
					cout<<"\t登录成功！"<<endl; 
					cout << "\t "; 
					system("pause");
						flag = 1;
				        break;
				} else { 
				flag = 1;
				cout<<"\t密码错误!"<<endl;
				cout << "\t "; 
				system("pause");
				return 0;
				}
			
			}
		}
		if (flag == 0) {
		
		cout << "\n\t\n";
		cout << "\t请注册后再登录"<< endl; 
		cout << "\t "; 
		system("pause");
				
		}
		return flag;
		
	}


/*登录菜单函数*/
void menu1(LinkList& L)
{
	char sel;
	system("cls");
	cout << "\t************欢迎来到外卖信息用户端**********" << endl;
	cout << "\t请输入你所选择功能的代号" << endl;
	cout << "\t|------------------------------------------|" << endl;
	cout << "\t|             1      登 录                 |" << endl;
	cout << "\t|------------------------------------------|" << endl;
	cout << "\t|             2      注 册                 |" << endl;
	cout << "\t|------------------------------------------|" << endl;
	cout << "\t|             0      退 出                 |" << endl;
	cout << "\t|------------------------------------------|" << endl;
	cout << "\t请选择【0-2】：";
	cin >> sel;
	while (sel < '0' || sel>'2')
	{
		cout << "\t输入非法,请重新选择【0-2】：";
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




