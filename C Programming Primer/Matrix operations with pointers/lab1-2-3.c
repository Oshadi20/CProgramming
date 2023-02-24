// general purpose standard C lib
#include <stdio.h>
#include <stdlib.h> // stdlib includes malloc() and free()

// user-defined header files
#include "chain.h"

// function prototypes
void print_chain(chain * chn); 
void run(chain * chn);


int main()
{
    chain * chn = (chain *) malloc(sizeof(chain));
    chn->head = NULL;
	run(chn);
    print_chain(chn);
    free(chn);
	return 0;
}

// parse the input
void run(chain *chn) 
{
	int num_rows;
	scanf("%d",&num_rows);
	
	matrix *newMat = (matrix*)malloc(sizeof(matrix));
	
	if(num_rows>=3){
		newMat = create_matrix(num_rows,num_rows+1);
	}else{
		newMat = create_matrix(num_rows,num_rows);
	}
	
	//put data to matrix
	for(int i=0; i<newMat->num_rows;i++){
		for(int j=0;j<newMat->num_cols;j++){
			scanf("%d",&(newMat->data[i][j]));
		}
	}
	//insert head node(initial matrix as head node)
	insert_node_after(chn, -1, newMat);
	
	int funNo = 1;
	
	while(funNo != 0){
		scanf("%d",&funNo);
		if(funNo == 2){
			//new row
			int newRow[newMat->num_cols];
			//input data for new row
			for(int i=0; i < newMat->num_cols;i++){
				scanf("%d",&(newRow[i]));
			}
			add_row(newMat,newRow);
			//add to linked list
			insert_node_after(chn,-1,newMat);
		}
		else if(funNo == 3){
			//new column
			int newCol[newMat->num_rows];
			//input data for new column
			for(int i=0; i < newMat->num_rows;i++){
				scanf("%d",&(newCol[i]));
			}
			add_col(newMat,newCol);
			//add to linked list
			insert_node_after(chn,-1,newMat);
		}
		else if(funNo == 4){
			int num;
			scanf("%d",&num);
			increment(newMat,num);
			//add to linked list
			insert_node_after(chn,-1,newMat);
		}
		else if(funNo == 5){
			int num;
			scanf("%d",&num);
			scalar_multiply(newMat,num);
			//add to linked list
			insert_node_after(chn,-1,newMat);
		}
		else if(funNo == 6){
			int num;
			scanf("%d",&num);
			scalar_divide(newMat,num);
			//add to linked list
			insert_node_after(chn,-1,newMat);
		}
		else if(funNo == 7){
			int num;
			scanf("%d",&num);
			scalar_power(newMat,num);
			//add to linked list
			insert_node_after(chn,-1,newMat);
		}
		else if(funNo == 8){
			delete_matrix(newMat);
		}
		else{
			break;
		}
	}
}

//Print the chain
void print_chain(chain * chn)
{
	//number of elements in the linkedlist
	node *temp = chn->head;
	int noEle = 0;
	if(temp != NULL){
		noEle++;
		temp = temp->next;
	}
	while(temp != chn->head){
		noEle++;
		temp = temp->next;
	}
	
	node *currNode = chn->head;
	for(int i=0;i<noEle;i++){
		print_matrix(currNode->mat);
		currNode = currNode->next;
	}
	
	
}

