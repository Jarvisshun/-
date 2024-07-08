 /* c2-1.h 线性表的动态分配顺序存储结构 */
 #define MAXSIZE 100 /* 线性表存储空间的初始分配量 */
 typedef struct
 {
   ElemType *elem; /* 存储空间基址 */
   int length; /* 当前长度 */
 }SqList;
