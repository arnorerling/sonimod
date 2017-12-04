#include "SalesUI.h"
#include "Order.h"

SalesUI::SalesUI(){

}
void SalesUI::startUI() {
    Order order;

    char select = '\0';
    while (select != 'q') {

        cout << "Sales Menu" << endl;
        cout << "Choose an action" << endl;
        cout << "------------------" << endl;
        cout << "p: Add Pizza" << endl;
        cout << "s: Add Sidedish" << endl;
        cout << "d: Add drink" << endl;
        cout << "o: Print order" << endl;
        cout << "t: Get order total" << endl;
        cout << "f: File order" << endl;
        cout << "------------------" << endl;

        cin >> select;

        switch(select){
            case 'p': {

                break;
            }
            case 's': {

                break;
            }
            case 'd': {

                break;
            }
            case 'o': {

                break;
            }
            case 't': {

                break;
            }
            case 'f': {

                break;
            }
        }
    }

}
