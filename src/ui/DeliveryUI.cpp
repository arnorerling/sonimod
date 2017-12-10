#include "DeliveryUI.h"

DeliveryUI::DeliveryUI()
{
    //ctor
}
void DeliveryUI::startUI() {

    printRestaurants();
    chooseRestaurant();

   /* char select = '\0';
    while (select != '5') {
        cout << "---------------------" << endl;
        cout << "1: Print ready orders" << endl;
        cout << "2: Print orders in process" << endl;
        cout << "3: Get order" << endl;
        cout << "4: Mark order paid" << endl;
        cout << "5: Mark order delivered/picked up" << endl;
        cout << "5: Quit" << endl;
        select = checkInput();

        switch(select) {
            case '1': printReadyOrders();
            break;
            case '2': printOtherOrders();
            break;
            case '3': markInProcess();
            break;
            case '4': markReady();
            break;
            case '5': cout << endl;
            default: cout << "Invalid input" << endl;
        }
    }*/
}

void DeliveryUI::printRestaurants() {

  cout << "----Restaurant list----" << endl;
    vector<Branch> branches = deliveryDomain.getBranch();
    for(unsigned int i = 0; i < branches.size(); i++){
        cout << branches[i];
    }
    cout << "-----------------------" << endl;
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


