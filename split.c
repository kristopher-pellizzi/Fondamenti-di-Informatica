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
	char** parole;
	parole=malloc(l);
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

void stampa_lista(struct nodo* head){
	if (head->prossimo==NULL){
		printf("%s\t(%d)\n",head->parola,head->contatore);
		return;
	}
	printf("%s\t(%d)\n",head->parola,head->contatore);
	stampa_lista(head->prossimo);
}

void indicizza(char* libro, int l){
	char** string_array;
	int i;
	struct nodo* head;
	head=NULL;
	string_array=split(libro, ' ', l);
	for(i=0;i<l;i++)
		insert(string_array[i],&head);
	stampa_lista(head);
	}

int main(){
	char libro[MAX_LEN]="ciao a tutti ciao a tutti ciao a tutti quanti voi altri";
	int i;
	int word_cnt;
	word_cnt=string_count(libro,' ');
	indicizza(libro,word_cnt);
	return 0;
	}
