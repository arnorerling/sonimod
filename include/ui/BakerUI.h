#ifndef BAKERUI_H
#define BAKERUI_H

#include "BakerDomain.h"
#include "Branch.h"
#include "Output.h"
#include <vector>
#include <cstdlib>

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
