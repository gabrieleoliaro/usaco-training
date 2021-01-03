/*
ID: ict2
LANG: C
TASK: beads
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b) {
    if (a>=b) {
        return a;
    }
    return b;
}

int get_real_index(int raw, int string_len) {
    if (raw < 0) {
        return string_len+raw;
    }
    if (raw >= string_len) {
        return raw - string_len;
    }
    return raw;
}

int main () {
    FILE *fin  = fopen ("beads.in", "r");
    FILE *fout = fopen ("beads.out", "w");

    int n;
    fscanf(fin, "%i\n", &n);
    char beads[n];
    fscanf(fin, "%s", beads);
    
    int max_beads = 0;
    for (int cut_index=0; cut_index<n; cut_index++) {
        int l_indx=1;
        while(beads[get_real_index(cut_index-l_indx,n)] == 'w') {
            l_indx++;
        }
        char l = beads[get_real_index(cut_index-l_indx,n)];

        int r_indx=0;
        while(beads[get_real_index(cut_index+r_indx,n)] == 'w') {
            r_indx++;
        }
        char r = beads[get_real_index(cut_index+r_indx,n)];

        int max_right=0,max_left=0;
        for (int right_offset=0; right_offset < n/2; right_offset++) {
            if (beads[get_real_index(cut_index+right_offset, n)] == r || beads[get_real_index(cut_index+right_offset, n)] == 'w') {
                max_right+=1;
            } else {
                break;
            }
        }
        int leftovers = (n/2)-max_right;
        // last one
        int counted=0;
        if (n%2!=0 && leftovers==0) {
            if (beads[get_real_index(cut_index+n/2, n)] == r || beads[get_real_index(cut_index+n/2, n)] == 'w') {
                max_right+=1;
                counted = 1;
            }
        }
        for (int left_offset=1; left_offset <= n/2+leftovers; left_offset++) {
            if (beads[get_real_index(cut_index-left_offset, n)] == l || beads[get_real_index(cut_index-left_offset, n)] == 'w') {
                max_left+=1;
            } else {
                break;
            }
        }
        if (n%2!=0 && max_left==(n/2)+leftovers && !counted) {
            if (beads[get_real_index(cut_index-(n/2+leftovers+1), n)] == l || beads[get_real_index(cut_index-(n/2+leftovers+1), n)] == 'w') {
                max_left+=1;
                counted = 1;
            }
        }
        max_beads = max(max_beads, max_left+max_right);
    }

    fprintf(fout, "%i\n",max_beads);
    fclose(fin);
    fclose(fout);
    return 0;

}