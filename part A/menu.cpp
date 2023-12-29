#include "menu.h"
#include "register.h"
#include "customer.h"
#include "item.h"
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <string>
using namespace std;

Menu::Menu() {}
//: Register(), customer();
void Menu::display()
{
    system("cls");
    cout << endl;
    system("color 03");
    //(100);
    cout << " \t\t\t\t\t\t              " << setw(40) << setfill('-') << "\n";
    //(100);
    cout << "\t\t\t\t\t\t               *                                   *\n";
    //(100);
    cout << "\t\t\t\t\t\t               *               WELCOME             *" << endl;
    //(100);
    cout << "\t\t\t\t\t\t               *     TO ONLINE SHOPPING SYSTEM     *" << endl;
    //(100);
    cout << "\t\t\t\t\t\t               *                                   *\n";
    //(100);
    cout << " \t\t\t\t\t\t              " << setw(40) << setfill('-') << "\n";

    cout << endl
         << endl;
    //(250);
    cout << "\t\t\t\t\t                 ^^^^^^^^^^^^^^^^^^^^^ LOADING ^^^^^^^^^^^^^^^^^^^^^^^ " << endl;
    cout << endl;
    cout << endl;
    //(50);
    cout << "\t\t\t\t\t------";
    //(50);
    cout << "------";
    //(50);
    cout << "------";
    //(50);
    cout << "------";
    //(50);
    cout << "------";
    //(50);
    cout << "------";
    //(50);
    cout << "------";
    //(50);
    cout << "------";
    //(50);
    cout << "------";
    //(50);
    cout << "------";
    //(50);
    cout << "------";
    //(50);
    cout << "------";
    //(50);
    cout << "------";
    //(50);
    cout << "------\n\n";
    //(300);
    cout << endl;
    //(350);
    cout << "\t\t\t\t\t\t              ---------------------------------------------    " << endl;
    //(350);
    cout << "\t\t\t\t\t\t                          Moving to Online Purchasing            \n";
    //(350);
    cout << "\t\t\t\t\t\t              ---------------------------------------------    " << endl;
    //(1500);
}

