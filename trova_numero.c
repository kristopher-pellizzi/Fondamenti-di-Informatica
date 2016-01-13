#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct numeri{
	int num;
	int pos;
	struct numeri* prossimo;};

void append(int num,struct numeri** head){
	struct numeri* new;
	int pos;
	new=malloc(sizeof(struct numeri));
	if((*head)==NULL){
		new->num=num;
		new->prossimo=*head;
		(*head)=new;
		}
	else
		append(num,&((*head)->prossimo));
}

int conta_numeri(char* val){
	int i=0,cont=0;
	while(val[i]!='\0'){
		if(val[i]==' ')
			cont++;
		i++;
	}
	cont++;
	return cont;
}

struct numeri* cerca(int pos,struct numeri* head){
	while(head->pos!=pos)
		head=head->prossimo;
	return head;
}

int trova_numero(char* val, char* pos){
	struct numeri* head,*finder;
	int min=0,conta,i;
	int tmp=0;
	char* num;
	char* position;
	char* sep;
	head=NULL;
	finder=malloc(sizeof(struct numeri));
	sep=" ";
	conta=conta_numeri(val);
	num=strtok(val,sep);
	while(num!=NULL){
		tmp=atoi(num);
		append(tmp,&head);
		num=strtok(NULL,sep);
	}
	finder=head;
	for(i=0;i<conta;i++){
		finder->pos=i;
		if(finder->num>min)
			min=finder->num;
		if(finder->prossimo!=NULL)
			finder=finder->prossimo;
		}
	position=strtok(pos,sep);
	finder=NULL;
	while(position!=NULL){
		tmp=atoi(position);
		if(tmp<conta && tmp>=0)
			finder=cerca(tmp,head);
		//printf("Indirizzo: %p\nNum: %d\n\n",finder,finder->num);
		if (finder!=NULL && finder->num<min)
			min=finder->num;
		position=strtok(NULL,sep);
	}
	return min;
}

int main(){
	char val[]="100 50 31 -45 999 -111 456";
	char pos[]="0 4 -2 6 9 2 -12 3 11";
	printf("%d\n",trova_numero(val,pos));
	return 0;
}
