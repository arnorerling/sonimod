#include "DeliveryRep.h"

DeliveryRep::DeliveryRep()
{
    //ctor
}

vector<Branch> DeliveryRep::getBranches() {
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

vector<Order> DeliveryRep::getOrders() {
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


void DeliveryRep::changeOrderList(vector<Order> &orders) {
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

void DeliveryRep::addToLegacy(Order &order) {
    ofstream fout;
    fout.open("LegacyOrder_Binary.dat", ios::binary|ios::app);
    if(fout.is_open()) {
        order.write(fout);
        fout.close();
    }
    else {
        cout << "File did not open" << endl;
    }
}
