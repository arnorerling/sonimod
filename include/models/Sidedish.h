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
        Sidedish(string name);
        Sidedish(string name, int price);

        void write(ofstream& fout) const;
        void read(ifstream& fin);

        friend ostream& operator << (ostream& out, const Sidedish& sidedish);

        int getPrice() const;
        string getName() const;

        void setPrice(int price);
};

#endif // SIDEDISH_H

