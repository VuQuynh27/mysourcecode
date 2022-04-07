#include<iostream>
using namespace std;
struct phanso {
int TuSo;
int MauSo;
};
typedef struct phanso PhanSo;
int UCLN(int x, int y){
if (x < 0)
x *= -1;
if (y < 0)
y *= -1;
if (x==0||y==0)
return 1;
while (x != y)
{
if (x > y)
x -= y;
else
y -= x;
}
return x;
}
void RutGonPS(PhanSo &x){
int ucln = UCLN(x.TuSo, x.MauSo);
x.TuSo = x.TuSo / ucln;
x.MauSo = x.MauSo / ucln;
}
PhanSo operator + (PhanSo ps1, PhanSo ps2){
PhanSo x;
x.TuSo = (ps1.TuSo*ps2.MauSo + ps2.TuSo*ps1.MauSo);
x.MauSo = ps1.MauSo*ps2.MauSo;
return x;
}
PhanSo operator - (PhanSo ps1, PhanSo ps2){
PhanSo x;
x.TuSo = (ps1.TuSo*ps2.MauSo - ps2.TuSo*ps1.MauSo);
x.MauSo = ps1.MauSo*ps2.MauSo;
return x;
}
PhanSo operator * (PhanSo ps1, PhanSo ps2){
PhanSo x;
x.TuSo = ps1.TuSo*ps2.TuSo;
x.MauSo = ps1.MauSo*ps2.MauSo;
return x;
}
PhanSo operator / (PhanSo ps1, PhanSo ps2){
PhanSo x;
x.TuSo = ps1.TuSo*ps2.TuSo;
x.MauSo = ps1.MauSo*ps2.MauSo;
return x;
}istream& operator >> (istream &is, PhanSo &ps){
cout<< "\nNhap tu so: " ;
is>> ps.TuSo;
cout<< "Nhap mau so: ";
is>> ps.MauSo;
if(ps.MauSo!=0)
return is;
while(ps.MauSo==0)
{
cout<< "\nPhan so khong xac dinh, vui long nhap lai!";
cout<< "\nNhap tu so: " ;
is>> ps.TuSo;
cout<< "Nhap mau so: ";
is>> ps.MauSo;
}
}
ostream& operator << (ostream& os, PhanSo& ps){
RutGonPS(ps);
if (ps.MauSo == 1 || ps.TuSo==0){
cout<< ps.TuSo;
return os;}
else
{
os<< ps.TuSo << "/" << ps.MauSo;
return os;
}
}int main(){
PhanSo ps1,ps2,x;
cout<< "\nNhap vao phan so 1: ";
cin>> ps1;
cout<< ps1;
cout<< "\nNhap vao phan so 2: ";
cin>> ps2;
cout<< ps2;
x= ps1 + ps2;
RutGonPS(x);
cout<< "\nTong hai phan so da cho la: "<< x;
x= ps1 - ps2;
RutGonPS(x);
cout<< "\nHieu hai phan so da cho la: "<< x;
x= ps1 * ps2;
RutGonPS(x);
cout<< "\nTich hai phan so da cho la: "<< x;
x= ps1 / ps2;
RutGonPS(x);
cout<< "\nThuong hai phan so da cho la: "<<x;
return 0;
}
