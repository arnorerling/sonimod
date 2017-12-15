#include "Crust.h"


Crust::Crust() {
	this->name = "";
	this->inches = 0;
	this->price = 0;
}

Crust::Crust(string name) {
	this->name = name;
	this->inches = 0;
	this->price = 0;
}

Crust::Crust(int inches) {
    this->name = "";
    this->inches = inches;
    this->price = 0;
}

Crust::Crust(string name, int inches) {
	this->name = name;
	this->inches = inches;
	this->price = 0;
}

Crust::Crust(string name, int inches, int price) {

	this->name = name;
	this->inches = inches;
	this->price = price;
}

void Crust::write(ofstream& fout) const {

    int strLen = name.length() + 1;
    fout.write((char*)(&strLen), sizeof(int));
    fout.write(name.c_str(), strLen);

    fout.write((char*)(&price), sizeof(int));
    fout.write((char*)(&inches), sizeof(int));
}

void Crust::read(ifstream& fin) {

    int strLen = name.length();
    fin.read((char*)(&strLen), sizeof(int));
    char *str = new char[strLen];
    fin.read(str, strLen);
    name = str;

    fin.read((char*)(&price), sizeof(int));
    fin.read((char*)(&inches), sizeof(int));

    delete[] str;
}

ostream& operator << (ostream& out, const Crust& crust) {

    out << "Name: " << crust.name << " ";
    out << "Inches: " << crust.inches << " ";
    out << "Price: " << crust.price << endl;
	return out;
}

bool operator == (const Crust &right_crust, const Crust &left_crust) {

    if (right_crust.name == left_crust.name) {
        if(right_crust.inches == left_crust.inches) {
            return true;
        }
    }
    return false;
}

string Crust::getName() const {
    return this->name;
}

int Crust::getInches() const {
    return this->inches;
}

int Crust::getPrice() const {
    return this->price;
}

void Crust::setName(const string &name) {
    this->name = name;
}

void Crust::setInches(int inches) {
    this->inches = inches;
}

void Crust::Crust::setPrice(int price){
    this->price = price;
}
