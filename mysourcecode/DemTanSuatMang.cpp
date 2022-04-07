#include <bits/stdc++.h>

using namespace std;

int main()
{
	unordered_map <int, int> mp;
	int n;
	cin>> n;
	int *str = new int[1000000];
	
	for(int i=0; i<n; i++){
		cin>> str[i];
		mp[str[i]]++;
	}
	
	cout<<mp.size()<<endl;
	
	for(int i=0; i<n; i++){
		if(mp[str[i]]!=0){
		cout<<str[i]<<" "<<mp[str[i]]<<endl;
		mp[str[i]]=0;
		}
	}
	
	delete[] str;
	return 0;

}
