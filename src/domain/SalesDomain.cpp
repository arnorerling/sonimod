#include "SalesDomain.h"

SalesDomain::SalesDomain() {
    //ctor
}

vector<Drink> SalesDomain::getDrinks() {
    vector<Drink> drinks = salesRep.getDrinks();
    if(drinks.size() == 0){
        throw LengthNotRightException();
    }
    return drinks;
}

vector<Sidedish> SalesDomain::getSidedishes() {
    vector<Sidedish> sidedishes = salesRep.getSidedishes();
    if(sidedishes.size() == 0){
        throw LengthNotRightException();
    }
    return sidedishes;

}

vector<Pizza> SalesDomain::getPizzas() {
    vector<Pizza> pizzas = salesRep.getPizzas();
    if(pizzas.size() == 0){
        throw LengthNotRightException();
    }
    return pizzas;
}

vector<Topping> SalesDomain::getToppings() {
    vector<Topping> toppings = salesRep.getToppings();
    if(toppings.size() == 0){
        throw LengthNotRightException();
    }
    return toppings;
}

vector<Crust> SalesDomain::getCrusts() {
    vector<Crust> crusts = salesRep.getCrusts();
    if(crusts.size() == 0){
        throw LengthNotRightException();
    }
    return crusts;
}

vector<Branch> SalesDomain::getBranches() {
    vector<Branch> branches = salesRep.getBranches();
    if(branches.size() == 0){
        throw LengthNotRightException();
    }
    return branches;
}

void SalesDomain::fileOrder(Order &order) {
    salesRep.fileOrder(order);
}

bool SalesDomain::markOrderPaidFor(Order &order) {
    if (order.getPaidFor()) {
        throw AlreadyMarkedException();
    }
    else {
        order.setPaidFor(true);
        return true;
    }
}

bool SalesDomain::checkPizzaAvailability(const string &name, int size, Pizza &pizza) {
    vector<Pizza> pizzas = this->getPizzas();
    Crust crust = pizza.getCrust();
    for(unsigned int i = 0; i < pizzas.size(); i++) {
        if(pizzas[i].getName() == name && pizzas[i].getCrustSize() == size) {
            pizza = pizzas[i];
            pizza.addCrust(crust);
            pizza.setFixedPrice(pizzas[i].getPrice());
            return true;
        }
    }
    throw NotFoundException();
}

bool SalesDomain::checkDrinkAvailability(Drink& drink) {
    vector<Drink> drinks = this->getDrinks();
    for(unsigned int i = 0; i < drinks.size(); i++) {
        if(drinks[i].getName() == drink.getName()) {
            for(unsigned int i = 0; i < drinks.size(); i++) {
                if(drinks[i].getName() == drink.getName() && drinks[i].getLiter() == drink.getLiter()) {
                    drink.setPrice(drinks[i].getPrice());
                    return true;
                }
            }
            throw NotFoundException();
        }
    }
    throw NotFoundException();
}

bool SalesDomain::checkSidedishAvailability(Sidedish& sidedish) {
    vector<Sidedish> sidedishes = getSidedishes();
    for(unsigned int i = 0; i < sidedishes.size(); i++) {
        if(sidedishes[i].getName() == sidedish.getName()) {
            sidedish.setPrice(sidedishes[i].getPrice());
            return true;
        }
    }
    throw NotFoundException();
}

void SalesDomain::checkToppingAvailability(Topping& topping) {
    bool available = false;
    vector<Topping> toppings = getToppings();
    for(unsigned int i = 0; i < toppings.size(); i++) {
        if(toppings[i].getName() == topping.getName()) {
            topping.setPrice(toppings[i].getPrice());
            available = true;
        }
    }
    if(!available){
        throw NotFoundException();
    }
}

bool SalesDomain::checkCrustAvailability(Crust& crust) {
    vector<Crust> crusts = getCrusts();
    for(unsigned int i = 0; i < crusts.size(); i++) {
        if(crusts[i].getName() == crust.getName() && crusts[i].getInches() == crust.getInches()) {
            crust.setPrice(crusts[i].getPrice());
            return true;
        }
    }
    throw NotFoundException();
}

bool SalesDomain::checkBranchAvailability(const string &branch) {
    vector<Branch> branches = getBranches();
    for(unsigned int i = 0; i < branches.size(); i++) {
        if(branches[i].getName() == branch) {
            return true;
        }
    }
    throw NotFoundException();
}

void SalesDomain::checkOrder(const Order &order) {
    if(order.getOrderSize() == 0) {
        throw CantFileOrderException();
    }
}


bool SalesDomain::checkValidAnswer(const string &answer) {
    if(answer == "y" || answer == "n") {
        return true;
    }
    throw InvalidInputException();
    return false;
}

bool SalesDomain::checkValidName(const string &name) {
    for(unsigned int i = 0; i < name.length(); i++) {
        if(isdigit(name[i])) {
             throw InvalidInputException();
        }
    }
    return true;
}

bool SalesDomain::checkValidPhoneNumber(const string &num) {
    vector<Order> orders = salesRep.getOrders();
    for(unsigned int i = 0; i < num.length(); i++) {
        if(!isdigit(num[i]) || num.length() != 7) {
             throw InvalidInputException();
        }
    }
    for (unsigned int i = 0; i < orders.size(); i++) {
        if (orders[i].getCustomerPhoneNumber() == num) {
            throw AlreadyMarkedException();
        }
    }
    return true;
}

int SalesDomain::checkValidSize(const string &number) {
    for (unsigned int i = 0; i < number.length(); i++) {
        if(!isdigit(number[i])) {
            throw InvalidInputException();
        }
    }
    int number1 = atoi(number.c_str());
    return number1;
}

bool SalesDomain::checkValidInput(const string &input) {
    if (input.length() == 1) {
      return true;
    }
    throw InvalidInputException();
    return false;
}

void SalesDomain::toLowerCase(string &str) {
    for (unsigned int i = 0; i < str.length(); i++) {
        if(str[i] != ' ' && isupper(str[i])) {
            str[i] = tolower(str[i]);
        }
    }
}
