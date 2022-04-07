#include <bits/stdc++.h>

using namespace std;

int main()
{
	unordered_map <int, int> mp;
	int n;
	long long cnt=0;
	cin>> n;
	int str[100000];
	
	for(int i=0; i<n; i++){
		cin>> str[i];
		mp[str[i]]++;
	}

	for( auto x: mp){
		if(x.second>1){
			for(int i=1; i<x.second; i++){
				cnt += i;
			}
		}
	}
	cout<<cnt;
	return 0;

}
