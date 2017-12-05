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
    vector<Drink>drinks = managerRep.getDrink();

    for (int i = 0; i < drinks.size(); i++){
        if (drinks[i].getName() == drink.getName()) {
            if (drinks[i].getLiter() == drink.getLiter()){
                drinks[i] = drink;
                managerRep.changeDrinkList(drinks);
                throw DrinkChangedException();
            }
        }
    }
    managerRep.addDrink(drink);
    return true;
}

bool ManagerDomain::addSidedish(const Sidedish &sidedish) {
    vector<Sidedish> sidedishes = managerRep.getSidedish();

    for (int i = 0; i < sidedishes.size(); i++){
        if (sidedishes[i].getName() == sidedish.getName()) {
            sidedishes[i] = sidedish;
            managerRep.changeSidedishList(sidedishes);
            throw SidedishChangedException();
        }
    }
    managerRep.addSidedish(sidedish);
    return true;
}

bool ManagerDomain::addBranch(Branch &branch) {
    vector<Branch> branches = managerRep.getBranch();
    for (int i = 0; i < branches.size(); i++) {
        if (branches[i].getName() == branch.getName()) {
            throw BranchExistsException();
        }
    }
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
