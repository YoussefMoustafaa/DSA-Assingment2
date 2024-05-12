//
// Created by mahmoud on 5/12/2024.
//
#include <bits/stdc++.h>
#include <ostream>

#ifndef DSA_ASSINGMENT2_ITEM_H
#define DSA_ASSINGMENT2_ITEM_H
using namespace std;

class Item {
private:
    string itemName;
    string category;
    int price;
public:

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


#endif //DSA_ASSINGMENT2_ITEM_H
