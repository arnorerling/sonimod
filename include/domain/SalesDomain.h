#ifndef SALESDOMAIN_H
#define SALESDOMAIN_H


#include "SalesRep.h"
#include "LengthNotRightException.h"
#include "NotFoundException.h"
#include "InvalidInputException.h"
#include <iostream>
#include <stdlib.h>

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
        bool checkBranchAvailability(const string &branch);

        void checkYesOrNo(string check);

        void fileOrder(Order &order);
        int isValidNumber(string &number);
        void toLowerCase(string &str);
        bool checkValidAnswer(const string &answer);

};

#endif // SALESDOMAIN_H
