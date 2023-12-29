#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "QuadraticProbing.cpp"
#include <algorithm>
using namespace std;

class item
{
public:
    // default constructor
    item() : Category(""), itemID(0), itemName(""), Price(0), quantity(0){};

    // parameterized copy costructor
    explicit item(const string &categ, const int &ID, const string &name, const int &price, const int &Quantity)
    {
        setItem(categ, ID, name, price, Quantity); // call setItem to set a new item using constructor
    }
    // copy constructor
    item(const item &rhs)
    {
        setItem(rhs.Category, rhs.itemID, rhs.itemName, rhs.Price, rhs.quantity);
    }

    // getters
    int getID() const
    {
        return itemID;
    }
    string getName() const
    {
        return itemName;
    }
    int getPrice() const
    {
        return Price;
    }
    int getQuantity() const
    {
        return quantity;
    }

    // function to set an item
    bool setItem(const string &categ, const int &ID, const string &name, const int &price, const int &Quantity)
    {
        Category = categ;
        itemID = ID;
        itemName = name;
        Price = price;
        quantity = Quantity;
        return true;
    }
    // overloading operator (!=)
    bool operator!=(const item &item1) const
    {
        return !(*this == item1);
    }
    // overloading operator (==)
    bool operator==(const item &item1) const
    {
        return (itemName == item1.itemName && itemID == item1.itemID);
    }

    // a funtion to print an item for customer
    void Print() const
    {
        if (quantity >= 100)
        {
            cout << this->getName() << setw(20 + (27 - this->getName().length())) << this->getPrice() << " Da\t\t\t\t" << quantity << " |";
            cout << endl;
        }
        else if (quantity >= 10)
        {
            cout << this->getName() << setw(20 + (27 - this->getName().length())) << this->getPrice() << " Da\t\t\t\t" << quantity << "  |";
            cout << endl;
        }
        else
        {
            cout << this->getName() << setw(20 + (27 - this->getName().length())) << this->getPrice() << " Da\t\t\t\t" << quantity << "   |";
            cout << endl;
        }
    }
    // a funtion to print an item for the bill
    void PrintBILL() const
    {

        cout << this->getName() << setw(15 + (27 - this->getName().length())) << this->getPrice() << " Da   |";

        cout << endl;
    }
    bool EnoughQuantity(int quant)
    {
        if ((quantity - quant) > 0)
        {
            quantity -= quant;
            return true;
        }
        return false;
    }
    void decreaseQuantity(int &quant)
    {
        quantity -= quant;
    }

    // private data members
private:
    string Category; // the item's category
    int itemID;      // the item ID
    string itemName; // the name of the product
    int Price;       // the price of the product per unit
    int quantity;    // the item quantity in the shop
};
HashTable<item> MenItems;
HashTable<item> WomenItems;
HashTable<item> KidsItems;
#endif