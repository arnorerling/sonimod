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
        cout << "c: Add new pizza crust" << endl;
        cout << "t: Add new topping" << endl;
        cout << "m: Add new menu option" << endl;
        cout << "d: Add new drink" << endl;
        cout << "s: Add new sidedish" << endl;
        cout << "b: Add new branch" << endl;
        cout << "q: Quit" << endl;
        cout << "--------------------------" << endl;

        cin >> select;

        switch(select){
            case 'c': addCrust();
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
    string name;
    int inches;
    int price;

    cout << "----Add Crust----" << endl;
    cout << "Name: ";
    cin >> ws;
    getline(cin, name);
    cout << "Inches: ";
    cin >> inches;
    cout << "Price: ";
    cin >> price;
}

void ManagerUI::addTopping() {
    //Topping topping;
    string name;
    int price;

    cout << "----Add Topping----" << endl;
    cout << "Name: ";
    cin >> ws;
    getline(cin, name);
    cout << "Price: ";
    cin >> price;
}

void ManagerUI::addMenu() {
   // Menu menu;
    //cout << "----Add Menu----" << endl;
    //cin >> menu;
}

void ManagerUI::addDrink() {
    //Drink drink;
    string name;
    int liters;
    int price;

    cout << "----Add Drink----" << endl;
    cout << "Name: ";
    cin >> ws;
    getline(cin, name);
    cout << "Liters: ";
    cin >> liters;
    cout << "Price: ";
    cin >> price;
}

void ManagerUI::addSide() {
    //Sidedish sidedish;
    string name;
    int price;

    cout << "----Add Sidedish----" << endl;
    cout << "Name: ";
    cin >> ws;
    getline(cin, name);
    cout << "Price: ";
    cin >> price;
}

void ManagerUI::addBranch() {
    string name;
    //Branch branch;
    cout << "----Add Branch----" << endl;
    cout << "Name: ";
    cin >> ws;
    getline(cin, name);
}
