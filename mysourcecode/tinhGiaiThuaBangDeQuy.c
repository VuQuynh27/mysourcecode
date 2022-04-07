#include <stdio.h>
unsigned long long giaiThua( int n) {
if (n==0 || n==1)
return 1;
return giaiThua(n-1)*n;}
int main(){
int i;
printf("nhap vao so nguyen nho hon 21: ");
scanf("%d", &i);
printf("%d!= %lld\n", i, giaiThua(i));
return 0;
}
