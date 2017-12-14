#ifndef DELIVERYDOMAIN_H
#define DELIVERYDOMAIN_H


#include "DeliveryRep.h"

#include "LengthNotRightException.h"
#include "InvalidInputException.h"
#include "NotFoundException.h"
#include "NotMarkedReadyException.h"
#include "NotMarkedPaidForException.h"
#include "AlreadyMarkedException.h"

class DeliveryDomain
{
    private:
        DeliveryRep deliveryRep;
        void toLowerCase(string &name);

    public:
        // Constructor
        DeliveryDomain();

        //gets all restaurant branches
        vector<Branch> getBranch();
        //get all orders
        vector<Order> getOrders(const string &branch);
        //get only ready orders
        vector<Order> getReadyOrders(const string& branch);

        //gets an order based on phone number and branch
        Order getOneOrder(const string &number, const string &branch);

        //marks an order paid for
        void markOrderPaidFor(const Order &order);
        //marks an order delivered and filed to legacy file
        void markOrderDelivered(Order &order);
        //deletes an order
        void deleteOrder(const Order &order);

        //checks if a branch is in a file
        bool checkBranchAvaliability(string &branch);
        //checks if a number is valid (7 digits)
        bool checkValidNumber(const string &num);
        //checks if input is valid (one digit)
        bool checkValidInput(const string &input);

};

#endif // DELIVERYDOMAIN_H
