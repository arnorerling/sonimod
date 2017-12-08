#ifndef SALESDOMAIN_H
#define SALESDOMAIN_H

#include "NotFoundException.h"

#include "SalesRep.h"
#include "InvalidNameException.h"
#include "InvalidPhoneNumberException.h"
#include "LengthNotRightException.h"
#include "NotAllowedYesOrNoException.h"
#include "NotFoundException.h"
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
        void getBranches(vector<Branch>& branches);

        bool isValidName(string name);
        bool isValidPhoneNumber(string num);

        bool checkDrinkAvailability(Drink& drink);
        bool checkSidedishAvailability(Sidedish& sidedish);
        void checkToppingAvailability(Topping& topping);
        bool checkCrustAvailability(Crust& crust);
        bool checkBranchAvailability(string branch);

        void checkYesOrNo(string check);

        void fileOrder(Order &order);

};

#endif // SALESDOMAIN_H
