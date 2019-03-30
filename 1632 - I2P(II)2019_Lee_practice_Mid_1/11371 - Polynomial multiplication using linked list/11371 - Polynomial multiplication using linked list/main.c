//
//  main.c
//  11371 - Polynomial multiplication using linked list
//
//  Created by engine210 on 2019/3/29.
//  Copyright © 2019 engine210. All rights reserved.
//

#include "function.h"

int main(void){
    Node *p1=create(); //polynomial linked list1
    Node *p2=create(); //polynomial linked list2
    Node *mul=multiple(p1,p2);
    printNode(mul);
    destroy(mul);
    destroy(p2);
    destroy(p1);
    return 0;
}
