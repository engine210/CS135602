//
//  main.c
//  10243 - moocFinal3_Max Pooling
//
//  Created by engine210 on 2019/2/12.
//  Copyright © 2019 engine210. All rights reserved.
//

#include <stdio.h>

int pool[12][12];

int findMax(int y, int x) {
    int i, j, max;
    max = pool[y][x];
    for (i = y; i < y+3; i++) {
        for (j = x; j < x+3; j++) {
            if (pool[i][j] > max) {
                max = pool[i][j];
            }
        }
    }
    return max;
}

int main(int argc, const char * argv[]) {
    
    int n;
    int i, j;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &pool[i][j]);
        }
    }
    
    for (i = 0; i < n-2; i++) {
        for (j = 0; j < n-3; j++) {
            printf("%d ", findMax(i, j));
        }
        printf("%d", findMax(i, j));
        printf("\n");
    }
    
    return 0;
}
