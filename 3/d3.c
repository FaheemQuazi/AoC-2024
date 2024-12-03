#include "stdio.h"

int main() {
    FILE* f = fopen("input.txt", "r");
    int product = 0;
    int count = 0;
    int a = 0, b = 0, scanned = 0;
    char c;
    while ((scanned = fscanf(f, "mul(%d,%d%[)]", &a, &b, &c)) != EOF) {
        if (scanned == 3 && a <= 999 && a >= 0 && b <= 999 && b >= 0) {
            printf("%d %d\n", a, b);
            product += a * b;
            count++;
            fseek(f, -1, SEEK_CUR);
        } else {
            fseek(f, 1, SEEK_CUR);
        }
    }
    fclose(f);
    printf("%d Product: %d\n", count, product);
}