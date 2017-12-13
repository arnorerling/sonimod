#ifndef BAKERUI_H
#define BAKERUI_H

#include <iostream>
#include "BakerDomain.h"
#include "Output.h"
#include <cstdlib>

using namespace std;

class BakerUI
{
    private:

        BakerDomain bakerDomain;
        Output output;
        string branch;

    public:

        BakerUI();
        void startUI();
        void chooseRestaurant();

        void printRestaurants();
        void printOrders();
        void printOneOrder();
        Order findOrder();

        void markInProcess();
        void markReady();

        string checkName();
        char checkInput();
        string checkNumber();

        void printLogo();
};

#endif // BAKERUI_H
