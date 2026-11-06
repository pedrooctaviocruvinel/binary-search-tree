#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "tree_node.h"
#include "compare_function.h"

/**
 * @struct BinarySearchTree
 * @brief Represents a generic Binary Search Tree.
 */
typedef struct BinarySearchTree
{
    TreeNode *root;          /** Root node of the Tree. */
    size_t element_size;     /** Size in bytes of the Tree. */
    CompareFunction compare; /** Function to compare two nodes inside the Tree. */
} BinarySearchTree;

/**
 * @brief Initializes a generic Binary Tree.
 *
 * @param[out] pointer      To the tree to initialize.
 * @param[in]  element_size Size in bytes of each element stored in the tree.
 * @param[in]  compare      Function to compare the two nodes.
 */
void bst_init(BinarySearchTree *tree, size_t element_size, CompareFunction compare);

int bst_insert(BinarySearchTree *tree, const void *key);

const void *bst_find(const BinarySearchTree *tree, const void *key);

int bst_remove(BinarySearchTree *tree, const void *key);

void bst_in_order(const BinarySearchTree *tree, VisitFunction visit);

size_t bst_count(const BinarySearchTree *tree);

int bst_height(const BinarySearchTree *tree);

void bst_destroy(BinarySearchTree *tree);

size_t bst_memory_usage(const BinarySearchTree *tree);

#endif
