#include<stdio.h>
int Stirling(int n,int m){
	
}
int main(){
	int n,m;
	printf("请输入元素个数n及非空子集个数m：");
	scanf("%d %d",&n,&m);
	printf("包含%d个元素的集合可以划分为%d个不同的由%d个非空子集构成的集合\n",n,Stirling(n,m),m);
	return 0;
} 
