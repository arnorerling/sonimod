#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include <iostream>
#include "Pizza.h"
#include "Drink.h"
#include "Sidedish.h"
#include "Branch.h"

using namespace std;

class Order {
    private:
        string custumerName;
        string phoneNumber;
        Branch branch;

        vector<Pizza> pizzas;
        vector<Drink> drinks;
        vector<Sidedish> sideDishes;

        int totalPrice;
        bool paidFor;
        bool ready;
        bool deliverd;

    public:
        Order();
        string getCustomerName();
        string getCustomerPhoneNumber();
        void addPizza(Pizza& pizza);
        void addSideDish(Sidedish& sidedish);
        void addDrink(Drink& drink);
        void addCustomerName(string name);
        void addCustomerPhoneNum(string num);
        friend ostream& operator << (ostream& out, Order& order);
        int getTotal();


};

#endif // ORDER_H
