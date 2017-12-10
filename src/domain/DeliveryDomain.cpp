#include "DeliveryDomain.h"

DeliveryDomain::DeliveryDomain()
{
    //ctor
}

vector<Branch> DeliveryDomain::getBranch() {
    vector<Branch> branchList = deliveryRep.getBranch();
    return branchList;
}

bool DeliveryDomain::checkBranchAvaliability(const string &branch) {
    vector<Branch> branches = getBranch();
    for(unsigned int i = 0; i < branches.size(); i++){
        if(branches[i].getName() == branch) {
            return true;
        }
    }
    throw NotFoundException();
}

bool DeliveryDomain::checkValidName(const string &name) {

    for(unsigned int i = 0; i < name.length(); i++){
        if(isdigit(name[i])){
             throw InvalidInputException();
        }
    }
    return true;
}

bool DeliveryDomain::checkValidInput(const string &input) {
    if (input.length() == 1) {
      return true;
    }
    throw InvalidInputException();
    return false;
}

bool DeliveryDomain::isValidNumber(const string num){
    for(unsigned int i = 0; i < num.length(); i++){
        if(!isdigit(num[i]) || num.length() != 7){
             throw InvalidInputException();
        }
    }
    return true;
}

void DeliveryDomain::toLowerCase(string &name) {

    for (unsigned int i = 0; i < name.length(); i++) {
        if(name[i] != ' ' && isupper(name[i])) {
            name[i] = tolower(name[i]);
        }
    }
}

