#include "Pizza.h"
using namespace std;

Pizza::Pizza() {
    price = 0;
}
Pizza::Pizza(vector<Topping> toppings, Crust crust){
    this->toppings = toppings;
    this->crust = crust;
    setPrice();

}
void Pizza::setPrice(){
    for(unsigned int i = 0;this->toppings.size(); i++){
        this->price += this->toppings[i].getPrice();
    }
    this->price += this->crust.getPrice();
}

int Pizza::getPrice(){
    return this->price;
}


