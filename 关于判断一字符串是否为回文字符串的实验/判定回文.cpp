typedef char  SElemType;
typedef char  QElemType;
#include "c1.h"
#include "C3-1.h"
#include "C3-2.h"
#include "BO3-1.c"
#include "BO3-2.c"
int main()
{   SqStack S1;	  //定义顺序栈S1
	LinkQueue Q1; //定义队列Q1
    InitStack(S1);//初始化栈S1
   	InitQueue(Q1); //初始化队列Q
   	char c,e1,e2;
   while((c=getchar())!='@')
  {
		push(S1,c);//将c入栈 ;
		EnQueue(Q1,c);//将c入队列;			
  }
	while(!StackEmpty(S1))
  {
		pop(S1,e1);//将元素出栈保存到e1
		DeQueue(Q1,e2);//将元素出队列保存到e2				
		if(e2!=e1)	
		{
		printf("不是回文");
		return ERROR;
		}
	}
	 printf("是回文");
	return OK;
}

