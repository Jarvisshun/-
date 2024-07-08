 /* bo3-1.c ˳��ջ���洢�ṹ��c3-1.h���壩�Ļ���������9���� */
Status InitStack(SqStack &S)
{
	// ����һ����ջS
   S.base=new SElemType[MAXSIZE];
   if (!S.base) exit (OVERFLOW); //�洢����ʧ��
   S.top = S.base;
   S.stacksize =MAXSIZE;
   return OK;
}
Status StackEmpty(SqStack S)
{
    //��ջΪ��ջ���򷵻�TRUE,���򷵻�FLASE
	return S.top == S.base;
}
Status push(SqStack &S, SElemType e)
{
  if (S.top-S.base==S.stacksize) 
     return ERROR;
    *S.top++=e;
    return OK;
}

// ��ջ
Status pop(SqStack &S,SElemType &e)
{
    if (S.top == S.base) return ERROR;
    e = *--S.top;
    return OK;

}
