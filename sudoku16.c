#include <stdio.h>
#include <stdlib.h>

#define O 4
#define DIM (O*O)
int nodupes(int array[DIM]){
	int i;
	int hits[DIM];
	for(i=0;i<DIM;i++)
		hits[i]=0;
	for(i=0;i<DIM;i++){
		if(array[i]!=0){
			(hits[array[i]-1])++;
			if(hits[array[i]-1]>1)
				return 0;
		}
	}
	return 1;
}

int* estrai_riga(int m[DIM][DIM],int riga){
	int *ritorno;
	int i;
	ritorno=malloc(sizeof(int)*DIM);
	for(i=0;i<DIM;i++)
		ritorno[i]=m[riga][i];
	return ritorno;
}

int* estrai_colonna(int m[DIM][DIM],int colonna){
	int* ritorno;
	int i;
	ritorno=malloc(sizeof(int)*DIM);
	for(i=0;i<DIM;i++)
		ritorno[i]=m[i][colonna];
	return ritorno;
}

int* estrai_quadro(int m[DIM][DIM], int x, int y){
	int i,j,k=0;
	int* ritorno=malloc(sizeof(int)*DIM);
	for(i=0;i<O;i++)
		for(j=0;j<O;j++)
			ritorno[k++]=m[x+i][y+j];
	return ritorno;
}

int corretto(int m[DIM][DIM]){
	int i,j;
	for(i=0;i<DIM;i++)
		for(j=0;j<DIM;j++){
			if(nodupes(estrai_riga(m,i))==0 || nodupes(estrai_colonna(m,j))==0)
				return 0;
			if(i%O==0 && j%O==0 && j!=DIM)
				if(nodupes(estrai_quadro(m,i,j))==0)
					return 0;
		}
	return 1;
}

int *prima_libera(int m[DIM][DIM]){
	int i,j;
	for(i=0;i<DIM;i++)
		for(j=0;j<DIM;j++)
			if(m[i][j]==0){
				return &(m[i][j]);
				}
	return NULL;
}

void stampa_m(int m[DIM][DIM]){
	int i,j;
	for(i=0;i<DIM;i++){
		for(j=0;j<DIM;j++)
			printf("%d\t",m[i][j]);
		printf("\n");
	}
}

int risolvi(int m[DIM][DIM]){
	int* p;
	int i;
	if(!corretto(m))
		return 0;
	if(prima_libera(m)==NULL)
		return 1;
	p=prima_libera(m);
	for(i=1;i<=DIM;i++){
		*p=i;
		if(risolvi(m))
			return 1;}
	*p=0;
	return 0;
}

int main(){
	int  m[DIM][DIM]={{1,9,2,4,7,0,5,15,0,0,0,0,6,0,0,0},{12,14,0,0,4,9,11,0,7,0,8,0,0,0,3,0},{16,0,0,15,2,12,0,0,4,0,0,0,0,9,11,0},{0,0,0,8,0,6,3,0,2,1,9,14,15,0,0,12},{2,10,14,9,12,0,0,0,11,0,0,0,0,6,8,4},{4,0,0,7,8,16,0,9,0,0,6,1,0,13,0,0},{8,0,1,0,0,2,0,0,9,5,0,0,0,7,0,0},{3,0,6,0,14,7,13,0,12,8,16,4,0,0,9,0},{0,12,0,0,11,14,7,8,0,4,2,13,0,3,0,5},{0,0,11,0,0,0,16,12,0,0,15,0,0,2,0,6},{0,0,9,0,3,5,0,0,8,0,14,12,4,0,0,11},{5,7,4,0,0,0,0,2,0,0,0,10,14,12,13,8},{9,0,0,16,10,3,12,6,0,14,1,0,8,0,0,0},{0,1,3,0,0,0,0,7,0,0,4,2,12,0,0,13},{0,6,0,0,0,13,0,4,0,9,12,8,0,0,10,3},{0,0,0,12,0,0,0,0,10,6,0,7,5,4,15,9}};
	int i;
	stampa_m(m);
	if(!risolvi(m))
		printf("\nNon risolvibile\n");
	printf("\n");
	stampa_m(m);
}
