#include "DeliveryDomain.h"

DeliveryDomain::DeliveryDomain()
{
    //ctor
}

vector<Branch> DeliveryDomain::getBranch() {
    vector<Branch> branchList = deliveryRep.getBranches();
    if(branchList.size() == 0) {
        throw LengthNotRightException();
    }
    return branchList;
}

vector<Order> DeliveryDomain::getOrders(const string &branch) {
    vector<Order> orderList = deliveryRep.getOrders();
    vector<Order> branchOrderList;

    for (unsigned int i = 0; i < orderList.size(); i++) {
        if (orderList[i].getBranch() == branch) {
            branchOrderList.push_back(orderList[i]);
        }
    }
    if(branchOrderList.size() == 0) {
        throw LengthNotRightException();
    }
    return branchOrderList;
}

vector<Order> DeliveryDomain::getReadyOrders(const string &branch) {
    vector<Order> orderList = deliveryRep.getOrders();
    vector<Order> branchOrderList;

    for (unsigned int i = 0; i < orderList.size(); i++) {
        if (orderList[i].getBranch() == branch && orderList[i].getReady() == true) {
            branchOrderList.push_back(orderList[i]);
        }
    }
    if(branchOrderList.size() == 0) {
        throw LengthNotRightException();
    }
    return branchOrderList;
}

Order DeliveryDomain::getOneOrder(const string &number, const string &branch) {
    vector<Order> orderList = deliveryRep.getOrders();
    if(orderList.size() == 0) {
        throw LengthNotRightException();
    }

    for (unsigned int i = 0; i < orderList.size(); i++) {
        if (orderList[i].getBranch() == branch && orderList[i].getCustomerPhoneNumber() == number) {
            return orderList[i];
        }
    }
    throw NotFoundException();
}

void DeliveryDomain::markOrderPaidFor(const Order &order) {
     vector<Order> orderList = deliveryRep.getOrders();
     for (unsigned int i = 0; i < orderList.size(); i++) {
        if (orderList[i] == order) {
            if (orderList[i].getPaidFor()) {
                throw AlreadyMarkedException();
            }
            else
            {
                orderList[i].setPaidFor(true);
                deliveryRep.changeOrderList(orderList);
            }
        }
    }
}

void DeliveryDomain::markOrderDelivered(Order &order) {
    vector<Order> orderList = deliveryRep.getOrders();
    vector<Order> newOrderList;
    if (!order.getReady()) {
        throw NotMarkedReadyException();
     }
    else if (!order.getPaidFor()) {
        throw NotMarkedPaidForException();
     }

    for (unsigned int i = 0; i < orderList.size(); i++) {
        if (orderList[i] != order) {
            newOrderList.push_back(orderList[i]);
        }
        order.setPickup(true);
        deliveryRep.addToLegacy(order);
        deliveryRep.changeOrderList(newOrderList);
     }
}

void DeliveryDomain::deleteOrder(const Order &order) {
    vector<Order> orderList = deliveryRep.getOrders();
    for (unsigned int i = 0; i < orderList.size(); i++) {
        if (orderList[i].getCustomerPhoneNumber() == order.getCustomerPhoneNumber()) {
            orderList.erase(orderList.begin()+i);
        }
    }
    deliveryRep.changeOrderList(orderList);
}

bool DeliveryDomain::checkBranchAvaliability(string &branch) {
    vector<Branch> branches = getBranch();
    toLowerCase(branch);

    for(unsigned int i = 0; i < branches.size(); i++){
        if(branches[i].getName() == branch) {
            return true;
        }
    }
    throw NotFoundException();
}

bool DeliveryDomain::checkValidNumber(const string &num){
    for(unsigned int i = 0; i < num.length(); i++){
        if(!isdigit(num[i]) || num.length() != 7){
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

void DeliveryDomain::toLowerCase(string &name) {
    for (unsigned int i = 0; i < name.length(); i++) {
        if(name[i] != ' ' && isupper(name[i])) {
            name[i] = tolower(name[i]);
        }
    }
}

