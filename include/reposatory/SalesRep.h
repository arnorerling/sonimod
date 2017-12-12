#ifndef SALESREP_H
#define SALESREP_H

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include "Drink.h"
#include "Sidedish.h"
#include "Pizza.h"
#include "Order.h"

using namespace std;

class SalesRep
{

    private:

    public:
        // Constructor
        SalesRep();

        //takes vectors from the domain and filles them up
        void getDrinks(vector<Drink>& drinks);
        void getSidedishes(vector<Sidedish>& sidedishes);
        void getPizzas(vector<Pizza>& pizzas);
        void getToppings(vector<Topping>& toppings);
        void getCrust(vector<Crust>& crusts);
        void getBranches(vector<Branch>& branches);

        //writes the current order to orders_binary
        void fileOrder(Order& order);

};

#endif // SALESREP_H
