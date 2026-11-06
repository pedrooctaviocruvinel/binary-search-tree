#include "unity.h"

#include "binary_search_tree.h"
#include "product.h"

BinarySearchTree tree;

void setUp(void)
{
    bst_init(&tree, sizeof(Product), compare_products);
}

void tearDown(void)
{
    bst_destroy(&tree);
}

void test_empty_tree(void)
{
    TEST_ASSERT_NULL(tree.root);
    TEST_ASSERT_EQUAL(bst_count(&tree), 0);

    return;
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_empty_tree);

    return UNITY_END();
}
