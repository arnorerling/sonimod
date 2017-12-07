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

        void printRestaurants();

        void chooseRestaurant();

        void printChoices();

        void bakerChoices();

        void printOrders();

        void printOrderOptions();

        void orderOptions();

};

#endif // BAKERUI_H
