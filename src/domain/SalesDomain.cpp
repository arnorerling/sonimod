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

bool SalesDomain::checkDrinkAvaliability(const vector<Drink>& drinks, Drink& drink){
    for(unsigned int i = 0; i < drinks.size(); i++){
        if(drinks[i].getName() == drink.getName() && drinks[i].getLiter() == drink.getLiter()){
            drink.setPrice(drinks[i].getPrice());
            return true;
        }
    }
    return false;
}

bool SalesDomain::checkSidedishAvaliability(const vector<Sidedish>& sidedishes, Sidedish& sidedish){
    for(unsigned int i = 0; i < sidedishes.size(); i++){
        if(sidedishes[i].getName() == sidedish.getName()){
            sidedish.setPrice(sidedishes[i].getPrice());
            return true;
        }
    }
    return false;
}

bool SalesDomain::checkToppingAvaliability(const vector<Topping>& toppings, Topping& topping){
    for(unsigned int i = 0; i < toppings.size(); i++){
        if(toppings[i].getName() == topping.getName()){
            topping.setPrice(toppings[i].getPrice());
            return true;
        }
    }
    return false;
}

bool SalesDomain::checkCrustAvaliability(const vector<Crust>& crusts, Crust& crust){
    for(unsigned int i = 0; i < crusts.size(); i++){
        if(crusts[i].getName() == crust.getName() && crusts[i].getInches() == crust.getInches()){
            crust.setPrice(crusts[i].getPrice());
            return true;
        }
    }
    return false;
}

