//
//  main.c
//  11344 - Josephus Problem using Circular Linked List
//
//  Created by engine210 on 2019/3/30.
//  Copyright © 2019 engine210. All rights reserved.
//

#include <stdio.h>
#include "function.h"

int main(void){
    int n,m;
    scanf("%u %u",&n, &m);
    josephus(m,create(n));
}
