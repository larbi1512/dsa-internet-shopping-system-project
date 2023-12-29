// LARBI SAIDCHIKH
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <string>
#include "register.h"
#include "item.h"
#include <queue>
using namespace std;

bool check_number(string str)
{
    for (int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == false)
            return false;
    return true;
}

struct date
{
    int month;
    int year;
};
struct CreditCard
{
    long long int CardNumber;
    date ExpiryDate;
};

class customer : public Register
{
public:
    friend bool findcustomers(vector<customer> &customers);
    friend void SignUp();
    customer() : boughtItems(0), VIP(0) {}

    customer(string &u, string &p, string &n, string &pn, string &e, string &a, string &pc, int &b) : VIP(0)
    {
        username = u;
        password = p;
        Name = n;
        PhoneNo = pn;
        email = e;
        Adress.addressName = a;
        Adress.PostalCode = pc;
        boughtItems = b;

    } // classic constructor to set everything independently

    // overloading (=) to assign an object to another
    customer &operator=(const customer &customer1)
    {
        email = customer1.email;
        Name = customer1.Name;
        boughtItems = customer1.boughtItems;
        return *this;
    }

    bool operator!=(const customer c) const
    {
        return !(*this == c);
    }

    // overloading operator (==)
    bool operator==(const customer &c) const
    {
        return (email == c.email && username == c.username);
    }

    // overloading (>) to compare if customers are Vip or not
    bool operator>(const customer &customer1) const
    {
        if (VIP && !customer1.VIP)
            return true;
        return false;
    }

    // overloading (<) to compare if customers are Vip or not
    bool operator<(const customer &customer1) const
    {
        if (!VIP && customer1.VIP)
            return true;
        return false;
    }

    // // overloading (==) to check if customers are both Vip or not
    // bool operator==(const customer &customer1) const
    // {
    //     if ((VIP && customer1.VIP) || (!VIP && !customer1.VIP))
    //         return true;
    //     return false;
    // }

    queue<item> getCart()
    {
        return cart;
    }

    void addToCartMen(int ItemIndex, int quant)
    {
        if (MenItems.FindWithIndex(ItemIndex).EnoughQuantity(quant))
        {
            addToCart(MenItems.FindWithIndex(ItemIndex), quant);
        }
        else
            cout << " SORRY, WE DO NOT HAVE ENOUGH QUANTITY \n";
    }

    void addToCartWomen(int ItemIndex, int quant)
    {
        if (WomenItems.FindWithIndex(ItemIndex).EnoughQuantity(quant))
        {
            addToCart(WomenItems.FindWithIndex(ItemIndex), quant);
        }
        else
            cout << " SORRY, WE DO NOT HAVE ENOUGH QUANTITY \n";
    }

    void addToCartKids(int ItemIndex, int quant)
    {
        if (KidsItems.FindWithIndex(ItemIndex).EnoughQuantity(quant))
        {
            addToCart(KidsItems.FindWithIndex(ItemIndex), quant);
        }
        else
            cout << " SORRY, WE DO NOT HAVE ENOUGH QUANTITY \n";
    }

    void addToCart(const item &newone, const int &quant)
    {
        cart.push(newone);
        cartQuantity.push(quant);
    }

    void addCard()
    {
        string cardNum;   // customerCard.CardNumber
        string cardYear;  // customerCard.ExpiryDate.year
        string cardMonth; // customerCard.ExpiryDate.month
        do
        {
            cout << "\t\t\t\t ENTER YOUR CREDIT CARD NUMBER PLEASE: ";
            cin >> cardNum;
        } while (!check_number(cardNum) || (cardNum.length() < 13 || cardNum.length() > 16));
        customerCard.CardNumber = stol(cardNum);
        do
        {
            do
            {
                cout << "\t\t\t\t                         EXPIRY DATE : " << endl;
                cout << "\t\t\t\t                               MONTH : ";
                cin >> cardMonth;
                cout << "\t\t\t\t                                YEAR : ";
                cin >> cardYear;
                cout << endl;
            } while (!check_number(cardYear) && !check_number(cardMonth));
            customerCard.ExpiryDate.year = stoi(cardYear);
            customerCard.ExpiryDate.month = stoi(cardMonth);
        } while (!(customerCard.ExpiryDate.month > 0 && customerCard.ExpiryDate.month < 13 && customerCard.ExpiryDate.year > 2022));
    }

