#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <time.h>
#include "Functions.h"

//TRANSPOSING-------------------------------------------------------------------------
int transpos(int *result, int **global2, int **global3, int *action, int *dim) {
	int string, column;
	int **matr, **copyMatr;

	//initialization
	

	if (*action == 1) {
		string = *dim;			//result = dimension
		column = *dim;
		
		matr = (int**)malloc(string * sizeof(int*));
		for (int i = 0; i < string; i++) {
			matr[i] = (int*)malloc(column * sizeof(int));
		}
		for (int i = 0; i < string; i++) {
			for (int j = 0; j < column; j++) {
				matr[i][j] = global2[i][j];
			}
		}	
	}
	else {
		printf("Enter matrix Strng: ");
		scanf("%d", &string);
		printf("Enter matrix Column: ");
		scanf("%d", &column);

		printf("Enter matrix elements by rows.\n");

		matr = (int**)malloc(string * sizeof(int*));			// WARNING!
		for (int i = 0; i < string; i++) {
			matr[i] = (int*)malloc(column * sizeof(int));
		}
		for (int i = 0; i < string; i++) {
			for (int j = 0; j < column; j++) {
				scanf("%d", &matr[i][j]);
			}
		}
	}
	

	//Creating a copy
	copyMatr = (int**)malloc(string * sizeof(int*));
	for (int i = 0; i < string; i++) {
		copyMatr[i] = (int*)malloc(column * sizeof(int));
	}
	for (int i = 0; i < string; i++) {
		for (int j = 0; j < column; j++) {
			copyMatr[i][j] = matr[i][j];
		}
	}

	//Recreating answer-matrix
	for (int i = 0; i < string; i++) {
		free(matr[i]);
	}
	free(matr);
	matr = (int**)malloc(column * sizeof(int*));
	for (int i = 0; i < column; i++) {
		matr[i] = (int*)malloc(string * sizeof(int));
	}
	
	printf("\n");
	printf("Your matrix:\n");
	for (int i = 0; i < string; i++) {
		for (int j = 0; j < column; j++) {
			printf("%3.1d ", copyMatr[i][j]);
		}
		printf("\n");
	}

	//Trasposition
	for (int i = 0; i < column; i++) {
		for (int j = 0; j < string; j++) {
			matr[i][j] = copyMatr[j][i];
		}
	}
	printf("\n");
	printf("Transposition: \n");
	for (int i = 0; i < column; i++) {
		for (int j = 0; j < string; j++) {
			printf("%3.1d ", matr[i][j]);
		}
		printf("\n");
	}

	//Copy to global2 or global3
	if ((string == 3) && (column == 3)) {
		for (int i = 0; i < column; i++) {
			for (int j = 0; j < string; j++) {
				global3[i][j] = matr[i][j];
			}
		}
	}
	if ((string == 2) && (column == 2)) {
		for (int i = 0; i < column; i++) {
			for (int j = 0; j < string; j++) {
				global2[i][j] = matr[i][j];
			}
		}
	}

	/*
	//Print global3-----------------------------------
	printf("\n");
	printf("global3:\n");
	for (int i = 0; i < column; i++) {
		for (int j = 0; j < string; j++) {
			printf("%3.d ", global3[i][j]);
		}
		printf("\n");
	}
	*/

	//End of Transposition

	//Delete matrix
	for (int i = 0; i < column; i++) {
		free(matr[i]);
	}
	free(matr);
	for (int i = 0; i < string; i++) {
		free(copyMatr[i]);
	}
	free(copyMatr);

	printf("\n");
	printf("End of operation.\n\n");
	if (*action != 1) {
		return 1;
	}
}

