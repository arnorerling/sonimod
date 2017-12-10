#include "DeliveryRep.h"

DeliveryRep::DeliveryRep()
{
    //ctor
}

vector<Branch> DeliveryRep::getBranch() {
    vector<Branch> branches;
    ifstream fin;
    fin.open("Branch_Binary.dat", ios::binary);
    if(fin.is_open()) {
        while(!fin.eof()){
            Branch branch;
            branch.read(fin);
            if(!fin.eof()){
                branches.push_back(branch);
            }
        }
        fin.close();
    }
    return branches;
}

vector<Order> DeliveryRep::getOrder() {
    vector<Order> orders;
    ifstream fin;
    fin.open("Order_Binary.dat", ios::binary);
    if(fin.is_open()) {
        while(!fin.eof()){
            Order order;
            order.read(fin);
            if(!fin.eof()){
                orders.push_back(order);
            }
        }
        fin.close();
    }
    return orders;
}
