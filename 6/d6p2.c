#include "stdio.h"
#include "stdbool.h"
#include "stdlib.h"
#include "string.h"
#include <string.h>
#include <unistd.h>
#define MAX_DIM 150

int stx, sty;

void printmap(int tmap[MAX_DIM][MAX_DIM], int mx, int my, int hx, int hy, bool sd) {
    for (int j = 0; j < my; j++) {
        for (int i = 0; i < mx; i++) {
            char x = tmap[j][i] & 0x00FF;
            if (i == hx && j == hy) {
                printf("O");
            } else if (i == stx && j == sty) {
                printf("@");
            } else if (x == '$' && sd) {
                printf("$");
            } else if (x == '#') {
                printf("#");
            } else {
                x = (tmap[j][i] & 0x0F00) >> 8;
                bool n = (x & 0b0001) > 0, e = (x & 0b0010) > 0,
                    s = (x & 0b0100) > 0, w = (x & 0b1000) > 0;
                if ((n && (e||w)) || (s && (e||w))) {
                    printf("+");
                } else if (n && s) {
                    printf("|");
                } else if (e && w) {
                    printf("-");
                } else {
                    if (n) printf("^");
                    else if (e) printf(">");
                    else if (s) printf("v");
                    else if (w) printf("<");
                    else printf(" ");
                }
            }
        }
        printf("\n");
    }
}

int main() {
    FILE* f = fopen("input.txt", "r");
    int mx = 0, my = 0, cx = -1, cy = -1;
    int movemap[MAX_DIM][MAX_DIM];
    int chkmap[MAX_DIM][MAX_DIM];
    do {
        char c = fgetc(f);
        if (c == EOF) {
            break;
        } else if (c == '\n') {
            my += 1;
            mx = -1;
        } else if (c == '#') {
            movemap[my][mx] = '#';
        } else if (c == '^') {
            cx = mx;
            cy = my;
            movemap[my][mx] = 0x0000;
        } else {
            movemap[my][mx] = 0x0000;
        }
        mx += 1;
    } while (!feof(f));
    my += 1;
    fclose(f);
    printf("\n DIM: %d %d\nSTART: %d %d\n", mx, my, cx, cy);
    stx = cx; sty = cy;
    int obstructs=0, turns = 0, cdir = 0, movedir[4][2] = {
        {  0,  -1}, // n
        {  1,  0}, // e
        {  0,  1}, // s
        {  -1, 0} // w
    }; // x, y
    do {
        printf("\033[%d;%dH", 1, 1);
        printmap(movemap, mx, my, cx + movedir[cdir][0], cy + movedir[cdir][1], true);
        usleep(1000);
        if ((movemap[cy][cx] & 0x00FF) == '#') { // back up and turn right on wall
            cx -= movedir[cdir][0];
            cy -= movedir[cdir][1];
            cdir = (cdir + 1) % 4;
            turns += 1;
        } else if (
                (cy >= 0 && cy + movedir[cdir][1] < my) && // space in front can hold obstacle
                (cx + movedir[cdir][0] >= 0 && cx + movedir[cdir][0] < mx) && // space in front can hold obstacle
                !(cy + movedir[cdir][1] == sty && cx + movedir[cdir][0] == stx) && // space in front is not the starting position
                ((movemap[cy + movedir[cdir][1]][cx + movedir[cdir][0]] & 0x00FF) != '#') && // space in front is not already obstruction
                ((movemap[cy + movedir[cdir][1]][cx + movedir[cdir][0]] & 0x00FF) != '$') // space in front is not already used as an obstacle
            ) {
            // printf("Q %d %d %d: %x\n", cx, cy, cdir, movemap[cy][cx]);
            memcpy(chkmap, movemap, sizeof chkmap);
            chkmap[cy][cx] |= (1 << (8+cdir));
            int qdir = cdir, qx = cx + movedir[cdir][0], qy = cy + movedir[cdir][1];
            chkmap[qy][qx] |= '#';
            do {
                if ((chkmap[qy][qx] & 0x00FF)  == '#') {
                    qx -= movedir[qdir][0];
                    qy -= movedir[qdir][1];
                    qdir = (qdir + 1) % 4;
                } else if (
                        (chkmap[qy][qx] & (1 << (8+qdir))) && // overlapping our path in the same direction
                        ((chkmap[qy][qx] & 0x00FF) != '#') && // not already declared obstruction
                        ((chkmap[qy][qx] & 0x00FF) != '$') // not already declared obstacle
                    ) { 
                    // printf("!! OBST !!\n");
                    obstructs += 1;
                    movemap[cy + movedir[cdir][1]][cx + movedir[cdir][0]] |= '$';
                    break;
                }
                chkmap[qy][qx] |= (1 << (8+qdir));
                qx += movedir[qdir][0];
                qy += movedir[qdir][1];
            } while (qy >= 0 && qy < mx && qx >= 0 && qx < my);
        }
        movemap[cy][cx] |= (1 << (8+cdir));
        cx += movedir[cdir][0];
        cy += movedir[cdir][1];
    } while (cy >= 0 && cy < my && cx >= 0 && cx < mx);
    
    printf("\nOBST %d\n", obstructs);
}