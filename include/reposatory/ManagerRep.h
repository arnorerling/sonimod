#ifndef MANAGERREP_H
#define MANAGERREP_H
#include "Crust.h"
#include "Drink.h"
#include "Topping.h"
#include "Sidedish.h"
#include "Branch.h"

class ManagerRep
{
    public:
        ManagerRep();
        void addCrust(const Crust &crust);
        void addTopping(const Topping &topping);
        void addDrink(const Drink &drink);
        void addSidedish(const Sidedish &sidedish);
        void addBranch(const Branch &branch);

    protected:

    private:
};

#endif // MANAGERREP_H
