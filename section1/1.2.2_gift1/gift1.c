/*
ID: ict2
LANG: C
TASK: gift1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PEOPLE 10
#define MAX_NAME_LEN 14

int find_index(char *name, char names[MAX_PEOPLE][MAX_NAME_LEN+1]) {
	for (int i=0; i<MAX_PEOPLE; i++) {
		if (strcmp(name, names[i]) == 0)
			return i;
	}
	return -1;
}

int main() {
	FILE *fin = fopen("gift1.in", "r");
	FILE *fout = fopen("gift1.out", "w");

	int np=0;
	fscanf(fin, "%i",&np);

	char names[MAX_PEOPLE][MAX_NAME_LEN+1];
	for (int i=0; i<np; i++) {
		fscanf(fin, "%s", names[i]);
	}

	int account_balance[MAX_PEOPLE] = {0};
	for (int i=0; i<np; i++) {
		int d,amount,recipients;

		char donor[MAX_NAME_LEN];
		fscanf(fin, "%s", donor);
		d = find_index(donor, names);

		fscanf(fin, "%i %i", &amount, &recipients);
		if (amount == 0) continue;
		account_balance[d] = account_balance[d] - amount + (amount % recipients);
		
		amount /= recipients;

		for (int g=0; g<recipients; g++) {
			char recipient[MAX_NAME_LEN];
			fscanf(fin, "%s", recipient);
			int r = find_index(recipient, names);
			account_balance[r] += amount; 
		}
	}

	for (int i=0; i<np; i++) {
		fprintf(fout, "%s %i\n", names[i], account_balance[i]);
	}

	fclose(fin);
	fclose(fout);
	return 0;
}