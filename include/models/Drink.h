#ifndef DRINK_H
#define DRINK_H

#include <iostream>
#include <string>
#include <fstream>
#include <string>
using namespace std;

class Drink
{
    private:
        string name;
        int price;
        int liter;

    public:
        Drink();
        Drink(string name, int price, int size);

        friend ostream& operator << (ostream& out, const Drink& drink);

        string getName();
        int getPrice();
        int getLiter();
};

#endif // DRINK_H

