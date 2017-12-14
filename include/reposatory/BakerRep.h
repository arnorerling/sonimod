#ifndef BAKERREP_H
#define BAKERREP_H

#include "FileNotOpenException.h"
#include "Branch.h"
#include "Order.h"
#include <fstream>
#include <vector>

class BakerRep
{
    private:

    public:
        BakerRep();
        //returns all branch classes from a file
        vector<Branch> getBranches();
        //returns all order classes from a file
        vector<Order> getOrders();

        //overwrites a file with a vector of order classes
        void changeOrderList(vector<Order> &orders);
};

#endif // BAKERREP_H
