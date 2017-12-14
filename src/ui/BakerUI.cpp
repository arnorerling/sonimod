#include "BakerUI.h"

BakerUI::BakerUI() {
}

void BakerUI::startUI() {
    output.clean();
    printLogo();
    chooseRestaurant();

    char select;
    if(branch == "") {
        select = '5';
    }
    else {
        select = '\0';
    }
    while (select != '5') {
        output.clean();
        printLogo();
        cout << "---------------------" << endl;
        cout << "1: Print orderlist" << endl;
        cout << "2: Choose order " << endl;
        cout << "3: Mark order in process" << endl;
        cout << "4: Mark order ready" << endl;
        cout << "5: Quit" << endl;
        select = checkInput();

        switch(select) {
            case '1':
                printOrders();
                output.wait();
            break;
            case '2':
                printOneOrder();
                output.wait();
            break;
            case '3':
                markInProcess();
                output.wait();
            break;
            case '4':
                markReady();
                output.wait();
            break;
            case '5':
                cout << endl;
            break;
            default:
                cout << "Invalid input" << endl;
                output.wait();
        }
    }
}

void BakerUI::chooseRestaurant() {
    bool available = false;
    while(!available ){
        try {
            printRestaurants();
            cout << "Choose restaurant branch? ";
            cin >> ws;
            getline(cin, this->branch);
            available = bakerDomain.checkBranchAvaliability(branch);
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
    vector<Order> orderList;
    try {
        orderList = bakerDomain.getOrders(branch);
        time_t time1 = time(0);
        time_t orderTime;
        for(unsigned int i = 0; i < orderList.size(); i++) {
            orderTime = orderList[i].getTime();
            double diff = difftime(time1, orderTime);
            cout << diff << endl;
            if(diff < 1800 ) {
                cout << "Number: " << orderList[i].getCustomerPhoneNumber();
                cout << " | Name: " << orderList[i].getCustomerName() << endl;
            }
            else if (diff < 3600) {
                cout << "Number: " << orderList[i].getCustomerPhoneNumber();
                cout << " | Name: " << orderList[i].getCustomerName();
                cout << " | hurry up! order older than 30 min!" << endl;
            }
            else {
                cout << "Number: " << orderList[i].getCustomerPhoneNumber();
                cout << " | Name: " << orderList[i].getCustomerName();
                cout << " | hurry up! order older than 1 hours!" << endl;
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
        catch(AlreadyMarkedException) {
            cout << "This order is already in process" << endl;
        }
    }
}

void BakerUI::markReady() {
    Order order = findOrder();
    if (order.getCustomerName() != "") {
        try {
            bakerDomain.markOrderReady(order);
            order.setTime();
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
    try {
        vector<Order> sizeChecker = bakerDomain.getOrders(branch);
        cout << "Order #: ";
        string number = checkNumber();
        order = bakerDomain.getOneOrder(number, branch);
    }
    catch(FileNotOpenException) {
        cout << "Order file not found" << endl;
    }
    catch(LengthNotRightException) {
        cout << "Order list is empty" << endl;
    }
    catch(NotFoundException) {
        cout << "This number is not on the list!" << endl;
    }
    return order;
}

char BakerUI::checkInput() {
    string input = "";
    char input1 = '\0';
    bool allowed = false;

    while(!allowed) {
        cin >> ws;
        getline(cin, input);
        try{
            allowed = bakerDomain.checkValidInput(input);
            input1 = input[0];
        }
        catch(InvalidInputException) {
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
        try {
            allowed = bakerDomain.checkValidNumber(number);
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
