#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int string_count(char* stringa, char separatore){
	int i=0,contatore=0;
	while(stringa[i]!='\0'){
		if(stringa[i]==separatore){
			contatore++;}
		i++;	
			}
	return contatore+1;
	}

char** split(char* libro, char separatore,int l){
	int i=0,j=0,k=0,length,pos=i;
	char* parola;
	char* parole[l];
	for(i=0;i<l;i++)
		parole[i]=malloc(MAX_LEN);
	i=0;	
	while(libro[i]!='\0'){
		length=len(libro,&pos,separatore);
		parola=malloc((sizeof(char)*length+1));
		for(j=0;j<=length;j++,i++){
			parola[j]=libro[i];}
		parole[k]=parola;
		k++;
		}
	return parole;
	}

void indicizza(char* libro){
	
	}

int main(){
	char libro[MAX_LEN]="ciao a tutti come state bene e tu niente male grazie";
	char** a;
	int i;
	i=string_count(libro,' ');
	printf("%d\n",i);
	/*a=split(libro,' ',11);
	for(i=0;i<11;i++)
		printf("%s\n",a[i]);*/
	return 0;
	}