int multiply(int *result, int **global2, int **global3, int *action, int *dim) {
	int string, column, string2, column2;
	int **matr, **firstMatrix, **secondMatrix;
	char square[5];

	while (1) {

		printf("Square matrix? (Y/y --> Yes, N/n --> No, end --> Exit): ");
		scanf("%s", &square);
		if (square[0] == 'e') {
			return 2;
		}
		//if (square)----------------------------------------------------------------!
		printf("Enter 1st matrix (A) String: ");
		scanf("%d", &string);
		printf("Enter 1st matrix (A) Column: ");
		scanf("%d", &column);
		if (square[0] == 'Y' || square[0] == 'y') {
			string2 = string;
			column2 = column;
		}
		else {
			printf("Enter 2d matrix (B) String: ");
			scanf("%d", &string2);
			printf("Enter 2d matrix (B) Column: ");
			scanf("%d", &column2);
		}

		if ((column != string2) && (string != column2)) {
			printf("Multipying is not available!\n\n");
			return 2;
		}

		printf("Enter matrix elements by rows.\n");

		srand(time(0));

		//firstMatrix
		firstMatrix = (int**)malloc(string * sizeof(int*));
		for (int i = 0; i < string; i++) {
			firstMatrix[i] = (int*)malloc(column * sizeof(int));
		}
		for (int i = 0; i < string; i++) {
			for (int j = 0; j < column; j++) {
				scanf("%d", &firstMatrix[i][j]);
			}
		}
		for (int i = 0; i < string; i++) {
			for (int j = 0; j < column; j++) {
				printf("%3.1d ", firstMatrix[i][j]);
			}
			printf("\n");
		}
		printf("\n");

		//secondMatrix
		secondMatrix = (int**)malloc(string2 * sizeof(int*));
		for (int i = 0; i < string2; i++) {
			secondMatrix[i] = (int*)malloc(column2 * sizeof(int));
		}
		if (square[0] == 'Y' || square[0] == 'y') {
			for (int i = 0; i < string2; i++) {
				for (int j = 0; j < column2; j++) {
					secondMatrix[i][j] = firstMatrix[i][j];
				}
			}
		}
		else {
			for (int i = 0; i < string2; i++) {
				for (int j = 0; j < column2; j++) {
					scanf("%d", &secondMatrix[i][j]);
				}
			}
			for (int i = 0; i < string2; i++) {
				for (int j = 0; j < column2; j++) {
					printf("%3.1d ", secondMatrix[i][j]);
				}
				printf("\n");
			}
			printf("\n");
		}

		//Multiply
		//First on Second
		if (column == string2) {
			matr = (int**)malloc(string * sizeof(int*));
			for (int i = 0; i < string; i++) {
				matr[i] = (int*)malloc(column2 * sizeof(int));
			}

			//Creating Answer-matrix
			for (int i = 0; i < string; i++) {
				for (int j = 0; j < column2; j++) {
					//matr[i][j] = rand() % 7 + 1;
					matr[i][j] = 1;
				}
			}
			/*
			for (int i = 0; i < string; i++) {
			for (int j = 0; j < column2; j++) {
			printf("%d ", matr[i][j]);
			}
			printf("\n");
			}
			*/

			//Multiplying
			for (int i = 0; i < string; i++) {
				for (int j = 0; j < column2; j++) {
					int element = 0;
					for (int k = 0; k < column; k++) {
						element += firstMatrix[i][k] * secondMatrix[k][j];
					}
					matr[i][j] = element;
				}
			}
			//Print result
			printf("\n");
			printf("Multiplying A*B:\n");
			for (int i = 0; i < string; i++) {
				for (int j = 0; j < column2; j++) {
					printf("%3.1d ", matr[i][j]);
				}
				printf("\n");
			}
			//End of 1st on 2d multiplying

			//Delete answer-matrix
			for (int i = 0; i < string; i++) {
				free(matr[i]);
			}
			free(matr);
		}

		if (square[0] != 'Y' && square[0] != 'y') {
			//Second on First
			if (string == column2) {
				matr = (int**)malloc(string2 * sizeof(int*));
				for (int i = 0; i < string2; i++) {
					matr[i] = (int*)malloc(column * sizeof(int));
				}

				//Creating Answer-matrix
				for (int i = 0; i < string2; i++) {
					for (int j = 0; j < column; j++) {
						//matr[i][j] = rand() % 7 + 1;
						matr[i][j] = 1;
					}
				}

				//Multiplying
				for (int i = 0; i < string2; i++) {
					for (int j = 0; j < column; j++) {
						int element = 0;
						for (int k = 0; k < column2; k++) {
							//element += firstMatrix[k][i] * secondMatrix[j][k];
							element += secondMatrix[i][k] * firstMatrix[k][j];
						}
						matr[i][j] = element;
					}
				}
				//Print result
				printf("\n");
				printf("Multiplying B*A:\n");
				for (int i = 0; i < string2; i++) {
					for (int j = 0; j < column; j++) {
						printf("%3.1d ", matr[i][j]);
					}
					printf("\n");
				}
				//End of 2d on 1st multiplying

				//Delete answer-matrix
				for (int i = 0; i < column; i++) {
					free(matr[i]);
				}
				free(matr);
			}
		}


		printf("\n");
		printf("End of operation.\n\n");		
	}
}

