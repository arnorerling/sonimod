#include "Sidedish.h"

Sidedish::Sidedish()
{
    name = "";
    price = 0;
}

Sidedish::Sidedish(string name, int price) {
    this->name = name;
    this->price = price;
}

void Sidedish::write(ofstream& fout) const {

    int strLen = name.length() + 1;

    fout.write((char*)(&strLen), sizeof(int));
    fout.write(name.c_str(), strLen);
    fout.write((char*)(&price), sizeof(int));

}
void Sidedish::read(ifstream& fin) {

    int strLen = name.length();

    fin.read((char*)(&strLen), sizeof(int));
    char *str = new char[strLen];
    fin.read(str, strLen);
    name = str;

    fin.read((char*)(&price), sizeof(int));

    delete[] str;
}

ostream& operator << (ostream& out, const Sidedish& sidedish) {

    out << "Name: " << sidedish.name << " ";
    out << "Price: " << sidedish.price << endl;
    return out;
}

int Sidedish::getPrice(){
    return this->price;
}

string Sidedish::getName(){
    return this->name;
}
