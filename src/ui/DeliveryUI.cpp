#include "DeliveryUI.h"

DeliveryUI::DeliveryUI()
{
    //ctor
}
void DeliveryUI::startUI() {
    system("CLS");
    printLogo();
    printRestaurants();
    chooseRestaurant();

    char select = '\0';
    while (select != '6') {
        cout << "---------------------" << endl;
        cout << "1: Print all orders" << endl;
        cout << "2: Print ready orders" << endl;
        cout << "3: Get order" << endl;
        cout << "4: Mark order paid" << endl;
        cout << "5: Mark order delivered/picked up" << endl;
        cout << "5: Quit" << endl;
        select = checkInput();

        switch(select) {
            case '1': printOrders();
            break;
            case '2': printReadyOrders();
            break;
            case '3': printOneOrder();
            break;
            case '4': markPaidFor();
            break;
            case '5': markDelivered();
            break;
            case '6': cout << endl;
            break;
            default: cout << "Invalid input" << endl;
        }
    }
}

void DeliveryUI::chooseRestaurant() {
    bool available = false;
    while(!available ){
        cout << "Choose restaurant? ";
        this->branch = checkName();
        try{
            available = deliveryDomain.checkBranchAvaliability(branch);
        }
        catch(NotFoundException){
            cout << "This restaurant is not available" << endl;
        }
    }
}

void DeliveryUI::printRestaurants() {

  cout << "----Restaurant list----" << endl;
    vector<Branch> branches = deliveryDomain.getBranch();
    for(unsigned int i = 0; i < branches.size(); i++){
        cout << branches[i];
    }
    cout << "-----------------------" << endl;
}

void DeliveryUI::printOrders() {
    cout << "----Order list for " << this->branch << "----" << endl;
    vector<Order> orderList = deliveryDomain.getOrders(branch);
    for(unsigned int i = 0; i < orderList.size(); i++){
        cout << "Number: " << orderList[i].getCustomerPhoneNumber() << " ";
        cout << "Name: " << orderList[i].getCustomerName() << endl;
    }
    cout << "-----------------------" << endl;
}

void DeliveryUI::printReadyOrders() {
    cout << "----Order list for " << this->branch << "----" << endl;
    vector<Order> orderList = deliveryDomain.getReadyOrders(branch);
    for(unsigned int i = 0; i < orderList.size(); i++){
        cout << "Number: " << orderList[i].getCustomerPhoneNumber() << " ";
        cout << "Name: " << orderList[i].getCustomerName() << endl;
    }
    cout << "-----------------------" << endl;
}

void DeliveryUI:: printOneOrder() {
    Order order = findOrder();
    if (order.getCustomerName() != "") {
        cout << order << endl;
    }
}

void DeliveryUI::markPaidFor() {
    Order order = findOrder();
    if (order.getCustomerName() != "") {
        try {
            deliveryDomain.markOrderPaidFor(order);
            cout << "Order has been paid for" << endl;
        }
        catch(MarkedPaidForException) {
            cout << "This order has already been paid for" << endl;
        }
    }
}

void DeliveryUI::markDelivered() {
    Order order = findOrder();
    if (order.getCustomerName() != "") {
        try {
            deliveryDomain.markOrderDelivered(order);
            cout << "Order has been delivered" << endl;
        }
        catch(NotMarkedReadyException) {
            cout << "This order is not ready" << endl;
        }
        catch(NotMarkedPaidForException) {
            cout << "This order has not been paid for" << endl;
        }
    }
}

Order DeliveryUI::findOrder() {
    Order order;
    cout << "Order #: ";
    string number = checkNumber();
    try {
        order = deliveryDomain.getOneOrder(number, branch);
    }
    catch(NotFoundException) {
        cout << "This number is not on the list, try again" << endl;
    }
    return order;
}

char DeliveryUI::checkInput() {
    string input = "";
    char input1 = '\0';
    bool allowed = false;

    while(!allowed){
        cin >> ws;
        getline(cin, input);
        try{
            allowed = deliveryDomain.checkValidInput(input);
            input1 = input[0];
        }
        catch(InvalidInputException){
            cout << "Invalid input" << endl;
        }
    }
    return input1;
}

string DeliveryUI::checkName() {
    string name = "";
    bool allowed = false;

    while(!allowed){
        cout << "Name: ";
        cin >> ws;
        getline(cin, name);
        deliveryDomain.toLowerCase(name);
        try{
            allowed = deliveryDomain.checkValidName(name);
        }
        catch(InvalidInputException){
            cout << "Name cant include numbers" << endl;
        }
    }
    return name;
}

string DeliveryUI::checkNumber() {
    string number = "";
    bool allowed = false;

    while(!allowed) {
        cin >> ws;
        getline(cin, number);
        try{
            allowed = deliveryDomain.checkValidNumber(number);
        }
        catch(InvalidInputException){
            cout << "Invalid phonenumber, try again!" << endl;
        }
    }
    return number;
}

void DeliveryUI::printLogo() {

cout << "___  ____ _    _ _  _ ____ ____ _   _ " << endl;
cout << "|  \\ |___ |    | |  | |___ |__/  \_\/  " << endl;
cout << "|__/ |___ |___ |  \\/  |___ |  \\   |   " << endl;


}

