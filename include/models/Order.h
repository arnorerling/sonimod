#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include <iostream>
#include <Pizza.h>
#include <Drink.h>
#include <Sidedish.h>

using namespace std;

class Order {
    private:
        vector<Pizza> pizzas;
        vector<Drink> drinks;
        vector<Sidedish> sideDishes;
        int totalPrice;
    public:
        Order();
        void addPizza(Pizza& pizza);
        void addSideDish(Sidedish& sidedish);
        void addDrink(Drink& drink);
        friend ostream& operator << (ostream& out, Order& order);
        int getTotal();


};

#endif // ORDER_H
