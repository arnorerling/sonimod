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
        ManagerRep();
        //add pizza to a file
        void addPizza(const Pizza &pizza);
        //add crust class to a file
        void addCrust(const Crust &crust);
        //add topping class to a file
        void addTopping(const Topping &topping);
        //add drink class to a file
        void addDrink(const Drink &drink);
        //add sidedish class to a file
        void addSidedish(const Sidedish &sidedish);
        //add branch class to a file
        void addBranch(const Branch &branch);
        //add user class to a file
        void addUser(const User &user);

        //gets all pizza classes from a file
        vector<Pizza> getPizza();
        //gets all crust classes from a file
        vector<Crust> getCrust();
        //gets all topping classes from a file
        vector<Topping> getTopping();
        //gets all drink classes from a file
        vector<Drink> getDrink();
        //gets all sidedish classes from a file
        vector<Sidedish> getSidedish();
        //gets all branch classes from a file
        vector<Branch> getBranch();
        //gets all user classes from a file
        vector<User> getUser();
        //gets all order classes from a legacy file
        vector<Order> getOrder();

        //overwrites a whole file with a vector of pizza classes
        void changePizzaList(vector<Pizza> &pizzas);
        //overwrites a whole file with a vector of crust classes
        void changeCrustList(vector<Crust> &crusts);
        //overwrites a whole file with a vector of topping classes
        void changeToppingList(vector<Topping> &toppings);
        //overwrites a whole file with a vector of sidedish classes
        void changeSidedishList(vector<Sidedish> &sidedishes);
        //overwrites a whole file with a vector of drink classes
        void changeDrinkList(vector<Drink> &drinks);
        //overwrites a whole file with a vector of branch classes
        void changeBranchList(vector<Branch> &branch);
        //overwrites a whole file with a vector of user classes
        void changeUsersList(vector<User> &users);
};

#endif // MANAGERREP_H
