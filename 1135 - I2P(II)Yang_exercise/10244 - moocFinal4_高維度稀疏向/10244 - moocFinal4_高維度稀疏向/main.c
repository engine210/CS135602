//
//  main.c
//  10244 - moocFinal4_高維度稀疏向
//
//  Created by engine210 on 2019/2/12.
//  Copyright © 2019 engine210. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int binarySearch(int** vector_2, int find, int len) {
    int low = 0;
    int upper = len - 1;
    int mid;
    while(low <= upper) {
        mid = (low + upper) / 2;
        if(vector_2[mid][0] < find) {
            low = mid + 1;
        }
        else if(vector_2[mid][0] > find) {
            upper = mid - 1;
        }
        else {
            return mid;
        }
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    
    int** vector_1;
    int** vector_2;
    int v1, v2;
    int len_1, len_2;
    int i;
    int index;
    long long sum;
    /* Why I can't raise memory size to 2^31? */
    vector_1 = (int**) malloc(sizeof(int*) * 1048576);
    vector_2 = (int**) malloc(sizeof(int*) * 1048576);
    
    scanf("%d:%d", &v1, &v2);
    len_1 = 0;
    while (v1 && v2) {
        vector_1[len_1] = (int*) malloc(sizeof(int) * 2);
        vector_1[len_1][0] = v1;
        vector_1[len_1][1] = v2;
        len_1++;
        scanf("%d:%d", &v1, &v2);
    }
    scanf("%d:%d", &v1, &v2);
    len_2 = 0;
    while (v1 && v2) {
        vector_2[len_2] = (int*) malloc(sizeof(int) * 2);
        vector_2[len_2][0] = v1;
        vector_2[len_2][1] = v2;
        len_2++;
        scanf("%d:%d", &v1, &v2);
    }
    
    sum = 0;
    for (i = 0; i < len_1; i++) {
        index = binarySearch(vector_2, vector_1[i][0], len_2);
        if (index != -1) {
            sum += vector_1[i][1] * vector_2[index][1];
        }
    }
    
    printf("%lld\n", sum);
    
    
    
    return 0;
}

