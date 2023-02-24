// general purpose standard C lib
#include <stdio.h>
#include <stdlib.h> // includes malloc(),free()
#include <string.h> // includes strlen(), memcpy()
#include <ctype.h> // includes toupper(), tolower()

// user-defined header files
#include "node.h" // do not modify this file

// put your function prototypes for additional helper functions below:


// implementation
void insert_node_before(list *lst, int index, char *word)
{	
	// TODO
	//create a pointer to store a new node
	node *newNode = (node *)malloc(sizeof(node));
	//create a pointer to store the data(word) of a node
	char *newWord = (char *)malloc(sizeof(char)*50);
	
	//put data
	newWord = word;
	newNode->word = newWord;
	//put nodes
	newNode->next = NULL;
	newNode->prev = NULL;
	
	//check for empty
	if(lst->head == NULL){
		//set newNode as head
		lst->head = newNode;
		newNode->next = newNode;
		newNode->prev = newNode;
		return;
	}
	
	//pointer to iterate through the list to find the corresponding node
	node *temp = lst->head;
	//insert before any node, but not head node
	//if index is positive, increment
	if(index > 0){
		//find node corresponds to index
		int i;
		for(i=0;i<index;i++){
			temp = temp->next;
		}
		
		newNode->next = temp;
		newNode->prev = temp->prev;
		temp->prev->next = newNode;
		temp->prev = newNode;
		return;	
	}
	//if index is negative, decrement
	else{
		//find node corresponds to index
		int j;
		for(j=0;j>index;j--){
			temp = temp->prev;
		}
		newNode->next = temp;
		newNode->prev = temp->prev;
		temp->prev->next = newNode;
		temp->prev = newNode;
		return;	
	}
	return;
}

void insert_node_after(list *lst, int index, char *word)
{
	// TODO
	//create a pointer to store a new node
	node *newNode = (node *)malloc(sizeof(node));
	//create a pointer to store the data(word) of a node
	char *newWord = (char *)malloc(sizeof(char)*50);
	
	//put data
	strcpy(newWord,word);
	newNode->word = newWord;
	
	//put nodes
	newNode->next = NULL;
	newNode->prev = NULL;
	
	//check for empty
	if(lst->head == NULL){
		//set newNode as head
		lst->head = newNode;
		newNode->next = newNode;
		newNode->prev = newNode;
		return;
	}
	
	//pointer to iterate through the list to find the corresponding node
	node *temp = lst->head;
	//insert after any node, but not head node
	//if index is positive, increment
	if(index>0){
		//find node corresponds to index
		int i;
		for(i=0;i<index;i++){
			temp = temp->next;
		}
		newNode->next = temp->next;
		newNode->prev = temp;
		temp->next = newNode;
		temp->next->prev = newNode;
		return;
	}
	//if index is negative, decrement
	else{
		//find node corresponds to index
		int j;
		for(j=0;j>index;j--){
			temp = temp->prev;
		}
		newNode->next = temp->next;
		newNode->prev = temp;
		temp->next = newNode;
		temp->next->prev = newNode;
		return;
	}	
	return;
}

char *list_to_sentence(list *lst)
{
	// TODO
	node *headNode = lst->head;
	node *temp = lst->head;
	
	char *sentence = temp->word;
	//concatanate words
	temp = temp->next;
	while(temp != headNode){
		strcat(sentence," ");
		strcat(sentence, temp->word);
		temp = temp->next;
	}
	
    return sentence; // Change this line accordingly
}

void delete_node(list *lst, int index)
{
	// TODO
	//if linked lis is empty, return nothing
	if(lst->head == NULL){
		return;
	}
	
	//pointer 
	node *temp = lst->head;
	
	if(index>0){
		//find the node
		int i;
		for(i=0;i<index;i++){
			temp = temp->next;
		}
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		
		//delete temp node
		free(temp);
		return;
	}
	else{
		//find the node
		int j;
		for(j=0;j<index;j--){
			temp = temp->prev;
		}
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		
		//delete temp node
		free(temp);
		return;
	}
	
}

void delete_list(list *lst)
{
	// TODO
	//pointers
	node *headNode = lst->head;
	node *curr = lst->head;
	node *temp;
	
	curr = curr->next;
	while(curr != headNode){
		temp = curr;
		curr = curr->next;
		free(temp); //delete node
	}
	
	//delete head node
	free(headNode);
	return;
}
