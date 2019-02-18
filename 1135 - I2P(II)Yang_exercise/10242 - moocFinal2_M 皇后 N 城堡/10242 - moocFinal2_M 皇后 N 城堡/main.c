//
//  main.c
//  10242 - moocFinal2_M 皇后 N 城堡
//
//  Created by engine210 on 2019/2/14.
//  Copyright © 2019 engine210. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int board[15][15];
int total, m, n;
int queenNum, castleNum;

void show() {
    int i, j;
    for (i = 1; i <= m+n; i++) {
        for (j = 1; j <= m+n; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

int only(int x, int y, int type) {
    int i,xc,yc;
    for (i = 1; i <= m+n; i++) {
        if (board[i][x] == 1 || board[i][x] == 2) {
            return 0;
        }
    }
    if (type == 1) {
        xc = x;
        yc = y;
        while (xc > 0 && yc > 0) {
            if (board[yc][xc] == 1 || board[yc][xc] == 2) {
                return 0;
            }
            xc--;
            yc--;
        }
        xc = x;
        yc = y;
        while (xc > 0 && yc <= m+n) {
            if (board[yc][xc] == 1 || board[yc][xc] == 2) {
                return 0;
            }
            xc--;
            yc++;
        }
        xc = x;
        yc = y;
        while (xc <= m+n && yc > 0) {
            if (board[yc][xc] == 1 || board[yc][xc] == 2) {
                return 0;
            }
            xc++;
            yc--;
        }
        xc = x;
        yc = y;
        while (xc <= m+n && yc <= m+n) {
            if (board[yc][xc] == 1 || board[yc][xc] == 2) {
                return 0;
            }
            xc++;
            yc++;
        }
    }
    else {
        xc = x;
        yc = y;
        while (xc > 0 && yc > 0) {
            if (board[yc][xc] == 1) {
                return 0;
            }
            xc--;
            yc--;
        }
        xc = x;
        yc = y;
        while (xc > 0 && yc <= m+n) {
            if (board[yc][xc] == 1) {
                return 0;
            }
            xc--;
            yc++;
        }
        xc = x;
        yc = y;
        while (xc <= m+n && yc > 0) {
            if (board[yc][xc] == 1) {
                return 0;
            }
            xc++;
            yc--;
        }
        xc = x;
        yc = y;
        while (xc <= m+n && yc <= m+n) {
            if (board[yc][xc] == 1) {
                return 0;
            }
            xc++;
            yc++;
        }
    }
    
    return 1;
}

void set(int y) {
    int i;
    if(y > m+n) {
        //show();
        total++;
    }
    else {
        for(i = 1; i <= m+n; i++) {
            if(only(i, y, 1) && queenNum > 0){
                board[y][i] = 1;
                queenNum--;
                set(y+1);
                board[y][i] = 0;
                queenNum++;
            }
            if (only(i, y, 2) && castleNum > 0) {
                board[y][i] = 2;
                castleNum--;
                set(y+1);
                board[y][i] = 0;
                castleNum++;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    
    scanf("%d%d", &m, &n);
    queenNum = m;
    castleNum = n;
    memset(board, 0, sizeof(board));
    total = 0;
    set(1);
    printf("%d\n", total);
    
    return 0;
}
