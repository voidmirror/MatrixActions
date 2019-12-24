#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include <conio.h>
#include "Functions.h"

/*
	ACTIONS

	action1 = transposing
	action5 = reverse matrix
*/

/*
	FOR COPY

	result, global2, global3, action, dim
*/

/*
	HELP

	//----- ... 87
*/

/*
	Сделать зацикливание каждой функции, пока не понадобится пользователю.
*/

int(*menu(void)) (int *result, int **global2, int **global3, int *action, int *dim) {
	int choice;
	int(*menu_items[])(int *result, int **global2, int **global3, int *action, int *dim) = { transpos, multiply, determinant, cofactor, reverse };

	printf("1. Transposition.\n");
	printf("2. Multiply.\n");
	printf("3. Determinant.\n");
	printf("4. Cofactor matrix (2x2 or 3x3 only) DOESN\'T WORK.\n");
	printf("5. Reverse matrix (2x2 or 3x3 only) DOESN\'T WORK.\n");
	printf("Enter number of operation: ");
	scanf("%d", &choice);
	system("cls");
	if ((choice > 0) && (choice < 6)) {
		return menu_items[choice - 1];
	}
	else {
		return NULL;
	}
}

int main() {
	int res, _act = 0, _dimension;
	int *result, *action, *dim;
	int(*fn)(int*, int**, int**, int*, int*);
	int **global2, **global3;
	
	result = &res;
	*result = NULL;
	action = &_act;
	dim = &_dimension;

	global2 = (int**)malloc(2 * sizeof(int*));
	for (int i = 0; i < 2; i++) {
		global2[i] = (int*)malloc(2 * sizeof(int));
	}
	global3 = (int**)malloc(3 * sizeof(int*));
	for (int i = 0; i < 3; i++) {
		global3[i] = (int*)malloc(3 * sizeof(int));
	}

	while (1) {
		fn = menu();
		if (fn == NULL) {
			printf("There is nothing.\n");
			return 0;
		}
		int t = fn(result, global2, global3, action, dim);
		
		printf("result: %d\n\n", *result);
		
		//printf("\nt = %d\n", t);	//Number of executed operation
	}

	//Clear global matrix
	for (int i = 0; i < 2; i++) {
		free(global2[i]);
	}
	free(global2);
	for (int i = 0; i < 3; i++) {
		free(global3[i]);
	}
	free(global3);
	
}