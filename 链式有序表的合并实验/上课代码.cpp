/* algo2-13.c ��������ṹʵ���㷨2.2�ĳ��򣬽���4����algo2-2.c��ͬ */
 #include"c1.h"
 typedef int ElemType;
 #include"c2-2.h" /* �˾���algo2-2.c��ͬ */
 #include"bo2-2.cpp" /* �˾���algo2-2.c��ͬ */
void print(ElemType c)
{
   printf("%d ",c);
 }
void MergeList_L(LinkList &LA,LinkList &LB,LinkList &LC)
{
	LinkList pa,pb,pc;
	pa=LA->next;pb=LB->next;
	LC=LA;
	pc=LC;
	while(pa&&pb)
	{
		if(pa->data<=pb->data)
		{
			pc->next=pa;
			pc=pa;
			pa=pa->next;
		}
		else
		{
			pc->next=pb;
			pc=pb;
			pb=pb->next;
	    }
	pc->next=pa?pa:pb;
	delete LB;
	LB=NULL;
    } 
}
 int main()
 {
    LinkList La,Lc; //���嵥����La,Lc��
	InitList(La);//��ʼ��������La��
	int i,k;
	for(i=1;i<=4;i++)
{
	printf("����������La�ĵ�%d��ֵ",i);//����k��
	scanf("%d",&k);//��k���뵽La��
	ListInsert(La,i,k);
}
ListTraverse(La,print);//���ñ����㷨����La���
	//ͬ���ķ�������������Lb;
	
	
	LinkList Lb;//���嵥����Lb
	InitList(Lb);//��ʼ��������Lb��
	int j;
	for(i=1;i<=5;i++)
{
	printf("����������Lb�ĵ�%d��ֵ",i);//����j��
	scanf("%d",&j);//��j���뵽Lb��
	ListInsert(Lb,i,j); 
}
ListTraverse(Lb,print);//���ñ����㷨����Lb���
MergeList_L(La,Lb,Lc);//��������
ListTraverse(Lc,print);
 }

