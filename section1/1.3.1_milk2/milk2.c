/*
ID: ict2
LANG: C
TASK: milk2
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct interval {
	int start;
	int finish;
} interval;

int compare_intervals(const void *a, const void *b) {
	return ((interval*)a)->start - ((interval*)b)->start;
}

int main() {
	
	FILE *fin = fopen("milk2.in", "r");
	FILE *fout = fopen("milk2.out", "w");

	int N=0;
	fscanf(fin, "%i", &N);
	
	interval intervals[N];
	for (int i=0; i<N; i++) {
		fscanf(fin, "%i %i", &intervals[i].start, &intervals[i].finish);
	}

	qsort(&intervals, N, sizeof(interval), compare_intervals);

	interval merged_intervals[N];
	int counter=0;

	for (int i=0; i<N; i++) {
		if (counter > 0 && merged_intervals[counter-1].finish >= intervals[i].start) {
			int later_ending = intervals[i].finish > merged_intervals[counter-1].finish ? intervals[i].finish : merged_intervals[counter-1].finish;
			merged_intervals[counter-1].finish = later_ending;
		} else {
			merged_intervals[counter] = intervals[i];
			counter++;
		}
	}

	int milking=0, idle=0;
	for (int i=0; i<counter; i++) {
		milking = (merged_intervals[i].finish - merged_intervals[i].start) > milking ? (merged_intervals[i].finish - merged_intervals[i].start) : milking;
		idle = i > 0 && (merged_intervals[i].start - merged_intervals[i-1].finish) > idle ? (merged_intervals[i].start - merged_intervals[i-1].finish) : idle;
	}

	fprintf(fout, "%i %i\n", milking, idle);

	fclose(fin);
	fclose(fout);
	return 0;
}