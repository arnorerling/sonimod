#include "BakerUI.h"
#include <iostream>
using namespace std;

BakerUI::BakerUI() {

}

void BakerUI::startUI() {

    printRestaurants();
    chooseRestaurant();
    bakerChoices();
}

void BakerUI::initOrdersInBranch() {
    ordersInBranch = 0;
    bakerDomain.getOrder(orders);
    for(unsigned int i = 0; i < orders.size(); i++){
        if(orders[i].getBranch() == branch.getName()){
            ordersInBranch++;
        }
    }
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

void BakerUI::printChoices() {
    cout << "What would you like to do?" << endl;
    cout << "--------------------------" << endl;
    cout << "1: View all orders" << endl;
    cout << "2: Quit" << endl;

}

void BakerUI::bakerChoices() {
    initOrdersInBranch();
    char choice;
    while(choice != '2') {
        printChoices();
        cin >> choice;
        switch(choice) {
        case '1':
            if(ordersInBranch > 0) {
                printOrders();
                orderOptions();
            }
            else {
                cout << "No orders" << endl;
            }
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
    int orderOptionChoice = 0;
    while(orderOptionChoice != (ordersInBranch + 1) ) {
        printOrderOptions();
        cin >> orderOptionChoice;

        if(orderOptionChoice != (ordersInBranch + 1) ) {
            if(orderOptionChoice > 0 && orderOptionChoice <= ordersInBranch) {
                int branchOrderCount = 0;
                int totalOrderNumber = 0;
                while(branchOrderCount < orderOptionChoice) {
                    if(orders[totalOrderNumber].getBranch() == branch.getName()) {
                        branchOrderCount++;
                    }
                    totalOrderNumber++;
                }
                orders[totalOrderNumber - 1].setReady(true);
                bakerDomain.markOrderAsReady(orders[totalOrderNumber - 1]);
                orders.erase(orders.begin() + totalOrderNumber);
                bakerDomain.overWriteOrder(orders);
                printOverwriteConfirmation(orderOptionChoice);
            }
            else {
                cout << "Invalid input" << endl;
            }
        }
    }
}

void BakerUI::printOrders() {

    cout << "----Order list----" << endl;
    for(unsigned int i = 0; i < orders.size(); i++){
        if(orders[i].getBranch() == branch.getName()){
            cout << orders[i];
        }
    }
    cout << "-----------------------" << endl;
}

void BakerUI::printOverwriteConfirmation(int orderNumber) {
    cout << "Order no. " << orderNumber << " overwritten" << endl;
}
