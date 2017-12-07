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
    vector<Branch> branches;
    bakerDomain.getBranch(branches);
    for(unsigned int i = 0; i < branches.size(); i++){
        cout << branches[i];
    }
    cout << "-----------------------" << endl;
}

void BakerUI::chooseRestaurant() {
    bool avaliable = false;
    string name;
    while(!avaliable){
        cout << "What restaurant would you like to choose? ";
        cin >> ws;
        getline(cin, name);

        this->branch.setName(name);

        try{
            avaliable = bakerDomain.checkBranchAvaliability(branch);
            cout << "This restaurant is available" << endl;
        }
        catch(ResturantNotAvailableException){
            cout << "This restaurant is not available" << endl;
        }
    }
}
void BakerUI::printOrders() {

    vector<Order> orders;
    cout << "----Order list----" << endl;
    bakerDomain.getOrder(orders);
    for(unsigned int i = 0; i < orders.size(); i++){
        if(orders[i].getBranch() == branch.getName()){
            cout << orders[i];
        }
    }
    cout << "-----------------------" << endl;
}
