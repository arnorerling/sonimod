#include "BakerUI.h"
#include <iostream>
using namespace std;

BakerUI::BakerUI() {

}

void BakerUI::startUI() {
    system("CLS");
    printLogo();
    printRestaurants();
    chooseRestaurant();

    char select = '\0';
    while (select != '5') {
        cout << "---------------------" << endl;
        cout << "1: Print orderlist" << endl;
        cout << "2: Choose order " << endl;
        cout << "3: Mark order in process" << endl;
        cout << "4: Mark order ready" << endl;
        cout << "5: Quit" << endl;
        select = checkInput();

        switch(select) {
            case '1': printOrders();
            break;
            case '2': printOneOrder();
            break;
            case '3': markInProcess();
            break;
            case '4': markReady();
            break;
            case '5': cout << endl;
            default: cout << "Invalid input" << endl;
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

void BakerUI:: printOneOrder() {
    Order order = findOrder();
    if (order.getCustomerName() != "") {
        cout << order << endl;
    }
}


void BakerUI::markInProcess() {
    Order order = findOrder();
    if (order.getCustomerName() != "") {
        try {
            bakerDomain.markOrderInProcess(order);
            cout << "Order has been marked in process" << endl;
        }
        catch(MarkedInProcessException) {
            cout << "This order is already in process" << endl;
        }
    }
}

void BakerUI::markReady() {
    Order order = findOrder();
    if (order.getCustomerName() != "") {
        try {
            bakerDomain.markOrderReady(order);
            cout << "Order has been marked ready" << endl;
        }
        catch(NotMarkedInProgressException) {
            cout << "This order has to go through \"in process\" ";
            cout << "before it cant be marked as ready"<< endl;
        }
    }
}

Order BakerUI::findOrder() {
    Order order;
        cout << "Order #: ";
        string number = checkNumber();
        try {
            order = bakerDomain.getOneOrder(number, branch);
        }
        catch(NotFoundException) {
            cout << "This number is not on the list!" << endl;
        }
    return order;
}

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

void BakerUI::printLogo() {
cout << "___  ____ _  _ ____ ____ " << endl;
cout << "|__] |__| |_/  |___ |__/ " << endl;
cout << "|__] |  | | \\_ |___ |  \\ " << endl;
}
