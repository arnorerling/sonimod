#ifndef PIZZA_H
#define PIZZA_H

#include "Topping.h"
#include "Crust.h"
#include <iostream>
#include <vector>
#include <string>

class Pizza {

    private:
        string name;
        vector<Topping> toppings;
        Crust crust;
        int price;

    public:
        Pizza();
<<<<<<< HEAD
        ///Basic constructor, sets all variables to 0
        Pizza(string &name, vector<Topping> &toppings, Crust &crust, int &price);

        /*Topping addTopping();
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

        void addPizza();*/


=======
        Pizza(vector<Topping> toppings, Crust crust);
        void setPrice();
        int getPrice();


>>>>>>> afdc87cafd30aff0bb023ca10c658deeb2b6737d
};

#endif // PIZZA_H

