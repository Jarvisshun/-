 /* bo2-1.c ˳���ʾ�����Ա�(�洢�ṹ��c2-1.h����)�Ļ�������(12��) */
 Status InitList(SqList &L) /* �㷨2.3 */
 { /* �������������һ���յ�˳�����Ա� */
   L.elem = new ElemType[MAXSIZE];
   if (!L.elem) exit(OVERFLOW);
   L.length = 0;
   return OK;
 }
 Status ListEmpty(SqList L)
 { /* ��ʼ������˳�����Ա�L�Ѵ��ڡ������������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE */
   if(L.length==0)
     return TRUE;
   else
     return FALSE;
 }

 int ListLength(SqList L)
 { /* ��ʼ������˳�����Ա�L�Ѵ��ڡ��������������L������Ԫ�ظ��� */
   return L.length;
 }

 Status GetElem(SqList L,int i,ElemType &e)
 { /* ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L) */
   /* �����������e����L�е�i������Ԫ�ص�ֵ */
   if(i<1||i>L.length)
     exit(ERROR);
   e=*(L.elem+i-1);
   return OK;
 }

 Status LocateElem(SqList L,ElemType e)
 { /* ��ʼ������˳�����Ա�L�Ѵ��ڣ�compare()������Ԫ���ж�����(����Ϊ1,����Ϊ0) */
   /* �������������L�е�1����e�����ϵcompare()������Ԫ�ص�λ�� */
   /*           ������������Ԫ�ز����ڣ��򷵻�ֵΪ0���㷨2.6 */
  for(int i=0;i<L.length;i++)
	  if(L.elem[i]==e) return i+1;
	  return 0;
 }
 
 Status ListInsert(SqList &L,int i,ElemType e) /* �㷨2.4 */
 { /* ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L)+1 */
   /* �����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1 */
  if (i < 1 || i > L.length+1) return ERROR; 
if(L.length==MAXSIZE) return ERROR;
for (int j=L.length-1; j >= i-1;  j--)  
     L.elem[j+1]=L.elem[j];//
   L.elem[i-1]= e;       // ����e

   ++L.length; /* ����1 */
   return OK;
 }

 
 Status ListTraverse(SqList L,void(*vi)(ElemType * ))
 { /* ��ʼ������˳�����Ա�L�Ѵ��� */
   /* ������������ζ�L��ÿ������Ԫ�ص��ú���vi()��һ��vi()ʧ�ܣ������ʧ�� */
   ElemType *p;
   int i;
   p=L.elem;
   for(i=1;i<=L.length;i++)
     vi(p++);
   printf("\n");
   return OK;
 }
