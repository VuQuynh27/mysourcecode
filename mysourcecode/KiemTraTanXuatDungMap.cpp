#include<bits/stdc++.h>
#include <map>
 using namespace std; 


int main()
{
	map <char, int> mp;
	char str[10000];
//	cin.ignore();
	cin.getline(str, 10000);

	for(int j=0; j<strlen(str); j++){
		str[j]= (tolower(str[j]));
		mp[str[j]]++;
	}
	
	for(auto x: mp){
		if( (x.first>='a' && x.first<='z') || (x.first>='A' && x.first<='Z') || (x.first>='0' && x.first<='9')){
			cout<<x.first<<" "<< x.second<<endl;
		}
	}
} 
