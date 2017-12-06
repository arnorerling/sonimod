#ifndef MANAGERDOMAIN_H
#define MANAGERDOMAIN_H

#include "BranchExistsException.h"
#include "SidedishChangedException.h"
#include "DrinkChangedException.h"
#include "ToppingChangedException.h"
#include "CrustChangedException.h"
#include "PizzaChangedException.h"
#include "CrustNotAvailableException.h"
#include "ToppingNotAvailableException.h"
#include "DrinkNotAvaliableException.h"
#include "SideDishNotAvailableException.h"
#include "BranchNotAvailableException.h"

#include "ManagerRep.h"
#include "Crust.h"
#include "Drink.h"
#include "Topping.h"
#include "Sidedish.h"
#include "Branch.h"
#include <string>
#include <vector>
using namespace std;

class ManagerDomain
{
    private:
        ManagerRep managerRep;

    public:
        ManagerDomain();

        void toLowerCase(string &name);

        bool addCrust(const Crust &crust);
        bool addTopping(const Topping &topping);
        bool addPizza(const Pizza &pizza);
        bool addDrink(const Drink &drink);
        bool addSidedish(const Sidedish &sidedish);
        bool addBranch(Branch &branch);

        vector<Crust> printCrust();
        vector<Topping> printTopping();
        vector<Pizza> printPizza();
        vector<Drink> printDrink();
        vector<Sidedish> printSidedish();
        vector<Branch> printBranch();

        bool removeCrust(const Crust &crust);
        bool removeTopping(const Topping &topping);
        bool removeDrink(const Drink &drink);
        bool removeSidedish(const Sidedish &sidedish);
        bool removeBranch(const Branch &branch);

        bool checkToppingAvaliability(const Topping &topping);

};

#endif // MANAGERDOMAIN_H
