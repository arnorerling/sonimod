#ifndef BAKERDOMAIN_H
#define BAKERDOMAIN_H
#include "BakerRep.h"
#include "LengthNotRightException.h"
#include "InvalidInputException.h"
#include "NotFoundException.h"
#include "NotMarkedInProcessException.h"
#include "AlreadyMarkedException.h"
#include "md5.h"

class BakerDomain
{
    private:
        BakerRep bakerRep;

    public:
        BakerDomain();
        //Turns uppercase to lowercase
        void toLowerCase(string &name);

        vector<Branch> getBranch();
        vector<Order> getOrders(const string &branch);

        Order getOneOrder(const string &number, const string &branch);

        void markOrderInProcess(const Order &order);
        void markOrderReady(const Order &order);
        void deleteOrder(const Order &order);

        bool checkBranchAvaliability(string &branchName);
        bool checkValidName(const string &name);
        bool checkValidInput(const string &input);
        bool isValidNumber(const string num);

};

#endif // BAKERDOMAIN_H
