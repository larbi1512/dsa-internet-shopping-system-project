// LARBI SAIDCHIKH
#ifndef MENU_H
#define MENU_H

#include "customer.h"
#include "register.cpp"
class Menu
{
private:
    // class object declaration
    Register reg;

public:
    customer custom;
    Menu();
    void display();
    void HomePage();
    void addItem();
    bool Quit();
    void TreatOrders();
};

#endif // MENU_H