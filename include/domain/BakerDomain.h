#ifndef BAKERDOMAIN_H
#define BAKERDOMAIN_H
#include <iostream>
#include "BakerRep.h"
#include "Branch.h"
#include "ResturantNotAvailableException.h"

using namespace std;

class BakerDomain
{
    private:
        BakerRep bakerRep;

    public:
        BakerDomain();
        void getBranch(vector<Branch> &branch);
        void getOrder(vector<Order> &order);
        bool checkBranchAvaliability(Branch &branch);
};

#endif // BAKERDOMAIN_H
