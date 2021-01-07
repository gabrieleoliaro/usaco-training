/*
ID: ict2
LANG: C++
TASK: namenum
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <set>
#include <string>
#include <iostream>


char number_to_letter[8][3] = {	{'A','B','C'},
								{'D','E','F'},
								{'G','H','I'},
								{'J','K','L'},
								{'M','N','O'},
								{'P','R','S'},
								{'T','U','V'},
								{'W','X','Y'}};

int main () {
    FILE *fin  = fopen ("namenum.in", "r");
    FILE *fdict = fopen ("dict.txt", "r");
    FILE *fout = fopen ("namenum.out", "w");

    char number[13];
    fscanf(fin,"%s\n", number);
    int ndigits = strlen(number);

    std::set<std::string> dictionary;
    char name[13];
    
    while(fscanf(fdict, "%s\n", name) != EOF) {
        if (strlen(name) == ndigits) {
            bool match = true;
            for (int i=0; i<ndigits; i++) {
                char num_char = number[i];
                int num_int = atoi(&num_char)-2;
                if (number_to_letter[num_int][0] != name[i] &&
                    number_to_letter[num_int][1] != name[i] &&
                    number_to_letter[num_int][2] != name[i]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                std::string s(name);
                auto ret = dictionary.insert(s);
            }
        }	
    }

    if (dictionary.size() == 0) {
        fprintf(fout, "NONE\n");
    } else {
        for (auto s : dictionary) {
            fprintf(fout, "%s\n", s.c_str());
        }
    }

    
    // int n_possible_names = (int) pow(3,ndigits);
    // bool found=false;
    // for (int rank=0; rank<n_possible_names; rank++) {
    // 	char word[ndigits+1];
    // 	word[ndigits] = '\0';
    // 	for (int i=0; i<ndigits; i++) {
    // 		char num_char = number[i];
    // 		int num_int = atoi(&num_char)-2;
    // 		word[i] = number_to_letter[num_int][(rank % (int) pow(3,ndigits-i) ) / (int) pow(3,ndigits-i-1)];
    // 	}
    // 	auto it = dictionary.find(std::string(word));
    // 	if (it != dictionary.end()) {
    // 		fprintf(fout, "%s\n", word);
    // 		found=true;
    // 	}
    	
    // }
    /*if (!found) {
    	fprintf(fout, "NONE\n");
    }*/

    fclose(fin);
    fclose(fout);
    
    return 0;
}