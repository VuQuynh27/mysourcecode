#include<bits/stdc++.h>
 using namespace std; 


int main()
{
	int c=11, r=0;
char str[11][11];
for(int i=0; i<11; i++){
	for(int j=0; j<11; j++){
		str[i][j]=' ';
	}
}

while(10-r>=r){
		str[r][r]='*';
		str[r][10-r]='*';
		r++;
}

for(int i=0; i<11; i++){
	for(int j=0; j<11; j++){
		cout<<str[i][j];
	}
	cout<<endl;
}
 }

