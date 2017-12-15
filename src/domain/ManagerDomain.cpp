#include "ManagerDomain.h"

ManagerDomain::ManagerDomain()
{
    //ctor
}

bool ManagerDomain::addPizza(const Pizza &pizza) {
    vector<Pizza> pizzas = managerRep.getPizza();
    for (unsigned int i = 0; i < pizzas.size(); i++) {
        if (pizzas[i] == pizza){
            pizzas[i] = pizza;
            managerRep.changePizzaList(pizzas);
            throw ItemChangedException();
        }
    }
    managerRep.addPizza(pizza);
    return true;
}

bool ManagerDomain::addCrust(const Crust &crust) {
    vector<Crust>crusts = managerRep.getCrust();
    for (unsigned int i = 0; i < crusts.size(); i++) {
        if (crusts[i] == crust) {
            crusts[i] = crust;
            managerRep.changeCrustList(crusts);
            throw ItemChangedException();
        }
    }
    managerRep.addCrust(crust);
    return true;
}

bool ManagerDomain::addTopping(const Topping &topping) {
    vector<Topping>toppings = managerRep.getTopping();
    for (unsigned int i = 0; i < toppings.size(); i++) {
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
    for (unsigned int i = 0; i < drinks.size(); i++) {
        if (drinks[i].getName() == drink.getName()) {
            if (drinks[i].getLiter() == drink.getLiter()) {
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
    for (unsigned int i = 0; i < sidedishes.size(); i++) {
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
    for (unsigned int i = 0; i < branches.size(); i++) {
        if (branches[i].getName() == branch.getName()) {
            throw ItemExistsException();
        }
    }
    managerRep.addBranch(branch);
    return true;
}

bool ManagerDomain::addUser(const User &user) {
    vector<User> users = managerRep.getUser();
    for (unsigned int i = 0; i < users.size(); i++) {
        if (users[i].getName() == user.getName()) {
            users[i] = user;
            managerRep.changeUsersList(users);
            throw ItemChangedException();
        }
    }
    managerRep.addUser(user);
    return true;
}


vector<Pizza> ManagerDomain::getPizzas() {
    vector<Pizza>pizzas = managerRep.getPizza();
    return pizzas;
}

vector<Crust> ManagerDomain::getCrusts() {
    vector<Crust>crusts = managerRep.getCrust();
    return crusts;
}

vector<Topping> ManagerDomain::getToppings() {
    vector<Topping>toppings = managerRep.getTopping();
    return toppings;
}

vector<Drink> ManagerDomain::getDrinks() {
    vector<Drink>drinks = managerRep.getDrink();
    return drinks;
}

vector<Sidedish> ManagerDomain::getSidedishes() {
    vector<Sidedish>sidedishes = managerRep.getSidedish();
    return sidedishes;
}

vector<Branch> ManagerDomain::getBranches() {
    vector<Branch>branches = managerRep.getBranch();
    return branches;
}

vector<User> ManagerDomain::getUsers() {
    vector<User>users = managerRep.getUser();
    return users;
}

vector<Order> ManagerDomain::getLegacyBranchOrders(const string &branch) {
    vector<Order>orders = managerRep.getLegacyOrder();
    vector<Order>branchOrders;
    if (branch.empty()) {
        return orders;
    }
    for (unsigned int i = 0; i < orders.size(); i++) {
        if (orders[i].getBranch() == branch) {
            branchOrders.push_back(orders[i]);
        }
    }
    return branchOrders;
}

vector<Order> ManagerDomain::getFailedBranchOrders(const string &branch) {
    vector<Order>orders = managerRep.getWaterlooOrder();
    vector<Order>branchOrders;
    if (branch.empty()) {
        return orders;
    }
    for (unsigned int i = 0; i < orders.size(); i++) {
        if (orders[i].getBranch() == branch) {
            branchOrders.push_back(orders[i]);
        }
    }
    return branchOrders;
}

vector<Order> ManagerDomain::getDateFromOrders(const string &dateFrom, vector<Order> branchOrders) {
    vector<Order>dateFromOrders;
    if (dateFrom.empty()) {
        return branchOrders;
    }

    char date[11];
    time_t result = 0;
    int year = 0, month = 0, day = 0;
    strcpy(date, dateFrom.c_str());

    sscanf(date, "%2d.%2d.%4d", &day, &month, &year);
    struct tm breakdown = {0};
    breakdown.tm_year = year - 1900;
    breakdown.tm_mon = month - 1;
    breakdown.tm_mday = day;

    result = mktime(&breakdown);

    for (unsigned int i = 0; i < branchOrders.size(); i++) {
        if (difftime( branchOrders[i].getTime(), result) > 0) {
            dateFromOrders.push_back(branchOrders[i]);
        }
    }
    return dateFromOrders;
}

vector<Order> ManagerDomain::getDateToOrders(const string &dateTo, vector<Order> dateFromOrders) {
    vector<Order>dateToOrders;
    if (dateTo.empty()) {
        return dateFromOrders;
    }

    char date[11];
    time_t result = 0;
    int year = 0, month = 0, day = 0;
    strcpy(date, dateTo.c_str());

    //////////////////////////////////////////
    sscanf(date, "%2d.%2d.%4d", &day, &month, &year);
    struct tm breakdown = {0};
    breakdown.tm_year = year - 1900;
    breakdown.tm_mon = month - 1;
    breakdown.tm_mday = day;

    result = mktime(&breakdown);
    //////////////////////////////////////////
    result += 86399;     //add 23 hours, 59 minutes and 59 seconds

    for (unsigned int i = 0; i < dateFromOrders.size(); i++) {
        if (difftime( dateFromOrders[i].getTime(), result) < 0) {
            dateToOrders.push_back(dateFromOrders[i]);
        }
    }
    return dateToOrders;
}

bool ManagerDomain::removePizza(const Pizza &pizza) {
    vector<Pizza>pizzas = managerRep.getPizza();
    vector<Pizza>newPizzas;

    for (unsigned int i = 0; i < pizzas.size(); i++) {
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

    for (unsigned int i = 0; i < crusts.size(); i++) {
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

    for (unsigned int i = 0; i < toppings.size(); i++) {
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

    for (unsigned int i = 0; i < drinks.size(); i++) {
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

    for (unsigned int i = 0; i < sidedishes.size(); i++) {
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

    for (unsigned int i = 0; i < branches.size(); i++) {
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
    if (user.getName() == "admin"){
        throw CantDeleteException();
    }
    vector<User>users = managerRep.getUser();
    vector<User>newUsers;

    for (unsigned int i = 0; i < users.size(); i++) {
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


bool ManagerDomain::checkTopping(const Topping &topping) {
    vector<Topping> toppings = managerRep.getTopping();

    for (unsigned int i = 0; i < toppings.size(); i++) {
        if (toppings[i].getName() == topping.getName()) {
            return true;
        }
    }
    throw NotFoundException();
}


bool ManagerDomain::checkValidName(const string &name) {
    if(name.length() > 15) {
        throw LengthNotRightException();
    }
    for(unsigned int i = 0; i < name.length(); i++){
        if(isdigit(name[i])){
             throw InvalidInputException();
        }
    }
    return true;
}

int ManagerDomain::checkValidPrice(const string &price) {

    int price1 = 0;
    for(unsigned int i = 0; i < price.length(); i++) {
        if(isalpha(price[i])){
            throw InvalidInputException();
        }
    }

    price1 = atoi(price.c_str());
    if(price1 < 0 || price1 > 99999){
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
     if (job == "1" || job == "2" || job == "3" || job == "4") {
        return true;
    }

    throw InvalidInputException();
    return false;
}

bool ManagerDomain::checkValidBranch(const string &branch) {
    vector<Branch>branches = managerRep.getBranch();
    for (unsigned int i = 0; i < branches.size(); i++) {
        if (branches[i].getName() == branch) {
            return true;
        }
    }
    throw NotFoundException();
    return false;
}

bool ManagerDomain::checkValidDate(const string &date) {

    if (date.length() != 10) {
        throw LengthNotRightException();
    }
    if (date[2] != '.' || date[5] != '.') {
        throw InvalidInputException();
    }
    string d = (date.substr(0,2));
    string m = (date.substr(3,2));
    string y = (date.substr(6,4));

    int day = atoi(d.c_str());
    int month = atoi(m.c_str());
    int year = atoi(y.c_str());

    if (day < 1 || day > 31) {
        throw InvalidInputException();
    }
    if (month < 1 || month > 12) {
        throw InvalidInputException();

    }
    if (year < 1970) {
        throw InvalidDateException();
    }

    return true;
}

void ManagerDomain::toLowerCase(string &name) {
    for (unsigned int i = 0; i < name.length(); i++) {
        if(name[i] != ' ' && isupper(name[i])) {
            name[i] = tolower(name[i]);
        }
    }
}
