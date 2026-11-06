#include "unity.h"

#include "binary_search_tree.h"
#include "product.h"

void setUp(void) {}

void tearDown(void) {}

void bst_init_must_init_empty_tree(void)
{
    // Arrange
    BinarySearchTree tree;

    // Act
    bst_init(&tree, sizeof(Product), compare_products);

    // Assert
    TEST_ASSERT_NULL(tree.root);
    TEST_ASSERT_EQUAL(tree.element_size, sizeof(Product));
    TEST_ASSERT_EQUAL(tree.compare, compare_products);
}

void bst_init_init_with_compare_as_null(void)
{
    // Arrange
    BinarySearchTree tree;
    BinarySearchTree original_tree = tree;

    // Act
    bst_init(&tree, sizeof(Product), NULL);

    // Assert
    TEST_ASSERT_EQUAL(tree.root, original_tree.root);
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(bst_init_must_init_empty_tree);
    RUN_TEST(bst_init_init_with_compare_as_null);

    return UNITY_END();
}
