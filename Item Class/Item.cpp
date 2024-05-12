//
// Created by mahmoud on 5/12/2024.
//

#include "Item.h"

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
    os << "itemName: " << item.itemName << " category: " << item.category << " price: " << item.price;
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