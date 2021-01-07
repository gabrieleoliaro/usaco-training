/*
ID: ict2
LANG: C
TASK: transform
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NMAX 10
int check90(char matrix1[NMAX][NMAX], char matrix2[NMAX][NMAX], int N) {
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
			if (matrix2[j][N-i-1] != matrix1[i][j])
				return 0;
	return 1;
}

int check180(char matrix1[NMAX][NMAX], char matrix2[NMAX][NMAX], int N) {
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
			if (matrix2[N-i-1][N-j-1] != matrix1[i][j])
				return 0;
	return 1;
}

int check270(char matrix1[NMAX][NMAX], char matrix2[NMAX][NMAX], int N) {
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
			if (matrix2[N-j-1][i] != matrix1[i][j])
				return 0;
	return 1;
}

int check_refl(char matrix1[NMAX][NMAX], char matrix2[NMAX][NMAX], int N) {
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
			if (matrix2[i][N-j-1] != matrix1[i][j])
				return 0;
	return 1;
}

int check_comb(char matrix1[NMAX][NMAX], char matrix2[NMAX][NMAX], int N) {
	char reflected_matrix[NMAX][NMAX];
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
			reflected_matrix[i][N-j-1] = matrix1[i][j];

	if (check90(reflected_matrix, matrix2, N) ||
		check180(reflected_matrix, matrix2, N) ||
		check270(reflected_matrix, matrix2, N))
		return 1;
	return 0;
}

int check_no_change(char matrix1[NMAX][NMAX], char matrix2[NMAX][NMAX], int N) {
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
			if (matrix2[i][j] != matrix1[i][j])
				return 0;
	return 1;
}


int main () {
    FILE *fin  = fopen ("transform.in", "r");
    FILE *fout = fopen ("transform.out", "w");

    int N;
    fscanf(fin, "%i", &N);
    char matrix1[NMAX][NMAX], matrix2[NMAX][NMAX];
    for (int i=0; i<N;i++) {
    	char row[N+1];
    	fscanf(fin, "%s", row);
    	strncpy(matrix1[i], row, N);
    }
    for (int i=0; i<N;i++) {
    	char row[N+1];
    	fscanf(fin, "%s", row);
    	strncpy(matrix2[i], row, N);
    }


    int r=7;
    if (check90(matrix1, matrix2, N))
    	r=1;
    else if (check180(matrix1, matrix2, N)) 
    	r=2;
    else if (check270(matrix1, matrix2, N)) 
    	r=3;
    else if (check_refl(matrix1, matrix2, N)) 
    	r=4;
    else if (check_comb(matrix1, matrix2, N)) 
    	r=5;
    else if (check_no_change(matrix1, matrix2, N)) 
    	r=6;

    fprintf(fout, "%i\n", r);

    fclose(fin);
    fclose(fout);
    
    return 0;
}