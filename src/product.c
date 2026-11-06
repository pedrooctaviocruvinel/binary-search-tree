#include <stdio.h>
#include <string.h>

#include "product.h"

int compare_products(const void *a, const void *b)
{
    const Product *product_a = a;
    const Product *product_b = b;

    return strcmp(product_a->sku, product_b->sku);
}

void print_product(const void *data)
{
    const Product *product = data;

    printf("> %-15s %s\n", product->sku, product->name);
}
