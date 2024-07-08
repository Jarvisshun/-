//斐波那契-递归 
#include<stdio.h>
#include<time.h>
const int N=10;
long long Fibonacci(int n){  
	
}
int main(){
	int start=clock();
	//Fibonacci(N);
	int end=clock();
	printf("%lld ",Fibonacci(N-1));
	printf("递归方法花费%dms\n",end-start);
	return 0;
}
