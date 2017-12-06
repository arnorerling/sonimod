#include "BakerUI.h"
#include <iostream>
using namespace std;

BakerUI::BakerUI()
{
    //ctor
}

void BakerUI::startUI() {

    printRestaurants();
    chooseRestaurant();
    printOrders();
}

void BakerUI::printRestaurants() {

  cout << "----Restaurant list----" << endl;
    bakerDomain.getBranch(this->branchList);
    for(unsigned int i = 0; i < this->branchList.size(); i++){
        cout << branchList[i];
    }
    cout << "-----------------------" << endl;
}

void BakerUI::chooseRestaurant() {
    bool avaliable = false;
    string name;
    int size = 0;
    while(!avaliable){
        cout << "What restaurant would you like to choose? ";
        cin >> ws;
        getline(cin, name);

        Branch branch(name);
        avaliable = bakerDomain.checkBranchAvaliability(this->branchList, branch);
        if(avaliable){
            cout << "This restaurant is available" << endl;
        }
        else {
            cout << "This restaurant is not available" << endl;
        }
    }
}
void BakerUI::printOrders() {

    vector<Order> orders;
    cout << "----Order list----" << endl;
    bakerDomain.getOrder(orders);
    for(unsigned int i = 0; i < orders.size(); i++){
        cout << orders[i];
    }
    cout << "-----------------------" << endl;
}
