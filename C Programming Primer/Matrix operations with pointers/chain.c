#include <stdio.h>
#include <stdlib.h> // includes malloc(), free(), realloc()
#include <string.h> // includes memcpy()

#include "chain.h" // do not modify this file

// put your function prototypes for additional helper functions below:


// implementation
matrix *create_matrix(int num_rows, int num_cols)
{   
    // TODO
	matrix *newMat = (matrix*)malloc(sizeof(matrix));
	newMat->num_rows = num_rows;
	newMat->num_cols = num_cols;
	
	//int **newData = (int**)malloc(sizeof(int*)*num_cols*num_rows);
	newMat->data = malloc(sizeof(int)*num_rows);
	for(int i=0;i<num_rows;i++){
		newMat->data[i] = malloc(sizeof(int)*num_cols); 
	}
	
	for(int j=0;j<num_rows;j++){
		for(int k=0;k<num_cols;k++){
			newMat->data[j][k] = 0;
		}
	}
    return newMat;
}

void add_row(matrix *mat, int *row)
{
    // TODO
    int newRow = malloc(sizeof(int)*mat->num_cols);
    mat->num_rows += 1;
    mat->data = (int*)realloc(mat->data,sizeof(int)*(mat->num_rows));
    mat->data[(mat->num_rows)-1] = newRow;
    for(int i =0; i<num_cols;i++){
    	mat->data[(mat->num_rows)-1][i] = row[i];
	}
    
//    mat->data = realloc(mat->data,mat->num_rows+1);
//    mat->data[mat->num_rows] = malloc(sizeof(int)*mat->num_cols);
//    //int n = sizeof(row)/sizeof(row[0]); //size of row array
//    for(int i=0;i<mat->num_cols;i++){
//    	mat->data[mat->num_rows][i] = row[i];
//	}
	return;
}

void add_col(matrix *mat, int *col)
{
    // TODO
    int newCol = malloc(sizeof(int)*mat->num_rows);
    mat->num_cols += 1;
    mat->data = (int*)realloc(mat->data,sizeof(int)*(mat->num_cols));
    mat->data[(mat->num_cols)-1] = newCol;
    for(int i =0; i<num_rows;i++){
    	mat->data[(mat->num_cols)-1][i] = col[i];
	}
    
//    for(int i=0;i<mat->num_rows;i++){
//    	mat->data[i] = realloc(mat->data[i],mat->num_cols+1);
//	}
//	//int n = sizeof(col)/sizeof(col[0]); //size of col array
//	for(int j=0;j<mat->num_rows;j++){
//		int newCol = mat->num_cols;
//		mat->data[j][newCol] = col[j];
//	}
	return;
}

void increment(matrix *mat, int num)
{
    // TODO
    for(int i=0;i<mat->num_rows;i++){
    	for(int j=0; j<mat->num_cols;j++){
    		mat->data[i][j] = (mat->data[i][j]) + num;
		}
	}
	return;
}

void scalar_multiply(matrix *mat, int num)
{
    // TODO
    for(int i=0;i<mat->num_rows;i++){
    	for(int j=0; j<mat->num_cols;j++){
    		mat->data[i][j] = (mat->data[i][j]) * num;
		}
	}
	return;
}

void scalar_divide(matrix *mat, int num)
{
    // TODO
    for(int i=0;i<mat->num_rows;i++){
    	for(int j=0; j<mat->num_cols;j++){
    		mat->data[i][j] = (mat->data[i][j]) / num;
		}
	}
	return;
}

void scalar_power(matrix *mat, int num)
{
    // TODO
    for(int i=0;i<mat->num_rows;i++){
    	for(int j=0; j<mat->num_cols;j++){
    		mat->data[i][j] = powerOfNum((mat->data[i][j]), num);
		}
	}
	return;
}

