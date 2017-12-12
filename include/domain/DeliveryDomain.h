#ifndef DELIVERYDOMAIN_H
#define DELIVERYDOMAIN_H
#include <iostream>
#include "DeliveryRep.h"
#include "Branch.h"
#include "Order.h"
#include "InvalidInputException.h"
#include "NotFoundException.h"
#include "NotMarkedReadyException.h"
#include "MarkedPaidForException.h"
#include "NotMarkedPaidForException.h"
using namespace std;


class DeliveryDomain
{
    private:
        DeliveryRep deliveryRep;

    public:
        DeliveryDomain();
        vector<Branch> getBranch();
        vector<Order> getOrders(const string &branch);
        vector<Order> getReadyOrders(const string& branch);
        Order getOneOrder(const string &number, const string &branch);

        void markOrderPaidFor(const Order &order);
        void markOrderDelivered(Order &order);
        void deleteOrder(const Order &order);

        bool checkBranchAvaliability(const string &branch);
        bool checkValidNumber(const string num);
        bool checkValidName(const string &name);
        bool checkValidInput(const string &input);
        void toLowerCase(string &name);
};

#endif // DELIVERYDOMAIN_H
