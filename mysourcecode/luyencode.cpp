#include<bits\stdc++.h>

using namespace std;

int main(){
	unordered_map<int, int> mp;
	int n, input;
	cin>> n;
	
	for(int i=0; i<n; i++){
		cin>> input;
		mp[input]++;
	}
	
	for(auto x : mp){
		if(x.second % 2 == 1) cout<< x.first;
	}
}
