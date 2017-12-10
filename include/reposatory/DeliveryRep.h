#ifndef DELIVERYREP_H
#define DELIVERYREP_H
#include "Branch.h"
#include "Order.h"
#include <fstream>
#include <vector>

class DeliveryRep
{
    private:

    public:
        DeliveryRep();
        vector<Branch> getBranches();
        vector<Order> getOrders();

        void changeOrderList(vector<Order> &orders);
        void addToLegacy(Order &order);

};

#endif // DELIVERYREP_H
