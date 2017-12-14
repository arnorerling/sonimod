#ifndef SALESREP_H
#define SALESREP_H

#include <fstream>
#include <vector>
#include <string>
#include "Drink.h"
#include "Sidedish.h"
#include "Pizza.h"
#include "Order.h"
#include "FileNotOpenException.h"
#include "CrustFileNotFoundException.h"

using namespace std;

class SalesRep
{

    private:

    public:
        // Constructor
        SalesRep();

        //takes vectors from the domain and filles them up
        vector<Drink> getDrinks();
        vector<Sidedish> getSidedishes();
        vector<Pizza> getPizzas();
        vector<Topping> getToppings();
        vector<Crust> getCrusts();
        vector<Branch> getBranches();

        //writes the current order to orders_binary
        void fileOrder(Order& order);

};

#endif // SALESREP_H
