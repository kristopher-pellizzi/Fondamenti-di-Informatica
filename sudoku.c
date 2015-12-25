#include <stdio.h>
#include <stdlib.h>

#define O 3
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
	int  m[DIM][DIM]={{7,0,0,0,0,0,2,0,0},{4,0,2,0,0,0,0,0,3},{0,0,0,2,0,1,0,0,0},{3,0,0,1,8,0,0,9,7},{0,0,9,0,7,0,6,0,0},{6,5,0,0,3,2,0,0,1},{0,0,0,4,0,9,0,0,0},{5,0,0,0,0,0,1,0,6},{0,0,6,0,0,0,0,0,8}};
	int i;
	stampa_m(m);
	if(!risolvi(m))
		printf("\nNon risolvibile\n");
	printf("\n");
	stampa_m(m);
}
