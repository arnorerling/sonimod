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
        //constructors
        Sidedish();
        Sidedish(string name);
        Sidedish(string name, int price);

        //read and writes into files
        void write(ofstream& fout) const;
        void read(ifstream& fin);

        //overwrite cout operator for sidedish class
        friend ostream& operator << (ostream& out, const Sidedish& sidedish);
        //checks if two sidedishes have the same name
        friend bool operator == (const Sidedish &left_side, const Sidedish &right_side);

        //gets private variables
        string getName() const;
        int getPrice() const;

        //sets private variables
        void setName(const string &name);
        void setPrice(const int &price);
};

#endif // SIDEDISH_H

