#include "stdio.h"
#include "stdbool.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"
#define MAX_TBL_SIZE 900

int main() {
    FILE* f = fopen("input.txt", "r");
    unsigned long table[MAX_TBL_SIZE][MAX_TBL_SIZE];
    int rc = 0, cc = 0;
    do {
        char c;
        long i;
        fscanf(f, "%ld%c", &i, &c);
        if (c == ':') {
            table[rc][0] = i;
        } else if (c == ' ') {
            table[rc][(cc++)+2] = i;
        } else if (c == '\n') {
            table[rc][(cc++)+2] = i;
            table[rc][1] = cc;
            rc += 1; 
            cc = 0;
        }
    } while (!feof(f));
    rc -= 1;
    printf("ROWS %d\n", rc);

    unsigned long goodvals = 0;
    for (int r = 0; r < rc; r++) {
        printf("%d - M(%ld)[%ld]", r, table[r][0], table[r][1]);
        bool cleared = false;
        for (int c = 0; c < pow(2, table[r][1]-1); c++) { // combinations
            unsigned long total = table[r][2];
            for (unsigned int s = 0; s < table[r][1]-1; s++) {
                bool b = ((c & (1 << s)) >> s) & 1;
                if (b) total = total * table[r][s+3];
                else total = total + table[r][s+3];
            }
            if (total == table[r][0]) {
                cleared = true;
                break;
            }
        }
        if (cleared) {
            goodvals += table[r][0];
            printf("!");
        }
        printf("\n");
    }
    printf("FINAL: %ld\n", goodvals);
}