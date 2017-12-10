#ifndef DELIVERYUI_H
#define DELIVERYUI_H
#include "DeliveryDomain.h"
#include <cstdlib>

class DeliveryUI
{
    private:
        DeliveryDomain deliveryDomain;
        string branch;

    public:
        DeliveryUI();
        void startUI();
        void chooseRestaurant();

        void printRestaurants();
        void printOrders();
        void printReadyOrders();
        void printOneOrder();

        void markPaidFor();
        void markDelivered();

        Order findOrder();
        char checkInput();
        string checkName();
        string checkNumber();

        void printLogo();
};

#endif // DELIVERYUI_H
