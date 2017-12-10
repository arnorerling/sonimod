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
        vector<Branch> getBranch();
        vector<Order> getOrder();

};

#endif // DELIVERYREP_H
