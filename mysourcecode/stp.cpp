#include<stdio.h>
#include<stdlib.h>

main(){
	int i;
	char s[10]="abcdefg";
	for(i=0;i<=7;i++){
		printf("%c ",s[i]);		
		if(i==7){
			printf("1");	
		}
		if(i==6){
			printf("2");	
		}
		if(i==5){
			printf("k");	
		}
	}
	return 0;
}
