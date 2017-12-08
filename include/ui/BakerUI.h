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

        vector<Order> orders;

        int ordersInBranch;

    public:

        BakerUI();

        void startUI();

        void initOrdersInBranch();

        void printRestaurants();

        void chooseRestaurant();

        void printChoices();

        void bakerChoices();

        void printOrderOptions();

        void orderOptions();

        void printOrders();

        void printOverwriteConfirmation(int orderNumber);

};

#endif // BAKERUI_H
