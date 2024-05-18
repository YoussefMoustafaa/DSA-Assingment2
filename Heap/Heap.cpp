//
// Created by omarashraf_3 on 18/05/2024.
//

#include "Heap.h"
#include <iostream>
#include <vector>
using namespace std;
void MaxHeapPrice::ascSort() {
    heapSort();
}

//
MaxHeapPrice& MaxHeapPrice::operator=( MinHeapPrice & other)  {
    size = other.size;
    position = other.position;
    heap.clear();
    for(int i = 0 ; i < size ; i++) {
        heap.push_back(other.heap[i]);
    }

    return *this;
}





//
void MaxHeapPrice::buildingMaxHeapPrice() {
    int times = (size-2)/2;
    while(times >= 0) {
        Item temp = heap[times];
        int p , child;
        p =  times;
        child = (p * 2) + 1 ;
        while(child < size){
            if(child + 1 < size) {
                if (heap[child + 1].getPrice() > heap[child].getPrice()) child++;
            }
            if(heap[child].getPrice() > heap[p].getPrice()) {
                swap(heap[child] , heap[p]);
                p = child;
                child = (child*2) + 1;
            }
            else break;
        }
        heap[p] = temp;
        times--;

    }
}


//
void MaxHeapPrice::remove(int i = 0 ) {
    Item temp = heap[i];

    heap[i] = heap[--z];
    int p , child;
    p = i ;
    child = (p * 2) + 1 ;
    while(child < z){
        if(child + 1 < size) {
            if (heap[child + 1].getPrice() > heap[child].getPrice()) child++;
        }
        if(heap[child].getPrice() > heap[p].getPrice()) {
            swap(heap[child] , heap[p]);
            p = child;
            child = (child*2) +1 ;
        }
        else break;
    }
    heap[z] = temp;
}


//
void MaxHeapPrice::maxHeapify(int n) {
//    heap.push_back(n);
    int p = n;
    Item temp = heap[p];
    while(p > 0 && temp.getPrice() > heap[(p+1)/2 -1].getPrice()){
        heap[p] = heap[(p+1)/2 -1];
        p = (p+1)/2 -1;

    }

    heap[p] = temp;

}



//
void MaxHeapPrice::deletee(string name) {
    for(int i = 0 ; i < size ;i ++){
        if(heap[i].getItemName() == name){
            z = size;
            remove(i);
            size --;
            break;
        }
    }
    buildingMaxHeapPrice();


}



//template <class Item>
MaxHeapPrice::MaxHeapPrice() {
//    this->heap.push_back(0);
}
//template <class Item>
MaxHeapPrice::MaxHeapPrice(Item arr[] , int n) {
    size = n;
    for(int i = 0 ; i < n ; i++){
        heap.push_back(arr[i]);
    }

    buildingMaxHeapPrice();
}




//
void MaxHeapPrice::display() {
    for(int i = 0 ; i < size; i++){
        cout << heap[i] << ' ';
    }
    cout << endl;

}



//
void MaxHeapPrice::insert(Item n) {
    if(flag){
        buildingMaxHeapPrice();
        flag = 0;
    }
    heap.push_back(n);
    maxHeapify(size);
    size ++;
}



//
void MaxHeapPrice::heapSort() {
    buildingMaxHeapPrice();
    int x = size;
    z = size;
    for(int i = 0 ; i < x ; i++){
        remove();
    }
    flag = 1;
//    buildingMaxHeapPrice();
}



//
//
//



void MinHeapPrice::desSort() {
    heapSort();
}

//
MinHeapPrice::MinHeapPrice(Item arr[], int n) {
    size = n;
    for(int i = 0 ; i < n ; i++){
        heap.push_back(arr[i]);
    }

    buildingMinHeapPrice();
}

//
void MinHeapPrice::buildingMinHeapPrice() {
    int w = size;
    int times = (size-2)/2;
    while(times >= 0) {
        Item temp = heap[times];
        int p , child;
        p =  times;
        child = (p * 2) + 1 ;
        while(child < size){
            if(child + 1 < size) {
                if (heap[child + 1].getPrice() < heap[child].getPrice()) child++;
            }
            if(heap[child].getPrice() < heap[p].getPrice()) {
                swap(heap[child] , heap[p]);
                p = child;
                child = (child*2)+1;
            }
            else break;
        }
//        displayMinHeapPrice();
        heap[p] = temp;
        times--;
//        displayMinHeapPrice();

    }
}

