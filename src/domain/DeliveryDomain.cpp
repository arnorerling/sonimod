#include "DeliveryDomain.h"

DeliveryDomain::DeliveryDomain()
{
    //ctor
}

void DeliveryDomain::getBranch(vector<Branch> &branch) {
    deliveryRep.getBranch(branch);
}

bool DeliveryDomain::checkBranchAvaliability(vector<Branch> &branchList, Branch &branch) {
    for(unsigned int i = 0; i < branchList.size(); i++){
        if(branchList[i].getName() == branch.getName()) {
            return true;
        }
    }
    return false;
}

