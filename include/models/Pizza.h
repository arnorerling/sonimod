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
        ///Basic constructor, sets all variables to 0
        Pizza(string &name, vector<Topping> &toppings, Crust &crust, int &price);

        void write(ofstream& fout) const;
        void read(ifstream& fin);

        void addTopping(Topping topping);
        ///Sets 'toppings[currentToppingNum]' to be the parameter 'topping'

        void addCrust(Crust crust);

        void displayPizza(Pizza& pizza);

        friend ostream& operator << (ostream& out, const Pizza& pizza);
        ///Overloads the '<<' operator to print the number of toppings, followed by
        ///a list of the pizzas topping (and their corresponding prices)

        void addPizza();

        void setPrice();
        int getPrice();
};

#endif // PIZZA_H

