//
//  main.c
//  11345 - Josephus Problem using doubly circular linked list
//
//  Created by engine210 on 2019/3/7.
//  Copyright © 2019 engine210. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "function.h"

man* head;
int main(){
    int n, m;
    
    while(scanf("%d%d", &n, &m)!=EOF){
        head = createList(n);
        printf("%d\n", solveJosephus(m));
    }
    
    return 0;
}
