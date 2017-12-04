#ifndef BAKERDOMAIN_H
#define BAKERDOMAIN_H
#include <iostream>
#include "BakerRep.h"
#include "Branch.h"
using namespace std;

class BakerDomain
{
    private:
        BakerRep bakerRep;

    public:
        BakerDomain();
        void getBranch(vector<Branch> &branch);
        bool checkBranchAvaliability(vector<Branch> &branchList, Branch &branch);
};

#endif // BAKERDOMAIN_H
