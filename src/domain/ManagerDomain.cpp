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

bool ManagerDomain::addPizza(const Pizza &pizza) {
    vector<Pizza> pizzas = managerRep.getPizza();

    for (int i = 0; i < pizzas.size(); i++){
        if (pizzas[i].getName() == pizza.getName() && pizzas[i].getCrustSize() == pizza.getCrustSize()) {
            {
                pizzas[i] = pizza;
                managerRep.changePizzaList(pizzas);
                throw ItemChangedException();
            }
        }
    }
    managerRep.addPizza(pizza);
    return true;
}

bool ManagerDomain::addCrust(const Crust &crust) {
    vector<Crust>crusts = managerRep.getCrust();

    for (int i = 0; i < crusts.size(); i++){
        if (crusts[i].getName() == crust.getName()) {
            if(crusts[i].getInches() == crust.getInches()) {
                crusts[i] = crust;
                managerRep.changeCrustList(crusts);
                throw ItemChangedException();
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
            throw ItemChangedException();
        }
    }
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
                throw ItemChangedException();
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
            throw ItemChangedException();
        }
    }
    managerRep.addSidedish(sidedish);
    return true;
}

bool ManagerDomain::addBranch(const Branch &branch) {
    vector<Branch> branches = managerRep.getBranch();
    for (int i = 0; i < branches.size(); i++) {
        if (branches[i].getName() == branch.getName()) {
            throw ItemExistsException();
        }
    }
    managerRep.addBranch(branch);
    return true;
 }

bool ManagerDomain::addUser(const User &user) {
    vector<User> users = managerRep.getUser();

    for (int i = 0; i < users.size(); i++){
        if (users[i].getName() == user.getName()) {
            users[i] = user;
            managerRep.changeUsersList(users);
            throw ItemChangedException();
        }
    }
    managerRep.addUser(user);
    return true;
}


vector<Pizza> ManagerDomain::printPizza() {
    vector<Pizza>pizzas = managerRep.getPizza();
    return pizzas;
}

vector<Crust> ManagerDomain::printCrust() {
    vector<Crust>crusts = managerRep.getCrust();
    return crusts;
}

vector<Topping> ManagerDomain::printTopping() {
    vector<Topping>toppings = managerRep.getTopping();
    return toppings;
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

vector<User> ManagerDomain::printUser() {
    vector<User>users = managerRep.getUser();
    return users;
}

bool ManagerDomain::removePizza(const Pizza &pizza) {
    vector<Pizza>pizzas = managerRep.getPizza();
    vector<Pizza>newPizzas;

    for (int i = 0; i < pizzas.size(); i++){
        if (pizzas[i].getName() != pizza.getName()) {
            newPizzas.push_back(pizzas[i]);
        }
    }

    if (pizzas == newPizzas) {
        throw NotFoundException();
    }

    else {
        managerRep.changePizzaList(newPizzas);
        return true;
    }
}

bool ManagerDomain::removeCrust(const Crust &crust) {
    vector<Crust>crusts = managerRep.getCrust();
    vector<Crust>newCrusts;

    for (int i = 0; i < crusts.size(); i++){
        if (crusts[i].getName() != crust.getName()) {
            newCrusts.push_back(crusts[i]);
        }
    }

    if (crusts == newCrusts) {
        throw NotFoundException();
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
        throw NotFoundException();
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
        if (drinks[i].getName() != drink.getName()) {
            newDrinks.push_back(drinks[i]);
        }
    }
    if (drinks == newDrinks) {
        throw NotFoundException();
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
        throw NotFoundException();
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
        throw NotFoundException();
    }
    else {
        managerRep.changeBranchList(newBranches);
        return true;
    }
}

bool ManagerDomain::removeUser(const User &user) {
    vector<User>users = managerRep.getUser();
    vector<User>newUsers;

    for (int i = 0; i < users.size(); i++){
        if (users[i].getName() != user.getName()) {
            newUsers.push_back(users[i]);
        }
    }
    if (users == newUsers) {
        throw NotFoundException();
    }
    else {
        managerRep.changeUsersList(newUsers);
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
    throw NotFoundException();
}


bool ManagerDomain::checkValidName(const string &name) {

    for(unsigned int i = 0; i < name.length(); i++){
        if(isdigit(name[i])){
             throw InvalidInputException();
        }
    }
    return true;
}

int ManagerDomain::checkValidPrice(const string &price) {
    int price1 = 0;
    for(unsigned int i = 0; i < price.length(); i++){
        if(isalpha(price[i])){
            throw InvalidInputException();
        }
    }
    price1 = atoi(price.c_str());

    if(price1 < 0){
        throw InvalidInputException();
    }
    return price1;
}

bool ManagerDomain::checkValidInput(const string &input) {
    if (input.length() == 1) {
      return true;
    }
    throw InvalidInputException();
    return false;
}

bool ManagerDomain::checkValidAnswer(const string &answer) {
    if(answer == "y" || answer == "n"){
        return true;
    }
    throw InvalidInputException();
    return false;
}

bool ManagerDomain::checkValidUsername(const string &username) {

    for(unsigned int i = 0; i < username.length(); i++){
        if(username[i] == ' '){
             throw InvalidInputException();
        }
    }
    return true;
}

bool ManagerDomain::checkValidPassword(const string &password) {

    int cDigit = 0;
    for(unsigned int i = 0; i < password.length(); i++){
        if(password[i] == ' '){
             throw InvalidInputException();
        }
        if(isdigit(password[i])) {
            cDigit ++;
        }
    }

    if (cDigit < 2) {
        throw InvalidInputException();
    }
    return true;
}

bool ManagerDomain::checkValidJob(const string &job) {
     if (job == "1" || job == "2" || job == "3" || job == "4"){
        return true;
    }

    throw InvalidInputException();
    return false;
}
