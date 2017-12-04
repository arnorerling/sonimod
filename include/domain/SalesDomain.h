#ifndef SALESDOMAIN_H
#define SALESDOMAIN_H

#include "SalesRep.h"
#include <iostream>
using namespace std;

class SalesDomain
{
    private:
        SalesRep salesRep;

    public:
        SalesDomain();
        void getDrinks(vector<Drink>& drinks);
        void getSidedishes(vector<Sidedish>& sidedishes);
        void getPizzas(vector<Pizza>& pizzas);
        void getToppings(vector<Topping>& toppings);
        void getCrusts(vector<Crust>& crusts);

        bool checkDrinkAvaliability(const vector<Drink>& drinks, Drink& drink);
        bool checkSidedishAvaliability(const vector<Sidedish>& sidedishes, Sidedish& sidedish);
        bool checkToppingAvaliability(const vector<Topping>& toppings, Topping& topping);
        bool checkCrustAvaliability(const vector<Crust>& crusts, Crust& crust);
};

#endif // SALESDOMAIN_H
