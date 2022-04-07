#include<stdio.h>

#define MAXLEN 100
typedef struct LIST{
	int elements[MAXLEN];
	int last;
} list_type;
list_type L;

//Chen vao vi tri p
void Insert(int x, int p){
int q;
if (L.last>=MAXLEN) {printf("Danh sach tran"); return;}
else{
	if ((p>L.last+1) || (p<1)) { printf("Vi tri khong ton tai\n"); return;}
	else {
	for (q=L.last; q>=p;q--) 
	L.elements[q+1]=L.elements[q];
	L.last = L.last +1;
	L.elements[p]=x;
	}
}
}

//Xoa khoi vi tri p
void Delete(int p){
int q;
if((p>L.last+1) || (p<1)) {printf("Danh sach tran"); exit(0);} 
else{
	L.last = L.last-1;
	for(q=p; q<=L.last; q++)
	L.elements[q]=L.elements[q+1];}
}

//Tra lai vi tri cuoi danh sach
int End(){
	return(L.last+1);
}

//Xac dinh v tri cua x
int Locate(int x){
	int q;
	for(q=1; q<=L.last;q++)
	if(L.elements[q]==x)  return q;
	return -1; //Khong tim thay
}

//Than ct
int main(){
	int i,p,x;
	//Chen 6 gia tri vao vi tri 1
	Insert(1,1); Insert(2,1); Insert(3,1);
	Insert(4,1); Insert(5,1); Insert(6,1);
	//Kiem tra cac phep toan
	printf("Vi tri cuoi cung %d \n", End());
	printf("In ra danh sach cac gia tri \n");
	for(i=1; i<=L.last; i++) printf("%d  ", L.elements[i]);
	printf("\n"); 
	printf("Cho gia tri muon tim kiem "); scanf("%d", &x);
	printf("Vi tri muon tim kiem %d la %d \n", x, Locate(x));
	printf("Cho vi tri muon xoa "); scanf("%d  ", &p);
	Delete(p);
	printf("In ra danh sach cac gia tri sau khi xoa \n");
	for(i=1; i<=L.last; i++) printf("%d", L.elements[i]); 
	getch();
	return 0;
}







































