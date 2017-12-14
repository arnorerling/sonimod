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
        //constructors
        Pizza();
        Pizza(string &name);
        Pizza(string &name, vector<Topping> &toppings, Crust &crust, int &price);

        //reads and writes into files
        void write(ofstream& fout) const;
        void read(ifstream& fin);

        //overwrites cout operator for pizza class
        friend ostream& operator << (ostream& out, const Pizza& pizza);
        //checks if two pizzas have the same name and size
        friend bool operator == (const Pizza &left_pizza, const Pizza &right_pizza);

        //adds to private variables
        void addTopping(const Topping &topping);
        void addCrust(const Crust &crust);
        //sets private variables
        void setName(const string &name);
        void setFixedPrice(const int &price);
        void setPrice();

        //gets private variables
        string getName() const;
        string getCrustName() const;
        int getPrice() const;
        int getCrustSize() const;
        Topping getTopping() const;
        Crust getCrust() const;
};

#endif // PIZZA_H

