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
        string customerName;
        string phoneNumber;
        string customerAddress;
        string branch;

        vector<Pizza> pizzas;
        vector<Drink> drinks;
        vector<Sidedish> sideDishes;

        int totalPrice;
        bool paidFor;
        bool inProcess;
        bool ready;
        bool deliverd;
        bool pickup;

    public:
        Order();
        string getCustomerName() const;
        string getCustomerPhoneNumber() const;
        string getCustomerAddress() const;
        string getBranch() const;

        void addPizza(Pizza& pizza);
        void addSideDish(Sidedish& sidedish);
        void addDrink(Drink& drink);

        void addCustomerName(string name);
        void addCustomerPhoneNum(string num);
        void addCustomerAddress(string address);
        void addBranch(string branch);

        void setPaidFor(bool paidFor);
        void setInProcess(bool inProcess);
        void setReady(bool ready);
        void setDeliverd(bool deliverd);
        void setPickup(bool pickup);

        bool getPaidFor() const;
        bool getInProcess() const;
        bool getReady() const;
        bool getDeliverd() const;
        bool getPickup() const;

        friend ostream& operator << (ostream& out, Order& order);
        friend bool operator == (const Order &left_order, const Order &right_order);
        friend bool operator != (const Order &left_order, const Order &right_order);
        int getTotal();
        void write(ofstream& fout) const;
        void read(ifstream& fin);



};

#endif // ORDER_H
