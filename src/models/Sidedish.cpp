#include "Sidedish.h"

Sidedish::Sidedish() {
    name = "";
    price = 0;
}

Sidedish::Sidedish(string name) {
    this->name = name;
    this->price = 0;
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
    out << "Price: " << sidedish.price;
    return out;
}

bool operator == (const Sidedish &left_side, const Sidedish &right_side) {
    if (left_side.name == right_side.name) {
        return true;
    }
    return false;
}

string Sidedish::getName() const {
    return this->name;
}

int Sidedish::getPrice() const {
    return this->price;
}

void Sidedish::setName(const string &name) {
    this->name = name;
}

void Sidedish::setPrice(const int &price) {
    this->price = price;
}
