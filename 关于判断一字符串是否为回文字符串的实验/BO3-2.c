 /* bo3-2.c 链队列(存储结构由c3-2.h定义)的基本操作(9个) */
 Status InitQueue(LinkQueue & Q)
	{
	  //构造并返回一个空链式队列Q
	  Q.front = Q.rear = new QNode;
          if(!Q.front) exit(OVERFLOW);
	  Q.front->next =NULL;
          return OK;
	 }

// 入队 插入，只在尾部
Status EnQueue (LinkQueue & Q, QElemType e)
   { 
	//插入一个值为X的结点到链式队列中，成为队尾结点
	QueuePtr p; 
	 p = new QNode;
    if (!p)  exit (OVERFLOW);   //存储分配失败
    p->data = e;   p->next = NULL;
    Q.rear->next = p;    Q.rear = p;
    return OK;
	}

//出队，从队首出队	
 Status DeQueue(LinkQueue & Q, QElemType &e) 
 {
   //若链队列Q 为空，则给出相应的信息；
	 //否则取出并返回队头结点数据的值且不修改队头结点
	  QueuePtr p;
	  if (Q.front == Q.rear)    return ERROR;
    p = Q.front->next;   e = p->data;
    Q.front->next = p->next;
    if (Q.rear == p)  Q.rear = Q.front;
    delete   p;      
    return OK;
	}
