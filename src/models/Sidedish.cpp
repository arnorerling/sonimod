#include "SideDish.h"

SideDish::SideDish()
{
    name = "";
    price = 0;
}

void SideDish::write(ofstream& fout) const {

    int strLen = name.length() + 1;

    fout.write((char*)(&strLen), sizeof(int));
    fout.write(name.c_str(), strLen);
    fout.write((char*)(&price), sizeof(int));

}
void SideDish::read(ifstream& fin) {

    int strLen = name.length();

    fin.read((char*)(&strLen), sizeof(int));
    char *str = new char[strLen];
    fin.read(str, strLen);
    name = str;

    fin.read((char*)(&price), sizeof(int));

    delete[] str;
}

ostream& operator << (ostream& out, const SideDish& sidedish) {

    out << "Name: " << sidedish.name << " ";
    out << "Price: " << sidedish.price << endl;
    return out;
}

istream& operator >> (istream& in, SideDish& sidedish) {

    cout << "Name: ";
    in >> ws;
    getline(in, sidedish.name);
    cout << "Price: ";
    in >> sidedish.price;

    return in;
}

int SideDish::getPrice(){
    return this->price;
}

string SideDish::getName(){
    return this->name;
}
