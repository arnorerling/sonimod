#ifndef SIDEDISH_H
#define SIDEDISH_H

#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


class Sidedish {

    private:
        string name;
        int price;

    public:
        Sidedish();
        Sidedish(string name, int price);

        friend ostream& operator << (ostream& out, const Sidedish& sidedish);
        int getPrice();
        string getName();
};

#endif // SIDEDISH_H

