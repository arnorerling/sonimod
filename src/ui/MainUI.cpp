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

   char select = '\0';

    while (select != 'q') {

        cout << "------Main Menu------" << endl;
        cout << "m: Mananger" << endl;
        cout << "s: Sales" << endl;
        cout << "b: Baker" << endl;
        cout << "d: delivery" << endl;
        cout << "q: quit" << endl;
        cout << "---------------------" << endl;

        cin >>  select;

        switch(select) {
            case 'm': {
                ManagerUI managerui;
                managerui.startUI();
                break;
                }
            case 's': {
                SalesUI salesui;
                salesui.startUI();
                break;
            }
            case 'b': {
                //Baker bakerui;
                //bakerui.startUI();
                break;
                }
            case 'd': {
                cout << "Coming Soon" << endl;
                }
        }
    }
}
