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
        friend bool operator == (const Sidedish &left_side, const Sidedish &right_side);

        string getName() const;
        int getPrice() const;

        void setName(const string &name);
        void setPrice(const int &price);
};

#endif // SIDEDISH_H