//
//MinHeapPrice::~MinHeapPrice() {
//
//}




//
void MinHeapPrice::minHeapify(int n ) {
    int p = n;
    Item temp = heap[p];
    while(p > 0 && temp.getPrice() < heap[(p+1)/2 -1].getPrice()){
        heap[p] = heap[(p+1)/2 -1];
        p = (p+1)/2 -1;

    }

    heap[p] = temp;

}



//
void MinHeapPrice::remove(int i = 0) {
    Item temp = heap[i];
    heap[i] = heap[--z];
    int p , child;
    p = i ;
    child = (p * 2) + 1 ;
    while(child < z){
        if(child + 1 < size) {
            if (heap[child + 1].getPrice() < heap[child].getPrice()) child++;
        }
        if(heap[child].getPrice() < heap[p].getPrice()) {
            swap(heap[child] , heap[p]);
            p = child;
            child = (child*2) +1;
        }
        else break;
    }
    heap[z] = temp;
}



//
void MinHeapPrice::deletee(string name) {
    for(int i = 0 ; i < size ;i ++){
        if(heap[i].getItemName() == name){
            z = size;
            remove(i);
            size --;
            break;
        }
    }
    buildingMinHeapPrice();

}



//template <class Item>
MinHeapPrice::MinHeapPrice() {
//    this->heap.push_back(0);
}



//
void MinHeapPrice::display() {
    for(int i = 0 ; i < size; i++){
        cout << heap[i] << ' ';
    }
    cout << endl;

}



//
void MinHeapPrice::insert(Item n) {
    heap.push_back(n);
    minHeapify(size);
    size ++;
}



void MinHeapPrice::heapSort() {
    buildingMinHeapPrice();
    int x = size;
    z = size;
    for(int i = 0 ; i < x ; i++){
        remove();
    }


}




MinHeapPrice& MinHeapPrice::operator=( MaxHeapPrice &other) {

    size = other.size;
    position = other.position;
    heap.clear();
    for(int i = 0 ; i < size ; i++) {
        heap.push_back(other.heap[i]);
    }

    return *this;
}



void MaxHeapPrice::desSort() {
    MinHeapPrice temp; // Assuming MaxHeapPrice is a separate class


    temp = *this;

    temp.buildingMinHeapPrice();


    temp.heapSort();


    *this = temp;
}

//
void MinHeapPrice::ascSort() {
    MaxHeapPrice temp;

    temp = *this;


    temp.buildingMaxHeapPrice();


    temp.heapSort();


    *this = temp;
}


void MaxHeapName::ascSort() {
    heapSort();
}

//
MaxHeapName& MaxHeapName::operator=( MinHeapName & other)  {
    size = other.size;
    position = other.position;
    heap.clear();
    for(int i = 0 ; i < size ; i++) {
        heap.push_back(other.heap[i]);
    }

    return *this;
}





//
void MaxHeapName::buildingMaxHeapName() {
    int times = (size-2)/2;
    while(times >= 0) {
        Item temp = heap[times];
        int p , child;
        p =  times;
        child = (p * 2) + 1 ;
        while(child < size){
            if(child + 1 < size) {
                if (heap[child + 1].getItemName() > heap[child].getItemName()) child++;
            }
            if(heap[child].getItemName() > heap[p].getItemName()) {
                swap(heap[child] , heap[p]);
                p = child;
                child = (child*2) + 1;
            }
            else break;
        }
        heap[p] = temp;
        times--;

    }
}


//
void MaxHeapName::remove(int i = 0) {
    Item temp = heap[i];

    heap[i] = heap[--z];
    int p , child;
    p = i ;
    child = (p * 2) + 1 ;
    while(child < z){
        if(child + 1 < size) {
            if (heap[child + 1].getItemName() > heap[child].getItemName()) child++;
        }
        if(heap[child].getItemName() > heap[p].getItemName()) {
            swap(heap[child] , heap[p]);
            p = child;
            child = (child*2) +1 ;
        }
        else break;
    }
    heap[z] = temp;
}


//
void MaxHeapName::maxHeapify(int n) {
//    heap.push_back(n);
    int p = n;
    Item temp = heap[p];
    while(p > 0 && temp.getItemName() > heap[(p+1)/2 -1].getItemName()){
        heap[p] = heap[(p+1)/2 -1];
        p = (p+1)/2 -1;

    }

    heap[p] = temp;

}



