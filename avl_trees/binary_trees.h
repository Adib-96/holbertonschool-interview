#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>

/* Data structure for binary tree node */
typedef struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
} binary_tree_t, avl_t;

/* Function prototypes */
size_t binary_tree_height(const binary_tree_t *tree);
int binary_tree_is_avl(const binary_tree_t *tree);

#endif /* BINARY_TREES_H */
