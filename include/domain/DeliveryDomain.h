#ifndef DELIVERYDOMAIN_H
#define DELIVERYDOMAIN_H
#include <iostream>
#include "DeliveryRep.h"
#include "Branch.h"
using namespace std;


class DeliveryDomain
{
    private:
        DeliveryRep deliveryRep;

    public:
        DeliveryDomain();
        void getBranch(vector<Branch> &branch);
        bool checkBranchAvaliability(vector<Branch> &branchList, Branch &branch);
};

#endif // DELIVERYDOMAIN_H
