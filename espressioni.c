#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int solve(char* expr){
	char* sep;
	char* token;
	int res=0,tmp=0;
	sep="+";
	token=strtok(expr,sep);
	while(token!=NULL){
		tmp=atoi(token);
		res+=tmp;
		token=strtok(NULL,sep);
	}
	return res;
}

int main(){
	char expr[]="3+2+1";
	int res=0;
	res=solve(expr);
	printf("%d\n",res);
	return 0;
}
