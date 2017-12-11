#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include <iostream>
#include <ctime>
#include "Pizza.h"
#include "Drink.h"
#include "Sidedish.h"
#include "Branch.h"

using namespace std;

class Order {
    private:
        vector<Pizza> pizzas;
        vector<Drink> drinks;
        vector<Sidedish> sideDishes;

        string customerName;
        string phoneNumber;
        string customerAddress;
        string branch;

        bool paidFor;
        bool inProcess;
        bool ready;
        bool deliverd;
        bool pickup;
        time_t orderTime;

        int totalPrice;

    public:
        Order();

        void addPizza(Pizza& pizza);
        void addSideDish(Sidedish& sidedish);
        void addDrink(Drink& drink);

        void addCustomerName(const string &name);
        void addCustomerPhoneNum(const string &num);
        void addCustomerAddress(const string &address);
        void addBranch(const string &branch);

        void setPaidFor(bool paidFor);
        void setInProcess(bool inProcess);
        void setReady(bool ready);
        void setDeliverd(bool deliverd);
        void setPickup(bool pickup);
        void setTime();

        string getCustomerName() const;
        string getCustomerPhoneNumber() const;
        string getCustomerAddress() const;
        string getBranch() const;
        time_t getTime() const;
        int getTotal() const;
        bool getPaidFor() const;
        bool getInProcess() const;
        bool getReady() const;
        bool getDeliverd() const;
        bool getPickup() const;

        void cleanOrder();

        friend ostream& operator << (ostream& out, const Order& order);
        friend bool operator == (const Order &left_order, const Order &right_order);
        friend bool operator != (const Order &left_order, const Order &right_order);

        void write(ofstream& fout) const;
        void read(ifstream& fin);
};

#endif // ORDER_H
