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
        //constructors
        Drink();
        Drink(string name);
        Drink(string name, int liter);
        Drink(string name, int liter, int price);

        //read and write into files
        void write(ofstream& fout) const;
        void read(ifstream& fin);

        //overwrites cout for drink class
        friend ostream& operator << (ostream& out, const Drink& drink);
        //checks if two drinks have the same name
        friend bool operator == (const Drink &left_drink, const Drink &right_drink);

        //gets private variables
        string getName() const;
        int getLiter() const;
        int getPrice() const;

        //sets private variables
        void setName(const string name);
        void setLiter(const int liter);
        void setPrice(const int price);
};

#endif // DRINK_H

