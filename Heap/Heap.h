//
// Created by omarashraf_3 on 18/05/2024.
//
#ifndef UNTITLED23_HEAP_H
#define UNTITLED23_HEAP_H
#include <iostream>
#include <vector>
#include "Item.h"
using namespace std;
class MinHeapPrice;
class MaxHeapPrice{
private:
    int position = 0 , size = 0 , z= 0 , flag = 0;
    vector<Item>heap;
    friend class MinHeapPrice;
    void remove(int i);
    void maxHeapify(int n);
    void buildingMaxHeapPrice ();
public:
    MaxHeapPrice();
    MaxHeapPrice(Item arr[] , int n);
    void insert(Item n);
    void display();
    void deletee(string name);
    void heapSort();
    void desSort();
    void ascSort();
    MaxHeapPrice& operator=( MinHeapPrice& other) ;


};



class MinHeapPrice{
private:
    friend class MaxHeapPrice;
    int position = 0 , size = 0 , z = 0;
    vector<Item>heap;
//    vectorsorted;
    void remove(int i);
    void minHeapify(int n);
    void buildingMinHeapPrice();
public:
    MinHeapPrice();
    MinHeapPrice(Item arr[] , int n);
    void insert(Item n);
    void display();
    void deletee(string name);
    void heapSort();
    void ascSort();
    void desSort();
    MinHeapPrice& operator=( MaxHeapPrice& other) ;


};


class MinHeapName;
class MaxHeapName{
private:
    int position = 0 , size = 0 , z= 0 , flag = 0;
    vector<Item>heap;
    friend class MinHeapName;
    void remove(int i);
    void maxHeapify(int n);
    void buildingMaxHeapName ();
public:
    MaxHeapName();
    MaxHeapName(Item arr[] , int n);
    void insert(Item n);
    void display();
    void deletee(string name);
    void heapSort();
    void desSort();
    void ascSort();
    MaxHeapName& operator=( MinHeapName& other) ;


};


class MinHeapName{
private:
    int position = 0 , size = 0 , z = 0;
    vector<Item>heap;
//    vectorsorted;
    friend class MaxHeapName;
    void remove(int i);
    void minHeapify(int n);
    void buildingMinHeapName();
public:
    MinHeapName();
    MinHeapName(Item arr[] , int n);
    void insert(Item n);
    void display();
    void deletee(string name);
    void heapSort();
    void ascSort();
    void desSort();
    MinHeapName& operator=( MaxHeapName& other) ;


};

#endif //UNTITLED23_HEAP_H
