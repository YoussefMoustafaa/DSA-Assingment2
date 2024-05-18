cmake_minimum_required(VERSION 3.27)
project(DSA_Assingment2)

set(CMAKE_CXX_STANDARD 14)

include_directories("Item Class")

add_executable(DSA_Assingment2
        "Item Class/Item.cpp"
        "Item Class/Item.h"
        main.cpp
        "Binary Search Trees (BST)/BinarySearchTree.h"
        "AVL Trees/AVLTree.cpp"
        "Heap/Heap.h")
