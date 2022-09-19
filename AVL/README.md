A step-by-step explanation.

### Table of content:

    1 -  ** what is a Binary Search Tree (BST)?**

    2 -**Why BST?**

    3 -**Implementation guide:**

→ insert().

→ remove().

→ search().

## What is a **Binary Search Tree (BST)?**

    As you can probably guess, a **binary search tree** is a binary tree ( I assume that u already know binary trees). The key difference is that a BST only allows you to store nodes with lesser value on the left side and nodes with greater value on the right.

![Screen Shot 2022-09-19 at 5.18.11 PM.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/59d7c58b-38cd-40f1-a292-d2754e13d194/Screen_Shot_2022-09-19_at_5.18.11_PM.png)

## Why BST?

    Simply put, **a binary search tree is a data structure that allows for fast insertion, removal, and lookup of items while offering an efficient way to iterate them in sorted order.**

 the time complexity of all these operations in the worst case ( if the tree is linear) is **O(n)**; **n** is the number of nodes, and O(h) in general (**h** is the height of the tree).

![Screen Shot 2022-09-19 at 5.21.10 PM.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/b0d8bc4c-98b3-4651-8f89-fd7172d134cc/Screen_Shot_2022-09-19_at_5.21.10_PM.png)

## Implementation guide:

### BST Node

```cpp
typedef struct bst_node{
    int data;
    bst_node* left;
    bst_node* right;
}bst_node;
```

### `Insert()`

To insert an element we use a simple recursive algorithm starting with the root, it’s  3 steps

if the node is NULL → create it ,and return.

if the node-data > data → repeat it all for the right child.

if the node-data < data → repeat it all for the left child.f

### `Remove()`

 To remove an element we need to find it, then we have 3 cases:

- if the node found is a leaf(both left and right children are NULL) → we deallocate the memory then we set it to NULL, no worries.
- if the node has only one child → we replace the node with the child and deallocate the memory.
- if the node has both children → there are two options: find the successor (the min element on the right branch) and replace the node, or find the predecessor ( the maximum element on the left branch). By replacing the node with one of these two elements it’s possible to keep the tree well ordered easily.

![Screen Shot 2022-09-19 at 3.32.04 PM.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/97a3cf65-d2dc-49a2-8f1b-04cd1577cb05/Screen_Shot_2022-09-19_at_3.32.04_PM.png)

     after doing so we have to delete that node by calling the same functin.

## `Search()`

To search for an element it’s similar to the `insert()`  function:

- if the node-data equals the data we’re searching for → then we found it.
- else if the node-data > data → we call the function for the left child.
- else if the node-data < data → we call the function for the right child.
