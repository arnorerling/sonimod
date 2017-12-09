#include "BakerDomain.h"
#include "Branch.h"

BakerDomain::BakerDomain()
{
    //ctor
}

void BakerDomain::toLowerCase(string &name) {

    for (unsigned int i = 0; i < name.length(); i++) {
        if(name[i] != ' ' && isupper(name[i])) {
            name[i] = tolower(name[i]);
        }
    }
}

bool BakerDomain::checkBranchAvaliability(string &branchName) {
    vector<Branch> branches;
    this->getBranch(branches);
    for(unsigned int i = 0; i < branches.size(); i++){
        if(branches[i].getName() == branchName) {
            return true;
        }
    }
    throw NotFoundException();
}


void BakerDomain::getBranch(vector<Branch> &branch) {
    bakerRep.getBranch(branch);
}

void BakerDomain::getOrder(vector<Order> &order) {
    bakerRep.getOrder(order);
}

void BakerDomain::overWriteOrder(vector<Order> &order) {
    bakerRep.ChangeOrderList(order);
}

void BakerDomain::markOrderAsReady(Order &order) {
    bakerRep.addReadyOrder(order);
}

bool BakerDomain::checkValidName(const string &name) {

    for(unsigned int i = 0; i < name.length(); i++){
        if(isdigit(name[i])){
             throw InvalidInputException();
        }
    }
    return true;
}

bool BakerDomain::checkValidInput(const string &input) {
    if (input.length() == 1) {
      return true;
    }
    throw InvalidInputException();
    return false;
}

