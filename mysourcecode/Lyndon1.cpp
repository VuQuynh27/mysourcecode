#include<bits\stdc++.h>

using namespace std;

int main() 
{ 
    int n, input; 
    char S[] = {'0', '1'}; 
    int k = 2; 
    sort(S, S + 2); 
    
        cin>>input;
   	for(n=1; n<=input; n++)
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
	            for(int i = 0; i < w.size(); i++) 
	            { 
	                str += S[w[i]]; 
	            } 
	            cout << str << endl; 
	        } 
	
	        while(w.size() < n) 
	        { 
	            w.push_back(w[w.size() - m]); 
	        } 
	
	        while(w.size() > 0 && w[w.size() - 1] == k - 1) 
	        { 
	            w.pop_back(); 
	        } 
	    } 
    }
    
    return 0; 
}
