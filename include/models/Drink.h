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
        int liter;
        int price;

    public:
        Drink();
        Drink(string name, int liter);
        Drink(string name, int liter, int price);

        friend ostream& operator << (ostream& out, const Drink& drink);
        friend bool operator == (const Drink &left_drink, const Drink &right_drink);

        void write(ofstream& fout) const;
        void read(ifstream& fin);

        string getName() const;
        int getPrice() const;
        int getLiter() const;

        void setPrice(int price);
};

#endif // DRINK_H