void Menu::HomePage()
{
    system("cls");
    system("color 06");
    cout << "\t\t\t\t\t\t\t\t| " << setw(41) << setfill('^') << " | \n";
    cout << "\t\t\t\t\t\t\t\t|              WELCOME TO OUR           |\n ";
    cout << "\t\t\t\t\t\t\t\t|                  SHOP                 |\n ";
    cout << "\t\t\t\t\t\t\t\t| " << setw(41) << setfill('^') << " | \n";
    cout << endl
         << endl;
    //(350);
    cout << "\t\t\t\t\t\t              ---------------------------------------------    " << endl;
    //(350);
    cout << "\t\t\t\t\t\t              |                 <PRESS 1> LOGIN           |" << endl;
    //(350);

    cout << "\t\t\t\t\t\t              |                 <PRESS 2> SIGN-UP         |" << endl;
    //(350);

    cout << "\t\t\t\t\t\t              |                 <PRESS 3> FOR EXIT        |" << endl;
    //(350);

    cout << "\t\t\t\t\t\t              --------------------------------------------- " << endl;
    cout << endl
         << endl;

    char choice;
    do
    {
        cout << "\t\t\tSELECT : ";
        cin >> choice;
        switch (choice)
        {
        case '1':
            if (reg.Login())
                break;
        case '2':
            reg.SignUp();
            break;
        case '3':
            system("cls");
            system("color 02");
            //(350);
            cout << "\t\t\t\t\t\t               --------------------------------------------- " << endl;
            //(350);
            cout << "\t\t\t\t\t\t              |              PROGRAMME TERMINATED          |" << endl;
            //(350);
            cout << "\t\t\t\t\t\t              --------------------------------------------- " << endl;
            //(1500);
            exit(0); // terminates program without any errors
        default:
            cout << "            ENTER A VALID VALUE " << endl;
            break;
        }
    } while (choice != '1' && choice != '2' && choice != '3');
}
void Menu::addItem()
{
    for (int i = 0; i < customers.size(); i++)
    {
        if (customers[i].getUsername() == menuusername)
        {
            custom = customers[i];
        }
    }
    bool finish = false;
    while (!finish)
    {
        //(350);
        cout << "\t\t\t\t\t\t              --------------------------------------------- " << endl;
        //(350);
        cout << "\t\t\t\t\t\t              |               CHOOSE A CATEGORY            |" << endl;
        //(350);
        cout << "\t\t\t\t\t\t              --------------------------------------------- " << endl;
        //(350);
        cout << "\t\t\t\t\t\t              |             <PRESS 1> Men Clothing          |" << endl;
        //(350);
        cout << "\t\t\t\t\t\t              |             <PRESS 2> Women Clothing        |" << endl;
        //(350);
        cout << "\t\t\t\t\t\t              |             <PRESS 3> Kids Clothing         |" << endl;
        //(350);
        cout << "\t\t\t\t\t\t              --------------------------------------------- " << endl;
        //(350);
        cout << "\t\t\t\t\t\t              |               <PRESS 4> EXIT                |" << endl;
        //(350);
        cout << "\t\t\t\t\t\t              --------------------------------------------- " << endl;
        cout << endl;
        char choice;
        string IID; // Item ID in string format
        int quant;  // quan in string format
        string quan;
        do
        {
            cout << "\t\t\tSELECT :  ";
            cin >> choice;
            switch (choice)
            {
            case '1':
                MenItems.printTable();
                int MenID;
                do
                {
                    do
                    {
                        cout << "             ENTER THE ID OF THE ITEM YOU WANT TO ADD TO YOUR CART : ";
                        cin >> IID;
                    } while (!check_number(IID));
                    MenID = stoi(IID);
                } while (!MenItems.checkIndex(MenID));

                do
                {

                    cout << "                                ENTER THE QUANTITY YOU WANT TO BUY : ";
                    cin >> quan;
                } while (!check_number(quan));
                quant = stoi(quan);
                custom.addToCartMen(MenID, quant);
                break;
            case '2':
                WomenItems.printTable();
                int WomenID;
                do
                {
                    do
                    {
                        cout << "             ENTER THE ID OF THE ITEM YOU WANT TO ADD TO YOUR CARD : ";
                        cin >> IID;
                    } while (!check_number(IID));
                    WomenID = stoi(IID);
                } while (!WomenItems.checkIndex(WomenID));

                do
                {
                    cout << "                               ENTER THE QUANTITY YOU WANT TO BUY : ";
                    cin >> quan;
                } while (!check_number(quan));
                quant = stoi(quan);
                custom.addToCartWomen(WomenID, quant);
                break;
            case '3':
                KidsItems.printTable();
                int KidsID;
                do
                {
                    do
                    {
                        cout << "               ENTER THE ID OF THE ITEM YOU WANT TO ADD TO YOUR CARD : ";
                        cin >> IID;
                    } while (!check_number(IID));
                    KidsID = stoi(IID);
                } while (!KidsItems.checkIndex(KidsID));
                do
                {
                    cout << "                                  ENTER THE QUANTITY YOU WANT TO BUY : ";
                    cin >> quan;
                } while (!check_number(quan));
                quant = stoi(quan);
                custom.addToCartKids(KidsID, quant);
                break;
            case '4':
                //(350);
                cout << "\t\t\t\t\t\t              --------------------------------------------- " << endl;
                //(350);
                cout << "\t\t\t\t\t\t               |              PROGRAMME TERMINATED           |" << endl;
                //(350);
                cout << "\t\t\t\t\t\t               --------------------------------------------- " << endl;

                exit(0);
                break;
            default:
                cout << " INVALID INPUT ! \n TRY AGAIN \n";
                break;
            }
        } while (choice != '1' && choice != '2' && choice != '3');
        char c;
        cout << "\n                           DO YOU WANT TO BUY MORE \n                           YES(Y) / NO(N) :  ";
        cin >> c;
        cout << endl;
        if (c == 'n' || c == 'N')
        {
            int total;
            if (custom.printBill(total))
            {
                pushCustomer(custom, total);
                finish = true;
            }
            else
            {
                //(350);
                cout << "\t\t\t\t\t               --------------------------------------------- " << endl;
                //(350);
                cout << "\t\t\t\t\t               |         YOU CAN GO FOR MORE SHOPPING       |" << endl;
                //(350);
                cout << "\t\t\t\t\t               --------------------------------------------- " << endl
                     << endl;
            }
        }
        continue;
    }
}
void Menu::TreatOrders()
{
    while (!VipCustomers.empty())
    {
        VipCustomers.front().confirm();
        VipCustomers.pop();
    }

    while (!Normalcustomers.empty())
    {
        Normalcustomers.front().confirm();
        Normalcustomers.pop();
    }
}

bool Menu::Quit()
{
    bool quit = false;
    cout << endl;
    //(350);
    cout << "\t\t\t\t\t\t\t\t    --------------------------------------------" << endl;
    //(350);
    cout << "\t\t\t\t\t\t\t\t   |               <PRESS 1> HOME Page          |" << endl;
    //(350);

    cout << "\t\t\t\t\t\t\t\t   |               <PRESS 2> FOR EXIT           |" << endl;
    //(350)

    cout << "\t\t\t\t\t\t\t\t    -------------------------------------------- " << endl;
    cout << endl
         << endl;
    char choice;
    do
    {
        cout << "\t\t\tSELECT :  ";
        cin >> choice;
        switch (choice)
        {
        case '1':
            quit = false;
            break;
        case '2':
            //(350);
            cout << "\t\t\t\t\t\t                   --------------------------------------------- " << endl;
            //(350);
            cout << "\t\t\t\t\t\t                   |             PROGRAMME TERMINATED          |" << endl;
            //(350);
            cout << "\t\t\t\t\t\t                   --------------------------------------------- " << endl;

            exit(0);
            quit = true;
            break;
        default:
            cout << "               INVALID INPUT ! \n              TRY AGAIN \n";
            break;
        }
    } while (choice != '1' && choice != '2');
    return quit;
}