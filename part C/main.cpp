// LARBI SAIDCHIKH
#include <fstream>
#include <istream>
#include <stdlib.h>
#include <string>
#include <iomanip>
#include <unistd.h>

#include "readers.cpp"

using namespace std;

int main()
{

    readItems(MenItems, WomenItems, KidsItems);
    readcustomers(customers);
    Menu menu;
    do
    {
        menu.display();
        menu.HomePage();
        menu.addItem();
        menu.TreatOrders();
        int menuboughtitems = menu.custom.getBoughtitems();
        writecustomers(customers, menuusername, menuboughtitems);
    } while (!menu.Quit());

    return 0;
}
