#include <iostream>
#include <vector>
using namespace std;
template <class T>
class MinHeap;

template <class T>
class MaxHeap{
private:
    int position = 0 , size = 0 , z= 0 , flag = 0;
    vector<T>heap;
    friend class MinHeap<T>;
    void remove();
    void maxHeapify(int n);
    void buildingMaxHeap ();
    MaxHeap<T>& operator=( MinHeap<T>& other) ;
public:
    MaxHeap();
    MaxHeap(T arr[] , int n);
    void insert(T n);
    void display();
    void delet();
    void heapSort();
    void desSort();
    void ascSort();
    ~MaxHeap();


};

template<class T>
void MaxHeap<T>::ascSort() {
    heapSort();
}

template<class T>
MaxHeap<T>::~MaxHeap() {

}


template<class T>
MaxHeap<T>& MaxHeap<T>::operator=( MinHeap<T> &other)  {
    size = other.size;
    position = other.position;
    heap.clear();
    for(int i = 0 ; i < size ; i++) {
        heap.push_back(other.heap[i]);
    }

    return *this;
}


//template<class T>
//void MaxHeap<T>::desSort() {
//    MinHeap<T> gg;
//    this = gg;
//    gg.heapSort();
//    for(int i = 0 ; i < size ; i++){
//        this->heap[i] = gg.heap[i];
//    }
//    displayMaxHeap();
//}


