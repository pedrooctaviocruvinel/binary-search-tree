#ifndef PRODUCT_H
#define PRODUCT_H

typedef struct Product
{
    char sku[15];
    char name[30];
} Product;

int compare_products(const void *a, const void *b);

void print_product(const void *data);

#endif
