#include "stdio.h"
#include "stdbool.h"

int main() {
    FILE* f = fopen("input.txt", "r");
    int product = 0, a = 0, b = 0, scanned = 0;
    char c;
    bool enable = true;
    do {
        if (enable) {
            fpos_t endAt = __INT_MAX__;
            fpos_t currPos = 0;
            fgetpos(f, &currPos);
            while ((scanned = fscanf(f, "%[d]%[o]%[n]%[']%[t]%[(]%[)]", &c, &c, &c, &c, &c, &c, &c)) != EOF) {
                if (scanned == 7) {
                    fgetpos(f, &endAt);
                    break;
                } else {
                    fseek(f, 1, SEEK_CUR);
                }
            }
            fseek(f, currPos, SEEK_SET);
            while ((scanned = fscanf(f, "mul(%d,%d%[)]", &a, &b, &c)) != EOF) {
                fgetpos(f, &currPos);
                if (currPos >= endAt) {
                    enable = false;
                    break;
                }
                if (scanned == 3 && a <= 999 && a >= 0 && b <= 999 && b >= 0) {
                    product += a * b;
                    fseek(f, -1, SEEK_CUR);
                } else {
                    fseek(f, 1, SEEK_CUR);
                }
            }
        } else {
            while ((scanned = fscanf(f, "%[d]%[o]%[(]%[)]", &c, &c, &c, &c)) != EOF) {
                if (scanned == 4) {
                    fseek(f, -1, SEEK_CUR);
                    enable = true;
                    break;
                } else {
                    fseek(f, 1, SEEK_CUR);
                }
            }
        }
    } while (!feof(f));
    fclose(f);
    printf("Product: %d\n", product);
}