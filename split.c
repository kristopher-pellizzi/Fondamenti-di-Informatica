#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 100

struct nodo{
	char* parola;
	int contatore;
	struct nodo* prossimo;};

void insert(char* parola, struct nodo** head){
	struct nodo* new=malloc(sizeof(struct nodo));
	if(*head==NULL || strcmp(parola,(*head)->parola)<0){
		new->parola=parola;
		new->contatore=1;
		new->prossimo=*head;
		*head=new;
		}
	else{
		if(strcmp(parola,(*head)->parola)==0){
			(*head)->contatore++;
			}
		else{
			insert(parola,&((*head)->prossimo));
			}
		}
	}

void print(char *parola){
	printf("%s\n",parola);
	}

int len(char* string,int* pos,char separatore){
	int cont=0;
	while(string[*pos]!=separatore && string[*pos]!='\0'){
		cont++;
		(*pos)++;}
	(*pos)++;
	return cont;
	}

void split(char* libro, char separatore){
	int i=0,j=0,length,pos=i;
	char* parola;
	while(libro[i]!='\0'){
		length=len(libro,&pos,separatore);
		parola=malloc((sizeof(char)*length+1));
		for(j=0;j<=length;j++,i++){
			parola[j]=libro[i];}
		print(parola);
		}
	}

void indicizza(char* libro){
	
	}

int main(){
	char libro[MAX_LEN]="ciao a tutti come state bene e tu niente male grazie";
	split(libro,' ');
	return 0;
	}
