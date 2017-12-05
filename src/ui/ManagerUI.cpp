#include "ManagerUI.h"
#include "Crust.h"
#include "Topping.h"
#include "Drink.h"
#include "Sidedish.h"
#include "Branch.h"
#include <iostream>
#include <vector>
#include <string>
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
        cout << "p: Add new pizza to menu" << endl;
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
            case 'p': addPizza();
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
    bool valid = false;
    string name;
    int inches;
    int price;

    while (!valid) {
    cout << "----Add Crust----" << endl;
    cout << "Name: ";
    cin >> ws;
    getline(cin, name);
    cout << "Inches: ";
    cin >> inches;
    cout << "Price: ";
    cin >> price;

    Crust crust(name, inches, price);
    cout << crust << endl;
    valid = managerDomain.addCrust(crust);
    }
}

void ManagerUI::addTopping() {
    bool valid = false;
    string name;
    int price;

    while (!valid) {
    cout << "----Add Topping----" << endl;
    cout << "Name: ";
    cin >> ws;
    getline(cin, name);
    cout << "Price: ";
    cin >> price;

    Topping topping(name, price);
    cout << topping << endl;
    valid = managerDomain.addTopping(topping);
    }
}

void ManagerUI::addPizza() {
    string name;
    vector<Topping> toppings;
    Crust crust;
    int price;
    bool valid = false;

    cout << "----Add Pizza----" << endl;
    cout << "Coming Soon" << endl;
}

void ManagerUI::addDrink() {
    bool valid = false;
    string name;
    int liter;
    int price;

    while (!valid) {
    cout << "----Add Drink----" << endl;
    cout << "Name: ";
    cin >> ws;
    getline(cin, name);
    cout << "Liters: ";
    cin >> liter;
    cout << "Price: ";
    cin >> price;

    Drink drink(name, liter, price);
    valid = managerDomain.addDrink(drink);
    }
}

void ManagerUI::addSide() {
    bool valid = false;
    string name;
    int price;

    while (!valid) {
    cout << "----Add Drink----" << endl;
    cout << "Name: ";
    cin >> ws;
    getline(cin, name);
    cout << "Price: ";
    cin >> price;

    managerDomain.toLowerCase(name);
    Sidedish sidedish(name, price);
    cout << sidedish << endl;

    valid = managerDomain.addSidedish(sidedish);
    }
}

void ManagerUI::addBranch() {
    bool valid = false;
    string name;

    while (!valid) {
    cout << "----Add Branch----" << endl;
    cout << "Name: ";
    cin >> ws;
    getline(cin, name);
    managerDomain.toLowerCase(name);
    Branch branch(name);
    cout << branch << endl;
    managerDomain.addBranch(branch);
    }
}
