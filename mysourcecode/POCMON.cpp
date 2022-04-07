 #include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
	int n; long long m;
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>m;
			if(m%8==0 && m!=0)
			cout<<m/8*5<<" "<<m/4<<" "<<m/8<<endl;
			else cout<<-1<<endl;
	}
	
    return 0;
    }
