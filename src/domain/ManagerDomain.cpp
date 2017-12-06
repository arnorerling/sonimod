#include "ManagerDomain.h"

ManagerDomain::ManagerDomain()
{
    //ctor
}

void ManagerDomain::toLowerCase(string &name) {

    for (unsigned int i = 0; i < name.length(); i++) {
        if(name[i] != ' ' && isupper(name[i])) {
            name[i] = tolower(name[i]);
        }
    }
}

bool ManagerDomain::addCrust(const Crust &crust) {
      vector<Crust>crusts = managerRep.getCrust();

    for (int i = 0; i < crusts.size(); i++){
        if (crusts[i].getName() == crust.getName()) {
            if(crusts[i].getInches() == crust.getInches()) {
                crusts[i] = crust;
                managerRep.changeCrustList(crusts);
                throw CrustChangedException();
            }
        }
    }
    managerRep.addCrust(crust);
    return true;
}

bool ManagerDomain::addTopping(const Topping &topping) {
    vector<Topping>toppings = managerRep.getTopping();

    for (int i = 0; i < toppings.size(); i++){
        if (toppings[i].getName() == topping.getName()) {
            toppings[i] = topping;
            managerRep.changeToppingList(toppings);
            throw ToppingChangedException();
        }
    }
    managerRep.addTopping(topping);
    return true;
}

bool ManagerDomain::addPizza(const Pizza &pizza) {
    /*vector<Pizza> pizzas = managerRep.getPizza();
    for (int i = 0; i < pizzas.size(); i++){
        if (drinks[i].getName() == drink.getName()) {
            if (drinks[i].getLiter() == drink.getLiter()){
                drinks[i] = drink;
                managerRep.changeDrinkList(drinks);
                throw DrinkChangedException();
            }
        }
    }*/
    managerRep.addPizza(pizza);
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

vector<Crust> ManagerDomain::printCrust() {
    vector<Crust>crusts = managerRep.getCrust();
    return crusts;
}

vector<Topping> ManagerDomain::printTopping() {
    vector<Topping>toppings = managerRep.getTopping();
    return toppings;
}

vector<Pizza> ManagerDomain::printPizza() {
    vector<Pizza>pizzas = managerRep.getPizza();
    return pizzas;
}

vector<Drink> ManagerDomain::printDrink() {
    vector<Drink>drinks = managerRep.getDrink();
    return drinks;
}

vector<Sidedish> ManagerDomain::printSidedish() {
    vector<Sidedish>sidedishes = managerRep.getSidedish();
    return sidedishes;
}

vector<Branch> ManagerDomain::printBranch() {
    vector<Branch>branches = managerRep.getBranch();
    return branches;
}

bool ManagerDomain::removeCrust(const Crust &crust) {
    vector<Crust>crusts = managerRep.getCrust();
    vector<Crust>newCrusts;

    for (int i = 0; i < crusts.size(); i++){
        if (crusts[i].getName() != crust.getName() || crusts[i].getInches() != crust.getInches()) {
            newCrusts.push_back(crusts[i]);
        }
    }

    if (crusts == newCrusts) {
        throw CrustNotAvailableException();
    }

    else {
        managerRep.changeCrustList(newCrusts);
        return true;
    }
}

bool ManagerDomain::removeTopping(const Topping &topping) {
    vector<Topping>toppings = managerRep.getTopping();
    vector<Topping>newToppings;

    for (int i = 0; i < toppings.size(); i++){
        if (toppings[i].getName() != topping.getName()) {
            newToppings.push_back(toppings[i]);
        }
    }

    if (toppings == newToppings) {
        throw ToppingNotAvailableException();
    }
    else {
        managerRep.changeToppingList(newToppings);
        return true;
    }
}

bool ManagerDomain::removeDrink(const Drink &drink) {
    vector<Drink>drinks = managerRep.getDrink();
    vector<Drink>newDrinks;

    for (int i = 0; i < drinks.size(); i++){
        if (drinks[i].getName() != drink.getName() || drinks[i].getLiter() != drink.getLiter()) {
            newDrinks.push_back(drinks[i]);
        }
    }
    if (drinks == newDrinks) {
        throw DrinkNotAvaliableException();
    }
    else {
        managerRep.changeDrinkList(newDrinks);
        return true;
    }
}

bool ManagerDomain::removeSidedish(const Sidedish &sidedish) {
    vector<Sidedish>sidedishes = managerRep.getSidedish();
    vector<Sidedish>newSidedishes;

    for (int i = 0; i < sidedishes.size(); i++){
        if (sidedishes[i].getName() != sidedish.getName()) {
            newSidedishes.push_back(sidedishes[i]);
        }
    }
    if (sidedishes == newSidedishes) {
        throw SideDishNotAvailableException();
    }
    else {
        managerRep.changeSidedishList(newSidedishes);
        return true;
    }
}

bool ManagerDomain::removeBranch(const Branch &branch) {
    vector<Branch>branches = managerRep.getBranch();
    vector<Branch>newBranches;

    for (int i = 0; i < branches.size(); i++){
        if (branches[i].getName() != branch.getName()) {
            newBranches.push_back(branches[i]);
        }
    }
    if (branches == newBranches) {
        throw BranchNotAvailableException();
    }
    else {
        managerRep.changeBranchList(newBranches);
        return true;
    }
}

bool ManagerDomain::checkToppingAvaliability(const Topping &topping) {
    vector<Topping> toppings = managerRep.getTopping();

    for (int i = 0; i < toppings.size(); i++) {
        if (toppings[i].getName() == topping.getName()) {
            return true;
        }
    }
    throw ToppingNotAvailableException();
}
