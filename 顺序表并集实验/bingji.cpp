/* algo2-1.c 实现算法2.15的程序 */
 #include"c1.h"
 typedef int ElemType;
 #include"c2-1.h" /* 采用线性表的动态分配顺序存储结构 */
 #include"bo2-1.cpp" /* 可以使用bo2-1.c中的基本操作 */
 void print(ElemType *c)
 {
   printf("%d ",*c);
 }
 //定义函数 
 void MergeList(SqList &La,SqList Lb)
 {
 	int i,e,m,n;
 	m=ListLength(La);
 	n=ListLength(Lb);
 	for(i=1;i<=n;i++)
	 {
 		GetElem(Lb,i,e);
 		if(!LocateElem(La,e))
 		ListInsert(La,++m,e); 
	 }
 }
 int main()
 {
   //定义一个采用顺序存储的线性表La
   SqList La;//定义了一个La int a;
   InitList(La);//初始化，分配空间
   int i,e;
   for(i=1;i<=4;i++)
   {
   	printf("请输入La的第%d个元素值",i);
   	scanf("%d",&e);
   	ListInsert(La,i,e);
	} 
	ListTraverse(La,print);
	SqList Lb;
	InitList(Lb);
	int m,n;
   for(m=1;m<=4;m++)
   {
   	printf("请输入Lb的第%d个元素值",m);
   	scanf("%d",&n);
   	ListInsert(Lb,m,n);
	} 
	ListTraverse(Lb,print);
	MergeList(La,Lb);//函数调用
	ListTraverse(La,print);
 }



