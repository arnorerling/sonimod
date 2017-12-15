#ifndef MANAGERREP_H
#define MANAGERREP_H
#include "FileNotOpenException.h"
#include "Crust.h"
#include "Drink.h"
#include "Pizza.h"
#include "Topping.h"
#include "Sidedish.h"
#include "Branch.h"
#include "User.h"
#include "Order.h"
#include <vector>

class ManagerRep
{
    public:
        // Constructor
        ManagerRep();

        //adds an item to file
        void addPizza(const Pizza &pizza);
        void addCrust(const Crust &crust);
        void addTopping(const Topping &topping);
        void addDrink(const Drink &drink);
        void addSidedish(const Sidedish &sidedish);
        void addBranch(const Branch &branch);
        void addUser(const User &user);

        //gets all items classes from a file
        vector<Pizza> getPizza();
        vector<Crust> getCrust();
        vector<Topping> getTopping();
        vector<Drink> getDrink();
        vector<Sidedish> getSidedish();
        vector<Branch> getBranch();
        vector<User> getUser();
        vector<Order> getLegacyOrder();
        vector<Order> getWaterlooOrder();

        //overwrites a whole file with a vector of items
        void changePizzaList(vector<Pizza> &pizzas);
        void changeCrustList(vector<Crust> &crusts);
        void changeToppingList(vector<Topping> &toppings);
        void changeSidedishList(vector<Sidedish> &sidedishes);
        void changeDrinkList(vector<Drink> &drinks);
        void changeBranchList(vector<Branch> &branch);
        void changeUsersList(vector<User> &users);
};

#endif // MANAGERREP_H
