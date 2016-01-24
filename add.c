#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int len(char* num){
	int i=0,cont=0;
	while(num[i]!='\0'){
		cont++;
		i++;
	}
	return cont;
}

char itoa(int num){
	return ('0'+num);
}

char* add(char* num1, char* num2){
	int cifra1=0,cifra2=0,lung_a=0,lung_b=0;
	int l_min=0,rip=0,somma_parz=0,l_max=0,i;
	char* max;
	lung_a=len(num1);
	lung_b=len(num2);
	l_min= lung_a<lung_b ? lung_a : lung_b;
	l_max= l_min==lung_b ? lung_a : lung_b;
	max=(char*)malloc(sizeof(char)*l_max+1);
	l_max==lung_a ? strcpy(max,num1) : strcpy(max,num2);
	for(i=0;i<l_min;i++){
		cifra1=num1[lung_a-i-1]-'0';
		cifra2=num2[lung_b-i-1]-'0';
		somma_parz=cifra1+cifra2+rip;
		max[l_max-i-1]=itoa(somma_parz%10);
		rip=somma_parz/10;
	}
	return max;
}

int main(){
	printf("%s\n",add("5","10"));
	printf("%s\n",add("2134","1000"));
	printf("%s\n",add("15","10"));
	printf("%s\n",add("5","0"));
	printf("%s\n",add("0","0"));
	printf("%s\n",add("11111111111111111110","1"));
}
