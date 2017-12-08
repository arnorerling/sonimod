#include "BakerRep.h"

BakerRep::BakerRep()
{
    //ctor
}

void BakerRep::getBranch(vector<Branch> &branch) {

    ifstream fin;
    fin.open("Branch_Binary.dat", ios::binary);
    if(fin.is_open()) {
        while(!fin.eof()){
            Branch currBranch;
            currBranch.read(fin);
            if(!fin.eof()){
            branch.push_back(currBranch);
            }
        }
        fin.close();
    }
}

void BakerRep::getOrder(vector<Order> &order) {

    ifstream fin;
    fin.open("Order_Binary.dat", ios::binary);
    if(fin.is_open()) {
        while(!fin.eof()){
            Order currOrder;
            currOrder.read(fin);
            if(!fin.eof()){
            order.push_back(currOrder);
            }
        }
        fin.close();
    }
}

void BakerRep::ChangeOrderList(vector<Order> &orders) {

    ofstream fout;
    fout.open("Order_Binary.dat", ios::binary);
    if(fout.is_open()) {
        for (unsigned int i = 0; i < orders.size(); i++) {
            orders[i].write(fout);
        }
        fout.close();
    }
    else {
        cout << "File did not open" << endl;
    }
}

void BakerRep::addReadyOrder(Order &order) {

    ofstream fout;
    fout.open("Ready_Order_Binary.dat", ios::binary|ios::app);
    if(fout.is_open()) {
        order.write(fout);
        fout.close();
    }
    else {
        cout << "File did not open" << endl;
    }
}
