#include<stdio.h>

int main(void){
/*FILE * fp = NULL;
char name[32] = {0};
int age = 0;
double height = 0;
char blood = 0;

fp = fopen( "user.txt","r"); // hoac fopen_s(&fp,"user.txt","r"); (an toan hon)

while (fscanf(fp,"%s %d %lfcm %c", name, &age, &height, &blood) !=EOF)
{
printf("%d %3.1lfcm \n", age,height);
}
fclose(fp);
return 0;
}
*/
int c;
printf(": ");
getchar();
while (c = getchar() != EOF)
   putchar(c);
   }


