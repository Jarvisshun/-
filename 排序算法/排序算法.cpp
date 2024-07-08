#include "stdio.h"
#include "stdlib.h"
#define MAX 10000
#define EQ(a,b) ((a)==(b))
#define LT(a,b) ((a)<(b))
#define LQ(a,b) ((a)<=(b))
//���������Ͷ��� 
typedef int KeyType;
typedef struct
   { KeyType  key;
   } RecType;
typedef struct
   { RecType r[100];
     int length;
   } SqList;
//��������
void Swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
// �����Ľ��� 
void Create(SqList &L)
{ int i,n;
  printf("\n�������:"); scanf("%d",&n);
  printf("������%dԪ��:",n);
  L.r[0].key=-100;
  for(i=1; i<=n; i++)
     scanf("%d",&(L.r[i].key));
  L.length=n; }
// ���������(����ڱ�) 
void Traverse(SqList &L)
{ int i;
  printf("\n(%d)\t",L.r[0].key);
  for(i=1; i<=L.length; i++)
     printf("%5d",L.r[i].key); }
//ð������
void BubbleSort(SqList &L, int size)
{
    int i, j;
    for(i=1;i<=size-1;i++)
    {
        for(j=size;j>i;j--)
        if(LT(L.r[j].key ,L.r[j-1].key))
                Swap(L.r[j].key,L.r[j-1].key);
        Traverse(L);}
}
//ð������ĸĽ��㷨
void BubbleSort2(SqList &L){
    int start=1,end=L.length;
    int i;
    KeyType source[MAX];
    for(i=1;i<=L.length;i++)
        source[i]=L.r[i].key;
    while(start<=end)                   //�������Ԫ��û��ȷ����λ��
    {
        for(i=start;i<end;i++)          //Ѱ��ʣ��Ԫ�ص������
            if(source[i]>source[i+1])
            {
                Swap(source[i],source[i+1]);
            }
                end--;                  //�ҵ������
            for(i=end;i>start;i--)      //Ѱ��ʣ��Ԫ�ص���СԪ��
                if(source[i]<source[i-1])
                {
                    Swap(source[i],source[i-1]);
                }
                    start++;            //�ҵ�һ����С��
    }
           printf("%4d",source[i]);
}
// �������� 
int Partition(SqList &L, int low, int high)
{ KeyType pivotkey;
  L.r[0]=L.r[low];                 //���ӱ�ĵ�һ����¼������
  pivotkey=L.r[low].key;            //�����¼�ؼ���
  while(low<high)                    //�ӱ�����˽������м�ɨ��
    { while (low<high && L.r[high].key>=pivotkey) high--;
      L.r[low]=L.r[high];          //��������С�ļ�¼�ƶ����Ͷ�
      while (low<high && L.r[low].key<=pivotkey) low++;
      L.r[high]=L.r[low];}         //���������ļ�¼�ƶ����߶�
  L.r[low]=L.r[0];                 //�����¼��λ
  Traverse(L);
  return low; }                      //��������λ��
