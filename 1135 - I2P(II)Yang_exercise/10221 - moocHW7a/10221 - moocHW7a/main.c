//
//  main.c
//  10221 - moocHW7a
//
//  Created by engine210 on 2019/2/5.
//  Copyright © 2019 engine210. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
 struct for product items
 */
typedef struct _Product {
    char name[51];
    float price;
    float review;
    int  num_reviews;
} Product;

int compare(const void *a, const void *b) {
    Product *ia, *ib;
    
    ia = *(Product **)a;
    ib = *(Product **)b;
    /*
     Can I do in this way?
    ia = (Product*) a;
    ib = (Product*) b;
     */
    /* your code here */
    if (ia->review > ib->review) {
        return 0;
    }
    else if (ia->review < ib->review) {
        return 1;
    }
    else {
        if (ia->price > ib->price) {
            return 1;
        }
        else {
            return 0;
        }
    }
}

void show_product(Product *item)
{
    printf("%s, ", item->name);
    printf("$%.2f, ", item->price);
    printf("%.1f\n", item->review);
}

int main(void) {
    Product **items;
    int i, j;
    int ndata, nqueries;
    char query[51];
    
    scanf("%d", &ndata);
    while (getchar() != '\n');
    
    items = (Product**) malloc(sizeof(Product*) * ndata);
    
    for (i = 0; i < ndata; i++) {
        items[i] = (Product*) malloc(sizeof(Product));
        fgets(items[i]->name, sizeof(items[i]->name), stdin);
        items[i]->name[strlen(items[i]->name)-1] = 0;
        scanf("%f", &items[i]->price);
        scanf("%f", &items[i]->review);
        scanf("%d", &items[i]->num_reviews);
        while (getchar() != '\n');
    }
    
    scanf("%d", &nqueries);
    while (getchar() != '\n');
    qsort(items, ndata, sizeof(Product*), compare);
    for (i = 0; i < nqueries; i++) {
        /* your code */
        fgets(query, sizeof(query), stdin);
        query[strlen(query) - 1] = 0;
        printf("%s\n", query);
        for (j = 0; j < ndata; j++) {
            if (strncmp(items[j]->name, query, strlen(query)) == 0) {
                show_product(items[j]);
            }
        }
    }
    
    for (i = 0; i < ndata; i++) {
        free(items[i]);
    }
    free(items);
    return 0;
}
