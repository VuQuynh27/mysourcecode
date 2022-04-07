#include<stdio.h>
#include<string.h>

struct SinhVien;
void HienThiDSSV(struct SinhVien*, int);
void HienThiTenCot();
void NhapHoTen();
void HienThiTTSV();
void SapXepTheoTen();


struct HoTen {
	char ho[6];
	char dem[20];
	char ten[10];
};

struct SinhVien {
	int ma;
	struct HoTen HoVaTen;
	};
	
void NhapHoTen(struct HoTen* ten){
	printf("Ho: ");
	scanf("%s",ten->ho);
printf ("Dem: ");
getchar();
gets(ten->dem);
printf("Ten: ");
scanf("%s", ten->ten);
}

struct SinhVien NhapSV(){
	   struct SinhVien sv;
	   printf("Nhap ma: ");
	   scanf("%d",&sv.ma);
	   NhapHoTen(&sv.HoVaTen);
	   return sv;
}

void HienThiTTSV(struct SinhVien sv){
	printf("%-10d %-10s %-20s %-10s \n", sv.ma, sv.HoVaTen, sv.HoVaTen.dem, sv.HoVaTen.ten);
	}
	
void SapXepTheoTen (struct SinhVien* ds, int slsv){
	int i,j;
	for(i=0; i< slsv -1; i++) {
		for( j=slsv -1; j>i;j--) {
			if (strcmp(ds[j].HoVaTen.ten, ds[j-1].HoVaTen.ten) <0) {
				struct SinhVien sv = ds[j];
				ds[j] = ds[j-1];
				ds[j-1] = sv;
			}
		}
	}
}

int main(){
	struct SinhVien dssv[5000];
	int slsv = 0;
	int LuaChon;
	int i;
	int n;
	
	void HienThiTenCot() {
	     printf("%-10s %-10s %-20s %-10s \n","Ma SV", "Ho", "Dem", "Ten");}
	     
	do {
		printf("-----MENU-----");
		printf("\n1. Bo sung danh sach.");
		printf("\n2. Sap xep danh sach theo thu tu.");
		printf("\n3. In danh sach.");
		printf("\nBam phim 1-3 de chon, phim bat ky de ket thuc.\n");
		
		scanf("%d",&LuaChon);
		
		struct SinhVien sv;
		
		switch(LuaChon){
			default:
			printf("Ban muon thoat? An phim bat ky de thoat!");
			getch();
			 return 0;
			 
			
			case 1: 
			printf("Nhap vao so luong sinh vien can bo sung: \n");
			scanf("%d",&n);
			for(i=0; i<n; i++){
             	sv = NhapSV();
	             dssv[slsv++] = sv;} break;
	             
	        case 2: 
			SapXepTheoTen(dssv, slsv);
			HienThiTenCot();
				for(i=0; i< slsv; i++){
	         	HienThiTTSV(dssv[i]);}
	         break;
        
	        case 3: 
	        HienThiDSSV;
	        HienThiTenCot();
	        	for(i=0; i< slsv; i++){
	         	HienThiTTSV(dssv[i]);}
	         	break;
	        
	    
			}
			} while(LuaChon);
	

return 0;
}
	
	
