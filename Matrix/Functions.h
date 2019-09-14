#ifndef Functions_H
#define Functions_H

int transpos(int *result, int **global2, int **global3, int *action, int *dim);
int multiply(int *result, int **global2, int **global3, int *action, int *dim);
int determinant(int *result, int **global2, int **global3, int *action, int *dim);
int cofactor(int *result, int **global2, int **global3, int *action, int *dim);
int reverse(int *result, int **global2, int **global3, int *action, int *dim);

#endif