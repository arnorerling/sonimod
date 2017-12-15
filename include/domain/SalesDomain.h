#ifndef SALESDOMAIN_H
#define SALESDOMAIN_H


#include "SalesRep.h"
#include "LengthNotRightException.h"
#include "NotFoundException.h"
#include "InvalidInputException.h"
#include "AlreadyMarkedException.h"
#include "CantFileOrderException.h"
#include <stdlib.h>

class SalesDomain {
    private:
        SalesRep salesRep;

    public:

        // Constructor
        SalesDomain();

        // Get functions that call functions in the repository to fill arrays
        vector<Drink> getDrinks();
        vector<Sidedish> getSidedishes();
        vector<Pizza> getPizzas();
        vector<Topping> getToppings();
        vector<Crust> getCrusts();
        vector<Branch> getBranches();


        bool checkPizzaAvailability(const string &name, int size, Pizza &pizza);
        bool checkDrinkAvailability(Drink& drink);
        bool checkSidedishAvailability(Sidedish& sidedish);
        void checkToppingAvailability(Topping& topping);
        bool checkCrustAvailability(Crust& crust);
        bool checkBranchAvailability(const string &branch);
        void checkYesOrNo(const string &check);
        bool checkValidAnswer(const string &answer);
        void checkOrder(const Order &order);
        bool checkValidInput(const string &input);
        bool checkValidName(const string &name);
        bool checkValidPhoneNumber(const string &num);
        int checkValidNumber(const string &number);

        // file order sends the order from the UI to the rep
        void fileOrder(Order &order);

        // takes in a string and makes it all lowercase
        void toLowerCase(string &str);

        // marks the order paid for
        bool markOrderPaidFor(Order &order);

};

#endif // SALESDOMAIN_H
