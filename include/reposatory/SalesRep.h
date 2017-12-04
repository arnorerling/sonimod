#ifndef SALESREP_H
#define SALESREP_H

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include "Drink.h"
#include "Sidedish.h"
#include "Pizza.h"

using namespace std;

class SalesRep
{

    private:

    public:
        SalesRep();
        void getDrinks(vector<Drink>& drinks);
        void getSidedishes(vector<Sidedish>& sidedishes);
        void getPizzas(vector<Pizza>& pizzas);
        void getToppings(vector<Topping>& toppings);
        void getCrust(vector<Crust>& crusts);

};

#endif // SALESREP_H
