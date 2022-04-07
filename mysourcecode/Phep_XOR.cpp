 #include<bits/stdc++.h>
using namespace std;

	int main(){
 	int n;
	int cnt=0, sum1, sum2;
	int a[n];
	cin>>n;
	
	//Nhap vao tat ca phan tu mang a
	int i=1;
	while(i<n+1){
		cin>>a[i];
		i++;
	} 

	//Chon bien chay k va j (k<j)
	int k=1;
	while(k<n){
		int j=k+1;
		if(a[k]==a[j]) cnt++;
		j=k+3;
		
		while(j<n+1){
			int m=k, l=(k+j-1)/2 +1;
			sum1= a[m];
			sum2= a[l];
			while(m<(k+j-1)/2){
				sum1= sum1^a[m+1]; //Phep XOR tu k den mid
				m++;
				sum2= sum2^a[l+1]; //Phep XOR tu mid+1 den j
				l++;
			}  

			if(sum1==sum2){
			//	cout<<k<<" "<<j<<", ";
			//	cout<<sum1<<" "<<sum2<<endl;
				cnt++;
			}  
		 
		j+=2;
		}
		k++;
	}
	cout<<cnt<<endl;  

		return 0;}

    
    
