#include<iostream>
using namespace std;

int main()
{
int N, S=2005;
cout<<"\nHay nhap nao N (N>2): ";
cin>>N;
if(N<=2)
cout<<"\nSo N khong hop le!";
else
{
S+= 2*N +1;
cout<< S;
}
}



