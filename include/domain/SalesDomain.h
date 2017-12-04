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

        bool checkDrinkAvaliability(const vector<Drink>& drinks, Drink& drink);
        bool checkSidedishAvaliability(const vector<Sidedish>& sidedishes, Sidedish& sidedish);
};

#endif // SALESDOMAIN_H
