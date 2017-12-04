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
        friend istream& operator >> (istream& in, Drink& drink);

        void write(ofstream& fout) const;
        void read(ifstream& fin);

        string getName();
        int getPrice();
        int getLiter();
};

#endif // DRINK_H

