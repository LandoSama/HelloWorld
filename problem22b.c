#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodes{
		char name[25]; //store name
		int len;
		struct nodes *next; //reference to the next node
}node; 																																																																																																																																																																																																																																																																					

node * add_link(FILE * fp){
	int quote, wordLen;
	char c;
	
	quote = 0;
	node *head = NULL;//empty linked list
	node *temp; //create a temporary node
	/*
	printf("'head' pointer declared\t points to %p\n", head);
	printf("'temp' pointer declared\t points to %p\n", temp);
	printf("'head' location: %p\n",head);
	*/
	while((c = fgetc(fp)) != EOF){
		
		if(c == '\"'){
			++quote;
			//printf("char is equal to \", there are %i \"\n\n", quote);
			if(quote == 1){
				//node *temp; //create a temporary node
				temp = (node *)malloc(sizeof(node));
				temp->next = head;
				head = temp;
				/*
				printf("------temp node created------\n\n");
				printf("'temp' node location: %p\n", temp);
				printf("temp->next location: %p\n", temp->next);
				printf("'head' location: %p\n", head);
				*/
			}
			else if(quote == 2){
				temp->len = wordLen;
				wordLen = 0;
				//printf("final name: %s\t at %p location\n", temp->name, temp);
				quote = 0;
			}
			else{
				printf("error\n");
			}
		}
		else if(c == ','){
			quote = 0;
		}
		else if(quote == 1){
			temp->name[wordLen] = c;
			//printf("c: %c\twordLen: %i\ttemp->name[wordLen]: %c\n", c,wordLen,temp->name[wordLen]);
			++wordLen;
		}
		else if(c == '\n'){
			printf("newline reached\n");
			break;
		}
		else{
			printf("problem\n");
			break;
		}
	}
	
	rewind(fp);
	fclose(fp);
	return head;
}

node * sort_list(node * head){
	node *temp1;
	temp1 = (node *)malloc(sizeof(node));
	
	node *temp2;
	temp2 = (node *)malloc(sizeof(node));
	
	char temp[25];
	
	for(temp1=head; temp1!=NULL; temp1=temp1->next){
		for(temp2=temp1->next; temp2!=NULL; temp2=temp2->next){
			if(temp1->name[0] > temp2->name[0]){
				strcpy(temp,temp1->name);
				strcpy(temp1->name, temp2->name);
				strcpy(temp2->name,temp);
			}
		}
	}
	return head;
}

int main(int argc, char *argv[]){
	
	FILE *fp;
	fp = fopen(argv[1], "r");
	rewind(fp);
	
	node * head1 = add_link(fp);

	head1 = sort_list(head1);
	
	node *temp1;
	temp1 = (node *)malloc(sizeof(node));
	temp1 = head1;
	
	while(temp1 != NULL){
		printf("name: %s\tnumber of letters: %i\n",temp1->name, temp1->len);
		temp1 = temp1->next;
	}
	printf("name: %s\n", head1->name);
	return 0;			
}
																																																																								
