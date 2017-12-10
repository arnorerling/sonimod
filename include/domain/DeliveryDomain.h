#ifndef DELIVERYDOMAIN_H
#define DELIVERYDOMAIN_H
#include <iostream>
#include "DeliveryRep.h"
#include "Branch.h"
#include "Order.h"
#include "InvalidInputException.h"
#include "NotFoundException.h"
using namespace std;


class DeliveryDomain
{
    private:
        DeliveryRep deliveryRep;

    public:
        DeliveryDomain();
        vector<Branch> getBranch();
        vector<Order> getReadyOrders();
        bool checkBranchAvaliability(const string &branch);

        bool checkValidName(const string &name);
        bool checkValidInput(const string &input);
        bool isValidNumber(const string num);
        void toLowerCase(string &name);
};

#endif // DELIVERYDOMAIN_H
