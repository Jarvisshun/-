/* algo2-13.c 采用链表结构实现算法2.2的程序，仅有4句与algo2-2.c不同 */
 #include"c1.h"
 typedef int ElemType;
 #include"c2-2.h" /* 此句与algo2-2.c不同 */
 #include"bo2-2.cpp" /* 此句与algo2-2.c不同 */
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
    LinkList La,Lc; //定义单链表La,Lc；
	InitList(La);//初始化单链表La；
	int i,k;
	for(i=1;i<=4;i++)
{
	printf("请输入链表La的第%d个值",i);//输入k；
	scanf("%d",&k);//将k插入到La中
	ListInsert(La,i,k);
}
ListTraverse(La,print);//调用遍历算法，将La输出
	//同样的方法创建单链表Lb;
	
	
	LinkList Lb;//定义单链表Lb
	InitList(Lb);//初始化单链表Lb；
	int j;
	for(i=1;i<=5;i++)
{
	printf("请输入链表Lb的第%d个值",i);//输入j；
	scanf("%d",&j);//将j插入到Lb中
	ListInsert(Lb,i,j); 
}
ListTraverse(Lb,print);//调用遍历算法，将Lb输出
MergeList_L(La,Lb,Lc);//函数调用
ListTraverse(Lc,print);
 }

