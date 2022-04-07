#include<bits\stdc++.h>

using namespace std;

 int main() 
{ 

    int n, input; 

    char S[] = {'0', '1'}; 
	string res [100000];
    int k = 2, count = 0; 

    sort(S, S + 2);
	cin>>input;
	
    for (int n=1; n<=input; n++)
    {
    	if (input%n == 0)
    	{
    		vector<int> w; 
    		w.push_back(-1); 
			while(w.size() > 0) 
    		{	 
        		w[w.size()-1]++; 
        		int m = w.size(); 
        		if(m == n)
        		{
            		string str;
            		for(int i = 0; i < w.size(); i++) str += S[w[i]]; 
            		res[count] = str;
            		count++;
        		}	 
        		while(w.size() < n) w.push_back(w[w.size() - m]); 
				while(w.size() > 0 && w[w.size() - 1] == k - 1) w.pop_back(); 
    		} 
    	}
	}
	sort(res,res+count);
	string kqua;
	for (int i=0;i<=count;i++) kqua+=res[i];
	cout<<kqua; 
    return 0; 
}
