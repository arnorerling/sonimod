#include "MainUI.h"
#include "ManagerUI.h"
#include "SalesUI.h"
#include "BakerUI.h"
#include "DeliveryUI.h"
#include <iostream>
using namespace std;

MainUI::MainUI()
{
    //ctor
}

void MainUI::start() {

   char answer = '\0';
        cout << "------Main Menu------" << endl;
        cout << "1: Mananger" << endl;
        cout << "2: Sales" << endl;
        cout << "3: Baker" << endl;
        cout << "4: delivery" << endl;
        cout << "5: quit" << endl;
        cout << "---------------------" << endl;

    while (answer != '5') {
        answer = checkInput();

        switch(answer) {
            case '1': {
                ManagerUI managerui;
                managerui.startUI();
                break;
                }
            case '2': {
                SalesUI salesui;
                salesui.startUI();
                break;
            }
            case '3': {
                BakerUI bakerui;
                bakerui.startUI();
                break;
                }
            case '4': {
                DeliveryUI deliveryui;
                deliveryui.startUI();
                break;
            }
            case '5': {
                cout << "GoodBye" << endl;
                break;
            }
            default: cout << "Invalid input" << endl;
        }
    }
}

char MainUI::checkInput() {
    string answer = "";
    char answer1 = '\0';
    bool allowed = false;

    while(!allowed){
        cin >> ws;
        getline(cin, answer);
        try{
            allowed = mainDomain.checkValidInput(answer);
            answer1 = answer[0];
        }
        catch(InvalidInputException){
            cout << "Invalid input" << endl;
        }
    }
    return answer1;
}
