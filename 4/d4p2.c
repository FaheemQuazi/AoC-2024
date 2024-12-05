#include "stdio.h"
#include "stdlib.h"
#include "string.h"

const char* strGridA = "M.S.A.M.S";
const char* strGridB = "S.S.A.M.M";
const char* strGridC = "M.M.A.S.S";
const char* strGridD = "S.M.A.S.M";
const int strDimX = 3;
const int strDimY = 3;

int gridSearch(char* data, int dimX, int dimY, const char* str, const int strX, const int strY) {
    int tot = 0;
    for (int Y = 0; Y < dimY - strY + 1; Y++) {
        for (int X = 0; X < dimX - strX + 1; X++) {
            char* ps = &data[(Y * dimY) + X];
            int count = 0;
            for (int sY = 0; sY < strY; sY++) {
                for (int sX = 0; sX < strX; sX++) {
                    char pc = str[(sY * strY) + sX];
                    if (ps[0] != pc && pc != '.') goto search_exit;
                    ps += 1;
                    count += 1;
                }
                ps += dimY - strY;
            }
search_exit:
            if (count == strX * strY) tot += 1;
        }
    }
    return tot;
}

int main() {
    FILE* f = fopen("input.txt", "r");
    fseek(f, 0, SEEK_END);
    int fsize = ftell(f);
    rewind(f);

    char* fd = (char*)malloc((sizeof(char) * fsize) + 1);
    int dimX = -1, dimY = 0, wordCount = 0;
    for (int i = 0; i < fsize; i++) {
        char c = fgetc(f);
        if (c == EOF) break;
        if (c == '\n' && dimX == -1) dimX = i;
        if (c == '\n') {dimY += 1; i--;}
        else fd[i] = c;
    }
    dimY += 1; // input doesn't end in newline
    printf("%d X %d \n%s\n", dimX, dimY, fd);

    wordCount += gridSearch(fd, dimX, dimY, strGridA, strDimX, strDimY);
    wordCount += gridSearch(fd, dimX, dimY, strGridB, strDimX, strDimY);
    wordCount += gridSearch(fd, dimX, dimY, strGridC, strDimX, strDimY);
    wordCount += gridSearch(fd, dimX, dimY, strGridD, strDimX, strDimY);
    printf("TOTAL: %d\n", wordCount);
    fclose(f);
}