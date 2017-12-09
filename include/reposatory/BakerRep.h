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
        Order getOneOrder(const string &number, const string &branch);
        void ChangeOrderList(vector<Order> &orders);
        void addReadyOrder(Order &order);

};

#endif // BAKERREP_H
