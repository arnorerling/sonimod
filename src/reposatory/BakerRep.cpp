#include "BakerRep.h"

BakerRep::BakerRep()
{
    //ctor
}

vector<Branch> BakerRep::getBranch() {
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
    else {
        throw FileNotOpenException();
    }
    return branches;
}

vector<Order> BakerRep::getOrders() {
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
    else {
        throw FileNotOpenException();
    }
    return orders;
}

void BakerRep::changeOrderList(vector<Order> &orders) {
    ofstream fout;
    fout.open("Order_Binary.dat", ios::binary);
    if(fout.is_open()) {
        for (unsigned int i = 0; i < orders.size(); i++) {
            orders[i].write(fout);
        }
        fout.close();
    }
}
