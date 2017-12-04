#include "BakerDomain.h"
#include "Branch.h"

BakerDomain::BakerDomain()
{
    //ctor
}

void BakerDomain::getBranch(vector<Branch> &branch) {
    bakerRep.getBranch(branch);
}

bool BakerDomain::checkBranchAvaliability(vector<Branch> &branchList, Branch &branch) {
    for(unsigned int i = 0; i < branchList.size(); i++){
        if(branchList[i].getName() == branch.getName()) {
            return true;
        }
    }
    return false;
}

