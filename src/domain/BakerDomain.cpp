#include "BakerDomain.h"
#include "Branch.h"

BakerDomain::BakerDomain()
{
    //ctor
}

void BakerDomain::getBranch(vector<Branch> &branch) {
    bakerRep.getBranch(branch);
}
void BakerDomain::getOrder(vector<Order> &order) {
    bakerRep.getOrder(order);
}

bool BakerDomain::checkBranchAvaliability(Branch &branch) {
    vector<Branch> branches;
    this->getBranch(branches);
    for(unsigned int i = 0; i < branches.size(); i++){
        if(branches[i].getName() == branch.getName()) {
            return true;
        }
    }
    throw NotFoundException();
}

void BakerDomain::overWriteOrder(vector<Order> &order) {
    bakerRep.ChangeOrderList(order);
}


