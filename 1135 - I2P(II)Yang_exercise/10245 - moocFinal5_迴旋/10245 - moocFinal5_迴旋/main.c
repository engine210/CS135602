//
//  main.c
//  10245 - moocFinal5_迴旋
//
//  Created by engine210 on 2019/2/14.
//  Copyright © 2019 engine210. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    
    int m, n, p;
    int map[35][35];
    int num, direction; //Left:1 down:2 right:3 up:4
    int i;
    int row, column;
    
    scanf("%d%d%d", &m, &n, &p);
    
    memset(map, 0, sizeof(map));
    
    for (i = 0; i < 35; i++) {
        map[i][0] = 1;
        map[i][n+1] = 1;
        map[m+1][i] = 1;
        map[0][i] = 1;
    }
    
    row = 1;
    column = 1;
    direction = 1;
    num = 1;
    while (num != p) {
        map[row][column] = 1;
        switch (direction) {
            case 1:
                if (map[row][column+1] != 1) {
                    column++;
                }
                else {
                    row++;
                    direction = 2;
                }
                break;
            case 2:
                if (map[row+1][column] != 1) {
                    row++;
                }
                else {
                    column--;
                    direction = 3;
                }
                break;
            case 3:
                if (map[row][column-1] != 1) {
                    column--;
                }
                else {
                    row--;
                    direction = 4;
                }
                break;
            case 4:
                if (map[row-1][column] != 1) {
                    row--;
                }
                else {
                    column++;
                    direction = 1;
                }
                break;
        }
        num++;
    }
    
    printf("%d %d\n", row, column);
    
    return 0;
}
