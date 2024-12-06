#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define MAX_MAP_DIM 150

int main() {
    FILE* f = fopen("input.txt", "r");
    int mx = 0, my = 0, cx = -1, cy = -1;
    char map[MAX_MAP_DIM][MAX_MAP_DIM];
    do {
        char c = fgetc(f);
        printf("%c", c);
        if (c == EOF) {
            break;
        } else if (c == '\n') {
            my += 1;
            mx = -1;
        } else if (c == '^') {
            cx = mx;
            cy = my;
            map[my][mx] = '.';
        } else {
            map[my][mx] = c;
        }
        mx += 1;
    } while (!feof(f));
    my += 1;
    fclose(f);
    printf("\n DIM: %d %d\nSTART: %d %d\n", mx, my, cx, cy);

    int visited=0, cdir = 0, movedir[4][2] = {
        {  0,  -1}, // n
        {  1,  0}, // e
        {  0,  1}, // s
        {  -1, 0} // w
    }; // x, y
    do {
        // printf("M %d %d: %c\n", cx, cy, map[cy][cx]);
        switch (map[cy][cx]) {
            case '#':
                cx -= movedir[cdir][0];
                cy -= movedir[cdir][1];
                cdir += 1;
                if (cdir > 3) {cdir = 0;}
                break;
            case 'X':
                break;
            case '.':
            default:
                map[cy][cx] = 'X';
                visited += 1;
                break;
        }
        cx += movedir[cdir][0];
        cy += movedir[cdir][1];
    } while (cy >= 0 && cy < mx && cx >= 0 && cx < my);
    
    printf("VISITED %d\n", visited);
}