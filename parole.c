#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct freq_parola{
	char* parola;
	int freq;
	int pos;
	struct freq_parola* prossimo;
};



char* copia_n(char* from, char* to){
	char* res=(char*)malloc(sizeof(char)*(to-from)+1);
	int i;
	for(i=0;i<to-from;i++){
		res[i]=from[i];
	}
	res[i]='\0';
	return res;
}

int isLetter(char c){
	return (c>='a' && c<='z') || (c>='A' && c<='Z');
}

char* punt_pross_parola(char* i){
	while(isLetter(*i)){
		i++;
	}
	if(*i=='\0')
		return NULL;
	while(!isLetter(*i)){
		i++;
	}
	return i;
}

char* parola(char* frase,int n){
	if(n==0){
		char* i=frase;
		while(isLetter(*i))
			i++;
	return copia_n(frase,i);
	}
	else{
		char* i=punt_pross_parola(frase);
		if(i==NULL)
			return NULL;
		return parola(i,n-1);
	}
}

int conta_parole(char* p,char* str){
	int i=0;
	int j;
	for(j=0;parola(str,j)!=NULL;j++)
		if(strcmp(p,parola(str,j))==0)
			i++;
	return i;
}

void insert(char* parola, int freq,struct freq_parola** head){
	struct freq_parola* new;
	if(*head==NULL || freq>(*head)->freq){
		new=malloc(sizeof(struct freq_parola));
		new->parola=parola;
		new->freq=freq;
		new->prossimo=*head;
		*head=new;
	}
	else	
		insert(parola,freq,&((*head)->prossimo));
}

int in(char* parola, struct freq_parola* head){
	if(head==NULL)
		return 0;
	while(head->prossimo!=NULL){
		if(strcmp(parola,head->parola)==0)
			return 1;
		head=head->prossimo;
	}
	return 0;
}

struct freq_parola* freqs(char* frase){
	int i,n;
	struct freq_parola* head;
	struct freq_parola* elem;
	head=NULL;
	for(i=0;parola(frase,i)!=NULL;i++){
		if(!in(parola(frase,i),head)){
			n=conta_parole(parola(frase,i),frase);	
			insert(parola(frase,i),n,&head);
		}
	}
	elem=head;
	for(i=0;elem->prossimo!=NULL;i++){
		elem->pos=i;
		elem=elem->prossimo;
	}
	return head;
}

char* max_parola(char* frase,int n){
	char* max_str=NULL;
	int max=0;
	int i;
	struct freq_parola* head;
	head=freqs(frase);
	for(i=0;head!=NULL;i++){
		if(i==n-1){
			max=head->freq;
			max_str=head->parola;
		}
		head=head->prossimo;
	}
	return max_str;
}

int main(){
	char* frase="ciao a tutti ciao ciao tutti";
	int i;
	for(i=1;i<=3;i++)
		printf("%d parola max: %s\n", i,max_parola(frase,i));
	return 0;
}
