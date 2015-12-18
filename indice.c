#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int len(char* s){
	int cont=0;
	while(s[cont]!='\0')
		cont++;
	return cont;}

void copy(char*origine, char*destinazione, int l){
	int i,length;
	length=len(origine);
	for(i=0;i<l && i<length;i++)
		destinazione[i]=origine[i];
	destinazione[i]='\0';}

struct parola{
	char* parola;
	int occorrenze;
	char* puntatori[MAX];
	};

void store_word(char* origin, int l, struct parola* p){
	p->occorrenze++;
	p->parola=malloc(sizeof(char)*l+1);
	copy(origin,(*p).parola,l);
	printf("\n\n");
	printf("Parola: %s\n", p->parola);
	printf("Occorrenze: %d\n", p->occorrenze);
	}

int main(){
	char s[MAX]="ciao a tutti etc etc";
	struct parola *p;
	int i;
	p=malloc(sizeof(struct parola)*4);
	for(i=0;i<4;i++)
		p[i].occorrenze=0;
	store_word(s,4,&p[0]);
	store_word(s+5, 1, &p[1]);
	store_word(s+7, 5, &p[2]);
	store_word(s+13, 3, &p[3]);
	store_word(s+17, 3, &p[3]);
	return 0;
	}
