#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include <string>
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
        string comment;

        bool paidFor;
        bool inProcess;
        bool ready;
        bool deliverd;
        bool pickup;
        time_t orderTime;

        int totalPrice;

    public:
        Order();

        //adds to private variables
        void addPizza(Pizza& pizza);
        void addSideDish(Sidedish& sidedish);
        void addDrink(Drink& drink);
        void addCustomerName(const string &name);
        void addCustomerPhoneNum(const string &num);
        void addCustomerAddress(const string &address);
        void addBranch(const string &branch);
        void addComment(string comment);

        //sets private variables
        void setPaidFor(bool paidFor);
        void setInProcess(bool inProcess);
        void setReady(bool ready);
        void setDeliverd(bool deliverd);
        void setPickup(bool pickup);
        void setTime();
        void setTotal();

        //gets private variables
        string getCustomerName() const;
        string getCustomerPhoneNumber() const;
        string getCustomerAddress() const;
        string getBranch() const;
        string getTimeString() const;
        time_t getTime() const;
        bool getPaidFor() const;
        bool getInProcess() const;
        bool getReady() const;
        bool getDeliverd() const;
        bool getPickup() const;
        int getTotalPrice() const;
        int getOrderSize() const;

        //deletes everything from order
        void cleanOrder();
        //overwrites cout operator for order class
        friend ostream& operator << (ostream& out, const Order& order);
        //checks if two orders have the same phone numbers and branch
        friend bool operator == (const Order &left_order, const Order &right_order);
        //checks if two orders dont have the same phone number or branch
        friend bool operator != (const Order &left_order, const Order &right_order);

        //reads and writes into files
        void write(ofstream& fout) const;
        void read(ifstream& fin);
};

#endif // ORDER_H
