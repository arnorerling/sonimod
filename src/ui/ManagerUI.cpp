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

    cout << "Welcome Manager" << endl;
    cout << "What would you like to do?" << endl;
    char select = '\0';
    while (select != '3') {
        cout << "--------------------------" << endl;
        cout << "1: Add/Change menu" << endl;
        cout << "2: Remove from menu" << endl;
        cout << "3: Quit" << endl;
        cin >> select;

        switch(select) {
            case '1': addChangeMenu();
            break;
            case '2': removeFromMenu();
            break;
            case '3': cout << endl;
            break;
            default: cout << "Invalid input" << endl;
        }
    }
}

void ManagerUI::addChangeMenu() {
    char select = '\0';
    while (select != 'q') {
        cout << "-----Add/Change-----" << endl;
        cout << "c: Pizza crust" << endl;
        cout << "t: Pizza topping" << endl;
        cout << "p: Pizza menu" << endl;
        cout << "d: Drink" << endl;
        cout << "s: Sidedish" << endl;
        cout << "b: Branch" << endl;
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

void ManagerUI::removeFromMenu() {
    char select = '\0';
    while (select != 'q') {
        cout << "-----Remove-----" << endl;
        cout << "c: Pizza crust" << endl;
        cout << "t: Pizza topping" << endl;
        cout << "p: Pizza menu" << endl;
        cout << "d: Drink" << endl;
        cout << "s: Sidedish" << endl;
        cout << "b: Branch" << endl;
        cout << "q: Quit" << endl;
        cout << "--------------------------" << endl;
        cin >> select;

        switch(select){
            case 'c':
                printCrust();
                removeCrust();
                break;
            case 't':
                printTopping();
                removeTopping();
                break;
            case 'p':
                printPizza();
                removePizza();
                break;
            case 'd':
                printDrink();
                removeDrink();
                break;
            case 's':
                printSide();
                removeSide();
                break;
            case 'b':
                printBranch();
                removeBranch();
        }
    }
}

void ManagerUI::addCrust() {
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
    managerDomain.toLowerCase(name);
    Crust crust(name, inches, price);

    try {
        managerDomain.addCrust(crust);
    }
    catch(CrustChangedException) {
        cout << "price of crust \"" << crust.getName() << "\" of size " << crust.getInches() << " has been changed" << endl;
    }


}

void ManagerUI::addTopping() {

    string name;
    int price;

    cout << "----Add Topping----" << endl;
    cout << "Name: ";
    cin >> ws;
    getline(cin, name);
    cout << "Price: ";
    cin >> price;

    managerDomain.toLowerCase(name);
    Topping topping(name, price);

    try {
        managerDomain.addTopping(topping);
    }
    catch(ToppingChangedException) {
        cout << "price of topping \"" << topping.getName() << "\" has been changed" << endl;
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
    string name;
    int liter;
    int price;

    cout << "----Add Drink----" << endl;
    cout << "Name: ";
    cin >> ws;
    getline(cin, name);
    cout << "Liters: ";
    cin >> liter;
    cout << "Price: ";
    cin >> price;

    managerDomain.toLowerCase(name);
    Drink drink(name, liter, price);

    try {
        managerDomain.addDrink(drink);
    }
    catch(DrinkChangedException) {
        cout << "price of drink \"" << drink.getName() << "\" has been changed" << endl;
    }
    cout << endl;
}

void ManagerUI::addSide() {
    string name;
    int price;

    cout << "----Add Sidedish----" << endl;
    cout << "Name: ";
    cin >> ws;
    getline(cin, name);
    cout << "Price: ";
    cin >> price;
    managerDomain.toLowerCase(name);
    Sidedish sidedish(name, price);
    try {
        managerDomain.addSidedish(sidedish);
    }
    catch(SidedishChangedException) {
        cout << "price of sidedish \"" << sidedish.getName() << "\" has been changed" << endl;
    }
    cout << endl;
}

void ManagerUI::addBranch() {
    string name;

    cout << "----Add Branch----" << endl;
    cout << "Name: ";
    cin >> ws;
    getline(cin, name);
    managerDomain.toLowerCase(name);
    Branch branch(name);
    try {
        managerDomain.addBranch(branch);
    }
    catch(BranchExistsException) {
        cout << "Branch already exists" << endl;
    }
}


void ManagerUI::printCrust() {
    cout << "----Crusts List----" << endl;
    vector<Crust> crusts = managerDomain.printCrust();
    for (int i = 0; i < crusts.size(); i++) {
        cout << crusts[i];
    }
    cout << "-------------------" << endl;
}

void ManagerUI::printTopping() {
    cout << "----Toppings List----" << endl;
    vector<Topping> toppings = managerDomain.printTopping();
    for (int i = 0; i < toppings.size(); i++) {
        cout << toppings[i];
    }
    cout << "---------------------" << endl;
}
void ManagerUI::printPizza() {
    cout << "----Pizza List----" << endl;
    cout << "Coming soon" << endl;
}

void ManagerUI::printDrink() {
    cout << "----Drinks List----" << endl;
    vector<Drink> drinks = managerDomain.printDrink();
    for (int i = 0; i < drinks.size(); i++) {
        cout << drinks[i];
    }
    cout << "-------------------" << endl;
}

void ManagerUI::printSide() {
    cout << "----Sidedish List----" << endl;
    vector<Sidedish> sidedishes = managerDomain.printSidedish();
     for (int i = 0; i < sidedishes.size(); i++) {
        cout << sidedishes[i];
    }
    cout << "---------------------" << endl;
}

void ManagerUI::printBranch() {
    cout << "----Branch List----" << endl;
    vector<Branch> branches = managerDomain.printBranch();
     for (int i = 0; i < branches.size(); i++) {
        cout << branches[i];
    }
    cout << "-------------------" << endl;
}

void ManagerUI::removeCrust() {
    string name;
    int inches;
    cout << "What crust would you like to remove? ";
    cin >> ws;
    getline(cin,name);
    cout << "What size? ";
    cin >> inches;
    managerDomain.toLowerCase(name);
    Crust crust(name, inches);

    try {
        managerDomain.removeCrust(crust);
    }
    catch(CrustNotAvailableException) {
        cout << "This crust \"" << crust.getName() << "\" of size " << crust.getInches() << " is not on the list" << endl;
    }
}

void ManagerUI::removeTopping() {
    string name;
    cout << "What topping would you like to remove? ";
    cin >> ws;
    getline(cin, name);
    managerDomain.toLowerCase(name);
    Topping topping(name);

    try {
        managerDomain.removeTopping(topping);
    }
    catch(ToppingNotAvailableException) {
        cout << "This topping \"" << topping.getName() << "\" is not on the list" << endl;
    }
}

void ManagerUI::removePizza() {
    cout << "Coming soon" << endl;
}
void ManagerUI::removeDrink() {
    string name;
    int liter;
    cout << "What drink would you like to remove? ";
    cin >> ws;
    getline(cin, name);
    cout << "what liter size?" << endl;
    cin >> liter;
    managerDomain.toLowerCase(name);
    Drink drink(name, liter);

    try {
        managerDomain.removeDrink(drink);
    }
    catch(DrinkNotAvaliableException) {
        cout << "This drink \"" << drink.getName() << "\" of size " << drink.getLiter() << "L is not on the list" << endl;
    }
}
void ManagerUI::removeSide() {
    string name;
    cout << "What sidedish would you like to remove? ";
    cin >> ws;
    getline(cin, name);
    managerDomain.toLowerCase(name);
    Sidedish sidedish(name);

    try {
        managerDomain.removeSidedish(sidedish);
    }
    catch(SideDishNotAvailableException) {
        cout << "This sidedish \"" << sidedish.getName() << "\" is not on the list" << endl;
    }
}
void ManagerUI::removeBranch() {
    string name;
    cout << "What restaurant branch would you like to remove? ";
    cin >> ws;
    getline(cin, name);
    managerDomain.toLowerCase(name);
    Branch branch(name);

    try {
        managerDomain.removeBranch(branch);
    }
    catch(BranchNotAvailableException) {
        cout << "This restaurant branch \"" << branch.getName() << "\" is not on the list" << endl;
    }
}
