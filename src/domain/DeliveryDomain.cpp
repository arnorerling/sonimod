#include "DeliveryDomain.h"

DeliveryDomain::DeliveryDomain()
{
    //ctor
}

vector<Branch> DeliveryDomain::getBranch() {
    vector<Branch> branchList = deliveryRep.getBranches();
    return branchList;
}

vector<Order> DeliveryDomain::getOrders(const string &branch) {
    vector<Order> orderList = deliveryRep.getOrders();
    vector<Order> branchOrderList;

    for (int i = 0; i < orderList.size(); i++) {
        if (orderList[i].getBranch() == branch) {
            branchOrderList.push_back(orderList[i]);
        }
    }
    return branchOrderList;
}

vector<Order> DeliveryDomain::getReadyOrders(const string &branch) {
    vector<Order> orderList = deliveryRep.getOrders();
    vector<Order> branchOrderList;

    for (int i = 0; i < orderList.size(); i++) {
        if (orderList[i].getBranch() == branch && orderList[i].getReady() == true) {
            branchOrderList.push_back(orderList[i]);
        }
    }
    return branchOrderList;
}

Order DeliveryDomain::getOneOrder(const string &number, const string &branch) {
    vector<Order> orderList = deliveryRep.getOrders();

    for (int i = 0; i < orderList.size(); i++) {
        if (orderList[i].getBranch() == branch && orderList[i].getCustomerPhoneNumber() == number) {
            return orderList[i];
        }
    }
    throw NotFoundException();
}

bool DeliveryDomain::markOrderPaidFor(const Order &order) {
     vector<Order> orderList = deliveryRep.getOrders();
     for (int i = 0; i < orderList.size(); i++) {
        if (orderList[i] == order) {
            if (orderList[i].getPaidFor()) {
                throw MarkedPaidForException();
                return false;
            }
            else
            {
                orderList[i].setPaidFor(true);
                deliveryRep.changeOrderList(orderList);
                return true;
            }
        }
    }
}

bool DeliveryDomain::markOrderDelivered(Order &order) {
    vector<Order> orderList = deliveryRep.getOrders();
    vector<Order> newOrderList;
    if (!order.getReady()) {
        throw NotMarkedReadyException();
        return false;
     }
    else if (!order.getPaidFor()) {
        throw NotMarkedPaidForException();
        return false;
     }

    for (int i = 0; i < orderList.size(); i++) {
        if (orderList[i] != order) {
            newOrderList.push_back(orderList[i]);
        }
        order.setPickup(true);
        deliveryRep.addToLegacy(order);
        deliveryRep.changeOrderList(newOrderList);
     }
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

bool DeliveryDomain::checkValidNumber(const string num){
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

