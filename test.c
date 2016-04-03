#include <stdio.h>
#include <assert.h>
#include "treeheap.h"

void test_one_heap_entry() {
    printf("Testing one heap entry... ");

    create_heap();
    add_to_heap(7);
    int max = peek_heap();
    if (max != 7) {
        printf("ERROR: Expected 7, but got %d\n", max);
    }
    else {
        printf("Pass\n");
    }

    destroy_heap();
}

void test_two_heap_entry() {
    printf("Testing two heap entry... ");

    create_heap();
    add_to_heap(7);
    add_to_heap(3);
    print_heap();
    int max = peek_heap();
    if (max != 7) {
        printf("ERROR: Expected 7, but got %d\n", max);
    }
    else {
        printf("Pass\n");
    }

    destroy_heap();
}

int main (int argc, char * argv[]) {
    test_one_heap_entry();
    test_two_heap_entry();
}

