// LARBI SAIDCHIKH
#include <fstream>
#include <istream>
#include <stdlib.h>
#include <string>
#include <iomanip>
#include <unistd.h>
#include "register.h"
#include <iostream>
using namespace std;

bool isValid(string password)
{

    // For checking if password length
    // is between 8 and 15
    if (!((password.length() >= 8) &&
          (password.length() <= 15)))
        return false;

    // To check space
    if (password.find(" ") !=
        std::string::npos)
        return false;

    if (true)
    {
        int count = 0;

        // Check digits from 0 to 9
        for (int i = 0; i <= 9; i++)
        {

            // To convert int to string
            string str1 = to_string(i);

            if (password.find(str1) !=
                std::string::npos)
                count = 1;
        }
        if (count == 0)
            return false;
    }
    if (true)
    {
        int count = 0;

        // Checking capital letters
        for (int i = 65; i <= 90; i++)
        {

            // Type casting
            char c = (char)i;
            string str1(1, c);

            if (password.find(str1) !=
                std::string::npos)
                count = 1;
        }
        if (count == 0)
            return false;
    }
    if (true)
    {
        int count = 0;

        // Checking small letters
        for (int i = 97; i <= 122; i++)
        {

            // Type casting
            char c = (char)i;
            string str1(1, c);

            if (password.find(str1) !=
                std::string::npos)
                count = 1;
        }
        if (count == 0)
            return false;
    }

    // If all conditions fails
    return true;
}

Register::Register()
{
    email = password = find_pass = Name = PhoneNo = " ";
}

void Register::setName()
{
    cout << " ENTER YOUR FULL NAME  : ";
    cin.ignore();
    getline(cin, Name);
}

string Register::getName() const
{
    return Name;
}

void Register::setPhoneNo()
{
    cout << " ENTER YOUR PHONENUMBER  : ";
    cin >> PhoneNo;
}

string Register::getPhoneNo() const
{
    return PhoneNo;
}

void Register::setEmail()
{
    cout << " ENTER YOUR EMAIL  : ";
    cin.ignore();
    getline(cin, email);
}

string Register::getEmail() const
{
    return email;
}

void Register::setAdress()
{

    cout << " ENTER YOUR ADDRESS: ";
    getline(cin, Adress.addressName);
    cout << endl;
    cout << "ENTER YOUR POSTAL CODE: ";
    cin >> Adress.PostalCode;
    cout << endl;
}
string Register::getAdressName() const
{
    return Adress.addressName;
}
string Register::getPostalCode() const
{
    return Adress.PostalCode;
}

void Register::SignUp()
{
    system("cls");
    system("color 04");
    cout << "\t\t\t\t\t\t          -----------------------------------------------------" << endl;
    cout << "\t\t\t\t\t\t          |                 ACCOUNT REGISTRATION              |" << endl;
    cout << "\t\t\t\t\t\t          -----------------------------------------------------" << endl;
    cout << endl
         << endl;
    setName();
    setPhoneNo();
    setEmail();
    setAdress();

    cout << "\t\t\t ENTER YOUR USERNAME : ";
    cin >> username;
    cout << endl;
    do
    {
        cout << "\t\t\t USE DIFFERENT CHARACTERS(BETWEEN 8 AND 15) \n";
        cout << "\t\t\t ENTER YOUR PASSWORD : ";
        cin >> password;
    } while (!isValid(password));

    ofstream file;
    file.open("userinfo.csv", ios::app);
    file << username << "," << password << "," << getName() << "," << getPhoneNo() << "," << getEmail() << "," << getAdressName() << "," << getPostalCode() << "," << 0 << ",\n";
    file.close();
    int x = 0;
    customer temp(username, password, Name, PhoneNo, email, Adress.addressName, Adress.PostalCode, x);
    customers.push_back(temp);

    cout << "\n\t\t\t\t\t\t\t                  YOU SIGNED UP SUCCESSFULLY!! " << endl;
    system("cls");
    //(150);
    cout << "\t\t\t\t\t\t\t                  |-----------------------|" << endl;
    //(150);
    cout << "\t\t\t\t\t\t\t                  |       LOGIN PAGE      |" << endl;
    //(150);
    cout << "\t\t\t\t\t\t\t                  |-----------------------|" << endl;
    // int i =0;
    Login();
}
// function to Login
bool Register::Login()
{

    system("color 04");
    system("cls");
    cout << endl;
    //(150);
    cout << "\t\t\t\t\t\t\t                    |------------------|" << endl;
    //(150);
    cout << "\t\t\t\t\t\t\t                    |       LOGIN      |" << endl;
    //(150);
    cout << "\t\t\t\t\t\t\t                    |------------------|" << endl;
    cout << endl;
    cout << endl;
    int allowed = 0;
    while (true)
    {
        if (findcustomers(customers))
        {
            return true;
        }
        else
        {
            allowed++;
            if (allowed == 3)
            {
                system("cls");
                system("color 02");
                cout << "\n\t\t\t\t\t\t\t                    YOU COULD NOT SIGN IN!! " << endl;
                //(350);
                cout << "\t\t\t\t\t\t               -------------------------------------------- " << endl;
                //(350);
                cout << "\t\t\t\t\t\t              |          YOU SHOULD SIGN UP FIRST          |" << endl;
                //(350);
                cout << "\t\t\t\t\t\t               -------------------------------------------- " << endl;
                //(1500);
                return false;
            }
        }
    }
}