#ifndef SALESUI_H
#define SALESUI_H

#include "SalesDomain.h"
#include <iostream>
#include "Output.h"
#include <iomanip>

using namespace std;


class SalesUI {

    private:
        SalesDomain salesDomain;
        Output output;
        Order order;

        //Add items to order
        void addCustomer();
        void addPizza();
        void addPizzaMenu();
        void addCrust(Pizza &pizza, int& size);
        void addToppings(Pizza &pizza);
        void addSidedish();
        void addDrink();
        void addBranch();
        void addAddress();
        string addComment();

        //prints items from list
        void printPizzas();
        void printCrusts();
        void printToppings();
        void printSidedishes();
        void printDrinks();

        //File order sends the order to a binary file
        void fileOrder();

        //Functions that send parameters to domain for validation, they also try and catch
        string validName();
        string validPhoneNumber();
        int validNumber();
        char validAnswer();
        char checkInput();
        void markPaidFor();
        void choosePizza(Pizza &pizza, int& size);

        //Prints sales logo
        void printLogo();

    public:
        //Constructor
        SalesUI();
        //Starts UI for sales, prints out menu
        void startUI();
};

#endif // SALESUI_H
