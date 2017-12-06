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
bool SalesDomain::isValidName(string name){
    for(unsigned int i = 0; i < name.length(); i++){
        if(isdigit(name[i])){
             throw InvalidNameException();
        }
    }
    return true;
}
bool SalesDomain::isValidPhoneNumber(string num){
    for(unsigned int i = 0; i < num.length(); i++){
        if(!isdigit(num[i]) || num.length() != 7){
             throw InvalidPhoneNumberException();
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
            throw SizeNotAvailableException();
        }
    }
    throw DrinkNotAvailableException();
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
    throw SideDishNotAvailableException();
}

bool SalesDomain::checkToppingAvailability(Topping& topping){
    vector<Topping> toppings;
    getToppings(toppings);
    for(unsigned int i = 0; i < toppings.size(); i++){
        if(toppings[i].getName() == topping.getName()){
            topping.setPrice(toppings[i].getPrice());
            return true;
        }
    }
    throw ToppingNotAvailableException();
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
    throw CrustNotAvailableException();
}

void SalesDomain::fileOrder(Order &order){
    salesRep.fileOrder(order);
}

