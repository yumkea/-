#ifndef _FUN_H_
#define _FUN_H_
#include <iostream>
#include <string>

using namespace std;
/*�û�����Ԫ��*/
typedef struct {
	string id;       // id
	int password ;	 //���� 
    int times;     //��ȡ���� 
	string helpnum;
	string num ;//�û��绰    
}user;

/*��¼����*/
typedef struct Node {
	user data;
	struct Node* next;
}Node, * LinkList;
//////////////////////////////////////////////////////////////
/*������ϢԪ��*/
typedef struct {
	string id;       // id
	string phonenum ; //�绰���� 
    int psword; 
	int sign;     //ȡ���� 
}tkout;

/*��������*/
typedef struct Node1 {
	tkout data1;  
	struct Node1* next1;
}Node1, * LinkList1;

///////////////////////////////////////////////////////////////
//���������б�
/////////////////////////////////////////////////////////////////
//���������б�
void Read_LinkList(LinkList& L);    				//��ȡ�˻���Ϣ���� 
void Init_LinkList(LinkList& L) ;   				//�����˻���Ϣ����
void Create_LinkList(LinkList& L) ; 				//ע���û���Ϣ����
void menu1(LinkList& L);           	 				//���ز˵�
void menu2(LinkList& L);            				//���ܲ˵�
int  Log( LinkList& L);             				//��¼����
void Modify_LinkList(LinkList& L);					//�˻���Ϣ�޸�
void Save_LinkList(LinkList& L);  					//���溯�� 
void Init_LinkList1(LinkList1& M);					//��ʼ������������                        
void Read_LinkList1(LinkList1& M); 					//��ȡ������Ϣ����                 
void help_take_information(LinkList& L);			//��ȡ��Ϣ�鿴����            
int  Line();                            			//���к���                                                         
void Delete_LinkList(LinkList& L);					//ע�� 
void Query_LinkList1( LinkList1& M,LinkList& L);	//��ѯ����                  
void help_take_LinkList1( LinkList1& M,LinkList& L);//��ȡ����                                       
void Print_LinkList1(LinkList1& M,LinkList& L);		//��ȡ����չʾ 
void Save_LinkList1(LinkList1& M);					//����������Ϣ����

 
 
 
LinkList L=NULL;
LinkList1 M=NULL;
#endif
