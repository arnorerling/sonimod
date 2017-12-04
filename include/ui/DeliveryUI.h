#ifndef DELIVERYUI_H
#define DELIVERYUI_H
#include "DeliveryDomain.h"

class DeliveryUI
{
    private:
        DeliveryDomain deliveryDomain;
        vector<Branch> branchList;

    public:
        DeliveryUI();
        void startUI();
        void printRestaurants();
        void chooseRestaurant();
};

#endif // DELIVERYUI_H
