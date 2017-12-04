#ifndef PIZZA_H
#define PIZZA_H

#include "Topping.h"
#include "Crust.h"
#include <iostream>
#include <vector>
#include <string>

class Pizza {

    private:
        vector<Topping> toppings;
        Crust crust;
        int price;

    public:
        Pizza();
        Pizza(vector<Topping> toppings, Crust crust);
        void setPrice();
        int getPrice();


};

#endif // PIZZA_H

