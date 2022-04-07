 #include<bits/stdc++.h>
using namespace std;


long Tong(int n) {
   long h1=1,h2=2,h,tg=3;
   if( n==1) return 1;
   else if (n==2) return 3;
   else {
      for(int i=3;i<=n;i++) {
          h=2*h2*h1;
          tg+=h;
          h1=h2; h2=h;}  
      return tg;
   }    
}

	int main(){
		int n=4;
	cout<<Tong(n);
	return 0;
}
 
------------------------------------------------------------------------
 #include<bits/stdc++.h>
using namespace std;


long Tong(int n) {
	   long h1=1,h2=2,h3=3,h,tg=6;
   if( n==1) return 1;
   else if (n==2) return 3;
	else if (n==3) return 6;
   else {
      for(int i=4;i<=n;i++) {
          h=h3+h2+h1;
          tg+=h;
          h1=h2; h2=h3; h3=h;}  
      return tg;
   }
}
	int main(){
	int n=5;
	cout<<Tong(n);
	return 0;
}
 
---------------------------------------------------------------
 #include<bits/stdc++.h>
using namespace std;

long  h(int n) {
   if( n<4) return n;
   else return (h(n-1)+h(n-2)+h(n-3));     
}


long Tong(int n) {
   long tg=0;
   for( int i=1; i<=n;i++)   tg+=h(i);
   return tg;
}

	int main(){
	cout<<h(5)<<endl<<Tong(5);
	return 0;
}
----------------------------------------------------------------------
 #include<bits/stdc++.h>
using namespace std;

long  h2(int n);

long  h1(int n) {
   if( n<5) return n;
   else return (h2(n-1)+h1(n-2)+h2(n-3)+h1(n-4));     
}


long Tong1(int n) {
   long tg=0;
   for( int i=1; i<=n;i++)   tg+=h1(i);
   return tg;
}

long  h2(int n) {
   if( n<5) return 2*n;
   else return (h1(n-1)+h2(n-2)+h1(n-3)+h2(n-4));     
}


long Tong2(int n) {
   long tg=0;
   for( int i=1; i<=n;i++)   tg+=h2(i);
   return tg;
}

	int main(){
		int n=5;
	cout<<h1(n)<<endl<<Tong1(n)<<endl<<h2(n)<<endl<<Tong2(n)<<endl<<(Tong1(n)+Tong2(n));
	return 0;
}
 
-------------------------------------------------------------------------------
 #include<bits/stdc++.h>
using namespace std;

long Tong(int n) {
   long tg=30, X[5]={1,2,3,4,16}, Y[5]={2,4,6,8,14};
    if(n==1) return 3;
    else if (n==2) return  9;     
	else if (n==3) return 18;
    else if (n==4) return 30;
    else {
	
	   for( int i=1; i<=n;i++){   
		   X[4]=Y[3]+X[2]+Y[1]+X[0];
		   Y[4]=X[3]+Y[2]+X[1]+Y[0];
		   tg+=X[4]+Y[4];
		   for(int i=0;i<=3;i++){
		   		X[i]=X[i+1]; Y[i]=Y[i+1];
		   }
		   return tg;
	   }
	}
}

	int main(){
		int n=5;
	cout<<Tong(n);
	return 0;
}
    
    
    