int determinant(int *result, int **global2, int **global3, int *action, int *dim) {
	int dimension;
	int **matr;

	if (*action == 3) {
		// Automatic------------------------------------------------------------------
		dimension = *dim;
		matr = (int**)malloc(dimension * sizeof(int*));
		for (int i = 0; i < dimension; i++) {
			matr[i] = (int*)malloc(dimension * sizeof(int));
		}
		if (dimension == 2) {
			for (int i = 0; i < dimension; i++) {
				for (int j = 0; j < dimension; j++) {
					matr[i][j] = global2[i][j];
				}
			}
		}
		if (dimension == 3) {
			for (int i = 0; i < dimension; i++) {
				for (int j = 0; j < dimension; j++) {
					matr[i][j] = global3[i][j];
				}
			}
		}
	}
	else {
		// Manual---------------------------------------------------------------------
		printf("How big is your matrix:\n2) 2x2\n3) 3x3\nEnter: ");
		scanf("%d", &dimension);
		printf("Enter matrix elements by rows.\n");

		matr = (int**)malloc(dimension * sizeof(int*));
		for (int i = 0; i < dimension; i++) {
			matr[i] = (int*)malloc(dimension * sizeof(int));
		}
		for (int i = 0; i < dimension; i++) {
			for (int j = 0; j < dimension; j++) {
				scanf("%d", &matr[i][j]);
			}
		}
		for (int i = 0; i < dimension; i++) {
			for (int j = 0; j < dimension; j++) {
				printf("%3.d ", matr[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
	
	// Counting-----------------------------------------------------------------------
	if (dimension == 2) {
		*result = matr[0][0] * matr[1][1] - matr[0][1] * matr[1][0];
		/*for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				global2[i][j] = matr[i][j];
			}
		}*/
	}

	if (dimension == 3) {
		*result = (matr[0][0] * matr[1][1] * matr[2][2]) + (matr[0][1] * matr[1][2] * matr[2][0]) + (matr[1][0] * matr[2][1] * matr[0][2]) - (matr[2][0] * matr[1][1] * matr[0][2]) - (matr[1][0] * matr[0][1] * matr[2][2]) - (matr[2][1] * matr[1][2] * matr[0][0]);
		/*for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				global3[i][j] = matr[i][j];
			}
		}*/
	}

	return 3;
}

int cofactor(int *result, int **global2, int **global3, int *action, int *dim) {
	int dimension;
	int **firstMatrix, **secondMatrix;

	if (*action == 4) {
		// Automatic------------------------------------------------------------------
		dimension = *dim;
		firstMatrix = (int**)malloc(dimension * sizeof(int*));
		for (int i = 0; i < dimension; i++) {
			firstMatrix[i] = (int*)malloc(dimension * sizeof(int));
		}
		if (dimension == 2) {
			for (int i = 0; i < dimension; i++) {
				for (int j = 0; j < dimension; j++) {
					firstMatrix[i][j] = global2[i][j];
				}
			}
		}
		if (dimension == 3) {
			for (int i = 0; i < dimension; i++) {
				for (int j = 0; j < dimension; j++) {
					firstMatrix[i][j] = global3[i][j];
				}
			}
		}
	}
	else {
		// Manual---------------------------------------------------------------------
		printf("How big is your matrix:\n2) 2x2\n3) 3x3\nEnter: ");
		scanf("%d", &dimension);
		printf("Enter matrix elements by rows.\n");

		firstMatrix = (int**)malloc(dimension * sizeof(int*));
		for (int i = 0; i < dimension; i++) {
			firstMatrix[i] = (int*)malloc(dimension * sizeof(int));
		}
		for (int i = 0; i < dimension; i++) {
			for (int j = 0; j < dimension; j++) {
				scanf("%d", &firstMatrix[i][j]);
			}
		}
		if (dimension == 2) {
			for (int i = 0; i < dimension; i++) {
				for (int j = 0; j < dimension; j++) {
					global2[i][j] = firstMatrix[i][j];
				}
			}
		}
		if (dimension == 3) {
			for (int i = 0; i < dimension; i++) {
				for (int j = 0; j < dimension; j++) {
					global3[i][j] = firstMatrix[i][j];
				}
			}
		}
		
		printf("\n");
		printf("firstMatrix:\n");
		for (int i = 0; i < dimension; i++) {			//Print firstMatrix
			for (int j = 0; j < dimension; j++) {
				printf("%3.d ", firstMatrix[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		
	}
	
	// Counting-----------------------------------------------------------------------
	secondMatrix = (int**)malloc(dimension * sizeof(int*));
	for (int i = 0; i < dimension; i++) {
		secondMatrix[i] = (int*)malloc(dimension * sizeof(int));
	}

	// DIMENSION = 2
	if (dimension == 2) {
		secondMatrix[0][0] = firstMatrix[1][1];
		secondMatrix[0][1] = (-1) * firstMatrix[1][0];
		secondMatrix[1][0] = (-1) * firstMatrix[0][1];
		secondMatrix[1][1] = firstMatrix[0][0];

		//Copy to global2
		for (int i = 0; i < dimension; i++) {
			for (int j = 0; j < dimension; j++) {
				global2[i][j] = secondMatrix[i][j];
			}
		}
	}

	// DIMENSION = 3
	if (dimension == 3) {
		int _tempDim = *dim;
		*dim = 2;									//Temporary for Transposing
		int _tempAction = *action;
		*action = 3;

		global2[0][0] = firstMatrix[1][1];			//1
		global2[0][1] = firstMatrix[1][2];
		global2[1][0] = firstMatrix[2][1];
		global2[1][1] = firstMatrix[2][2];
		determinant(result, global2, global3, action, dim);
		secondMatrix[0][0] = *result;

		global2[0][0] = firstMatrix[1][0];			//2
		global2[0][1] = firstMatrix[1][2];
		global2[1][0] = firstMatrix[2][0];
		global2[1][1] = firstMatrix[2][2];
		determinant(result, global2, global3, action, dim);
		secondMatrix[0][1] = *result * (-1);

		global2[0][0] = firstMatrix[1][0];			//3
		global2[0][1] = firstMatrix[1][1];
		global2[1][0] = firstMatrix[2][0];
		global2[1][1] = firstMatrix[2][1];
		determinant(result, global2, global3, action, dim);
		secondMatrix[0][2] = *result;

		global2[0][0] = firstMatrix[0][1];			//4
		global2[0][1] = firstMatrix[0][2];
		global2[1][0] = firstMatrix[2][1];
		global2[1][1] = firstMatrix[2][2];
		determinant(result, global2, global3, action, dim);
		secondMatrix[1][0] = *result * (-1);

		global2[0][0] = firstMatrix[0][0];			//5
		global2[0][1] = firstMatrix[0][2];
		global2[1][0] = firstMatrix[2][0];
		global2[1][1] = firstMatrix[2][2];
		determinant(result, global2, global3, action, dim);
		secondMatrix[1][1] = *result;

		global2[0][0] = firstMatrix[0][0];			//6
		global2[0][1] = firstMatrix[0][1];
		global2[1][0] = firstMatrix[2][0];
		global2[1][1] = firstMatrix[2][1];
		determinant(result, global2, global3, action, dim);
		secondMatrix[1][2] = *result * (-1);

		global2[0][0] = firstMatrix[0][1];			//7
		global2[0][1] = firstMatrix[0][2];
		global2[1][0] = firstMatrix[1][1];
		global2[1][1] = firstMatrix[1][2];
		determinant(result, global2, global3, action, dim);
		secondMatrix[2][0] = *result;

		global2[0][0] = firstMatrix[0][0];			//8
		global2[0][1] = firstMatrix[0][2];
		global2[1][0] = firstMatrix[1][0];
		global2[1][1] = firstMatrix[1][2];
		determinant(result, global2, global3, action, dim);
		secondMatrix[2][1] = *result * (-1);

		global2[0][0] = firstMatrix[0][0];			//9
		global2[0][1] = firstMatrix[0][1];
		global2[1][0] = firstMatrix[1][0];
		global2[1][1] = firstMatrix[1][1];
		determinant(result, global2, global3, action, dim);
		secondMatrix[2][2] = *result;

		//Copy to global3
		for (int i = 0; i < dimension; i++) {
			for (int j = 0; j < dimension; j++) {
				global3[i][j] = secondMatrix[i][j];
			}
		}

		*dim = _tempDim;
		*action = _tempAction;
	}

	if (*action == 4) {
		*result = 0;
		return 4;
	}
	else {
		printf("Your matrix:\n");
		for (int i = 0; i < dimension; i++) {			//Print firstMatrix
			for (int j = 0; j < dimension; j++) {
				printf("%3.1d ", secondMatrix[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		*result = 0;
		return 4;
	}
	
}

int reverse(int *result, int **global2, int **global3, int *action, int *dim) {
	int dimension, operation;

	printf("How big is your matrix:\n2) 2x2\n3) 3x3\nEnter: ");
	scanf("%d", &dimension);
	*dim = dimension;
	printf("Enter matrix elements by rows.\n");
	
	if (dimension == 2) {
		for (int i = 0; i < dimension; i++) {
			for (int j = 0; j < dimension; j++) {
				scanf("%d", &global2[i][j]);
			}
		}
	}
	if (dimension == 3) {
		for (int i = 0; i < dimension; i++) {
			for (int j = 0; j < dimension; j++) {
				scanf("%d", &global3[i][j]);
			}
		}
	}

	*action = 1;
	operation = transpos(result, global2, global3, action, dim);
	*action = 4;
	operation = cofactor(result, global2, global3, action, dim);

	if (dimension == 2) {
		for (int i = 0; i < dimension; i++) {
			for (int j = 0; j < dimension; j++) {
				scanf("%3.1d", global2[i][j]);
			}
			printf("\n");
		}
	}
	if (dimension == 3) {
		for (int i = 0; i < dimension; i++) {
			for (int j = 0; j < dimension; j++) {
				printf("%3.1d ", global3[i][j]);
			}
			printf("\n");
		}
	}

	return 5;
}