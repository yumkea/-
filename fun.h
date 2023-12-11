#ifndef _FUN_H_
#define _FUN_H_
#include <iostream>
#include <string>

using namespace std;
/*用户数据元素*/
typedef struct {
	string id;       // id
	int password ;	 //密码 
    int times;     //代取次数 
	string helpnum;
	string num ;//用户电话    
}user;

/*登录链表*/
typedef struct Node {
	user data;
	struct Node* next;
}Node, * LinkList;
//////////////////////////////////////////////////////////////
/*外卖信息元素*/
typedef struct {
	string id;       // id
	string phonenum ; //电话号码 
    int psword; 
	int sign;     //取件码 
}tkout;

/*外卖链表*/
typedef struct Node1 {
	tkout data1;  
	struct Node1* next1;
}Node1, * LinkList1;

///////////////////////////////////////////////////////////////
//函数声明列表
/////////////////////////////////////////////////////////////////
//函数声明列表
void Read_LinkList(LinkList& L);    				//读取账户信息函数 
void Init_LinkList(LinkList& L) ;   				//保存账户信息函数
void Create_LinkList(LinkList& L) ; 				//注册用户信息函数
void menu1(LinkList& L);           	 				//主控菜单
void menu2(LinkList& L);            				//功能菜单
int  Log( LinkList& L);             				//登录函数
void Modify_LinkList(LinkList& L);					//账户信息修改
void Save_LinkList(LinkList& L);  					//保存函数 
void Init_LinkList1(LinkList1& M);					//初始化外卖链表函数                        
void Read_LinkList1(LinkList1& M); 					//读取外卖信息函数                 
void help_take_information(LinkList& L);			//代取信息查看函数            
int  Line();                            			//读行函数                                                         
void Delete_LinkList(LinkList& L);					//注销 
void Query_LinkList1( LinkList1& M,LinkList& L);	//查询函数                  
void help_take_LinkList1( LinkList1& M,LinkList& L);//代取外卖                                       
void Print_LinkList1(LinkList1& M,LinkList& L);		//代取外卖展示 
void Save_LinkList1(LinkList1& M);					//保存外卖信息函数

 
 
 
LinkList L=NULL;
LinkList1 M=NULL;
#endif
