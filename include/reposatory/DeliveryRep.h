#ifndef DELIVERYREP_H
#define DELIVERYREP_H

#include "FileNotOpenException.h"
#include "Branch.h"
#include "Order.h"
#include <fstream>
#include <vector>

class DeliveryRep
{
    private:

    public:
        // Constructor
        DeliveryRep();

        //returns all branch classes from a file
        vector<Branch> getBranches();
        //returns all order classes from a file
        vector<Order> getOrders();

        //overwrites a file with a vector of order classes
        void changeOrderList(vector<Order> &orders);

        //adds delivered orders to legacy file
        void addToLegacy(Order &order);
        //adds failed orders to waterloo file
        void addToWaterloo(Order &order);

};

#endif // DELIVERYREP_H
