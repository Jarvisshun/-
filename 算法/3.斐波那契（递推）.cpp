//斐波那契-递推 
#include<stdio.h>
#include<time.h>
const int N=5;
long long Fibonacci(int n)
{
	//long long a[N]={1,1};
	
	//long long f1 = 1,f2= 1,f3;
	
	
}
int main(){
	int start=clock();
	//Fibonacci(N);
	int end=clock();
	printf("递推方法花费%dms\n",end-start);
	printf("%lld ",Fibonacci(N-1));
	return 0;
}

