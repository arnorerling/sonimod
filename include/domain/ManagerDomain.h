#ifndef MANAGERDOMAIN_H
#define MANAGERDOMAIN_H

#include "ManagerRep.h"

#include "ItemChangedException.h"
#include "NotFoundException.h"
#include "ItemExistsException.h"
#include "InvalidInputException.h"
#include "LengthNotRightException.h"
#include "InvalidDateException.h"
#include "CantDeleteException.h"

#include <string>
#include <stdlib.h>
using namespace std;

class ManagerDomain
{
    private:
        ManagerRep managerRep;

    public:
        // Constructor
        ManagerDomain();

        //adds item to list.
        //if item already exists, the rest of the info will change
        bool addPizza(const Pizza &pizza);
        bool addCrust(const Crust &crust);
        bool addTopping(const Topping &topping);
        bool addDrink(const Drink &drink);
        bool addSidedish(const Sidedish &sidedish);
        bool addBranch(const Branch &branch);
        bool addUser(const User &user);

        //gets list of items
        vector<Pizza> getPizzas();
        vector<Crust> getCrusts();
        vector<Topping> getToppings();
        vector<Drink> getDrinks();
        vector<Sidedish> getSidedishes();
        vector<Branch> getBranches();
        vector<User> getUsers();

        //returns legacy orders with the same branch, if branch is not chosen it returns all
        vector<Order> getLegacyBranchOrders(const string &branch);
        //returns failed order withe the same branch, if branch is not chosen it returns all
        vector<Order> getFailedBranchOrders(const string &branch);
        //returns orders after a specific date, if no date is chosen it returns all
        vector<Order> getDateFromOrders(const string &dateFrom, vector<Order> branchOrders);
        //returns orders before/with a specific date, if no date is chosen it returns all
        vector<Order> getDateToOrders(const string &dateTo, vector<Order> dateFromOrders);

        //removes items from list
        bool removePizza(const Pizza &pizza);
        bool removeCrust(const Crust &crust);
        bool removeTopping(const Topping &topping);
        bool removeDrink(const Drink &drink);
        bool removeSidedish(const Sidedish &sidedish);
        bool removeBranch(const Branch &branch);
        bool removeUser(const User &user);

        //check if a certain topping is in a list
        bool checkTopping(const Topping &topping);
        //check if a name is valid (no digits)
        bool checkValidName(const string &name);
        //check if a price is valid (between 0 and 99999)
        int  checkValidPrice(const string &price);
        //check if input is valid (only one digit)
        bool checkValidInput(const string &input);
        //check if answer is valid (only 'y' or 'n')
        bool checkValidAnswer(const string &answer);
        //check if username is valid (must be one word)
        bool checkValidUsername(const string &username);
        //check if password is valid (must be one word and contain at least 2 numbers)
        bool checkValidPassword(const string &password);
        //check if jobNumber is valid (1,2,3 or 4)
        bool checkValidJob(const string &job);
        //check if a certain branch is in a list
        bool checkValidBranch(const string &branch);
        //check if a certain date is valid. (Must be "DD.MM.YYYY" format)
        bool checkValidDate(const string &date);
        //turns uppercase letters to lowercase
        void toLowerCase(string &name);

};

#endif // MANAGERDOMAIN_H
