#include<iostream>

using namespace std;

int SoTho(int n){ 
	if (n<=2) return 1; 
	int Fn, Fn_1,Fn_2; 
	Fn_1 = Fn_2 = 1; 
	for (int i=3; i<=n; i++) 
			{ Fn=Fn_1 + Fn_2; 
			Fn_2=Fn_1; Fn_1=Fn; 
			}
			int Fnban_13, Fnban_14, Fnban;
			Fnban_13 = Fnban_14 = 1;
			Fn= Fn - 1;
		for(int j=15; j<=n; j++){
		 	Fnban=Fnban_13 + Fnban_14; 
			Fnban_14=Fnban_13; Fnban_13=Fnban; 
			Fn= Fn - Fnban;
		 	} 
			return Fn; }

int main(){
	int n;
Menu:	cout<<"nhap vao n\n";
	cin>>n;
	cout<<"So cap tho la:"<<SoTho(n)<<"\n";
	goto Menu;
	return 0;
            }
