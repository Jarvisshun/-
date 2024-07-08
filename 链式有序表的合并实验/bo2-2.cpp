 /* bo2-2.c 单链表线性表(存储结构由c2-2.h定义)的基本操作(12个) */
 Status InitList(LinkList &L)
 { /* 操作结果：构造一个空的线性表L */
   L=new LNode; /* 产生头结点,并使L指向此头结点 */
   if(!L) /* 存储分配失败 */
     exit(OVERFLOW);
   L->next=NULL; /* 指针域为空 */
   return OK;
 }

 int ListLength(LinkList L)
 { /* 初始条件：线性表L已存在。操作结果：返回L中数据元素个数 */
   int i=0;
   LinkList p=L->next; /* p指向第一个结点 */
   while(p) /* 没到表尾 */
   {
     i++;
     p=p->next;
   }
   return i;
 }

 Status ListInsert(LinkList L,int i,ElemType e) /* 算法2.9。不改变L */
 { /* 在带头结点的单链线性表L中第i个位置之前插入元素e */
   int j=0;
   LinkList p=L,s;
   while(p&&j<i-1) /* 寻找第i-1个结点 */
   {
     p=p->next;
     j++;
   }
   if(!p||j>i-1) /* i小于1或者大于表长 */
     return ERROR;
   s=(LinkList)malloc(sizeof(struct LNode)); /* 生成新结点 */
   s->data=e; /* 插入L中 */
   s->next=p->next;
   p->next=s;
   return OK;
 } 
 Status ListTraverse(LinkList L,void(*vi)(ElemType))
 /* vi的形参类型为ElemType，与bo2-1.c中相应函数的形参类型ElemType&不同 */
 { /* 初始条件：线性表L已存在 */
   /* 操作结果:依次对L的每个数据元素调用函数vi()。一旦vi()失败,则操作失败 */
   LinkList p=L->next;
   while(p)
   {
     vi(p->data);
     p=p->next;
   }
   printf("\n");
   return OK;
 }
