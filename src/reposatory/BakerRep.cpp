#include "BakerRep.h"

BakerRep::BakerRep()
{
    //ctor
}

void BakerRep::getBranch(vector<Branch> &branch) {

    Branch currBranch;
    ifstream fin;
    fin.open("Branch_Binary.dat", ios::binary);
    if(fin.is_open()) {
        while(!fin.eof()){
            currBranch.read(fin);
            if(!fin.eof()){
            branch.push_back(currBranch);
            }
        }
        fin.close();
    }
}

void BakerRep::getOrder(vector<Order> &order) {

    Order currOrder;
    ifstream fin;
    fin.open("Order_Binary.dat", ios::binary);
    if(fin.is_open()) {
        while(!fin.eof()){
            currOrder.read(fin);
            if(!fin.eof()){
            order.push_back(currOrder);
            }
        }
        fin.close();
    }
}
