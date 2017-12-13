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
        vector<Branch> getBranch();
        vector<Order> getOrders();

        void changeOrderList(vector<Order> &orders);
};

#endif // BAKERREP_H
