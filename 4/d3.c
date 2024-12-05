#include "stdio.h"
#include "stdlib.h"
#include "string.h"

const char* strFwd = "XMAS";
const char* strBkd = "SAMX";
const int strLen = 4;

int searchW(char* data, int dimX, int dimY, const char* str, const int len, int searchOffset, int startX, int startY, int stopX, int stopY) {
    int tot = 0;
    for (int Y = startY; Y < stopY; Y++) {
        for (int X = startX; X < stopX; X++) {
            char* ps = &data[(Y * dimY) + X];
            int count = 0;
            for (; count < len; count++) {
                if (ps[0] != str[count]) break;
                ps += searchOffset;
            }
            if (count == len) tot += 1;
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

    wordCount += searchW(fd, dimX, dimY, strFwd, strLen, 1, 0, 0, dimX-strLen+1, dimY); //horiz
    wordCount += searchW(fd, dimX, dimY, strBkd, strLen, 1, 0, 0, dimX-strLen+1, dimY);
    wordCount += searchW(fd, dimX, dimY, strFwd, strLen, dimY, 0, 0, dimX, dimY-strLen+1); //vert
    wordCount += searchW(fd, dimX, dimY, strBkd, strLen, dimY, 0, 0, dimX, dimY-strLen+1);
    wordCount += searchW(fd, dimX, dimY, strFwd, strLen, dimY+1, 0, 0, dimX-strLen+1, dimY-strLen+1); //diag
    wordCount += searchW(fd, dimX, dimY, strBkd, strLen, dimY+1, 0, 0, dimX-strLen+1, dimY-strLen+1);
    wordCount += searchW(fd, dimX, dimY, strFwd, strLen, dimY-1, strLen-1, 0, dimX, dimY); //diag (reverse)
    wordCount += searchW(fd, dimX, dimY, strBkd, strLen, dimY-1, strLen-1, 0, dimX, dimY);
    printf("TOTAL: %d\n", wordCount);
    fclose(f);
}