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
        void getBranch(vector<Branch> &branch);
        void getOrder(vector<Order> &order);
        void ChangeOrderList(vector<Order> &orders);
        void addReadyOrder(Order &order);

};

#endif // BAKERREP_H
