#ifndef SIDEDISH_H
#define SIDEDISH_H

#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


class SideDish {

    private:
        string name;
        int price;

    public:
        SideDish();

        void write(ofstream& fout) const;
        void read(ifstream& fin);

        friend ostream& operator << (ostream& out, const SideDish& sidedish);
        friend istream& operator >> (istream& in, SideDish& sidedish);

        int getPrice();
        string getName();
};

#endif // SIDEDISH_H

