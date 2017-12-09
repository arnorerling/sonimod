#ifndef BAKERREP_H
#define BAKERREP_H
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
        void addOrderReady(Order &order);
};

#endif // BAKERREP_H
