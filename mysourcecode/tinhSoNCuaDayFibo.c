#include<stdio.h>
unsigned long long fibo(n){
if (n==0||n==1)
return n;
return (fibo(n-1)+fibo(n-2));}
int main(){
	int i;
	printf("Nhap vao so thu n: ");
	scanf("%d",&i);
printf("fibo(%d) : %lld\n",i,fibo(i));
return 0;}
