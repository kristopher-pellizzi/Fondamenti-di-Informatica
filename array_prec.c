#include <stdio.h>
#include <stdlib.h>

#define F 2

int * aggiungi_numero(int val, int n, int size, int *p){
	int *new_p,i;
	if(n==size){
		size=size*F;
		new_p=malloc(sizeof(int)*size);
		for(i=0;i<n;i++)
			new_p[i]=p[i];
		new_p[n]=val;
		return new_p;}
	p[n]=val;
	return NULL;}

int main(){
	int disp=0,*p,*new_p,i,c=0,size=1,val;
	do{
	printf("Inserisci il numero da inserire nell'array: ");
	scanf("%d", &val);
	new_p=aggiungi_numero(val,c,size,p);
	if(new_p!=NULL){
		p=new_p;
		free(new_p);
		size=size*F;}
	c++;
	for(i=0;i<c;i++){
		printf("%p --> %d\n",&p[i],p[i]);}
	printf("SIZE: %i\n",size);
	printf("DISPONIBILI: %i\n",size-c);
	disp=size-c;
	printf("\n");
	}while(val!=0);
	size=size-disp;
	new_p=malloc(sizeof(int)*size);
	for(i=0;i<size;i++){
		new_p[i]=p[i];
		printf("%p --> %d\n",new_p+i,new_p[i]);}
	printf("\n");
	}
