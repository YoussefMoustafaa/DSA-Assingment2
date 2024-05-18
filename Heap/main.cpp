#include <iostream>
#include <vector>
using namespace std;
//template <class Item>

class Item {
private:
    string itemName;
    string category;
    int price;
public:
    bool operator==(const Item& other) const {
        return price == other.price;
    }
    Item();
    Item(const string &itemName, const string &category, int price);

    bool operator<(const Item&);

    friend ostream &operator<<(ostream &os, const Item &item);

    void setItemName(const string &itemName);

    friend std::istream& operator>>(std::istream& in, Item& st);

    const string &getCategory() const;

    void setCategory(const string &category);

    int getPrice() const;

    void setPrice(int price);

    const string &getItemName() const;

};
const string &Item::getItemName() const {
    return itemName;
}

void Item::setItemName(const string &itemName) {
    Item::itemName = itemName;
}

const string &Item::getCategory() const {
    return category;
}

void Item::setCategory(const string &category) {
    Item::category = category;
}

int Item::getPrice() const {
    return price;
}

void Item::setPrice(int price) {
    Item::price = price;
}

ostream &operator<<(ostream &os, const Item &item) {
    os << "ItemName: " << item.itemName << " Category: " << item.category
       << " Price: " << item.price <<"$\n";
    return os;
}

Item::Item(const string &itemName, const string &category, int price) : itemName(itemName), category(category),
                                                                        price(price) {}

std::istream &operator>>(istream &in, Item &st) {
    in >> st.price >> st.category >> st.itemName;
    return in;
}
bool Item::operator<(const Item &st)
{
    return this->price < st.price;
}

Item::Item() {
    this->price=0;
    this->itemName="";
    this->category="";
}

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
    int position = 0 , size = 0 , z = 0;
    vector<Item>heap;
//    vectorsorted;
    friend class MaxHeapPrice;
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
int main() {
    Item gg;
    gg.setItemName("a");
    gg.setCategory("dakj");
    gg.setPrice(50);
    Item g;
    g.setItemName("b");
    g.setCategory("dakj");
    g.setPrice(70);
    Item gh;
    gh.setItemName("c");
    gh.setCategory("dakj");
    gh.setPrice(9);
    Item gj;
    gj.setItemName("d");
    gj.setCategory("dakj");
    gj.setPrice(10);
    Item gl;
    gl.setItemName("e");
    gl.setCategory("dakj");
    gl.setPrice(20);
    Item gm;
    gm.setItemName("f");
    gm.setCategory("dakj");
    gm.setPrice(40);
    Item gu;
    gu.setItemName("g");
    gu.setCategory("dakj");
    gu.setPrice(90);
    MaxHeapName morio;
    morio.insert(gu);
    morio.insert(gm);
    morio.insert(gl);
    morio.insert(g);
    morio.insert(gg);
    morio.insert(gj);
    morio.insert(gh);
    morio.heapSort();
//    morio.ascSort();
//    morio.display();
    morio.deletee("e");
//    morio.deletee(string name);
    morio.display();
//    morio.desSort();
//    morio.display();
//    morio.insert(5);
//    morio.insert(4);
//    morio.insert(3);
//    morio.insert(2);
//    morio.insert(1);
//    morio.insert(9);
//    morio.deletee(string name);
//    morio.display();
//    morio.heapSort();
//    morio.display();
//    morio.ascSort();
//    morio.display();
//    morio.desSort();
//    morio.display();

    cout<<endl<<endl;
//    int arr[5] = { 6 , 1 , 2, 3, 4};
//    MaxHeapPrice<int> jj(arr , 5);
//    jj.display();
//    MinHeapPrice<int> gg(arr, 5);
//    gg.display();
//    morio.insertMaxHeapPrice(9);
//    morio.displayMaxHeapPrice();
//    cout<<endl<<endl;
    cout<<endl<<endl;
//    MinHeapPrice<int> morio2;
//    morio2.insert(5);
//    morio2.insert(4);
//    morio2.insert(3);
//    morio2.insert(2);
//    morio2.insert(1);
//    morio2.insert(9);
////    morio2.deletee(string name);
//    morio2.display();
//    morio2.heapSort();
//    morio2.display();
//    morio2.desSort();
//    morio2.display();
//    morio2.ascSort();
//    morio2.display();


}
