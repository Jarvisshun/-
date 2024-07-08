 /* bo2-2.c ���������Ա�(�洢�ṹ��c2-2.h����)�Ļ�������(12��) */
 Status InitList(LinkList &L)
 { /* �������������һ���յ����Ա�L */
   L=new LNode; /* ����ͷ���,��ʹLָ���ͷ��� */
   if(!L) /* �洢����ʧ�� */
     exit(OVERFLOW);
   L->next=NULL; /* ָ����Ϊ�� */
   return OK;
 }

 int ListLength(LinkList L)
 { /* ��ʼ���������Ա�L�Ѵ��ڡ��������������L������Ԫ�ظ��� */
   int i=0;
   LinkList p=L->next; /* pָ���һ����� */
   while(p) /* û����β */
   {
     i++;
     p=p->next;
   }
   return i;
 }

 Status ListInsert(LinkList L,int i,ElemType e) /* �㷨2.9�����ı�L */
 { /* �ڴ�ͷ���ĵ������Ա�L�е�i��λ��֮ǰ����Ԫ��e */
   int j=0;
   LinkList p=L,s;
   while(p&&j<i-1) /* Ѱ�ҵ�i-1����� */
   {
     p=p->next;
     j++;
   }
   if(!p||j>i-1) /* iС��1���ߴ��ڱ� */
     return ERROR;
   s=(LinkList)malloc(sizeof(struct LNode)); /* �����½�� */
   s->data=e; /* ����L�� */
   s->next=p->next;
   p->next=s;
   return OK;
 } 
 Status ListTraverse(LinkList L,void(*vi)(ElemType))
 /* vi���β�����ΪElemType����bo2-1.c����Ӧ�������β�����ElemType&��ͬ */
 { /* ��ʼ���������Ա�L�Ѵ��� */
   /* �������:���ζ�L��ÿ������Ԫ�ص��ú���vi()��һ��vi()ʧ��,�����ʧ�� */
   LinkList p=L->next;
   while(p)
   {
     vi(p->data);
     p=p->next;
   }
   printf("\n");
   return OK;
 }
