#ifndef MANAGERREP_H
#define MANAGERREP_H
#include "Crust.h"
#include "Drink.h"
#include "Pizza.h"
#include "Topping.h"
#include "Sidedish.h"
#include "Branch.h"
#include <vector>

class ManagerRep
{
    public:
        ManagerRep();
        void addPizza(const Pizza &pizza);
        void addCrust(const Crust &crust);
        void addTopping(const Topping &topping);
        void addDrink(const Drink &drink);
        void addSidedish(const Sidedish &sidedish);
        void addBranch(const Branch &branch);

        vector<Pizza> getPizza();
        vector<Crust> getCrust();
        vector<Topping> getTopping();
        vector<Drink> getDrink();
        vector<Sidedish> getSidedish();
        vector<Branch> getBranch();

        void changePizzaList(vector<Pizza> &pizzas);
        void changeCrustList(vector<Crust> &crusts);
        void changeToppingList(vector<Topping> &toppings);
        void changeSidedishList(vector<Sidedish> &sidedishes);
        void changeDrinkList(vector<Drink> &drinks);
        void changeBranchList(vector<Branch> &branch);
};

#endif // MANAGERREP_H
