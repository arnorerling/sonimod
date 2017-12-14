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
        ManagerDomain();

        //adds pizza to list, if pizza name already exists,
        //the toppings, crust and price will change
        bool addPizza(const Pizza &pizza);
        //add crust to list, if crust name already exists, crust price will change
        bool addCrust(const Crust &crust);
        //add topping to list, if topping name already exists, topping price will change
        bool addTopping(const Topping &topping);
        //add drink to list, if drink name already exists, drink price will change
        bool addDrink(const Drink &drink);
        //add sidedish to list, if sidedish name already exists, sidedish price will change
        bool addSidedish(const Sidedish &sidedish);
        //add branch to list, if branch name already exists, nothing will happen
        bool addBranch(const Branch &branch);
        //add user to list, if user name already exists, the user password and job will change
        bool addUser(const User &user);


        //gets pizza list
        vector<Pizza> getPizzas();
        //gets crust list
        vector<Crust> getCrusts();
        //gets toppings list
        vector<Topping> getToppings();
        //gets drinks list
        vector<Drink> getDrinks();
        //gets sidedish list
        vector<Sidedish> getSidedishes();
        //gets branch list
        vector<Branch> getBranches();
        //gets users list
        vector<User> getUsers();

        //returns orders with the same branch, if branch is not chosen it returns all
        vector<Order> getBranchOrders(const string &branch);
        //returns orders after a specific date, if no date is chosen it returns all
        vector<Order> getDateFromOrders(const string &dateFrom, vector<Order> branchOrders);
        //returns orders before/with a specific date, if no date is chosen it returns all
        vector<Order> getDateToOrders(const string &dateTo, vector<Order> dateFromOrders);

        //removes a pizza from list
        bool removePizza(const Pizza &pizza);
        //removes a crust from list
        bool removeCrust(const Crust &crust);
        //removes a topping from list
        bool removeTopping(const Topping &topping);
        //removes a drink from list
        bool removeDrink(const Drink &drink);
        //removes a sidedish from list
        bool removeSidedish(const Sidedish &sidedish);
        //removes a branch from list
        bool removeBranch(const Branch &branch);
        //removes a user from list
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
