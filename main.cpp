#include "Item Class/Item.h"
#include "Binary Search Trees (BST)/BinarySearchTree.h"
#include "AVL Trees/AVLTree.h"
AVLTree avlTree;
BinarySearchTree binarySearchTree;
void readItems(ifstream& fileName,AVLTree& tree){
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
}void readItems(ifstream& fileName,BinarySearchTree& tree){
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
    ifstream file("C:\\Users\\001\\Documents\\GitHub\\DSA-Assingment2\\Output files\\items.txt");
    readItems(file,avlTree);
    readItems(file,binarySearchTree);
    mainMenu();
}