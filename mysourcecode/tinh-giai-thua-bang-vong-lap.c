#include<stdio.h>  
#include<conio.h>  

int main(){  
  int i,giaithua=1,sobatky;  

  printf("Nhap mot so bat ky: ");  
  scanf("%d",&sobatky);  

  for(i=1;i<=sobatky;i++){  
      giaithua=giaithua*i;  
  }  
  printf("\nGiai thua cua %d la: %d",sobatky,giaithua);  

  printf("\n\n===========================\n");
  printf("Hoclaptrinh chuc cac ban hoc tot!");
  getch();  }
