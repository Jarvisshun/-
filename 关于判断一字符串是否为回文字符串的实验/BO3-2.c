 /* bo3-2.c ������(�洢�ṹ��c3-2.h����)�Ļ�������(9��) */
 Status InitQueue(LinkQueue & Q)
	{
	  //���첢����һ������ʽ����Q
	  Q.front = Q.rear = new QNode;
          if(!Q.front) exit(OVERFLOW);
	  Q.front->next =NULL;
          return OK;
	 }

// ��� ���룬ֻ��β��
Status EnQueue (LinkQueue & Q, QElemType e)
   { 
	//����һ��ֵΪX�Ľ�㵽��ʽ�����У���Ϊ��β���
	QueuePtr p; 
	 p = new QNode;
    if (!p)  exit (OVERFLOW);   //�洢����ʧ��
    p->data = e;   p->next = NULL;
    Q.rear->next = p;    Q.rear = p;
    return OK;
	}

//���ӣ��Ӷ��׳���	
 Status DeQueue(LinkQueue & Q, QElemType &e) 
 {
   //��������Q Ϊ�գ��������Ӧ����Ϣ��
	 //����ȡ�������ض�ͷ������ݵ�ֵ�Ҳ��޸Ķ�ͷ���
	  QueuePtr p;
	  if (Q.front == Q.rear)    return ERROR;
    p = Q.front->next;   e = p->data;
    Q.front->next = p->next;
    if (Q.rear == p)  Q.rear = Q.front;
    delete   p;      
    return OK;
	}
