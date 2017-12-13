#include "MainUI.h"
#include "ManagerUI.h"
#include "SalesUI.h"
#include "BakerUI.h"
#include "DeliveryUI.h"
#include <iostream>
using namespace std;

MainUI::MainUI() {
    //ctor
}

void MainUI::start() {
    char answer = '\0';
    while (answer != '2') {
        output.clean();
        printLogo();
        cout << "1: Login" << endl;
        cout << "2: Quit" << endl;
        answer = checkInput();

        switch (answer) {
            case '1': login();
            break;
            case '2': cout << endl;
            break;
            default: cout << "Invalid input" << endl;
        }
    }
}

void MainUI::login() {
    User user = checkUser();
    switch(user.getJobNumber()) {
        case '1': {
            mainMenu();
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
        default: cout << endl;
    }
}

void MainUI::mainMenu() {

    char answer = '\0';
    while (answer != '5') {
        output.clean();
        printLogo();
        cout << "------Main Menu------" << endl;
        cout << "1: Mananger" << endl;
        cout << "2: Sales" << endl;
        cout << "3: Baker" << endl;
        cout << "4: Delivery" << endl;
        cout << "5: Quit" << endl;
        cout << "---------------------" << endl;
        answer = checkInput();
        cout << answer << endl;

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
                cout << endl;
                break;
            }
            default: cout << "Invalid input" << endl;
        }
    }
}

User MainUI::checkUser() {
    output.clean();
    printLogo();
    User user;
    string name = "";
    string password = "";
    cout << "Username: " << endl;
    cin >> ws;
    getline(cin, name);
    cout << "Password: " << endl;
    SetStdinEcho(false);
    cin >> ws;
    getline(cin, password);
    SetStdinEcho(true);
    try {
        user = mainDomain.checkUser(name, password);
    }
    catch(NotFoundException){
        output.clean();
        cout << "wrong password" << endl;
        output.wait();
    }
    catch(FileNotOpenException) {
        cout << "Contact admin, user file not found." << endl;
        output.wait();
    }
    return user;
}

void MainUI::SetStdinEcho(bool enable = true) {
#ifdef WIN32
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode;
    GetConsoleMode(hStdin, &mode);

    if( !enable )
        mode &= ~ENABLE_ECHO_INPUT;
    else
        mode |= ENABLE_ECHO_INPUT;

    SetConsoleMode(hStdin, mode );

#else
    struct termios tty;
    tcgetattr(STDIN_FILENO, &tty);
    if( !enable )
        tty.c_lflag &= ~ECHO;
    else
        tty.c_lflag |= ECHO;

    (void) tcsetattr(STDIN_FILENO, TCSANOW, &tty);
#endif
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

void MainUI::printLogo() {
cout << " __                  " << endl;
cout << "(_  _ __  o __  _  _|" << endl;
cout << "__)(_)| | | |||(_)(_|" << endl;
}