void delete_matrix(matrix *mat)
{
    // TODO
    for(int i=0;i<mat->num_rows;i++){
    	free(mat->data[i]);
	}
	free(mat->data);
	free(mat);
	return;
    
}

int powerOfNum(int base,int exp){
	long int result = 1;
	while(exp != 0){
		result *= base;
		exp--;
	}
	return result;
}
/*
    DO NOT MODIFY BELOW
*/
// print out matrix in row-major order
// elements in the same row are space-separated
// each row starts in a new line
void print_matrix(matrix *mat) 
{
    int row_idx, col_idx;
    for(row_idx = 0; row_idx < mat->num_rows; ++row_idx) {
        for(col_idx = 0; col_idx < mat->num_cols; ++col_idx) {
            if (col_idx == mat->num_cols-1) {
                printf("%d\n", mat->data[row_idx][col_idx]);
            } else {
                printf("%d ", mat->data[row_idx][col_idx]);
            }
        }
    }
}

//Add the rest of the functions needed for the chain below

void insert_node_before(chain *chn, int index, matrix *mat){
	//create a pointer to store a new node
	node *newNode = (node *)malloc(sizeof(node));
	//create a pointer to store the matrix of a node
	matrix *newMat = (matrix *)malloc(sizeof(matrix));
	
	//put data
	newMat = mat;
	newNode->mat = newMat;
	//put nodes
	newNode->next = NULL;
	newNode->prev = NULL;
	
	//check for empty
	if(chn->head == NULL){
		//set newNode as head
		chn->head = newNode;
		newNode->next = newNode;
		newNode->prev = newNode;
		return;
	}
	
	//pointer to iterate through the list to find the corresponding node
	node *temp = chn->head;
	//insert before any node, but not head node
	//if index is positive, increment
	if(index > 0){
		//find node corresponds to index
		for(int i=0; i<index; i++){
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
		for(int j=0; j>index; j--){
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

void insert_node_after(chain *chn, int index, matrix *mat){
	//create a pointer to store a new node
	node *newNode = (node *)malloc(sizeof(node));
	//create a pointer to store the matrix of a node
	matrix *newMat = (matrix *)malloc(sizeof(matrix));
	
	//put data
	newMat = mat;
	newNode->mat = newMat;
	
	//put nodes
	newNode->next = NULL;
	newNode->prev = NULL;
	
	//check for empty
	if(chn->head == NULL){
		//set newNode as head
		chn->head = newNode;
		newNode->next = newNode;
		newNode->prev = newNode;
		return;
	}
	
	//pointer to iterate through the list to find the corresponding node
	node *temp = chn->head;
	//insert after any node, but not head node
	//if index is positive, increment
	if(index>0){
		//find node corresponds to index
		for(int i=0; i<index; i++){
			temp = temp->next;
		}
		newNode->next = temp->next;
		newNode->prev = temp;
		temp->next->prev = newNode;
		temp->next = newNode;
		return;
	}
	//if index is negative, decrement
	else{
		//find node corresponds to index
		for(int j=0; j>index; j--){
			temp = temp->prev;
		}
		newNode->next = temp->next;
		newNode->prev = temp;
		temp->next->prev = newNode;
		temp->next = newNode;
		return;
	}	
	return;
}

void delete_node(chain *chn, int index){
	//if linked lis is empty, return nothing
	if(chn->head == NULL){
		return;
	}
	
	//pointer 
	node *temp = chn->head;
	
	if(index>0){
		//find the node
		for(int i=0; i<index; i++){
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
		for(int j=0; j<index; j--){
			temp = temp->prev;
		}
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		
		//delete temp node
		free(temp);
		return;
	}
	return;
}

void delete_list(chain *chn){
	//pointers
	node *headNode = chn->head;
	node *curr = chn->head;
	//node *temp;
	
	curr = curr->next;
	while(curr != headNode){
		node *temp = curr;
		curr = curr->next;
		free(temp); //delete node
	}
	
	//delete head node
	free(headNode);
	return;
}
