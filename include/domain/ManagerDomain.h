#ifndef MANAGERDOMAIN_H
#define MANAGERDOMAIN_H

#include "ManagerRep.h"
#include "Crust.h"
#include "Drink.h"
#include "Topping.h"
#include "Sidedish.h"
#include "Branch.h"
#include <string>
using namespace std;

class ManagerDomain
{
    private:
        ManagerRep managerRep;

    public:
        ManagerDomain();
        bool addCrust(const Crust &crust);
        bool addTopping(const Topping &topping);
        bool addDrink(const Drink &drink);
        bool addSidedish(const Sidedish &sidedish);
        bool addBranch(const Branch &branch);

        void toLowerCase(string &name);

};

#endif // MANAGERDOMAIN_H
