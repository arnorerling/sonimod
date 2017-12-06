#ifndef SALESDOMAIN_H
#define SALESDOMAIN_H

#include "SalesRep.h"
#include "DrinkNotAvailableException.h"
#include "SizeNotAvailableException.h"
#include "SideDishNotAvailableException.h"
#include "ToppingNotAvailableException.h"
#include "CrustNotAvailableException.h"
#include "InvalidNameException.h"
#include "InvalidPhoneNumberException.h"
#include <iostream>

using namespace std;

class SalesDomain {
    private:
        SalesRep salesRep;

    public:
        SalesDomain();
        void getDrinks(vector<Drink>& drinks);
        void getSidedishes(vector<Sidedish>& sidedishes);
        void getPizzas(vector<Pizza>& pizzas);
        void getToppings(vector<Topping>& toppings);
        void getCrusts(vector<Crust>& crusts);

        bool isValidName(string name);
        bool isValidPhoneNumber(string num);

        bool checkDrinkAvailability(Drink& drink);
        bool checkSidedishAvailability(Sidedish& sidedish);
        bool checkToppingAvailability(Topping& topping);
        bool checkCrustAvailability(Crust& crust);

        void fileOrder(Order &order);

};

#endif // SALESDOMAIN_H
