#include <stdio.h>
#include <stdlib.h>

void NhapVaoMang(int n,int m,int p,int ***arr){
	int i,j,k;
	printf("Nhap vao ma tran: \n");
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			for(k=0;k<p;k++){
			scanf("%d",&arr[i][j][k]);			
			}
		}
	}	
};


void XuatRaMang(int n,int m,int p,int ***arr){
	int i,j,k;
	printf("----Cac phan tu trong mang la:\n");
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			for(k=0;k<p;k++){
				printf("Arr[%d][%d][%d]= %d\n",i,j,k,arr[i][j][k]);
			}
		}
		printf("\n");
	}
};

int main(){

	//Khai bao cho mang ba chieu thu nhat
	int n1,m1,p1;
	printf("Nhap ma tran so %d\nNhap chieu thu nhat: ",1);
	scanf("%d",&n1);
	printf("Nhap chieu thu hai: ");
	scanf("%d",&m1);	
	printf("Nhap chieu thu ba: ");
	scanf("%d",&p1);
	
	
	int ***arr1,i,j,k;
	arr1 = (int ***)malloc(n1 * sizeof(int **));
	for(i = 0; i < n1; i++)
	{
	    arr1[i] = (int **)malloc(m1 * sizeof(int *));
	    for(j=0;j<m1;j++){
	    	arr1[i][j] = (int *)malloc(p1 * sizeof(int ));
		}
	}
	
		NhapVaoMang(n1,m1,p1,arr1);
	
	XuatRaMang(n1,m1,p1,arr1);
	
}
