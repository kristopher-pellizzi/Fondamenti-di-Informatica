#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list{
	int base;
	int num;
	int dec;
	int lung;
	struct list* prossimo;
};

void append(int base, int num, int lung, struct list** head){
	struct list* new;
	if((*head)==NULL){
		new=malloc(sizeof(struct list));
		new->base=base;
		new->num=num;
		new->lung=lung;
		new->prossimo=(*head);
		(*head)=new;
	}
	else
		append(base,num,lung,&((*head)->prossimo));
}

int conta_numeri(char* expr){
	int cont=0,i=0;
	while(expr[i]!='\0'){
		if(expr[i]==' '){
			cont++;
		}
	i++;
	}
	cont++;
	return cont;
}

int len(int num){
	int lung=0,ord=1;
	while(num/ord!=0){
		lung++;
		ord=ord*10;
		}
	return lung;
}

int pot(int base, int esp){
	int i=0,res=1;
	for(i=0;i<esp;i++)
		res=res*base;
	return res;
}

void converti(struct list* head){
	int ord=0,dec=0,num;
	int pot_10=0;
	while(head!=NULL){
		num=head->num;
		ord=head->lung-1;
		dec=0;
		while(num!=0){
			pot_10=pot(10,ord);
			dec+=(num/pot_10)*(pot(head->base,ord));
			num=num-((num/pot_10)*pot_10);
			ord=len(num)-1;
		}
		head->dec=dec;
		head=head->prossimo;
	}
}

int max_basi(char* expr){
	const char sep[]=" ";
	char* num;
	struct list* head,*finder;
	int tmp=0,trig=0,base=0,numero=0;
	int i,conta=0,max,lung=0;
	conta=conta_numeri(expr)/2;
	num=strtok(expr,sep);
	head=NULL;
	while(num!=NULL){
		tmp=atoi(num);
		if(trig==0)
			base=tmp;
		else{
			numero=tmp;
			lung=len(tmp);
			append(base,numero,lung,&head);
		}
		num=strtok(NULL,sep);
		trig=(trig+1)%2;
	}
	converti(head);	
	max=head->dec;
	finder=malloc(sizeof(struct list));
	finder=head;
	for(i=0;i<conta;i++){
		if(finder->dec>max)
			max=finder->dec;
		finder=finder->prossimo;
		}
	return max;
}

int main(){
	char expr[]="2 101 3 2 8 1111";
	int max;
	if(conta_numeri(expr)%2!=0){
		printf("Mi spiace, nella stringa expr devono esserci coppie di numeri, perciò devono esserci un numero pari di numeri\n");
		return 0;
		}
	max=max_basi(expr);
	printf("%d\n",max);
	return 0;
}
