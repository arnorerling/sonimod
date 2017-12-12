#ifndef MANAGERDOMAIN_H
#define MANAGERDOMAIN_H
#include "ManagerRep.h"

#include "ItemChangedException.h"
#include "NotFoundException.h"
#include "ItemExistsException.h"
#include "InvalidInputException.h"
#include "LengthNotRightException.h"
#include "InvalidDateException.h"

#include "Pizza.h"
#include "Crust.h"
#include "Topping.h"
#include "Drink.h"
#include "Sidedish.h"
#include "Branch.h"
#include "User.h"
#include "Order.h"

#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

class ManagerDomain
{
    private:
        ManagerRep managerRep;

    public:
        ManagerDomain();

        void toLowerCase(string &name);

        bool addPizza(const Pizza &pizza);
        bool addCrust(const Crust &crust);
        bool addTopping(const Topping &topping);
        bool addDrink(const Drink &drink);
        bool addSidedish(const Sidedish &sidedish);
        bool addBranch(const Branch &branch);
        bool addUser(const User &user);

        vector<Pizza> getPizzas();
        vector<Crust> getCrusts();
        vector<Topping> getToppings();
        vector<Drink> getDrinks();
        vector<Sidedish> getSidedishes();
        vector<Branch> getBranches();
        vector<User> getUsers();

        vector<Order> getOrders();
        vector<Order> getBranchOrders(const string &branch);
        vector<Order> getDateFromOrders(const string &dateFrom, vector<Order> branchOrders);
        vector<Order> getDateToOrders(const string &dateTo, vector<Order> dateFromOrders);

        bool removePizza(const Pizza &pizza);
        bool removeCrust(const Crust &crust);
        bool removeTopping(const Topping &topping);
        bool removeDrink(const Drink &drink);
        bool removeSidedish(const Sidedish &sidedish);
        bool removeBranch(const Branch &branch);
        bool removeUser(const User &user);

        bool checkTopping(const Topping &topping);
        bool checkValidName(const string &name);
        int  checkValidPrice(const string &price);
        bool checkValidInput(const string &input);
        bool checkValidAnswer(const string &answer);
        bool checkValidUsername(const string &username);
        bool checkValidPassword(const string &password);
        bool checkValidJob(const string &job);
        bool checkValidBranch(const string &branch);
        bool checkValidDate(const string &date);


};

#endif // MANAGERDOMAIN_H
