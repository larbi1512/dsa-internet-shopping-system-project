// LARBI SAIDCHIKH
#include <iostream>
#include <stdlib.h>
#include <string>
#include <iomanip>
#include <unistd.h>
#include "menu.cpp"

using namespace std;

void readItems(BinarySearchTree &MenItems, BinarySearchTree &WomenItems, BinarySearchTree &KidsItems)
{
    string cat, name, id, price, quant;
    string line;
    fstream file("finalitems.csv", ios::in);
    if (file.is_open())
    {
        while (getline(file, line))
        {
            stringstream str(line);
            getline(str, cat, ',');
            getline(str, id, ',');
            getline(str, name, ',');
            getline(str, price, ',');
            getline(str, quant);

            int id1 = atoi(id.c_str());       // convert string to int (atoi)
            int price1 = atoi(price.c_str()); // convert string to int (atoi)
            int quant1 = atoi(quant.c_str()); // convert string to int (atoi)

            item temp(cat, id1, name, price1, quant1);
            switch (cat[0])
            {
            case 'm':
                MenItems.insert(temp);
                break;
            case 'w':
                WomenItems.insert(temp);
                break;
            case 'k':
                KidsItems.insert(temp);
                break;
            }
        }
    }
    else
    {
        cout << "Could not open the file\n";
        return;
    }
}

bool findcustomers(vector<customer> &customersvector)
{
    string username, password;
    std::cout << "\t\t\tENTER YOUR USERNAME : ";
    std::cin >> username;
    menuusername = username;
    std::cout << "\t\t\tENTER YOUR PASSWORD : ";
    std::cin >> password;

    for (int i = 0; i < customers.size(); i++)
    {
        string temp1 = customers[i].getUsername();
        string temp2 = customers[i].getPassword();

        if (temp1 == username && temp2 == password)
        {
            std::cout << "\t\t\t\t\t\t\t" << setw(15) << setfill(' ') << "\t   CONGRATULATIONS LOGIN SUCCESSFULLY ! " << endl;
            std::cout << endl;
            return true;
        }
    }
    cout << endl;
    std::cout << "\t\t\t\t\t\t\t\t\t    LOGIN UNSUCCESSFUL " << endl;
    cout << endl;
    return false;
}

void readcustomers(vector<customer> &customersvector)
{
    fstream users;

    string line, username, pass, name, phoneno, email, adress, postalcode, bought;

    users.open("userinfo.csv", ios::in);
    if (users.is_open())
    {
        while (getline(users, line))
        {
            stringstream str(line);
            getline(str, username, ',');
            getline(str, pass, ',');
            getline(str, name, ',');
            getline(str, phoneno, ',');
            getline(str, email, ',');
            getline(str, adress, ',');
            getline(str, postalcode, ',');
            getline(str, bought);
            int b = atoi(bought.c_str()); // convert string to int (atoi)
            customer temp(username, pass, name, phoneno, email, adress, postalcode, b);
            customers.push_back(temp);
        }
        users.close();
    }
    else
    {
        cout << "Could not open the file\n";
        return;
    }
}
void writecustomers(vector<customer> &customers, string &user, int &bough)
{
    ofstream file;
    file.open("userinfo.csv");

    for (int i = 0; i < customers.size(); i++)
    {
        if (customers[i].getUsername() == user)
        {
            customers[i].setBoughtitems(bough);
        }
    }
    for (int i = 0; i < customers.size(); i++)
    {

        file << customers[i].getUsername() << "," << customers[i].getPassword() << "," << customers[i].getName() << "," << customers[i].getPhoneNo() << "," << customers[i].getEmail() << "," << customers[i].getAdressName() << "," << customers[i].getPostalCode() << "," << customers[i].getBoughtitems() << ",\n";
    }
    file.close();
}
