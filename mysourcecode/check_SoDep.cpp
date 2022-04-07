#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    if(n>=0 && n<10){
        if(n==9) cout<<"YES";
        else cout<<"NO";
          }
    else if(n>=10 && n<100){
        int a,b;
        b=n%10; a=n/10; 
        if(a+b==9) cout<<"YES";
        else cout<<"NO";
    }
    else{
        int a,b,c,d;
        c=n%10; b=((n%100)-c)/10; a=n/100; d=a+b+c;
        if(d%10==9) cout<<"YES";
        else cout<<"NO";
    }
    return 0;
}
