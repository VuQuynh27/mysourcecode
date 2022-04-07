
 
// N?u dùng fgets()
#include <stdio.h>
 
 int main(){
    int age;
    char name[30];
    printf("\nNhap tuoi: "); scanf("%d", &age);
    getchar(); // d?c ký t? '\n'
    printf("\nNhap ten: "); fgets(name, sizeof name, stdin);
    printf("%s - %d", name, age); 
} 
 
// N?u dùng gets()
/*  #include <stdio.h>
 
int main(){
    int age;
    char name[30];
    printf("\nNhap tuoi: "); scanf("%d", &age);
    fflush(stdin); // d?c ký t? '\n'
    printf("\nNhap ten: "); gets(name);
    printf("%s - %d", name, age);
} */
 
