#include<iostream>
using namespace std;
int main(){
	Menu:
    int date,month,year;
    cin>>date>>month>>year;
    if((year>1999) && (year<3001)){
    	if((year%4==0) && (year%100!=0) ){
			    if(month==1||month==3||month==5||month==7||month==8||month==10||month==12){
        			if(date<1 || date>31){
         			
          			  goto Menu;
     			   } 
        			else cout<<"users setClock \\"<<month<<"\\"<<date<<"\\"<<year;
  			  }
      			else if(month==4||month==6||month==9||month==11){
          			  if(date<1 || date>30){
               		 
               		 goto Menu;
           			 }
           			 else cout<<"users setClock \\"<<month<<"\\"<<date<<"\\"<<year;
       			 }
  				else if(month==2) {
        		    if(date<1 || date>29){
            	    
             	    goto Menu;
           			 }
           			 else cout<<"users setClock \\"<<month<<"\\"<<date<<"\\"<<year;
       			 }
       			 else {
       			 	
             	    goto Menu;
					}
       			 	
		}
		
		else {
				if(month==1||month==3||month==5||month==7||month==8||month==10||month==12){
        			if(date<1 || date>31){
         			
          			  goto Menu;
     			   } 
        			else cout<<"users setClock \\"<<month<<"\\"<<date<<"\\"<<year;
  			  }
      			else if(month==4||month==6||month==9||month==11){
          			  if(date<1 || date>30){
               		 
               		 goto Menu;
           			 }
           			 else cout<<"users setClock \\"<<month<<"\\"<<date<<"\\"<<year;
       			 }
  				else if(month==2) {
        		    if(date<1 || date>28){
            	    
             	   goto Menu;
           			 }
           			 else cout<<"users setClock \\"<<month<<"\\"<<date<<"\\"<<year;
       			 }
       			 else{
       			 	
             	    goto Menu;
					}
		}
		}
		else{ goto Menu; }
		return 0;
} 

