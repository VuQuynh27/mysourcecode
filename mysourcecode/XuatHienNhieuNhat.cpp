#include<iostream>
#include <map>
#include <string>
 using namespace std; 


int main()
{
	map <string, int> mp;
	string str, win;
	int n, max=0;
	cin>>n;
	cin.ignore();

	for(int j=0; j<n; j++){
		cin>>str;
		mp[str]++;
	}
	
	for(auto x: mp){
	if(x.second>max){ max=x.second; win=x.first;}
	} 
	
	cout<<win;
} 
