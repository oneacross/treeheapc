#ifndef MMENDELL_TREEHEAP_H
#define MMENDELL_TREEHEAP_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// An implementation of a heap.
// The heap invariant: every node is larger than each of its children.

// The heap is implemented as a tree of nodes. Each node has a left and right child.

struct node {
    int val;
    struct node * left;
    struct node * right;
};
typedef struct node NODE;

static NODE * _root = NULL;

// Heap operations.
void create_heap();
void add_to_heap(int val);
int peek_heap();
void print_heap();
void destroy_heap();

#endif
