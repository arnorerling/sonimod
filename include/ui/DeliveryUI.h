#ifndef DELIVERYUI_H
#define DELIVERYUI_H
#include "DeliveryDomain.h"

class DeliveryUI
{
    private:
        DeliveryDomain deliveryDomain;
        string branch;

    public:
        DeliveryUI();
        void startUI();
        void printRestaurants();
        void printReadyOrders();
        void chooseRestaurant();

        char checkInput();
        string checkName();
};

#endif // DELIVERYUI_H
