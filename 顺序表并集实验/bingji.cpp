/* algo2-1.c ʵ���㷨2.15�ĳ��� */
 #include"c1.h"
 typedef int ElemType;
 #include"c2-1.h" /* �������Ա�Ķ�̬����˳��洢�ṹ */
 #include"bo2-1.cpp" /* ����ʹ��bo2-1.c�еĻ������� */
 void print(ElemType *c)
 {
   printf("%d ",*c);
 }
 //���庯�� 
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
   //����һ������˳��洢�����Ա�La
   SqList La;//������һ��La int a;
   InitList(La);//��ʼ��������ռ�
   int i,e;
   for(i=1;i<=4;i++)
   {
   	printf("������La�ĵ�%d��Ԫ��ֵ",i);
   	scanf("%d",&e);
   	ListInsert(La,i,e);
	} 
	ListTraverse(La,print);
	SqList Lb;
	InitList(Lb);
	int m,n;
   for(m=1;m<=4;m++)
   {
   	printf("������Lb�ĵ�%d��Ԫ��ֵ",m);
   	scanf("%d",&n);
   	ListInsert(Lb,m,n);
	} 
	ListTraverse(Lb,print);
	MergeList(La,Lb);//��������
	ListTraverse(La,print);
 }



