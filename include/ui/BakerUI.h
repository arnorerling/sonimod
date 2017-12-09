#ifndef BAKERUI_H
#define BAKERUI_H

#include "BakerDomain.h"
#include "Branch.h"
#include <vector>

class BakerUI
{
    private:

        BakerDomain bakerDomain;
        string branch;

    public:

        BakerUI();
        void startUI();

        void printRestaurants();
        void printOrders();
        void printOneOrder();

        void initOrdersInBranch();


        void chooseRestaurant();

        void bakerChoices();

        void orderOptions();


        void printOverwriteConfirmation(int orderNumber);

        string checkName();
        char checkInput();
        string checkNumber();

};

#endif // BAKERUI_H
