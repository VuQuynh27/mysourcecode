#include<bits/stdc++.h>
using namespace std;

bool Palin(string s){
	int i=0, j= s.length()-1;
	while(i<j){
		if(s[i]!=s[j]) return false;
		
			i++; j--;
	}
	return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    int i;
    cin>>n;
    string* a= new string[n];
	for(i=0; i<n; i++){
		cin>>a[i];
	 if(Palin(a[i])) cout<<a[i]<<" ";
	 
	}

	return 0;
	}
    
