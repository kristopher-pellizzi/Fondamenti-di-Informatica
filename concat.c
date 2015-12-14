#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int len(char* string){
	int length=0,i;
	for(i=0;string[i]!='\0';i++){
		length++;}
	return length;}

void plen(int l,char* s){
	printf("La %s  stringa e lunga %d caratter",s, l);
	if(l==1)
		printf("e\n");
	else
		printf("i\n");}

void copy(char* origine, char* destinazione){
	int i,l;
	l=len(origine);
	for(i=0;i<l;i++){
		destinazione[i]=origine[i];}
	}

char * concat(char *a, char* b){
	char* c;
	int la,lb;
	printf("Inizio funzione\n");
	la=len(a);
	lb=len(b);
	plen(la,"prima");
	plen(lb,"seconda");
	c=malloc(sizeof(char)*(la+lb+1));
	copy(a,c);
	copy(b,c+la);
	printf("Fine funzione\n");
	return c;
	}

int main(){
	char s1[MAX], s2[MAX];
	char* c;
	printf("Inserisci la prima stringa: ");
	scanf("%s", s1);
	printf("Inserisci la seconda stringa: ");
	scanf("%s", s2);
	printf("La prima stringa e: %s\n", s1);
	printf("La seconda stringa e: %s\n", s2);
	printf("La concatenazione e: %s%s\n", s1, s2);
	c=concat(s1,s2);
	printf("La funzione restituisce: %s\n", c);
	return 0;}
