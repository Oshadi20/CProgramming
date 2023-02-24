// general purpose standard C lib
#include <stdio.h>
#include <stdlib.h> // stdlib includes malloc() and free()
#include <string.h>
// user-defined header files
#include "node.c"
//#include "node.c"

// macros

#define INSERT_BEFORE 1
#define INSERT_AFTER 2
#define DELETE_NODE 3
#define DELETE_LIST 4

// function prototypes
void print_list(list * lst); 
void run(list * lst);


int main()
{
    list * lst = (list *) malloc(sizeof(list));
    lst->head = NULL;
	run(lst);
    print_list(lst);
    free(lst);
	return 0;
}

// parse the input
void run(list *lst) 
{	
	char inputStr[100];
	scanf("%s",inputStr);
	
	//split
	char *token = strtok(inputStr,",");
	
	int i = 0;
	
	while(token != NULL){
		insert_node_after(lst,i-1,token);
		i++;
		token = strtok(NULL,",");
	}
	
	int terNo = 1;
	while(terNo == 1){
		int funNo, indexNo;
		char *word = (char *)malloc(sizeof(char)*20);
		scanf("%d",&funNo);
		//check
		switch(funNo){
			case INSERT_BEFORE :
				scanf("%d %s",&indexNo,word);
				insert_node_before(lst, indexNo, word);
				break;
			case INSERT_AFTER :
				scanf("%d %s",&indexNo,word);
				insert_node_after(lst, indexNo, word);
				break;
			case DELETE_NODE :
				scanf("%d",&indexNo);
				delete_node(lst, indexNo);
				break;
			case DELETE_LIST :
				delete_list(lst);
				break;
			case 0 :
				terNo = 0;
				break;
		}
	}
	
	
}

//Print the list contents
void print_list(list * lst)
{
   char *outSen;
   outSen = list_to_sentence(lst);
   printf("%s",outSen);
}

