typedef char TElemType;
#include"c1.h"
#include"c6-1.h"  //树的二叉链表的C语言描述



void CreateBiTree(BiTree &T)   //先序建立二叉树算法5.3
 {  
     char ch;   
     scanf("%c",&ch);  //输入二叉树数据
     if(ch=='#') T=NULL;
     else
     {
     	T=new BiTNode;
     	T->data=ch;
     	CreateBiTree(T->lchild);
     	CreateBiTree(T->rchild);
	 }
 }  
void PreOrderTraverse(BiTree T)  //先序遍历算法 
 {  
    if(T!=NULL)
	{
		printf("%c",T->data);
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	 } 
 }  
void InOrderTraverse(BiTree T) //中序遍历算法
 {   
	if(T!=NULL)
	{
		InOrderTraverse(T->lchild);
		printf("%c",T->data);		
		InOrderTraverse(T->rchild);
	 } 
 }  
void PostOrderTraverse(BiTree T)  //后序遍历算法
 {  
    if(T!=NULL)
	{		
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		printf("%c",T->data);
	 } 
 }  

 
int main() {
    //1定义一棵树；BiTree T；
	BiTree T=NULL;
    printf("请输入二叉树:");
    //2创建这棵树 ；CreateBiTree(T)
	CreateBiTree(T);


 
//3对这棵树进行三种遍历；
printf("PreOrderTraver:");
PreOrderTraverse(T);//调用先序遍历算法；
printf("\nInOrderTraver:");
InOrderTraverse(T); //调用中序遍历算法；
printf("\nPostOrderTraver:");
PostOrderTraverse(T);//调用后序遍历算法；
return 0;
}