    bool printBill(int &total)
    {
        int totalprice(0);
        cout << "\t\t\t\t\t\t|---------------------------------  B I L L  -----------------------------------|" << endl;
        cout << "\t\t\t\t\t\t|                                                                               |" << endl;
        cout << "\t\t\t\t\t\t|   Quantity\t\t\t\t"
             << "Name \t\t\t\t"
             << " Price  |" << endl;
        cout << "\t\t\t\t\t\t|-------------------------------------------------------------------------------|" << endl;

        queue<item> tempCart = cart;
        queue<int> temquantities = cartQuantity;
        while (!tempCart.empty())
        {
            item tmp = tempCart.front();
            int temp2 = temquantities.front();
            totalprice += (temp2 * tmp.getPrice());
            cout << "\t\t\t\t\t\t|   " << temp2 << "\t\t\t\t";
            tmp.PrintBILL();
            tempCart.pop();
            temquantities.pop();
        }
        cout << "\t\t\t\t\t\t|-------------------------------------------------------------------------------| " << endl;
        cout << "\t\t\t\t\t\t| "
             << "\t\t\t     TOTAL PRICE:  " << totalprice << " DA\t\t\t\t|";
        cout << endl;
        cout << "\t\t\t\t\t\t|-------------------------------------------------------------------------------|" << endl
             << endl;
        char c;
        cout << "\n\t\t\t\tDO YOU WANT TO CONFIRM YOUR PURCHASE " << endl;
        cout << "\t\t\t\tSELECT 'y/n' : ";
        cin >> c;
        cout << endl;
        if (c == 'y' || c == 'Y')
        {
            total = totalprice;
            return true;
        }
        return false;
    }

    void AddAdress()
    {
        cout << "\t\t\t\tENTER YOUR SHIPPING ADRESS PLEASE: ";
        cin >> ShippingAddress.addressName;
        do
        {
            cout << "\t\t\t\t                      POSTAL CODE:  ";
            cin >> ShippingAddress.PostalCode;
        } while (!check_number(ShippingAddress.PostalCode));
    }

    bool confirm()
    {
        addCard();
        AddAdress();
        cout << endl;
        if (VIP)
        {
            //(350);
            cout << "\t\t\t\t\t\t               -------------------------------------------------------- " << endl;
            //(350);
            cout << "\t\t\t\t\t\t               |     THANK YOU FOR YOUR VISIT OUR DEAR VIP CUSTOMER    |" << endl;
            //(350);
            cout << "\t\t\t\t\t\t               |    YOUR ITEMS WILL BE DELIVERED TO YOUR ADRESS SOON   |" << endl;
            //(350);
            cout << "\t\t\t\t\t\t               |              HOPE TO SEE YOU AGAIN !! <3              |" << endl;
            //(350);
            cout << "\t\t\t\t\t\t               -------------------------------------------------------- " << endl;
        }
        else
        {
            //(350);
            cout << "\t\t\t\t\t\t               -------------------------------------------------------- " << endl;
            //(350);
            cout << "\t\t\t\t\t\t               |              THANK YOU FOR YOUR VISIT                 |" << endl;
            //(350);
            cout << "\t\t\t\t\t\t               |    YOUR ITEMS WILL BE DELIVERED TO YOUR ADRESS SOON   |" << endl;
            //(350);
            cout << "\t\t\t\t\t\t               |              HOPE TO SEE YOU AGAIN !! <3              |" << endl;
            //(350);
            cout << "\t\t\t\t\t\t               -------------------------------------------------------- " << endl;
        }
        while (!cart.empty())
        {
            cart.front().decreaseQuantity(cartQuantity.front());
            cart.pop();
            cartQuantity.pop();
        }
        return true;
    }

    /** set customer details **/
    void setCustomerDetails()
    {
        Register::SignUp();
    }

    void Print() const
    {
        cout << setw(10) << username << endl;
        cout << setw(10) << password << endl;
    }

    // to check if the customer became a VIP
    bool isVip(int newPurchase)
    {
        int VipAmount = 100000; // the minimum bought items amount
        boughtItems += newPurchase;
        if (boughtItems >= VipAmount)
        {
            VIP = true;
            return true;
        }
        return false;
    }

    int getBoughtitems() const
    {
        return boughtItems;
    }
    void setBoughtitems(int n)
    {
        boughtItems += n;
    }
    // private data members
private:
    Register Customer1;
    CreditCard customerCard; // the credit card of the customer
    int boughtItems;         // the total price of items bought by the customer
    bool VIP;                // to know if the customer is VIP or no
    queue<item> cart;
    queue<int> cartQuantity;
};
vector<customer> customers;
queue<customer> VipCustomers;
queue<customer> Normalcustomers;
string menuusername;

void pushCustomer(customer &c, int totalprice)
{
    if (c.isVip(totalprice))
    {
        VipCustomers.push(c);
    }
    else
    {
        Normalcustomers.push(c);
    }
}

#endif