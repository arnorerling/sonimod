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
        ///Basic constructor, sets all variables to 0

        Topping addTopping();
        ///Sets 'toppings[currentToppingNum]' to be the parameter 'topping'

        Crust addCrust();

        void displayPizza(Pizza& pizza);

        friend ostream& operator << (ostream& out, const Pizza& pizza);
        ///Overloads the '<<' operator to print the number of toppings, followed by
        ///a list of the pizzas topping (and their corresponding prices)

        friend istream& operator >> (istream& in, Pizza& pizza);
        ///Overloads the '>>' operator to request input of the number of toppings,
        ///it then calls 'void initialize' with the input as a parameter.
        ///Then it loops 'toppingCount' times and requests input of each topping and it's price

        int getPrice();

        void addPizza();
};

#endif // PIZZA_H

