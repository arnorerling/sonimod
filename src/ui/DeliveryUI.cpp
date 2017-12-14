#include "DeliveryUI.h"

DeliveryUI::DeliveryUI() {

}

void DeliveryUI::startUI() {
    output.clean();
    printLogo();
    chooseRestaurant();

    char select;
    if(branch == "") {
        select = '6';
    }
    else {
        select = '\0';
    }
    while (select != '6') {
        output.clean();
        printLogo();
        cout << "---------------------" << endl;
        cout << "1: Print all orders" << endl;
        cout << "2: Print ready orders" << endl;
        cout << "3: Get order" << endl;
        cout << "4: Mark order paid" << endl;
        cout << "5: Mark order delivered/picked up" << endl;
        cout << "6: Quit" << endl;
        select = checkInput();

        switch(select) {
            case '1':
                printOrders();
                output.wait();
                break;
            case '2':
                printReadyOrders();
                output.wait();
                break;
            case '3':
                printOneOrder();
                output.wait();
                break;
            case '4':
                markPaidFor();
                output.wait();
                break;
            case '5':
                markDelivered();
                output.wait();
                break;
            case '6':
                cout << endl;
                break;
            default:
                cout << "Invalid input" << endl;
                output.wait();
        }
    }
}

void DeliveryUI::chooseRestaurant() {
    bool available = false;
    while(!available ){
        try {
            printRestaurants();
            cout << "Choose restaurant branch? ";
            cin >> ws;
            getline(cin, this->branch);
            available = deliveryDomain.checkBranchAvaliability(branch);
        }
        catch(NotFoundException){
            cout << "This branch is not on the list" << endl;
        }
        catch(LengthNotRightException) {
            cout << "Branch list is empty" << endl;
            output.wait();
            break;
        }
        catch(FileNotOpenException) {
            cout << "Branch file not found" << endl;
            output.wait();
            break;
        }
    }
}

void DeliveryUI::printRestaurants() {

  cout << "----Restaurant list----" << endl;
    vector<Branch> branches = deliveryDomain.getBranch();
    for(unsigned int i = 0; i < branches.size(); i++) {
        cout << branches[i];
    }
    cout << "-----------------------" << endl;
}

void DeliveryUI::printOrders() {
    cout << "----Orders for " << this->branch << "----" << endl;
    vector<Order> orderList;
    try {
        orderList = deliveryDomain.getOrders(branch);
        for(unsigned int i = 0; i < orderList.size(); i++) {
            cout << "Number: " << orderList[i].getCustomerPhoneNumber();
            cout << " Name: " << orderList[i].getCustomerName() << endl;
        }
        cout << "-----------------------" << endl;
    }
    catch(LengthNotRightException) {
        cout << "Order list empty" << endl;
    }
    catch(FileNotOpenException) {
        cout << "Order file not found" << endl;
    }
}

void DeliveryUI::printReadyOrders() {
    cout << "----Ready orders for " << this->branch << "----" << endl;
    vector<Order> orderList;
    try {
        orderList = deliveryDomain.getReadyOrders(branch);
        time_t time1 = time(0);
        time_t orderTime;
        for(unsigned int i = 0; i < orderList.size(); i++) {
            orderTime = orderList[i].getTime();
            double diff = difftime(time1, orderTime);
            if(diff < 1800) {
                cout << "Number: " << orderList[i].getCustomerPhoneNumber();
                cout << " | Name: " << orderList[i].getCustomerName() << endl;
            }
            else if(diff < 3600 ) {
                cout << "Number: " << orderList[i].getCustomerPhoneNumber();
                cout << " | Name: " << orderList[i].getCustomerName();
                cout << " | hurry up! Order is older than 30 minutes" << endl;

            }
            else if(diff < 7200) {
                cout << "Number: " << orderList[i].getCustomerPhoneNumber();
                cout << "Name: " << orderList[i].getCustomerName();
                cout << " | hurry up! order older than an hour" << endl;

            }
            else {
                cout << "Number: " << orderList[i].getCustomerPhoneNumber();
                cout << " | Name: " << orderList[i].getCustomerName();
                cout << " | Order older than 2 hours! Will be thrown out" << endl;
                deleteOrder(orderList[i]);
            }
        }
        cout << "-----------------------" << endl;
    }
    catch(LengthNotRightException) {
        cout << "Order list empty" << endl;
    }
    catch(FileNotOpenException) {
        cout << "Order file not found" << endl;
    }
}

void DeliveryUI:: printOneOrder() {
    Order order = findOrder();
    if (order.getCustomerName() != "") {
        cout << order;
    }
    cout << "----------------------------" << endl;
}

void DeliveryUI::markPaidFor() {
    Order order = findOrder();
    if (order.getCustomerName() != "") {
        try {
            deliveryDomain.markOrderPaidFor(order);
            cout << "Order has been paid for" << endl;
        }
        catch(AlreadyMarkedException) {
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
        catch(InvalidInputException) {
            cout << "Invalid input" << endl;
        }
    }
    return input1;
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



Order DeliveryUI::findOrder() {
    Order order;
    try {
        vector <Order> sizeChecker = deliveryDomain.getOrders(branch);
        cout << "Order #: ";
        string number = checkNumber();
        order = deliveryDomain.getOneOrder(number, branch);
    }
    catch(FileNotOpenException) {
        cout << "Order file not found" << endl;
    }
    catch(LengthNotRightException) {
        cout << "Order list is empty" << endl;
    }
    catch(NotFoundException) {
        cout << "This number is not on the list, try again" << endl;
    }
    return order;
}

void DeliveryUI::deleteOrder(Order order) {
    deliveryDomain.deleteOrder(order);
    cout << order.getCustomerPhoneNumber() << "has been deleted" << endl;
}

void DeliveryUI::printLogo() {

cout << "___  ____ _    _ _  _ ____ ____ _   _ " << endl;
cout << "|  \\ |___ |    | |  | |___ |__/  \\_/  " << endl;
cout << "|__/ |___ |___ |  \\/  |___ |  \\   |   " << endl;


}

