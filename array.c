#include <stdio.h>
#include <stdlib.h>

#define F 2

int * aggiungi_numero(int *p, int size, int n ,int val){
	int * new_p,i;
	if(n==size){
		size=size*F;
		new_p=malloc(sizeof(int)*size);
		for(i=0;i<n;i++){
			new_p[i]=p[i];}
		new_p[n]=val;
		return new_p;}
	p[n]=val;
	return NULL;}

int main(){
	int i=0,val,size=1,c=0;
	int *p,*new_p;
	p=malloc(sizeof(int)*size);
	do{
		printf("Inserisci il numero da inserire: ");
		scanf("%d",&val);
		new_p=aggiungi_numero(p,size,c,val);
		if(new_p!=NULL){
			p=new_p;
			size=size*F;}
		c++;
		for(i=0;i<c;i++){
			printf("%p --> %d\n",p+i,*(p+i));}
		printf("SIZE: %i\n",size);
		printf("DISPONIBILI: %i\n",size-c);
		printf("\n");
	} while(val!=0);}
