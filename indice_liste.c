#include <stdio.h>
#include <stdlib.h>

struct node{
	int numero;
	int contatore;
	struct node* prossimo;};

void stampa_lista(struct node* head){
	if(head->prossimo==NULL)
		printf("%d (%d)\n",head->numero,head->contatore);
	else{
		printf("%d (%d)\n",head->numero,head->contatore);
		stampa_lista(head->prossimo);}}

void append(int n, struct node* head){
	struct node* new;
	if(head->prossimo==NULL)
		{new=malloc(sizeof(struct node));
		new->numero=n;
		new->contatore=1;
		new->prossimo=NULL;
		head->prossimo=new;}
	else
		append(n,head->prossimo);}

void push(int n, struct node** head){
	struct node* new,tmp;
	new=malloc(sizeof(struct node));
	new->numero=n;
	new->contatore=1;
	new->prossimo=*head;
	*head=new;}

void insert(int n, struct node** head){
	struct node* new_elem=malloc(sizeof(struct node));
	if(*head==NULL || n<(*head)->numero){
		new_elem->numero=n;
		new_elem->contatore=1;
		new_elem->prossimo=*head;
		*head=new_elem;
		}
	else{
		if((*head)->numero==n){
			(*head)->contatore++;
			}
		else{
			insert(n,&((*head)->prossimo));
			}
		}
	}

struct node* last(struct node* head){
	if(head->prossimo==NULL)
		return head;
	else
		return last(head->prossimo);}

int main(){
	int i;
	struct node* head=NULL;
	for(i=0;i<10;i++)
		insert(i*i,&head);
	for(i=0;i<10;i++)
		insert(i*i*i,&head);
	stampa_lista(head);
	}
