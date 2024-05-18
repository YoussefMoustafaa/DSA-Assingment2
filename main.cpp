#include "Item Class/Item.h"
#include "Binary Search Trees (BST)/BinarySearchTree.cpp"
#include "AVL Trees/AVLTree.h"
#include "Heap/Heap.cpp"
ifstream file("C:\\Users\\001\\Documents\\GitHub\\DSA-Assingment2\\Output files\\items.txt");
auto comparePrice = [](const Item &a, const Item &b)
{
    if (a.getPrice() < b.getPrice())
        return -1;
    else if (a.getPrice() == b.getPrice())
        return 0;
    else
        return 1;
};
auto compareName = [](const Item &a, const Item &b)
{
    if (a.getItemName() < b.getItemName())
        return -1;
    else if (a.getItemName() == b.getItemName())
        return 0;
    else
        return 1;
};
bool opened = 0;
vector<Item> vectorForNormalInput; // for sorting items the order they were entered in
template <typename TreeType>
void readItems(ifstream &fileName, TreeType &tree)
{
    if (!fileName.is_open())
    {
        cout << "Failed to open the file." << endl;
    }
    int size;
    fileName >> size;
    fileName.ignore();
    Item itemList[size];
    for (int i = 0; i < size; ++i)
    {
        string name, category;
        int price;
        getline(fileName, name);
        fileName >> category >> price;
        fileName.ignore();
        itemList[i] = Item(name, category, price);
    }
    fileName.close();
    for (int i = 0; i < size; i++)
    {
        tree.insert(itemList[i]);
    }
    if(!opened){
        opened=1;
        for (int i = 0; i < size; i++)
        {
            vectorForNormalInput.push_back(itemList[i]);
        }
    }
    fileName.open("C:\\Users\\001\\Documents\\GitHub\\DSA-Assingment2\\Output files\\items.txt");
}
Item itemToBeDeleted;
void BinaryTreeMenu()
{
    // initiating instances
    binarySearchTreeType<Item> BSTname(compareName);
    binarySearchTreeType<Item> BSTprice(comparePrice);
    string nameOfDeleted;

    bool loop = true;

    while (loop)
    {
        cout << "1-Add item\n"
             << "2-Remove item\n"
             << "3-Display all the items normally\n"
             << "4-Display all the items sorted by their name ascending\n"
             << "5-Display all the items sorted by their name descending\n"
             << "6-Display all the items sorted by their prices ascending\n"
             << "7-Display all the items sorted by their prices descending\n"
             << "8-Exist\n";
        int x;
        cin >> x;
        switch (x)
        {
        case 1:
            cout << "1-add data from file\n2-add data manually";
            int c;
            cin >> c;
            if (c == 1)
            {

                readItems(file, BSTname);
                readItems(file, BSTprice);
            }
            else
            {
                Item item;
                cout << "enter item's name\n";
                string name;
                cin >> name;
                item.setItemName(name);
                cout << "enter item's category\n";
                string category;
                cin >> category;
                item.setCategory(category);
                cout << "enter item's price\n";
                int price;
                cin >> price;
                item.setPrice(price);
                BSTname.insert(item);
                BSTprice.insert(item);
                vectorForNormalInput.push_back(item);
            }
            break;
        case 2:
            cout << "enter the name of the item you want to delete\n";
            cin >> nameOfDeleted;
            itemToBeDeleted.setItemName("not Found");
            for (auto i : vectorForNormalInput)
            {
                if (i.getItemName() == nameOfDeleted)
                {
                    itemToBeDeleted = i;
                    break;
                }
            }
            if (itemToBeDeleted.getItemName() != "not Found")
            {
                BSTname.remove(itemToBeDeleted);
                BSTprice.remove(itemToBeDeleted);
                vectorForNormalInput.erase(
                    remove(vectorForNormalInput.begin(), vectorForNormalInput.end(), itemToBeDeleted), vectorForNormalInput.end());
            }
            else
            {
                cout << "item not found\n";
            }
            break;
        case 3:
            for (auto i : vectorForNormalInput)
            {
                cout << i << endl;
            }
            break;
        case 4:
            BSTname.inorderTraversal();
            break;
        case 5:
            BSTname.descendingorderTraversal();
            break;
        case 6:
            BSTprice.inorderTraversal();
            break;
        case 7:
            BSTprice.descendingorderTraversal();
            break;
        case 8:
            loop = false;
            break;
        default:
            cout << "invalid input\n";
            break;
        }
    }
}


