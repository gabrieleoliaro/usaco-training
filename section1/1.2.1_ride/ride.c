/*
ID: ict2
LANG: C
TASK: ride
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFLEN 6

int  main () {
    FILE *fin  = fopen ("ride.in", "r");
    FILE *fout = fopen ("ride.out", "w");
    char *comet = (char*)calloc(BUFLEN+1, sizeof(char));
    char *group = (char*)calloc(BUFLEN+1, sizeof(char));
    
    fscanf (fin, "%s\n%s", comet, group);

    int comet_n=1, group_n=1;
    for (int i=0; i<strlen(comet); i++) {
    	comet_n *= (comet[i]- 'A'+1);
    }

    for (int i=0; i<strlen(group); i++) {
    	group_n *= (group[i]- 'A'+1);
    }

    if (comet_n % 47 == group_n % 47) {
    	fprintf(fout,"GO\n");
    } else {
    	fprintf(fout,"STAY\n");
    }

    free(comet);
    free(group);
    fclose(fin);
    fclose(fout);
    
    return 0;
}