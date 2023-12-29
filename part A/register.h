#ifndef REGISTER_H
#define REGISTER_H

#include <iostream>
#include "customer.h"
using namespace std;

// Class register to login or  Sign Up
class Register
{
private:
    struct address
    {
        string addressName;
        string PostalCode;
    };
    string Name;
    string email;
    string PhoneNo;
    address Adress;
    address ShippingAddress;
    string username;
    string password;
    string find_user;
    string find_pass;

public:
    friend class customer;
    Register(); // default constructor
    Register(string &usernam, string &pas, string &n, string &pn, string &mail, string &adres, string &postal)
    {
        username = usernam;
        password = pas;
        Name = n;
        PhoneNo = pn;
        email = mail;
        Adress.addressName = adres;
        Adress.PostalCode = postal;
    }
    //~Register();
    void setName();
    string getName() const;
    void setPhoneNo();
    string getPhoneNo() const;
    void setEmail();
    string getEmail() const;
    void setAdress();
    string getAdressName() const;
    string getPostalCode() const;
    string getUsername() const
    {
        return username;
    }
    string getPassword() const
    {
        return password;
    }

    // void Enter();  Registration form
    void SignUp(); // User registration
    bool Login();  // id and password verification
};

#endif // REGISTER_H