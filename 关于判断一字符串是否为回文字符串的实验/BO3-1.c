 /* bo3-1.c 顺序栈（存储结构由c3-1.h定义）的基本操作（9个） */
Status InitStack(SqStack &S)
{
	// 构造一个空栈S
   S.base=new SElemType[MAXSIZE];
   if (!S.base) exit (OVERFLOW); //存储分配失败
   S.top = S.base;
   S.stacksize =MAXSIZE;
   return OK;
}
Status StackEmpty(SqStack S)
{
    //若栈为空栈，则返回TRUE,否则返回FLASE
	return S.top == S.base;
}
Status push(SqStack &S, SElemType e)
{
  if (S.top-S.base==S.stacksize) 
     return ERROR;
    *S.top++=e;
    return OK;
}

// 出栈
Status pop(SqStack &S,SElemType &e)
{
    if (S.top == S.base) return ERROR;
    e = *--S.top;
    return OK;

}
