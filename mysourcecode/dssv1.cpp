
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include<fstream>
#include<iostream>
#include <fstream> 

using namespace std;


int alloc3d( float ****Cub, int m, int r, int c)   // truy?n dc
{ 
    *Cub = new float** [m]; 
    if (*Cub==NULL) return 0;
    for (int i = 0; i < m; i++) 
    { 
        (*Cub)[i] = new float * [r]; 
         if ((*Cub)[i]==NULL) return 0;
        for (int j = 0; j < r; j++) {
            (*Cub)[i][j] = new float[c]; 
            if ((*Cub)[i][j]==NULL) return 0;
        } 
    } 
    return 1;
} 
int alloc3d( float *** &Cub, int m, int r, int c)   // truy?n tham chieu
{ 
    Cub = new float** [m]; 
    if (Cub==NULL) return 0;
    for (int i = 0; i < m; i++) 
    { 
        Cub[i] = new float * [r]; 
         if (Cub[i]==NULL) return 0;
        for (int j = 0; j < r; j++) {
            Cub[i][j] = new float[c]; 
            if (Cub[i][j]==NULL) return 0;
        } 
    } 
    return 1;
} 

// gp
void free3d(float ***Cub,int m,int r) {
    for (int i = 0; i < m; i++) 
    { 
        for (int j = 0; j < r; j++) {
            delete [] Cub[i][j]; 
        } 
        delete [] Cub[i];
    } 
    delete [] Cub;
}


void free3d(float ***Cub,int m,int r,int c) {
    for (int i = 0; i < m; i++) 
    { 
        for (int j = 0; j < r; j++)
        {
        delete [] Cub[i][j];
    } 
    delete [] Cub[i];
  }
  delete [] Cub;
  }


// tai cap phat
int realloc3d( float ***&Cub,int m,int r,int c)
{
    float *** Cm;
    int m2,r2,c2;
    // vao kich thuoc moi : m2,r2 va c2
     if (!alloc3d(Cm,m2,r2,c2)) {
         return 0;
    }
    for(int i=0;i<m2;i++) 
        for(int j=0;j<r2;j++)
           for(int k=0;k<c2;k++)
           {
                Cm[i][j][k]=(i<m && j<r &&k<c)?Cub[i][j][k]:0;
             free3d(Cub,m,r,c);
             Cub=Cm;
             }
    return 1;
}



int n=0,ts=50;
char **ds, *tg, ht[60];
void bosung();
void sapxep();
void inds();
void sapxepVN();

int main() {
   char ch;
   ds=new char *[50];
   while (1) {
        system("cls");
        printf("\n                  CHUONG TRINH QLSV");
        printf("\n                  1. Bo sung");
        printf("\n                  2 . Sap xep theo kieu VN");
        printf("\n                  3. In danh sach");
        printf("\n                      Bam 1..3 de chon, fim # dde ket thuc");
        ch=getch();
        if (ch=='1') bosung();
        else if (ch=='2') sapxepVN();
        else if (ch=='3') inds();
        else {
                   printf("chan roi a ?  Y.... ");
                   ch=getch();
                   if( ch=='y' ||ch=='Y')  break;
        }
   }
   delete []ds;
}


void bosung() {
   char **dsm;
   
   FILE * file = NULL;
file = fopen("dssv.txt", "a");
   if(file == NULL)
   {
      printf("Error!");
      exit(1);
   }
   

   while(1) {
       printf("\n Vao ho ten sv thu %d : ",n+1);
       gets(ht);
       if(ht[0]=='\0') break;
       ds[n]=new char [strlen(ht)+1];  
        fprintf(file,"%s\n", ht);
       strcpy(ds[n],ht);
       n++;
       if(n>=ts) {
           ts+=50;
           dsm=new char *[ts];
           for(int i=0;i<n;i++) dsm[i]=ds[i];
           delete []ds;
           ds=dsm;
     
          
      }
   }
 
   fclose(file); 
}


char * daoten(char *hoten) {
   int i =strlen(hoten);
   char *tm;
   while(hoten[i-1] ==' ' && i>0) i--;
   while(hoten[i-1] !=' ' && i>0) i--;
   if (i==0) return hoten;
   else {
      tm=new char[strlen(hoten+i)+strlen(hoten)+2];
      strcpy(tm,hoten+i);
      strcat(tm," ");
      strcat(tm,hoten);
      return tm; }
}
int  vitriten(char *hoten) {
   int i =strlen(hoten);
   char *tm;
   while(hoten[i-1] ==' ' && i>0) i--;
   while(hoten[i-1] !=' ' && i>0) i--;
      return i;
}
void sapxepVN() {
   int i,j,k;
   for(i=0;i<n-1;i++) {
      k=i;
      for (j=i+1;j<n;j++)
          if(stricmp(daoten(ds[k]),daoten(ds[j])) >0) k=j;
      if (k!=i) {
         tg=ds[k];
         ds[k]=ds[i];
         ds[i]=tg;
     }
  }
printf("\n Da sap xep xong !");
  getch();
  }
  
  
void sapxepVN2() {
   int i,j,k;
   for(i=0;i<n-1;i++) {
      k=i;
      for (j=i+1;j<n;j++)
          if(stricmp(ds[k]+vitriten(ds[k]),ds[j]+vitriten(ds[j])) >0) k=j;
          else if(stricmp(ds[k]+vitriten(ds[k]),ds[j]+vitriten(ds[j])) ==0)
                      if(stricmp(ds[k],ds[j]) >0) k=j;
      if (k!=i) {
         tg=ds[k];
         ds[k]=ds[i];
         ds[i]=tg;
     }
  }
  printf("\n Da sap xep xong !");
  getch();
}

void inds() {
FILE * file = NULL;
char ht[60] = {0};

file = fopen( "dssv.txt","r"); // hoac fopen_s(&fp,"user.txt","r"); (an toan hon)

  printf("\n Danh sach sv \n");
  //for (int i=0;i<n;i++) 
    while (fgets(ht, 60, file) != NULL)
    {
        //Xu?t t?ng dòng ra màn hình
        printf("%s", ht);}
fclose(file);
  getch();
  }
  
  













 