//
void MaxHeapName::deletee(string name) {
    for(int i = 0 ; i < size ;i ++){
        if(heap[i].getItemName() == name){
            z = size;
            remove(i);
            size --;
            break;
        }
    }
    buildingMaxHeapName();

}



//template <class Item>
MaxHeapName::MaxHeapName() {
//    this->heap.push_back(0);
}
//template <class Item>
MaxHeapName::MaxHeapName(Item arr[] , int n) {
    size = n;
    for(int i = 0 ; i < n ; i++){
        heap.push_back(arr[i]);
    }

    buildingMaxHeapName();
}




//
void MaxHeapName::display() {
    for(int i = 0 ; i < size; i++){
        cout << heap[i] << ' ';
    }
    cout << endl;

}



//
void MaxHeapName::insert(Item n) {
    if(flag){
        buildingMaxHeapName();
        flag = 0;
    }
    heap.push_back(n);
    maxHeapify(size);
    size ++;
}



//
void MaxHeapName::heapSort() {
    buildingMaxHeapName();
    int x = size;
    z = size;
    for(int i = 0 ; i < x ; i++){
        remove();
    }
    flag = 1;
//    buildingMaxHeapName();
}



//
//
//



void MinHeapName::desSort() {
    heapSort();
}

//
MinHeapName::MinHeapName(Item arr[], int n) {
    size = n;
    for(int i = 0 ; i < n ; i++){
        heap.push_back(arr[i]);
    }

    buildingMinHeapName();
}

//
void MinHeapName::buildingMinHeapName() {
    int w = size;
    int times = (size-2)/2;
    while(times >= 0) {
        Item temp = heap[times];
        int p , child;
        p =  times;
        child = (p * 2) + 1 ;
        while(child < size){
            if(child + 1 < size) {
                if (heap[child + 1].getItemName() < heap[child].getItemName()) child++;
            }
            if(heap[child].getItemName() < heap[p].getItemName()) {
                swap(heap[child] , heap[p]);
                p = child;
                child = (child*2)+1;
            }
            else break;
        }
//        displayMinHeapName();
        heap[p] = temp;
        times--;
//        displayMinHeapName();

    }
}

//
//MinHeapName::~MinHeapName() {
//
//}




//
void MinHeapName::minHeapify(int n ) {
    int p = n;
    Item temp = heap[p];
    while(p > 0 && temp.getItemName() < heap[(p+1)/2 -1].getItemName()){
        heap[p] = heap[(p+1)/2 -1];
        p = (p+1)/2 -1;

    }

    heap[p] = temp;

}



//
void MinHeapName::remove(int i = 0) {
    Item temp = heap[i];
    heap[i] = heap[--z];
    int p , child;
    p = i ;
    child = (p * 2) + 1 ;
    while(child < z){
        if(child + 1 < size) {
            if (heap[child + 1].getItemName() < heap[child].getItemName()) child++;
        }
        if(heap[child].getItemName() < heap[p].getItemName()) {
            swap(heap[child] , heap[p]);
            p = child;
            child = (child*2) +1;
        }
        else break;
    }
    heap[z] = temp;
}



//
void MinHeapName::deletee(string name) {
    for(int i = 0 ; i < size ;i ++){
        if(heap[i].getItemName() == name){
            z = size;
            remove(i);
            size --;
            break;
        }
    }
    buildingMinHeapName();

}



//template <class Item>
MinHeapName::MinHeapName() {
//    this->heap.push_back(0);
}



//
void MinHeapName::display() {
    for(int i = 0 ; i < size; i++){
        cout << heap[i] << ' ';
    }
    cout << endl;

}



//
void MinHeapName::insert(Item n) {
    heap.push_back(n);
    minHeapify(size);
    size ++;
}



void MinHeapName::heapSort() {
    buildingMinHeapName();
    int x = size;
    z = size;
    for(int i = 0 ; i < x ; i++){
        remove();
    }


}




MinHeapName& MinHeapName::operator=( MaxHeapName &other) {

    size = other.size;
    position = other.position;
    heap.clear();
    for(int i = 0 ; i < size ; i++) {
        heap.push_back(other.heap[i]);
    }

    return *this;
}



void MaxHeapName::desSort() {
    MinHeapName temp; // Assuming MaxHeapName is a separate class


    temp = *this;

    temp.buildingMinHeapName();


    temp.heapSort();


    *this = temp;
}

//
void MinHeapName::ascSort() {
    MaxHeapName temp;

    temp = *this;


    temp.buildingMaxHeapName();


    temp.heapSort();


    *this = temp;
}
