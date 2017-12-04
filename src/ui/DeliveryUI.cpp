#include "DeliveryUI.h"

DeliveryUI::DeliveryUI()
{
    //ctor
}
void DeliveryUI::startUI() {

    printRestaurants();
    chooseRestaurant();
}

void DeliveryUI::printRestaurants() {

  cout << "----Restaurant list----" << endl;
    deliveryDomain.getBranch(this->branchList);
    for(unsigned int i = 0; i < this->branchList.size(); i++){
        cout << branchList[i];
    }
    cout << "-----------------------" << endl;
}

void DeliveryUI::chooseRestaurant() {
    bool avaliable = false;
    string name;
    int size = 0;
    while(!avaliable){
        cout << "What restaurant would you like to choose? ";
        cin >> ws;
        getline(cin, name);

        Branch branch(name);
        avaliable = deliveryDomain.checkBranchAvaliability(this->branchList, branch);
        if(avaliable){
            cout << "This restaurant is available" << endl;
        }
        else {
            cout << "This restaurant is not available" << endl;
        }
    }
}
