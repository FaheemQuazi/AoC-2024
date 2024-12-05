#include "stdio.h"
#include "stdbool.h"
#include "stdlib.h"
#include "string.h"

#define ORDER_FILE "input_order.txt"
#define LISTS_FILE "input_lists.txt"

int main() {
    FILE* fO = fopen(ORDER_FILE, "r");
    int ordCount = 0, ord[2048][2];
    do {
        int a, b; char c;
        fscanf(fO, "%d|%d\n", &a, &b);
        ord[ordCount][0] = a;
        ord[ordCount][1] = b;
        ordCount += 1;
    } while (!feof(fO));
    fclose(fO);

    FILE* fL = fopen(LISTS_FILE, "r");
    int listCount = 0, col = 0, lst[256][64];
    do {
        int a; char c;
        int scanned = fscanf(fL, "%d%c", &a, &c);
        if (scanned == 2) {
            lst[listCount][col+1] = a;
        }
        if (c == ',') { // value
            col += 1;
        } else if (c == '\n') {// last val
            lst[listCount][0] = col+1;
            col = 0;
            listCount += 1;
        }
    } while (!feof(fL));
    printf("O:%d | L: %d\n\n", ordCount, --listCount);
    fclose(fL);

    int sum = 0;
    for (int l = 0; l < listCount; l++) {
        int valid = 0;
        bool fail = false;

        printf("--LIST %d--\n", l);
        for (int i = 0; i < lst[l][0]; i++) {
            printf("%d ", lst[l][i+1]);
        }
        printf("\n");
        for (int lI = 0; lI < lst[l][0]; lI++) {
            int listUT = lst[l][lI + 1];
            // printf("%d:%d ", lI, listUT);
            for (int lJ = lI+1; lJ < lst[l][0]; lJ++) {
                int listV = lst[l][lJ + 1];
                bool swapped = false;
                for (int oI = 0; oI < ordCount; oI++) {
                    if (ord[oI][0] == listUT && ord[oI][1] == listV) {
                        // printf("P");
                    } else if (ord[oI][0] == listV && ord[oI][1] == listUT) {
                        // printf("F");
                        fail = true;
                        lst[l][lI + 1] = listV;
                        lst[l][lJ + 1] = listUT;
                        listUT = listV;
                        break;
                    }
                }
            }
        }
        printf("** STATE %d**\n", !fail);
        if (fail) {
            for (int i = 0; i < lst[l][0]; i++) {
                printf("%d ", lst[l][i+1]);
            }
            printf("\n");
            sum += lst[l][(lst[l][0] / 2) + 1];
        }
    }
    printf("SUM: %d\n", sum);

}