MinHeapName minHeapItemsName;
MinHeapPrice minHeapItemPrice;
MaxHeapPrice maxHeapItemPrice;
MaxHeapName maxHeapItemsName;
string n;
void minHeapMenu()
{
    cout << "1-Add item\n"
         << "2-Remove item\n"
         << "3-Display all the items normally\n"
         << "4-Display all the items sorted by their name ascending\n"
         << "5-Display all the items sorted by their name descending\n"
         << "6-Display all the items sorted by their prices ascending\n"
         << "7-Display all the items sorted by their prices descending\n"
         << "8-Exist\n";
    int x;
    cin >> x;
    Item newItem;
    string name;
    string nameOfDeleted;
    string category;
    int price;
    switch (x)
    {
    case 1:
        cout << "1-Insert data from file\n";
        cout << "2-Insert data manually\n";
        int y;
        cin >> y;
        if (y == 1)
        {

            readItems(file,minHeapItemsName );
            readItems(file,minHeapItemPrice);
            cout << "inserted!\n";
        }
        else if (y == 2)
        {
            cout << "Please enter item's name:\n";
            cin >> name;
            newItem.setItemName(name);
            cout << "Please enter item's category:\n";
            cin >> category;
            newItem.setCategory(category);
            cout << "Please enter item's price:\n";
            cin >> price;
            newItem.setPrice(price);
            minHeapItemsName.insert(newItem);
            minHeapItemPrice.insert(newItem);
            vectorForNormalInput.push_back(newItem);
        }
        minHeapMenu();
        break;
    case 2:
                cout << "enter the name of the item you want to delete\n";
                cin >> nameOfDeleted;
                itemToBeDeleted.setItemName("not Found");
            for (auto i : vectorForNormalInput)
            {
                if (i.getItemName() == nameOfDeleted)
                {
                    itemToBeDeleted = i;
                    break;
                }
            }
                if (itemToBeDeleted.getItemName() != "not Found")
                {
                    minHeapItemsName.deletee(nameOfDeleted);
                    minHeapItemPrice.deletee(nameOfDeleted);
                    vectorForNormalInput.erase(remove(vectorForNormalInput.begin()
                                                      , vectorForNormalInput.end(),
                                                      itemToBeDeleted),
                                               vectorForNormalInput.end());
                    cout << "The element removed successfully!\n";
                }
                else
                {
                    cout << "item not found\n";
                }

            minHeapMenu();
            break;
    case 3:
        for (auto i : vectorForNormalInput)
        {
            cout << i << endl;
        }
        minHeapMenu();
        break;
    case 4:
        minHeapItemsName.ascSort();
        minHeapItemsName.display();
        minHeapMenu();
        break;

    case 5:
        minHeapItemsName.desSort();
        minHeapItemsName.display();

        minHeapMenu();

        break;
    case 6:
        minHeapItemPrice.ascSort();
        minHeapItemPrice.display();

        minHeapMenu();
        break;
    case 7:
        minHeapItemPrice.desSort();
        minHeapItemPrice.display();
        minHeapMenu();
        break;
    case 8:
        break;
    default:
        cout << "Invalid option make sure you choose number 1 or 2\n\n";
        minHeapMenu();
        break;
    }
}
void maxHeapMenu()
{
    cout << "1-Add item\n"
         << "2-Remove item\n"
         << "3-Display all the items normally\n"
         << "4-Display all the items sorted by their name ascending\n"
         << "5-Display all the items sorted by their name descending\n"
         << "6-Display all the items sorted by their prices ascending\n"
         << "7-Display all the items sorted by their prices descending\n"
         << "8-Exist\n";
    int x;
    cin >> x;
    Item newItem;
    string name;
    string category;
    string nameOfDeleted;
    int price;
        switch (x)
        {
            case 1:
                cout << "1-Insert data from file\n";
                cout << "2-Insert data manually\n";
                int y;
                cin >> y;
                if (y == 1)
                {

                    readItems(file,maxHeapItemsName );
                    readItems(file,maxHeapItemPrice);
                    cout << "inserted!\n";
                }
                else if (y == 2)
                {
                    cout << "Please enter item's name:\n";
                    cin >> name;
                    newItem.setItemName(name);
                    cout << "Please enter item's category:\n";
                    cin >> category;
                    newItem.setCategory(category);
                    cout << "Please enter item's price:\n";
                    cin >> price;
                    newItem.setPrice(price);
                    maxHeapItemsName.insert(newItem);
                    maxHeapItemPrice.insert(newItem);
                    vectorForNormalInput.push_back(newItem);
                }
                maxHeapMenu();
                break;
        case 2:
            cout << "enter the name of the item you want to delete\n";
                cin >> nameOfDeleted;
                itemToBeDeleted.setItemName("not Found");
                for (auto i : vectorForNormalInput)
                {
                    if (i.getItemName() == nameOfDeleted)
                    {
                        itemToBeDeleted = i;
                        break;
                    }
                }
                if (itemToBeDeleted.getItemName() != "not Found")
                {
                    maxHeapItemsName.deletee(nameOfDeleted);
                    maxHeapItemPrice.deletee(nameOfDeleted);
                    vectorForNormalInput.erase(remove(vectorForNormalInput.begin()
                                                       , vectorForNormalInput.end(),
                                                      itemToBeDeleted),
                                               vectorForNormalInput.end());
                    cout << "The element removed successfully!\n";
                }
                else
                {
                    cout << "item not found\n";
                }
            maxHeapMenu();
            break;
        case 3:
            for (auto i : vectorForNormalInput)
            {
                cout << i << endl;
            }
            maxHeapMenu();
            break;
        case 4:

            maxHeapItemsName.ascSort();

            maxHeapItemsName.display();

            maxHeapMenu();
            break;

        case 5:
            maxHeapItemsName.desSort();
            maxHeapItemsName.display();
            maxHeapMenu();

            break;
        case 6:
            maxHeapItemPrice.ascSort();
            maxHeapItemPrice.display();
            maxHeapMenu();
            break;
        case 7:
            maxHeapItemPrice.desSort();
            maxHeapItemPrice.display();
            maxHeapMenu();
            break;
        case 8:
            break;
        default:
            cout << "Invalid option make sure you choose number 1 or 2\n\n";
            maxHeapMenu();
            break;
        }
}
void heapMenu()
{
    cout << "Please Select heap type:\n\n";
    cout << "1-MaxHeap\n"
         << "2-MinHeap\n";
    int x;
    cin >> x;
    switch (x)
    {
    case 1:
        maxHeapMenu();
        break;
    case 2:
        minHeapMenu();
        break;
    default:
        cout << "Invalid option make sure you choose number 1 or 2\n\n";
        heapMenu();
        break;
    }
}
void mainMenu()
{
    cout << "Please Select which structure do you want to use:\n\n";
    cout << "1-Binary Search Trees (BST)\n"
         << "2-Heaps\n"
         << "3-AVL Trees\n";
    int x;
    cin >> x;
    switch (x)
    {
    case 1:
        BinaryTreeMenu();
        break;
    case 2:
        heapMenu();
        break;
    case 3:
        break;
    default:
        cout << "Invalid option make sure you choose number 1:3.\n\n";
        mainMenu();
        break;
    }
}
int main()
{
     mainMenu();

}
