/*
ID: ict2
LANG: C
TASK: friday
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isleap(int year) {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? 1 : 0;
}

// Takes year number (not offset)
int year_to_days(int year) {
    return 365 + isleap(year);
}

int month_to_days(int month, int year) {
    if (month == 2) {
        return 28 + isleap(year);
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    return 31;
}

int main () {
    FILE *fin  = fopen ("friday.in", "r");
    FILE *fout = fopen ("friday.out", "w");

    int n;
    fscanf(fin, "%i", &n);

    int ndays_since_1900 = 0;
    int n13occurrences[7];
    for (int d=0; d<7; d++){
        n13occurrences[d] = 0;
    }
    for (int y=1900; y<1900+n; y++) {
        for (int m=1; m<=12; m++) {
            ndays_since_1900+=12;
            n13occurrences[ndays_since_1900 % 7]++;
            ndays_since_1900+=month_to_days(m,y)-12;
        }
    }

    for (int d=0;d<7;d++) {
        if (d==6) {
            fprintf(fout, "%i\n",n13occurrences[(5+d)%7]);
        } else {
            fprintf(fout, "%i ",n13occurrences[(5+d)%7]);
        }   
    }
    
    fclose(fin);
    fclose(fout);
    return 0;

}