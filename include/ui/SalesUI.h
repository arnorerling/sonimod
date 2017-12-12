#ifndef SALESUI_H
#define SALESUI_H

#include "SalesDomain.h"
#include <iostream>
#include "Order.h"
#include "Output.h"
#include <cstdlib>
#include <iomanip>

using namespace std;


class SalesUI {

    private:
        SalesDomain salesDomain;
        Output output;
        Order order;

    public:

        // Starts UI for sales, prints out menu
        SalesUI();
        void startUI();

        // Add functions
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

        // print functions
        void printPizzas();
        void printCrusts();
        void printToppings();
        void printSidedishes();
        void printDrinks();

        // File order sends the order to a binary file
        void fileOrder();

        // functions that send parameters to domain, they also try and catch
        string validName();
        string validPhoneNumber();
        int validNumber();
        char validAnswer();
        void markPaidFor();
        void choosePizza(Pizza &pizza, int& size);

        // Prints logo
        void printLogo();
};

#endif // SALESUI_H
