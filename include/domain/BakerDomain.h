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
        void toLowerCase(string &name);

    public:
        BakerDomain();
        //get all restaurant branches
        vector<Branch> getBranch();
        //gets all orders and returns the ones that aren't ready
        vector<Order> getOrders(const string &branch);
        //get one order based on the number and branch
        Order getOneOrder(const string &number, const string &branch);

        //mark an order in process
        void markOrderInProcess(const Order &order);
        //mark and order ready
        void markOrderReady(const Order &order);
        //deletes an order
        void deleteOrder(const Order &order);

        //checks if restaurant branch is in the list
        bool checkBranchAvaliability(string &branch);
         //checks if a number is valid (7 digits)
        bool checkValidNumber(const string &num);
        //checks if input is valid (1 digit)
        bool checkValidInput(const string &input);

};

#endif // BAKERDOMAIN_H
