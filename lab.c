#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int len(char* parola){
	int cont=0,i=0;
	while(parola[i]!='\0'){
		cont++;
		i++;
	}
	return cont;
}

int inside(char car, char* parola){
	int ver=0,i;
	for(i=0;i<len(parola);i++)
		if(car==parola[i])
			ver=1;
	return ver;
}

int anagramma(char* parola_a, char* parola_b){
	int lung_a=len(parola_a),lung_b=len(parola_b);
	int i;
	if(lung_a!=lung_b)
		return 0;
	for(i=0;i<lung_a;i++)
		if(!inside(parola_b[i],parola_a))
			return 0;
	return 1;
}

int sostit(char* parola_a, char* parola_b){
	int conta=0,i;
	int lung_a=len(parola_a);
	int lung_b=len(parola_b);
	if(lung_a!=lung_b)
		return 0;
	for(i=0;i<lung_a;i++)
		if(!inside(parola_b[i],parola_a))
			conta++;
	if(conta==1)
		return 1;
	return 0;
}

int agg(char*parola_a, char* parola_b){
	int lung_a,lung_b;
	int i=0,j=0,conta=0;
	lung_a=len(parola_a);
	lung_b=len(parola_b);
	if(lung_b!=lung_a+1)
		return 0;
	while(i<lung_b){
		if(parola_b[i]!=parola_a[j]){
			conta++;
			j--;
		}
		i++;
		j++;
	}
	if(conta!=1)
		return 0;
	return 1;
}

int elimin(char* parola_a,char* parola_b){
	int lung_a,lung_b;
	int i=0,j=0,conta=0;
	lung_a=len(parola_a);
	lung_b=len(parola_b);
	if(lung_b!=lung_a-1)
		return 0;
	while(i<lung_b){
		if(parola_b[i]!=parola_a[j]){
			conta++;
			i--;
		}
		i++;
		j++;
	}
	if(conta!=1 && conta!=0)
		return 0;
	return 1;
}

int controllo(char* parola_a, char* parola_b){
	int conta_r=0;
	if(anagramma(parola_a,parola_b))
		conta_r++;
	if(sostit(parola_a,parola_b))
		conta_r++;
	if(agg(parola_a,parola_b))
		conta_r++;
	if(elimin(parola_a,parola_b))
		conta_r++;
	if(conta_r!=1)
		return 0;
	return 1;
}

int main(){
	printf("%d\n",controllo("ciao","aoic"));
	return 0;
}
