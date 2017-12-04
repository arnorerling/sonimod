#include "ManagerUI.h"
#include <iostream>
using namespace std;

ManagerUI::ManagerUI()
{
    //ctor
}

void ManagerUI::startUI() {

    char select = '\0';

    while (select != 'q') {
        cout << "-----Choose an action-----" << endl;
        cout << "p: Add new pizza crust" << endl;
        cout << "t: Add new topping" << endl;
        cout << "m: Add new menu option" << endl;
        cout << "d: Add new drink" << endl;
        cout << "s: Add new sidedish" << endl;
        cout << "b: Add new branch" << endl;
        cout << "q: Quit" << endl;
        cout << "--------------------------" << endl;

        cin >> select;

        switch(select){
            case 'p': addCrust();
            break;
            case 't': addTopping();
            break;
            case 'm': addMenu();
            break;
            case 'd': addDrink();
            break;
            case 's': addSide();
            break;
            case 'b': addBranch();
        }
    }
}

void ManagerUI::addCrust() {
    //Crust crust;
    //cout << "----Add Crust----" << endl;
    //cin >> crust;
}

void ManagerUI::addTopping() {
    //Topping topping;
    //cout << "----Add Topping----" << endl;
    //cin >> topping;
}

void ManagerUI::addMenu() {
   // Menu menu;
    //cout << "----Add Menu----" << endl;
    //cin >> menu;
}

void ManagerUI::addDrink() {
    //Drink drink;
    //cout << "----Add Drink----" << endl;
    //cin >> drink;
}

void ManagerUI::addSide() {
    //Sidedish sidedish;
    //cout << "----Add Sidedish----" << endl;
    //cin >> sidedish;;
}

void ManagerUI::addBranch() {
    //Branch branch;
    //cout << "----Add Branch----" << endl;
    //cin >> branch;
}
