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


        //file order sends the order from the UI to the rep
        void fileOrder(Order &order);
        //marks the order paid for
        bool markOrderPaidFor(Order &order);

        //check if pizza is in a list
        bool checkPizzaAvailability(const string &name, int size, Pizza &pizza);
        //check if drink is in a list
        bool checkDrinkAvailability(Drink& drink);
        //check if sidedish is in a list
        bool checkSidedishAvailability(Sidedish& sidedish);
        //check if topping is in a list
        void checkToppingAvailability(Topping& topping);
        //check if crust is in a list
        bool checkCrustAvailability(Crust& crust);
        //check if restaurant branch is in a list
        bool checkBranchAvailability(const string &branch);
        //check if order is in a list
        void checkOrder(const Order &order);

        //check if answer is 'y' or 'n'
        bool checkValidAnswer(const string &answer);
        //check if name is valid (no digits)
        bool checkValidName(const string &name);
        //check if phone number is valid (7 digits)
        bool checkValidPhoneNumber(const string &num);
        //check if size is valid
        int checkValidSize(const string &number);
        //check if number is valid (1 digit)
        bool checkValidInput(const string &input);
        // takes in a string and makes it all lowercase
        void toLowerCase(string &str);

};

#endif // SALESDOMAIN_H
