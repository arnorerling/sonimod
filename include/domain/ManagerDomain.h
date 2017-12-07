#ifndef MANAGERDOMAIN_H
#define MANAGERDOMAIN_H
#include "ManagerRep.h"

#include "PizzaChangedException.h"
#include "CrustChangedException.h"
#include "ToppingChangedException.h"
#include "SidedishChangedException.h"
#include "DrinkChangedException.h"
#include "BranchExistsException.h"

#include "PizzaNotAvailableException.h"
#include "CrustNotAvailableException.h"
#include "ToppingNotAvailableException.h"
#include "DrinkNotAvaliableException.h"
#include "SideDishNotAvailableException.h"
#include "BranchNotAvailableException.h"

#include "InvalidNameException.h"
#include "InvalidPriceException.h"
#include "InvalidAnswerException.h"
#include "InvalidInputException.h"

#include "Pizza.h"
#include "Crust.h"
#include "Topping.h"
#include "Drink.h"
#include "Sidedish.h"
#include "Branch.h"
#include <string>
#include <vector>
#include <stdlib.h>
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

        vector<Pizza> printPizza();
        vector<Crust> printCrust();
        vector<Topping> printTopping();
        vector<Drink> printDrink();
        vector<Sidedish> printSidedish();
        vector<Branch> printBranch();

        bool removePizza(const Pizza &pizza);
        bool removeCrust(const Crust &crust);
        bool removeTopping(const Topping &topping);
        bool removeDrink(const Drink &drink);
        bool removeSidedish(const Sidedish &sidedish);
        bool removeBranch(const Branch &branch);

        bool checkToppingAvaliability(const Topping &topping);
        bool checkValidName(const string &name);
        int  checkValidPrice(const string &price);
        bool checkValidInput(const string &input);
        bool checkValidAnswer(const string &answer);

};

#endif // MANAGERDOMAIN_H
