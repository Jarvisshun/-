typedef char  SElemType;
typedef char  QElemType;
#include "c1.h"
#include "C3-1.h"
#include "C3-2.h"
#include "BO3-1.c"
#include "BO3-2.c"
int main()
{   SqStack S1;	  //����˳��ջS1
	LinkQueue Q1; //�������Q1
    InitStack(S1);//��ʼ��ջS1
   	InitQueue(Q1); //��ʼ������Q
   	char c,e1,e2;
   while((c=getchar())!='@')
  {
		push(S1,c);//��c��ջ ;
		EnQueue(Q1,c);//��c�����;			
  }
	while(!StackEmpty(S1))
  {
		pop(S1,e1);//��Ԫ�س�ջ���浽e1
		DeQueue(Q1,e2);//��Ԫ�س����б��浽e2				
		if(e2!=e1)	
		{
		printf("���ǻ���");
		return ERROR;
		}
	}
	 printf("�ǻ���");
	return OK;
}

