#include <stdio.h>
#define MAXSIZE 100
typedef  int  keytype;
typedef struct
  { keytype key;
   }Elemtype;  //��������Ԫ��
typedef struct
  {Elemtype R[MAXSIZE];
    int  length;
   }sstable;//���徲̬���ұ�Ҳ����һ��˳���
int  Search_Bin(sstable ST,keytype key)/*���ַ����Һ���*/
 { //�ο��㷨7.3��������
 	//�������ST���۰������ؼ��ʵ���key������Ԫ�ء����ҵ�������ֵΪ��Ԫ���ڱ��е�λ�ã�����Ϊ0 
 	int low,high,mid; 
	low=1;high=ST.length;						//�ò��������ֵ 
	while(low<=high)
	{
		mid=(low+high)/2;
		if(key==ST.R[mid].key) return mid;		//�ҵ�����Ԫ�� 
		else if(key<ST.R[mid].key) high=mid-1;	//������ǰһ�ֱ���в���
		else low=mid+1;							//�����ں�һ�ֱ���в��� 
	}  											//while
	return 0;									//���в����ڴ���Ԫ�� 
 }
int main()/*������*/
{sstable ST;//��һ����̬���ұ�
 int i,pos,key;
 pos=0;
       printf("������˳����:");
       scanf("%d",&ST.length);/*��������˳����*/      
       printf("������%d��Ԫ��ֵ:\n",ST.length);
        for(i=1;i<=ST.length;i++)
          scanf("%d",&ST.R[i].key);//ʹ��ѭ���ṹΪ���ұ��Ԫ������ֵ��ѭ�������±��1��ʼ��0�ŵ�Ԫ����
       printf("������Ҫ���ҵĹؼ���ֵ:");/*������������ҵļ�¼�ؼ���ֵ*/
       scanf("%d",&key);
       pos=Search_Bin(ST,key);/*���ö��ַ����Һ���*/    
  if(pos==0)
     printf("%dδ�ҵ�\n",key); /*���Ҳ�������ʾ��Ϣ*/
  else
     printf("%d��λ����%d\n",key,pos); /*���ҵ������λ��*/
  return 0;
}


