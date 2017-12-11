#ifndef BAKERDOMAIN_H
#define BAKERDOMAIN_H
#include <iostream>
#include "BakerRep.h"
#include "Branch.h"
#include "NotFoundException.h"
#include "InvalidInputException.h"
#include "MarkedInProcessException.h"
#include "MarkedReadyException.h"
#include "AlreadyMarkedException.h"
#include "NotMarkedInProgressException.h"

using namespace std;

class BakerDomain
{
    private:
        BakerRep bakerRep;

    public:
        BakerDomain();
        void toLowerCase(string &name);

        vector<Branch> getBranch();
        vector<Order> getOrders(const string &branch);
        Order getOneOrder(const string &number, const string &branch);

        bool markOrderInProcess(const Order &order);
        bool markOrderReady(const Order &order);
        bool markOrderPaidFor(const Order &order);

        bool checkBranchAvaliability(string &branchName);
        bool checkValidName(const string &name);
        bool checkValidInput(const string &input);
        bool isValidNumber(const string num);

};

#endif // BAKERDOMAIN_H
