#include<conio.h>
#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

class MT {
public:
   double a [20][20];
   int n;
};

//typedef class MaTran MT;

istream& operator>> (istream& is, MT& x)
{
   cout<< "--Nhap vao cap cua ma tran: ";
   is>> x.n;
   cout<< "\n--Nhap vao cac phan tu cua ma tran: ";
   for(int i=1; i<= x.n; ++i)
       for (int j=1; j<= x.n; ++j)
       {
	   cout<< "\nNhap vao phan tu a["<<i<<"]["<<j<<"]: ";
       is>> x.a[i][j];
   }
   return is;
   }

ostream &operator<< (ostream &os, MT &x)
{
os<< setprecision(2) << setiosflags (ios::showpoint);
   for(int i=1; i<= x.n; ++i)
   {
      os<< "\n";
      for (int j=1; j<= x.n; ++j)
      	os<< setw(6)<< x.a[i][j];
   }
os<< "\n";
return os;
}

MT operator + (const MT& x1, const MT& x2)
{
    if (x1.n != x2.n)
    {
	  cout<< "\nKhong the thuc hien phep cong vi hai ma tran khong cung cap";
	  getch();
	}
	else
	{
	   MT x;
	   int n, i,j,k;
	   n= x.n = x1.n;
	   for(i=1; i<=n; ++i)
	       for(j=1; j<=n; ++j)
	       {
		   x.a[i][j]= 0.0;
		   for(k=1; k<= n;++k)
		      x.a[i][j] += x1.a[i][k] + x2.a[k][j];
		      return x;
		   }
	   
	}
}


MT operator * (const MT& x1, const MT& x2)
{
	if (x1.n != x2.n)
   {
	  cout<< "\nKhong the thuc hien phep nhan vi hai ma tran khong cung cap";
	  getch();
	}
	else
	{
	    MT x;
	   int n, i,j,k;
	   n= x.n = x1.n;
	   for(i=1; i<=n; ++i)
	       for(j=1; j<=n; ++j)
	       {
		   x.a[i][j]= 0.0;
		   for(k=1; k<= n;++k)
		      x.a[i][j] += x1.a[i][k] * x2.a[k][j];
		      return x;
		      }
	}
}

MT& operator = (const MT& x1) {
	if (this != &x1)
	{
           n = x1.n;
           a = x1.a;
           return *this;
           }
           }


int main()
{
  MT x,y,z;
   cout<< "----Nhap vao ma tran x: \n";
   cin>> x;
   cout<< "\n----Nhap vao ma tran y: \n";
   cin>> y;
   cout<< "\n----Tong hai ma tran la: \n";
   z= x+y;
   cout<< z;
   cout<< "\n----Tich hai ma tran la: \n";
   z = x*y;
   cout<< z;
   return 0;
}



















