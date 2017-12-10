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
    while (answer != 2) {
        cout << "1: Login" << endl;
        cout << "2: Quit" << endl;
        answer = checkInput();

        switch (answer) {
            case '1': login();
            break;
            case '2':
            break;
            default: cout << "Invalid input" << endl;
        }
    }
}

void MainUI::login() {

    User user = checkUser();
    char answer = '\0';
    while (answer != '5') {
        char answer = '\0';
        cout << "------Main Menu------" << endl;
        cout << "1: Mananger" << endl;
        cout << "2: Sales" << endl;
        cout << "3: Baker" << endl;
        cout << "4: delivery" << endl;
        cout << "5: quit" << endl;
        cout << "---------------------" << endl;
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

User MainUI::checkUser() {
    User user;
    string name = "";
    string password = "";
    bool allowed = false;

    while(!allowed){
        cout << "Username: " << endl;
        cin >> ws;
        getline(cin, name);
        cout << "Password: " << endl;
        cin >> ws;
        getline(cin, password);
        try{
            user = mainDomain.checkUser(name, password);
            allowed = true;
        }
        catch(NotFoundException){
            cout << "wrong password" << endl;
        }
    }
    return user;


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
