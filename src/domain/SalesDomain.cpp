#include "SalesDomain.h"

SalesDomain::SalesDomain() {
    //ctor
}

void SalesDomain::getDrinks(vector<Drink>& drinks) {
    salesRep.getDrinks(drinks);
}

void SalesDomain::getSidedishes(vector<Sidedish>& sidedishes) {
    salesRep.getSidedishes(sidedishes);
}

void SalesDomain::getPizzas(vector<Pizza>& pizzas) {
    salesRep.getPizzas(pizzas);
}

void SalesDomain::getToppings(vector<Topping>& toppings){
    salesRep.getToppings(toppings);
}

void SalesDomain::getCrusts(vector<Crust>& crusts){
    salesRep.getCrust(crusts);
}

void SalesDomain::getBranches(vector<Branch>& branches){
    salesRep.getBranches(branches);
}

bool SalesDomain::isValidName(string name){
    for(unsigned int i = 0; i < name.length(); i++){
        if(isdigit(name[i])){
             throw InvalidInputException();
        }
    }
    return true;
}
bool SalesDomain::isValidPhoneNumber(string num){
    for(unsigned int i = 0; i < num.length(); i++){
        if(!isdigit(num[i]) || num.length() != 7){
             throw InvalidInputException();
        }
    }
    return true;
}
bool SalesDomain::checkDrinkAvailability(Drink& drink){
    vector<Drink> drinks;
    getDrinks(drinks);
    for(unsigned int i = 0; i < drinks.size(); i++){
        if(drinks[i].getName() == drink.getName()){
            for(unsigned int i = 0; i < drinks.size(); i++){
                if(drinks[i].getName() == drink.getName() && drinks[i].getLiter() == drink.getLiter()){
                    drink.setPrice(drinks[i].getPrice());
                    return true;
                }
            }
            throw NotFoundException();
        }
    }
    throw NotFoundException();
}

bool SalesDomain::checkSidedishAvailability(Sidedish& sidedish){
    vector<Sidedish> sidedishes;
    getSidedishes(sidedishes);
    for(unsigned int i = 0; i < sidedishes.size(); i++){
        if(sidedishes[i].getName() == sidedish.getName()){
            sidedish.setPrice(sidedishes[i].getPrice());
            return true;
        }
    }
    throw NotFoundException();
}

void SalesDomain::checkToppingAvailability(Topping& topping){
    bool available = false;
    vector<Topping> toppings;
    getToppings(toppings);
    for(unsigned int i = 0; i < toppings.size(); i++){
        if(toppings[i].getName() == topping.getName()){
            topping.setPrice(toppings[i].getPrice());
            available = true;
        }
    }
    if(!available){
        throw NotFoundException();
    }
}

bool SalesDomain::checkCrustAvailability(Crust& crust){
    vector<Crust> crusts;
    getCrusts(crusts);
    for(unsigned int i = 0; i < crusts.size(); i++){
        if(crusts[i].getName() == crust.getName() && crusts[i].getInches() == crust.getInches()){
            crust.setPrice(crusts[i].getPrice());
            return true;
        }
    }
    throw NotFoundException();
}

bool SalesDomain::checkBranchAvailability(string branch){
    vector<Branch> branches;
    getBranches(branches);
    for(unsigned int i = 0; i < branches.size(); i++){
        if(branches[i].getName() == branch){
            return true;
        }
    }
    throw NotFoundException();
}

void SalesDomain::fileOrder(Order &order){
    salesRep.fileOrder(order);
}

void SalesDomain::checkYesOrNo(string check){
    if(check.length() != 1){
        throw LengthNotRightException();
    }
    if(check != "y" && check != "n"){
        throw InvalidInputException();
    }
}

