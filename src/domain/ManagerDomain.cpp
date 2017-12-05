#include "ManagerDomain.h"

ManagerDomain::ManagerDomain()
{
    //ctor
}

bool ManagerDomain::addCrust(const Crust &crust) {
    managerRep.addCrust(crust);
    return true;
}

bool ManagerDomain::addTopping(const Topping &topping) {
    managerRep.addTopping(topping);
    return true;
}

bool ManagerDomain::addDrink(const Drink &drink) {
    managerRep.addDrink(drink);
    return true;
}

bool ManagerDomain::addSidedish(const Sidedish &sidedish) {
    managerRep.addSidedish(sidedish);
    return true;
}

bool ManagerDomain::addBranch(const Branch &branch) {
    isValid(branch);
    managerRep.addBranch(branch);
    return true;
 }

void ManagerDomain::toLowerCase(string &name) {

    for (unsigned int i = 0; i < name.length(); i++) {
        if(name[i] != ' ' && isupper(name[i])) {
            name[i] = tolower(name[i]);
        }
    }
}