template<class T>
void MaxHeap<T>::buildingMaxHeap() {
    int times = (size-2)/2;
    while(times >= 0) {
        T temp = heap[times];
        int p , child;
        p =  times;
        child = (p * 2) + 1 ;
        while(child < size){
            if(child + 1 < size) {
                if (heap[child + 1] > heap[child]) child++;
            }
            if(heap[child] > heap[p]) {
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


template<class T>
void MaxHeap<T>::remove() {
    T temp = heap[0];

    heap[0] = heap[--z];
    int p , child;
    p = 0 ;
    child = (p * 2) + 1 ;
    while(child < z){
        if(child + 1 < size) {
            if (heap[child + 1] > heap[child]) child++;
        }
        if(heap[child] > heap[p]) {
            swap(heap[child] , heap[p]);
            p = child;
            child = (child*2) +1 ;
        }
        else break;
    }
    heap[z] = temp;
}


template<class T>
void MaxHeap<T>::maxHeapify(int n) {
//    heap.push_back(n);
    int p = n;
    T temp = heap[p];
    while(p > 0 && temp > heap[(p+1)/2 -1]){
        heap[p] = heap[(p+1)/2 -1];
        p = (p+1)/2 -1;

    }

    heap[p] = temp;

}



template<class T>
void MaxHeap<T>::delet() {
    z = size;
    remove();
    size --;

}



template <class T>
MaxHeap<T>::MaxHeap() {
//    this->heap.push_back(0);
}
template <class T>
MaxHeap<T>::MaxHeap(T arr[] , int n) {
    size = n;
    for(int i = 0 ; i < n ; i++){
        heap.push_back(arr[i]);
    }

    buildingMaxHeap();
}




template<class T>
void MaxHeap<T>::display() {
    for(int i = 0 ; i < size; i++){
        cout << heap[i] << ' ';
    }
    cout << endl;

}



template<class T>
void MaxHeap<T>::insert(T n) {
    if(flag){
        buildingMaxHeap();
        flag = 0;
    }
    heap.push_back(n);
    maxHeapify(size);
    size ++;
}



template<class T>
void MaxHeap<T>::heapSort() {
    buildingMaxHeap();
    int x = size;
    z = size;
    for(int i = 0 ; i < x ; i++){
        remove();
    }
    flag = 1;
//    buildingMaxHeap();
}



//
//
//


template <class T>
class MinHeap{
private:
    int position = 0 , size = 0 , z = 0;
    vector<T>heap;
    vector<T>sorted;
    friend class MaxHeap<T>;
    void remove();
    void minHeapify(int n);
    void buildingMinHeap();
public:
    MinHeap();
    MinHeap(T arr[] , int n);
    void insert(T n);
    void display();
    void delet();
    void heapSort();
    void ascSort();
    void desSort();

//    ~MinHeap();
    MinHeap<T>& operator=( MaxHeap<T>& other) ;


};

template<class T>
void MinHeap<T>::desSort() {
    heapSort();
}

template<class T>
MinHeap<T>::MinHeap(T arr[], int n) {
    size = n;
    for(int i = 0 ; i < n ; i++){
        heap.push_back(arr[i]);
    }

    buildingMinHeap();
}

template<class T>
void MinHeap<T>::buildingMinHeap() {
    int w = size;
    int times = (size-2)/2;
    while(times >= 0) {
        T temp = heap[times];
        int p , child;
        p =  times;
        child = (p * 2) + 1 ;
        while(child < size){
            if(child + 1 < size) {
                if (heap[child + 1] < heap[child]) child++;
            }
            if(heap[child] < heap[p]) {
                swap(heap[child] , heap[p]);
                p = child;
                child = (child*2)+1;
            }
            else break;
        }
//        displayMinHeap();
        heap[p] = temp;
        times--;
//        displayMinHeap();

    }
}

//template<class T>
//MinHeap<T>::~MinHeap() {
//
//}




template<class T>
void MinHeap<T>::minHeapify(int n ) {
    int p = n;
    T temp = heap[p];
    while(p > 0 && temp < heap[(p+1)/2 -1]){
        heap[p] = heap[(p+1)/2 -1];
        p = (p+1)/2 -1;

    }

    heap[p] = temp;

}



template<class T>
void MinHeap<T>::remove() {
    T temp = heap[0];
    heap[0] = heap[--z];
    int p , child;
    p = 0 ;
    child = (p * 2) + 1 ;
    while(child < z){
        if(child + 1 < size) {
            if (heap[child + 1] < heap[child]) child++;
        }
        if(heap[child] < heap[p]) {
            swap(heap[child] , heap[p]);
            p = child;
            child = (child*2) +1;
        }
        else break;
    }
    heap[z] = temp;
}



template<class T>
void MinHeap<T>::delet() {
    z = size;
    remove();
    size --;

}



template <class T>
MinHeap<T>::MinHeap() {
//    this->heap.push_back(0);
}



template<class T>
void MinHeap<T>::display() {
    for(int i = 0 ; i < size; i++){
        cout << heap[i] << ' ';
    }
    cout << endl;

}



template<class T>
void MinHeap<T>::insert(T n) {
    heap.push_back(n);
    minHeapify(size);
    size ++;
}


template<class T>
void MinHeap<T>::heapSort() {
    buildingMinHeap();
    int x = size;
    z = size;
    for(int i = 0 ; i < x ; i++){
        remove();
    }


}



template<class T>
MinHeap<T>& MinHeap<T>::operator=( MaxHeap<T> &other) {

        size = other.size;
        position = other.position;
        heap.clear();
        for(int i = 0 ; i < size ; i++) {
            heap.push_back(other.heap[i]);
        }

    return *this;
}


template<class T>
void MaxHeap<T>::desSort() {
    MinHeap<T> temp; // Assuming MaxHeap is a separate class


    temp = *this;

    temp.buildingMinHeap();


    temp.heapSort();


    *this = temp;
}

template<class T>
void MinHeap<T>::ascSort() {
    MaxHeap<T> temp;


    temp = *this;


    temp.buildingMaxHeap();


    temp.heapSort();


    *this = temp;
}
int main() {
    MaxHeap<int> morio;
    morio.insert(5);
    morio.insert(4);
    morio.insert(3);
    morio.insert(2);
    morio.insert(1);
    morio.insert(9);
    morio.delet();
    morio.display();
    morio.heapSort();
    morio.display();
    morio.ascSort();
    morio.display();
    morio.desSort();
    morio.display();

    cout<<endl<<endl;
//    int arr[5] = { 6 , 1 , 2, 3, 4};
//    MaxHeap<int> jj(arr , 5);
//    jj.display();
//    MinHeap<int> gg(arr, 5);
//    gg.display();
//    morio.insertMaxHeap(9);
//    morio.displayMaxHeap();
//    cout<<endl<<endl;
cout<<endl<<endl;
    MinHeap<int> morio2;
    morio2.insert(5);
    morio2.insert(4);
    morio2.insert(3);
    morio2.insert(2);
    morio2.insert(1);
    morio2.insert(9);
//    morio2.delet();
    morio2.display();
    morio2.heapSort();
    morio2.display();
    morio2.desSort();
    morio2.display();
    morio2.ascSort();
    morio2.display();


}
