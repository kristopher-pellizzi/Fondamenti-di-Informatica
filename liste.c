#include <stdio.h>
#include <stdlib.h>

struct node{
	int numero;
	struct node* prossimo;};

void stampa_lista(struct node* head){
	if(head->prossimo==NULL)
		printf("%d\n",head->numero);
	else{
		printf("%d -> ",head->numero);
		stampa_lista(head->prossimo);}}

void append(int n, struct node* head){
	struct node* new;
	if(head->prossimo==NULL)
		{new=malloc(sizeof(struct node));
		new->numero=n;
		new->prossimo=NULL;
		head->prossimo=new;}
	else
		append(n,head->prossimo);}

void push(int n, struct node** head){
	struct node* new,tmp;
	new=malloc(sizeof(struct node));
	new->numero=n;
	new->prossimo=*head;
	*head=new;}

struct node* last(struct node* head){
	if(head->prossimo==NULL)
		return head;
	else
		return last(head->prossimo);}

int main(){
	struct node* head;
	struct node* last_elem;
	int i;
	head->numero=13;
	head->prossimo=NULL;
	stampa_lista(head);
	for(i=0;i<10;i++)
		push(i*i,&head);
	stampa_lista(head);
	last_elem=last(head);
	last_elem->prossimo=head;
	return 0;}
