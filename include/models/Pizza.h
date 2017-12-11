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
        Pizza(string &name);
        Pizza(string &name, vector<Topping> &toppings, Crust &crust, int &price);

        void write(ofstream& fout) const;
        void read(ifstream& fin);

        friend ostream& operator << (ostream& out, const Pizza& pizza);
        friend bool operator == (const Pizza &left_pizza, const Pizza &right_pizza);

        void addTopping(const Topping &topping);
        void addCrust(const Crust &crust);

        void setName(const string &name);
        void setFixedPrice(const int &price);
        void setPrice();

        string getName() const;
        int getPrice() const;
        int getCrustSize() const;
};

#endif // PIZZA_H

