#ifndef SALESUI_H
#define SALESUI_H

#include "SalesDomain.h"
#include <iostream>
#include "Order.h"

using namespace std;


class SalesUI {

    private:
        SalesDomain salesDomain;
        Order order;

    public:
        SalesUI();
        void startUI();
        void addCustomer();

        void printPizzas();
        void printSidedishes();
        void printDrinks();
        void printToppings();
        void printCrusts();

        void addPizza();
        void addCrust(Pizza &pizza);
        void addToppings(Pizza &pizza);
        void addSidedish();
        void addDrink();
        void addBranch(Order &order);

        void fileOrder();
};

#endif // SALESUI_H
