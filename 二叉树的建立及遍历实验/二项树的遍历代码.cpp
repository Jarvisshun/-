typedef char TElemType;
#include"c1.h"
#include"c6-1.h"  //���Ķ��������C��������



void CreateBiTree(BiTree &T)   //�������������㷨5.3
 {  
     char ch;   
     scanf("%c",&ch);  //�������������
     if(ch=='#') T=NULL;
     else
     {
     	T=new BiTNode;
     	T->data=ch;
     	CreateBiTree(T->lchild);
     	CreateBiTree(T->rchild);
	 }
 }  
void PreOrderTraverse(BiTree T)  //��������㷨 
 {  
    if(T!=NULL)
	{
		printf("%c",T->data);
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	 } 
 }  
void InOrderTraverse(BiTree T) //��������㷨
 {   
	if(T!=NULL)
	{
		InOrderTraverse(T->lchild);
		printf("%c",T->data);		
		InOrderTraverse(T->rchild);
	 } 
 }  
void PostOrderTraverse(BiTree T)  //��������㷨
 {  
    if(T!=NULL)
	{		
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		printf("%c",T->data);
	 } 
 }  

 
int main() {
    //1����һ������BiTree T��
	BiTree T=NULL;
    printf("�����������:");
    //2��������� ��CreateBiTree(T)
	CreateBiTree(T);


 
//3��������������ֱ�����
printf("PreOrderTraver:");
PreOrderTraverse(T);//������������㷨��
printf("\nInOrderTraver:");
InOrderTraverse(T); //������������㷨��
printf("\nPostOrderTraver:");
PostOrderTraverse(T);//���ú�������㷨��
return 0;
}

