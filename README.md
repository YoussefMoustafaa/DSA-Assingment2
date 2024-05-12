# DSA-Assingment2

a program that will allow users the ability to order items from a
supermarket online. The Item will consist of three attributes.

● Item Name
● It’s category
● Item price

For the Item creation, there must be an item class where objects are part of
the node which will form the non-linear trees. In other terms, the program
is made up of three tree data structures which are 1 binary search tree,
2 heaps and 3 avl and they are all node-based.
Below is an example of what the item class must include, however more
functionality can be added.

The program will implement the three tree data structures as following:
1) A Menu that allow user to choose which non linear structure:

i. Binary Search Trees (BST)

ii. Heaps

iii. AVL Trees

2) Each tree should have its own mini menu:
The mini-menu has all the operation that are applied the tree
structures:

I. Add item data,

II. Remove item data,

III. Display the item data normally

IV. Display all the items sorted by their name
ascending

V. Display all the items sorted by their name
descending,

VI. Display all the items sorted by their prices
ascending

VII. Display all the items sorted by their prices
descending.


Note: For Heap, the sorting is done using, Min Heap, Max Heap and
Heap sort
3) Read the items from a file or add items manually
To do so you should:
Implement a global
readItems(istream&,tree&) function, which takes the file name and
the tree and reads the items in the file into the tree. Consider having the following file as a user reading list to use it for filling your trees.
