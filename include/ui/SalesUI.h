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
        SalesUI();
        void startUI();

        void addCustomer();
        void addPizza();
        void addPizzaMenu();
        void choosePizza(Pizza &pizza, int& size);
        void addCrust(Pizza &pizza, int& size);
        void addToppings(Pizza &pizza);
        void addSidedish();
        void addDrink();
        void addBranch();
        void addAddress();

        void printPizzas();
        void printCrusts();
        void printToppings();
        void printSidedishes();
        void printDrinks();

        void fileOrder();

        string validName();
        string validPhoneNumber();
        int validNumber();
        char validAnswer();
        void markPaidFor();

        void printLogo();
};

#endif // SALESUI_H
