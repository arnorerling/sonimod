#include "BakerUI.h"
#include <iostream>
using namespace std;

BakerUI::BakerUI() {

}

void BakerUI::startUI() {
    printRestaurants();
    chooseRestaurant();

    char select = '\0';
    while (select != '5') {
        cout << "---------------------" << endl;
        cout << "1: Print orderlist" << endl;
        cout << "2: Choose order " << endl;
        cout << "3: Mark order in process" << endl;
        cout << "4: Mark order read" << endl;
        cout << "5: Quit" << endl;
        select = checkInput();

        switch(select) {
            case '1': printOrders();
            break;
            case '2': printOneOrder();
            break;
            case '3': //markReady();
            break;
            case '4': //printRestaurants();
            break;
            case '5': cout << endl;
            default: cout << "Invalid input" << endl;
        }
    }

}

void BakerUI::printRestaurants() {

  cout << "----Restaurant list----" << endl;
    vector<Branch> branches = bakerDomain.getBranch();
    for(unsigned int i = 0; i < branches.size(); i++){
        cout << branches[i];
    }
    cout << "-----------------------" << endl;
}

void BakerUI::printOrders() {
    cout << "----Order list for " << this->branch << "----" << endl;
    vector<Order> orderList = bakerDomain.getOrders(branch);
    for(unsigned int i = 0; i < orderList.size(); i++){
        cout << "Number: " << orderList[i].getCustomerPhoneNumber() << " ";
        cout << "Name: " << orderList[i].getCustomerName() << endl;
    }
    cout << "-----------------------" << endl;
}

void BakerUI::printOneOrder() {
    bool available = false;
    while (!available) {
        cout << "Order #: ";
        string number = checkNumber();
        try {
            Order order = bakerDomain.getOneOrder(number, branch);
            cout << order << endl;
            available = true;
        }
        catch(NotFoundException) {
            cout << "This number is not on the list, try again" << endl;
        }
    }
}

void BakerUI::chooseRestaurant() {
    bool available = false;
    while(!available ){
        cout << "Choose restaurant? ";
        this->branch = checkName();
        try{
            available = bakerDomain.checkBranchAvaliability(branch);
        }
        catch(NotFoundException){
            cout << "This restaurant is not available" << endl;
        }
    }
}

/*void BakerUI::initOrdersInBranch() {
    ordersInBranch = 0;
    bakerDomain.getOrder(orders);
    for(unsigned int i = 0; i < orders.size(); i++){
        if(orders[i].getBranch() == branch.getName()){
            ordersInBranch++;
        }
    }
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

void BakerUI::printOverwriteConfirmation(int orderNumber) {
    cout << "Order no. " << orderNumber << " overwritten" << endl;
}*/

string BakerUI::checkName() {
    string name = "";
    bool allowed = false;

    while(!allowed){
        cout << "Name: ";
        cin >> ws;
        getline(cin, name);
        bakerDomain.toLowerCase(name);
        try{
            allowed = bakerDomain.checkValidName(name);
        }
        catch(InvalidInputException){
            cout << "Name cant include numbers" << endl;
        }
    }
    return name;
}

char BakerUI::checkInput() {
    string input = "";
    char input1 = '\0';
    bool allowed = false;

    while(!allowed){
        cin >> ws;
        getline(cin, input);
        try{
            allowed = bakerDomain.checkValidInput(input);
            input1 = input[0];
        }
        catch(InvalidInputException){
            cout << "Invalid input" << endl;
        }
    }
    return input1;
}

string BakerUI::checkNumber() {
    string number = "";
    bool allowed = false;

    while(!allowed) {
        cin >> ws;
        getline(cin, number);
        try{
            allowed = bakerDomain.isValidNumber(number);
        }
        catch(InvalidInputException){
            cout << "Invalid phonenumber, try again!" << endl;
        }
    }
    return number;
}
