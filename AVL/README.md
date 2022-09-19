A step-by-step explanation.

### Table of content:

  1 - **what is a Binary Search Tree (BST)?**

  2 - **Why BST?**

  3 - **Implementation guide:**

    → insert().
   
    → remove().
   
    → search().

## What is a **Binary Search Tree (BST)?**

   As you can probably guess, a **binary search tree** is a binary tree ( I assume that u already know binary trees). The key difference is that a BST only allows you to store nodes with lesser value on the left side and nodes with greater value on the right.

<img width="898" alt="Screen Shot 2022-09-19 at 5 18 11 PM" src="https://user-images.githubusercontent.com/80783319/191067163-f86ce75c-5852-47c9-b90b-b24870a23307.png">


## Why BST?

   Simply put, **a binary search tree is a data structure that allows for fast insertion, removal, and lookup of items while offering an efficient way to iterate them in sorted order.**

 the time complexity of all these operations in the worst case ( if the tree is linear) is **O(n)**; **n** is the number of nodes, and O(h) in general (**h** is the height of the tree).

<img width="588" alt="Screen Shot 2022-09-19 at 5 21 10 PM" src="https://user-images.githubusercontent.com/80783319/191067364-640a9362-e0e5-4aef-b819-fb1532f41b16.png">

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

- if the node is NULL → create it ,and return.

- if the node-data > data → repeat it all for the right child.

- if the node-data < data → repeat it all for the left child.f

### `Remove()`

 To remove an element we need to find it, then we have 3 cases:

- if the node found is a leaf(both left and right children are NULL) → we deallocate the memory then we set it to NULL, no worries.
- if the node has only one child → we replace the node with the child and deallocate the memory.
- if the node has both children → there are two options: find the successor (the min element on the right branch) and replace the node, or find the predecessor ( the maximum element on the left branch). By replacing the node with one of these two elements it’s possible to keep the tree well ordered easily.

<img width="816" alt="Screen Shot 2022-09-19 at 3 32 04 PM" src="https://user-images.githubusercontent.com/80783319/191067569-8605cc7d-9e32-47ff-82fe-0c6a4b46cb4b.png">

   after doing so we have to delete that node by calling the same functin.

## `Search()`

To search for an element it’s similar to the `insert()`  function:

- if the node-data equals the data we’re searching for → then we found it.
- else if the node-data > data → we call the function for the left child.
- else if the node-data < data → we call the function for the right child.