//�ݹ���ʽ�Ŀ�������
void QSort(SqList &L, int low, int high)
{ int pivotloc;
  if (low<high)                      //���ȴ���1
   { pivotloc=Partition(L,low,high); //����¼һ��Ϊ��
     QSort(L,low,pivotloc-1);        // �Ե��ӱ�ݹ�����pivotloc�������λ��
     QSort(L,pivotloc+1,high); }     // �Ը��ӱ�ݹ�����
} 
//��������ĸĽ��㷨
void Merge(SqList &L, int start, int mid, int end)
{
    RecType temp1[MAX], temp2[MAX];
    int n1, n2;
    int i, j, k;
    n1 = mid - start + 1;               //��ԭ��¼�ֳ������ֵĵ�һ�γ���
    n2 = end - mid;                     //��ԭ��¼�ֳ������ֵĵڶ��γ���
    for(i=0;i<n1;i++)
        temp1[i] =L.r[start + i];      //����һ�����Ԫ�ش洢��temp1[i]
    for(i=0;i<n2;i++)
        temp2[i] =L.r[mid + i + 1];    //���ڶ������Ԫ�ش洢��temp2[i]
    temp1[n1].key  = temp2[n2].key =MAX;//ÿ��Ԫ��Ϊ�����ֵ
    i = j = 0;
    for(k=start;k<=end;k++)             
    {
        if(LT(temp1[i].key,temp2[j].key))
        {
            L.r[k] = temp1[i];          //�Ƚ����������Ԫ��ʹ��������
            i++;
        }
        else
        {
            L.r[k] = temp2[j];
            j++;
        }
    }
}
//�ݹ���ʽ��������
void RecMerge(SqList &L, int start, int end)
{
    int i;
    if(start < end)
    {
        i = (start + end) / 2;      //ȡmidֵ
        RecMerge(L, start, i);      //��ǰһ������
        RecMerge(L, i+1, end);      //�Ժ�һ������
        Merge(L, start, i, end);    //�ϲ�����
        Traverse(L);
    }
}
//�ϲ�����
void MergeSort(SqList &L, int size)
{
    RecMerge(L, 0, size);
    Traverse(L);
}
// ��ѡ������ 
void SelectSort1(SqList &L)
{ int i,j,min; 
  for(i=0; i<=L.length; i++)            //ѡ���iС�ļ�¼
  {
      min=i;
      for(j=i+1;j<=L.length;j++)
            if(LT(L.r[j].key,L.r[min].key))
                min = j;                 //��L.[i...L.length]��ѡ����С�ļ�¼
        Swap(L.r[i].key, L.r[min].key);//���i������
        Traverse(L);
    }
}
//��ѡ������ĸĽ�:��Ԫѡ������ 
void SelectSort2(SqList &L) 
{
    int i ,j , min ,max,flag; 
    flag=0;
    int n=L.length;
    flag=L.length;
    for (i=1;i<=int(n/2);i++) 
    {  
       min = i; max = i ; 
       for (j=i+1; j<=n-i+1; j++) 
       { 
         if (LT(L.r[max].key,L.r[j].key)) 
         { max = j ; continue ;}       //ȷ�����ֵλ��
         if (LT(L.r[j].key,L.r[min].key)) 
         { min = j; continue;}         //ȷ����Сֵλ��
}
       if(max!=i||min!=flag)
       {    
           if(min>=max&&max!=i)
           {Swap(L.r[min].key,L.r[i].key);  
            Swap(L.r[max].key,L.r[flag].key);}
           else
           {Swap(L.r[max].key,L.r[flag].key);
            Swap(L.r[min].key,L.r[i].key);}
       }
      else
      Swap(L.r[max].key,L.r[min].key);
           flag--;                    //�����ֵ��Сֵ����ָ��λ��
           Traverse(L);
    }
}
//�˵� 
int MainMenue()
{
   // fflush( stdin );
    printf("\n********************** Main Menue **************************\n");
    printf("**                                                        **\n");
    printf("**              1. BubbleSort                             **\n");
    printf("**              2. BubbleSort2                            **\n");
    printf("**              3. QSort                                  **\n");
    printf("**              4. MergeSort                              **\n");
    printf("**              5. SelectSort1                            **\n");
    printf("**              6. SelectSort2                            **\n");
    printf("**              7. Exit.                                  **\n");
    printf("**                                                        **\n");
    printf("************************************************************\n");
}
//������ 
int main()
{  
   int flag = 1;
   char ch[10];
   SqList L;
   Create(L);
   while ( flag )
    {
        MainMenue();
        printf("Please input your choice(1~7): ");
        gets( ch );
        switch ( ch[0] )
        {
        case '1':
            BubbleSort(L,L.length);    exit(0);
        case '2':
            BubbleSort2(L);            exit(0);
        case '3':
            QSort(L,1,L.length);       exit(0);
        case '4':
            MergeSort(L,L.length);     exit(0);
        case '5':
            SelectSort1(L);            exit(0);
        case '6':
            SelectSort2(L);            exit(0);
        case '7':                       exit(0);
        default:
            printf("Input error!\n");   break;
        }
    }
}

