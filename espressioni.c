#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int solve(char* expr){
	char* sep;
	char* token;
	char* expr_cp;
	int k=0,i=0,cont=0;
	int res=0,tmp=0;
	while(expr[i]!='\0'){
		if(expr[i]=='-')
			cont++;
	i++;
	}
	expr_cp=malloc(sizeof(char)*(strlen(expr)+cont));
	i=0;
	while(expr[i]!='\0'){
		if(expr[i]=='-'){
			expr_cp[k++]='+';
			expr_cp[k++]='-';
			}
		else
			expr_cp[k++]=expr[i];
		i++;
	}
	sep="+";
	token=strtok(expr_cp,sep);
	while(token!=NULL){
		tmp=atoi(token);
		res+=tmp;
		token=strtok(NULL,sep);
	}
	return res;
}

int main(int argc, char** argv){
	int res=0;
	if(argv[1]=='\0'){
		printf("Per eseguire il programma devi passare come parametro una stringa contenente un'espressione aritmetica\n");
		return 0;
	}
	res=solve(argv[1]);
	printf("%d\n",res);
	return 0;
}
