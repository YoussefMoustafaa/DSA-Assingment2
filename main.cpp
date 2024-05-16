#include "Item Class/Item.h"
#include "Binary Search Trees (BST)/BinarySearchTree.h"
#include "AVL Trees/AVLTree.h"
#include "Heap/main.cpp"
ifstream file("C:\\Users\\001\\Documents\\GitHub\\DSA-Assingment2\\Output files\\items.txt");
MinHeap<Item>minHeapItems;
MaxHeap<Item>maxHeapItem;
template<typename TreeType>
void readItems(ifstream& fileName,TreeType& tree){
    if (!fileName.is_open()) {
        cout << "Failed to open the file." << endl;
    }
    int size;
    fileName >> size;
    fileName.ignore();
    Item itemList[size];
    for (int i = 0; i < size; ++i) {
        string name, category;
        int price;
        getline(fileName, name);
        fileName >> category >> price;
        fileName.ignore();
        itemList[i]=Item(name, category, price);
    }
    fileName.close();
    for(int i =0; i<size;i++){
        tree.insert(itemList[i]);
    }
}
void minHeapMenu(){
    cout<<"1-Add item\n"
    <<"2-Remove item\n"
    <<"3-Display all the items normally\n"
    <<"4-Display all the items sorted by their name ascending\n"
    <<"5-Display all the items sorted by their name descending\n"
    <<"6-Display all the items sorted by their prices ascending\n"
    <<"7-Display all the items sorted by their prices descending\n"
    <<"8-Exist\n";
    int x;
    cin>>x;
    Item newItem;
    string name;
    string category;
    int price;
    switch (x) {
        case 1:
            cout<<"1-Insert data from file\n";
            cout<<"2-Insert data manually\n";
            int y;
            cin>>y;
            if(y==1){
                readItems(file,minHeapItems);
                cout<<"inserted!\n";
            }else if(y==2){
                cout<<"Please enter item's name:\n";
                cin>>name;
                newItem.setItemName(name);
                cout<<"Please enter item's category:\n";
                cin>>category;
                newItem.setCategory(category);
                cout<<"Please enter item's price:\n";
                cin>>price;
                newItem.setPrice(price);
                minHeapItems.insert(newItem);

            }
            minHeapMenu();
            break;
        case 2:
            minHeapItems.delet();
            cout<<"Last element removed successfully!\n";
            minHeapMenu();
            break;
        case 3:
            minHeapItems.display();
            minHeapMenu();
            break;
        case 4:
            minHeapItems.ascSort();
            minHeapMenu();
            break;

        case 5:
            minHeapMenu();


            break;
        case 6:
            minHeapMenu();
            break;
            minHeapMenu();
        case 7:
            minHeapMenu();
            break;
        case 8:
            break;
        default:
            cout<<"Invalid option make sure you choose number 1 or 2\n\n";
            minHeapMenu();
            break;
    }

}void maxHeapMenu(){
    cout<<"1-Add item\n"
        <<"2-Remove item\n"
        <<"3-Display all the items normally\n"
        <<"4-Display all the items sorted by their name ascending\n"
        <<"5-Display all the items sorted by their name descending\n"
        <<"6-Display all the items sorted by their prices ascending\n"
        <<"7-Display all the items sorted by their prices descending\n"
        <<"8-Exist\n";
    int x;
    cin>>x;
    Item newItem;
    string name;
    string category;
    int price;
    switch (x) {
        case 1:
            cout<<"1-Insert data from file\n";
            cout<<"2-Insert data manually\n";
            int y;
            cin>>y;
            if(y==1){
                readItems(file,minHeapItems);
                cout<<"inserted!\n";
            }else if(y==2){
                cout<<"Please enter item's name:\n";
                cin>>name;
                newItem.setItemName(name);
                cout<<"Please enter item's category:\n";
                cin>>category;
                newItem.setCategory(category);
                cout<<"Please enter item's price:\n";
                cin>>price;
                newItem.setPrice(price);
                cout<<newItem;

            }
            minHeapMenu();
            break;
        case 2:
            minHeapItems.delet();
            cout<<"Last element removed successfully!\n";
            minHeapMenu();
            break;
        case 3:
            minHeapItems.display();
            minHeapMenu();
            break;
        case 4:
            minHeapMenu();
            break;

        case 5:
            minHeapMenu();


            break;
        case 6:
            minHeapMenu();
            break;
            minHeapMenu();
        case 7:
            minHeapMenu();
            break;
        case 8:
            break;
        default:
            cout<<"Invalid option make sure you choose number 1 or 2\n\n";
            minHeapMenu();
            break;
    }
}
void heapMenu(){
    cout<<"Please Select heap type:\n\n";
    cout<<"1-MaxHeap\n"<<"2-MinHeap\n";
    int x;
    cin>>x;
    switch (x) {
        case 1:
            maxHeapMenu();
            break;
        case 2:
            minHeapMenu();
            break;
        default:
            cout<<"Invalid option make sure you choose number 1 or 2\n\n";
            heapMenu();
            break;
    }

}
void mainMenu(){
    cout<<"Please Select which structure do you want to use:\n\n";
    cout<<"1-Binary Search Trees (BST)\n"<<"2-Heaps\n"<<"3-AVL Trees\n";
    int x;
    cin>>x;
    switch (x) {
        case 1:
            break;
        case 2:
            heapMenu();
            break;
        case 3:
            break;
        default:
            cout<<"Invalid option make sure you choose number 1:3.\n\n";
            mainMenu();
            break;
    }

}
int main(){
    mainMenu();
}