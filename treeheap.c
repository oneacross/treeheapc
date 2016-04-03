#include "treeheap.h"

// An implementation of a heap.
// The heap invariant: every node is larger than each of its children.

void create_heap() {
    _root = NULL;
}

void add_to_heap(int val) {

    NODE * new_node = malloc(sizeof(NODE));
    new_node->val = val;
    new_node->left = NULL;
    new_node->right = NULL;

    if (_root == NULL) {
        // First entry.
        _root = new_node;
    }
    else if (val > _root->val) {
        // Got a new maximum value.
        // Simply attach the current tree to the left child.
        // Not balanced!
        new_node->left = _root;
        _root = new_node;
    }
    else {
        // Walk the tree until we find the place for the new node.
        int done = 0;
        NODE * tmpnode = _root;

        while (!done) {

            if (tmpnode->left && (val > tmpnode->left->val)) {
                // The new node is greater than the left child.
                new_node->left = tmpnode->left;
                tmpnode->left = new_node;

                done = 1;
            }
            else if (tmpnode->right && (val > tmpnode->right->val)) {
                // The new node is greater than the right child.
                new_node->right = tmpnode->right;
                tmpnode->right = new_node;

                done = 1;
            }
            else if (tmpnode->left) {
                // Walk left.
                tmpnode = tmpnode->left;
            }
            else if (tmpnode->right) {
                // Walk right.
                tmpnode = tmpnode->right;
            }
            else {
                // This is a leaf node, simply add a new node as a child.
                tmpnode->left = new_node;

                done = 1;
            }
        }
    }
}

int peek_heap() {
    assert(_root);
    return _root->val;
}

typedef void (*node_cb)(NODE * node);

void _walk_tree(NODE * node, node_cb action) {

    action(node);
    
    if (node->left) {
        _walk_tree(node->left, action);
    }

    if (node->right) {
        _walk_tree(node->right, action);
    }
}

void _walk_tree_act_last(NODE * node, node_cb action) {

    if (node->left) {
        _walk_tree_act_last(node->left, action);
    }

    if (node->right) {
        _walk_tree_act_last(node->right, action);
    }

    action(node);
}

void print_node(NODE * node) {
    printf("%d\n", node->val);
}

void print_heap() {
    // Walk the tree breadth-first and print the nodes.
    _walk_tree(_root, &print_node);
}

void free_node(NODE * node) {
    free(node);
}

void destroy_heap() {
    // Walk the tree and free the nodes.
    _walk_tree_act_last(_root, &free_node);
}

