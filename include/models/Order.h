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
        string branch;

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
        string getBranch();
        void addPizza(Pizza& pizza);
        void addSideDish(Sidedish& sidedish);
        void addDrink(Drink& drink);
        void addCustomerName(string name);
        void addCustomerPhoneNum(string num);
        void addBranch(string branch);
        friend ostream& operator << (ostream& out, Order& order);
        int getTotal();
        void write(ofstream& fout) const;
        void read(ifstream& fin);



};

#endif // ORDER_H
