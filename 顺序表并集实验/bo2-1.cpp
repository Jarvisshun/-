 /* bo2-1.c 顺序表示的线性表(存储结构由c2-1.h定义)的基本操作(12个) */
 Status InitList(SqList &L) /* 算法2.3 */
 { /* 操作结果：构造一个空的顺序线性表 */
   L.elem = new ElemType[MAXSIZE];
   if (!L.elem) exit(OVERFLOW);
   L.length = 0;
   return OK;
 }
 Status ListEmpty(SqList L)
 { /* 初始条件：顺序线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE */
   if(L.length==0)
     return TRUE;
   else
     return FALSE;
 }

 int ListLength(SqList L)
 { /* 初始条件：顺序线性表L已存在。操作结果：返回L中数据元素个数 */
   return L.length;
 }

 Status GetElem(SqList L,int i,ElemType &e)
 { /* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
   /* 操作结果：用e返回L中第i个数据元素的值 */
   if(i<1||i>L.length)
     exit(ERROR);
   e=*(L.elem+i-1);
   return OK;
 }

 Status LocateElem(SqList L,ElemType e)
 { /* 初始条件：顺序线性表L已存在，compare()是数据元素判定函数(满足为1,否则为0) */
   /* 操作结果：返回L中第1个与e满足关系compare()的数据元素的位序。 */
   /*           若这样的数据元素不存在，则返回值为0。算法2.6 */
  for(int i=0;i<L.length;i++)
	  if(L.elem[i]==e) return i+1;
	  return 0;
 }
 
 Status ListInsert(SqList &L,int i,ElemType e) /* 算法2.4 */
 { /* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L)+1 */
   /* 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1 */
  if (i < 1 || i > L.length+1) return ERROR; 
if(L.length==MAXSIZE) return ERROR;
for (int j=L.length-1; j >= i-1;  j--)  
     L.elem[j+1]=L.elem[j];//
   L.elem[i-1]= e;       // 插入e

   ++L.length; /* 表长增1 */
   return OK;
 }

 
 Status ListTraverse(SqList L,void(*vi)(ElemType * ))
 { /* 初始条件：顺序线性表L已存在 */
   /* 操作结果：依次对L的每个数据元素调用函数vi()。一旦vi()失败，则操作失败 */
   ElemType *p;
   int i;
   p=L.elem;
   for(i=1;i<=L.length;i++)
     vi(p++);
   printf("\n");
   return OK;
 }
