#include <stdio.h>
#define MAXSIZE 100
typedef  int  keytype;
typedef struct
  { keytype key;
   }Elemtype;  //定义数据元素
typedef struct
  {Elemtype R[MAXSIZE];
    int  length;
   }sstable;//定义静态查找表也就是一个顺序表
int  Search_Bin(sstable ST,keytype key)/*二分法查找函数*/
 { //参考算法7.3补充完整
 	//在有序表ST中折半查找其关键词等于key的数据元素。若找到，则函数值为该元素在表中的位置，否则为0 
 	int low,high,mid; 
	low=1;high=ST.length;						//置查找区间初值 
	while(low<=high)
	{
		mid=(low+high)/2;
		if(key==ST.R[mid].key) return mid;		//找到代查元素 
		else if(key<ST.R[mid].key) high=mid-1;	//继续在前一字表进行查找
		else low=mid+1;							//继续在后一字表进行查找 
	}  											//while
	return 0;									//表中不存在待查元素 
 }
int main()/*主函数*/
{sstable ST;//定一个静态查找表
 int i,pos,key;
 pos=0;
       printf("请输入顺序表表长:");
       scanf("%d",&ST.length);/*请求输入顺序表表长*/      
       printf("请输入%d个元素值:\n",ST.length);
        for(i=1;i<=ST.length;i++)
          scanf("%d",&ST.R[i].key);//使用循环结构为查找表的元素输入值，循环变量下标从1开始，0号单元不用
       printf("请输入要查找的关键字值:");/*请求输入待查找的记录关键字值*/
       scanf("%d",&key);
       pos=Search_Bin(ST,key);/*调用二分法查找函数*/    
  if(pos==0)
     printf("%d未找到\n",key); /*若找不到，提示信息*/
  else
     printf("%d的位置是%d\n",key,pos); /*若找到，输出位置*/
  return 0;
}


