#include "BakerDomain.h"

BakerDomain::BakerDomain()
{
    //ctor
}

vector<Branch> BakerDomain::getBranch() {
    vector<Branch> branchList = bakerRep.getBranches();
    if(branchList.size() == 0) {
        throw LengthNotRightException();
    }
    return branchList;
}

vector<Order> BakerDomain::getOrders(const string &branch) {
    vector<Order> orderList = bakerRep.getOrders();
    vector<Order> branchOrderList;

    for (unsigned int i = 0; i < orderList.size(); i++) {
        if (orderList[i].getBranch() == branch && orderList[i].getReady() == false) {
            branchOrderList.push_back(orderList[i]);
        }
    }
    if(branchOrderList.size() == 0) {
        throw LengthNotRightException();
    }
    return branchOrderList;
}

Order BakerDomain::getOneOrder(const string &number, const string &branch) {
    vector<Order> orderList = bakerRep.getOrders();
    if(orderList.size() == 0) {
        throw LengthNotRightException();
    }

    for (unsigned int i = 0; i < orderList.size(); i++) {
        if (orderList[i].getBranch() == branch && orderList[i].getCustomerPhoneNumber() == number) {
            if (orderList[i].getReady() == false) {
                return orderList[i];
            }
        }
    }
    throw NotFoundException();
}

void BakerDomain::markOrderInProcess(const Order &order) {
    vector<Order> orderList = bakerRep.getOrders();
    for (unsigned int i = 0; i < orderList.size(); i++) {
        if (orderList[i].getCustomerPhoneNumber() == order.getCustomerPhoneNumber()) {
            if (orderList[i].getInProcess() == 1) {
                throw AlreadyMarkedException();
            }
            else {
                orderList[i].setInProcess(true);
                bakerRep.changeOrderList(orderList);
                break;
            }
        }
    }
}

void BakerDomain::markOrderReady(const Order &order) {
    vector<Order> orderList = bakerRep.getOrders();
    for (unsigned int i = 0; i < orderList.size(); i++) {
        if (orderList[i].getCustomerPhoneNumber() == order.getCustomerPhoneNumber()) {
            if (orderList[i].getInProcess() == 0) {
                throw NotMarkedInProgressException();
            }
            else {
                orderList[i].setReady(true);
                orderList[i].setTime();
                bakerRep.changeOrderList(orderList);
                break;
            }
        }
    }
}

bool BakerDomain::checkBranchAvaliability(string &branch) {
    vector<Branch> branches = getBranch();
    toLowerCase(branch);

    for(unsigned int i = 0; i < branches.size(); i++){
        if(branches[i].getName() == branch) {
            return true;
        }
    }
    throw NotFoundException();
}

bool BakerDomain::checkValidInput(const string &input) {
    if (input.length() == 1) {
      return true;
    }
    throw InvalidInputException();
    return false;
}

bool BakerDomain::checkValidNumber(const string &num) {
    for(unsigned int i = 0; i < num.length(); i++) {
        if(!isdigit(num[i]) || num.length() != 7) {
             throw InvalidInputException();
        }
    }
    return true;
}

void BakerDomain::toLowerCase(string &name) {
    for (unsigned int i = 0; i < name.length(); i++) {
        if(name[i] != ' ' && isupper(name[i])) {
            name[i] = tolower(name[i]);
        }
    }
}
