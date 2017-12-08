#include "BakerUI.h"
#include <iostream>
using namespace std;

BakerUI::BakerUI()
{
    ordersInBranch = 0;
}

void BakerUI::startUI() {

    printRestaurants();
    chooseRestaurant();
    bakerChoices();
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
    bool available = false;
    string name;
    while(!available ){
        cout << "What restaurant would you like to choose? ";
        cin >> ws;
        getline(cin, name);

        this->branch.setName(name);

        try{
            available = bakerDomain.checkBranchAvaliability(branch);
        }
        catch(NotFoundException){
            cout << "This restaurant is not available" << endl;
        }
    }
}
void BakerUI::printOrders() {

    cout << "----Order list----" << endl;
    bakerDomain.getOrder(orders);
    for(unsigned int i = 0; i < orders.size(); i++){
        if(orders[i].getBranch() == branch.getName()){
            ordersInBranch++;
            cout << orders[i];
        }
    }
    cout << "-----------------------" << endl;
}

void BakerUI::printChoices() {
    cout << "What would you like to do?" << endl;
    cout << "--------------------------" << endl;
    cout << "1: View all orders" << endl;
    cout << "2: Quit" << endl;

}


void BakerUI::bakerChoices() {
    char choice;
    while(choice != 2) {
        printChoices();
        cin >> choice;
        switch(choice) {
        case '1':
            printOrders();
            orderOptions();
            break;
        case '2':
            break;
        }
    }
}

void BakerUI::printOrderOptions() {
    for(int i = 0; i < ordersInBranch; i++) {
        cout << i + 1 << ": Mark order no. " << i + 1 << " as ready" << endl;
    }
    cout << ordersInBranch + 1 << ": Quit" << endl;
}

void BakerUI::orderOptions() {
    char orderOptionChoice;
    while(orderOptionChoice != (ordersInBranch + 1) ) {
        printOrderOptions();
        cin >> orderOptionChoice;

        int branchOrderCount = 0;
        int totalOrderNumber = 0;
        while(branchOrderCount < ordersInBranch) {
            if(orders[totalOrderNumber].getBranch() == branch.getName()) {
                branchOrderCount++;
            }
            totalOrderNumber++;
        }
        orders[totalOrderNumber - 1].setReady(true);
        //bakerDomain.bakerRep.ChangeOrderList(orders);
    }
}
