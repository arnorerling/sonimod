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
        vector<Pizza> avaliablePizzas;
        vector<Sidedish> avaliableSidedishes;
        vector<Drink> avaliableDrinks;


    public:
        SalesUI();
        void startUI();

        void printPizzas();
        void printSidedishes();
        void printDrinks();

        void addPizza();
        void addSidedish();
        void addDrink();
};

#endif // SALESUI_H
