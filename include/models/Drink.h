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
        Drink(string name);
        Drink(string name, int liter);
        Drink(string name, int liter, int price);

        void write(ofstream& fout) const;
        void read(ifstream& fin);

        friend ostream& operator << (ostream& out, const Drink& drink);
        friend bool operator == (const Drink &left_drink, const Drink &right_drink);

        string getName() const;
        int getLiter() const;
        int getPrice() const;

        void setName(const string name);
        void setLiter(const int liter);
        void setPrice(const int price);
};

#endif // DRINK_H

