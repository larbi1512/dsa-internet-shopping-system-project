#include <fstream>
#include <istream>
#include <stdlib.h>
#include <string>
#include <iomanip>
#include <unistd.h>
//#include"register.cpp"
#include "readers.cpp"
#include "item.h"
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
        writeitems(MenItems, WomenItems, KidsItems);
    } while (!menu.Quit());

    return 0;
}
