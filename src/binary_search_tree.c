#include <stdlib.h>
#include <string.h>

#include "binary_search_tree.h"
#include "tree_node.h"

void bst_init(BinarySearchTree *tree, size_t element_size, CompareFunction compare)
{
    if (tree == NULL || compare == NULL)
        return;

    tree->root = NULL;
    tree->element_size = element_size;
    tree->compare = compare;
}

static TreeNode *create_node(const BinarySearchTree *tree, const void *data)
{
    TreeNode *node = malloc(sizeof(TreeNode));

    if (node == NULL)
        return NULL;

    node->data = malloc(tree->element_size);

    if (node->data == NULL)
    {
        free(node);

        return NULL;
    }

    memcpy(node->data, data, tree->element_size);

    node->left = NULL;
    node->right = NULL;

    return node;
}

static TreeNode *insert_node(BinarySearchTree *tree, TreeNode *root, const void *data, int *inserted)
{
    if (root == NULL)
    {
        TreeNode *node = create_node(tree, data);

        if (node != NULL)
        {
            *inserted = 1;
        }

        return node;
    }

    int result = tree->compare(data, root->data);

    if (result < 0)
    {
        root->left = insert_node(tree, root->left, data, inserted);
    }
    else if (result > 0)
    {
        root->right = insert_node(tree, root->right, data, inserted);
    }

    return root;
}

int bst_insert(BinarySearchTree *tree, const void *data)
{
    if (tree == NULL || data == NULL || tree->compare == NULL || tree->element_size == 0)
    {
        return 0;
    }

    int inserted = 0;

    tree->root = insert_node(tree, tree->root, data, &inserted);

    return inserted;
}

const void *bst_find(const BinarySearchTree *tree, const void *key)
{
    if (tree == NULL || key == NULL || tree->compare == NULL)
    {
        return NULL;
    }

    TreeNode *current = tree->root;

    while (current != NULL)
    {
        int result = tree->compare(key, current->data);

        if (result == 0)
        {
            return current->data;
        }

        current = result < 0 ? current->left : current->right;
    }

    return NULL;
}

static TreeNode *detach_min(TreeNode *root, TreeNode **minimum)
{
    if (root->left == NULL)
    {
        *minimum = root;

        return root->right;
    }

    root->left = detach_min(root->left, minimum);

    return root;
}

static TreeNode *remove_node(BinarySearchTree *tree, TreeNode *root, const void *key, int *removed)
{
    if (root == NULL)
    {
        return NULL;
    }

    int result = tree->compare(key, root->data);

    if (result < 0)
    {
        root->left = remove_node(tree, root->left, key, removed);
    }
    else if (result > 0)
    {
        root->right = remove_node(tree, root->right, key, removed);
    }
    else
    {
        *removed = 1;

        if (root->left == NULL)
        {
            TreeNode *right = root->right;

            free(root->data);
            free(root);

            return right;
        }

        if (root->right == NULL)
        {
            TreeNode *left = root->left;

            free(root->data);
            free(root);

            return left;
        }

        TreeNode *successor = NULL;

        TreeNode *right = detach_min(root->right, &successor);

        successor->left = root->left;
        successor->right = right;

        free(root->data);
        free(root);

        return successor;
    }

    return root;
}

int bst_remove(BinarySearchTree *tree, const void *key)
{
    if (tree == NULL || key == NULL || tree->compare == NULL)
    {
        return 0;
    }

    int removed = 0;

    tree->root = remove_node(tree, tree->root, key, &removed);

    return removed;
}

static void in_order_node(TreeNode *root, VisitFunction visit)
{
    if (root == NULL)
    {
        return;
    }

    in_order_node(root->left, visit);

    visit(root->data);

    in_order_node(root->right, visit);
}

void bst_in_order(const BinarySearchTree *tree, VisitFunction visit)
{
    if (tree == NULL || visit == NULL)
    {
        return;
    }

    in_order_node(tree->root, visit);
}

static size_t count_nodes(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return 1 + count_nodes(root->left) + count_nodes(root->right);
}

size_t bst_count(const BinarySearchTree *tree)
{
    if (tree == NULL)
    {
        return 0;
    }

    return count_nodes(tree->root);
}

static int calculate_height(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int left = calculate_height(root->left);
    int right = calculate_height(root->right);

    return 1 + (left > right ? left : right);
}

int bst_height(const BinarySearchTree *tree)
{
    if (tree == NULL)
    {
        return 0;
    }

    return calculate_height(tree->root);
}

static void destroy_node(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    destroy_node(root->left);
    destroy_node(root->right);

    free(root->data);
    free(root);
}

void bst_destroy(BinarySearchTree *tree)
{
    if (tree == NULL)
    {
        return;
    }

    destroy_node(tree->root);

    tree->root = NULL;
}

size_t bst_memory_usage(const BinarySearchTree *tree)
{
    if (tree == NULL)
        return 0;

    size_t nodes = bst_count(tree);

    size_t tree_size = sizeof(*tree);

    size_t nodes_size = nodes * sizeof(TreeNode);

    size_t data_size = nodes * tree->element_size;

    return tree_size + nodes_size + data_size;
}
