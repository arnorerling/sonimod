#ifndef BAKERUI_H
#define BAKERUI_H

#include "BakerDomain.h"
#include "Branch.h"
#include <vector>

class BakerUI
{
    private:

        BakerDomain bakerDomain;
        Branch branch;
        int ordersInBranch;

    public:

        BakerUI();
        void startUI();

        void printRestaurants();

        void initOrdersInBranch();


        void chooseRestaurant();

        void bakerChoices();

        void orderOptions();

        void printOrders();

        void printOverwriteConfirmation(int orderNumber);

        string checkName();
        char checkInput();

};

#endif // BAKERUI_H
