#include<bits/stdc++.h>
#include <map>
 using namespace std; 


int main()
{
	set <string> greets;
	string s;
	int n;
	cin>>n;
	cin.ignore();
	for(int j=0; j<n; j++){
		getline(cin,s);
			greets.insert(s); }


cout<<greets.size();
return 0;
}
