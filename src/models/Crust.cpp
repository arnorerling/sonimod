#include "Crust.h"


Crust::Crust() {
	this->name = "";
	this->price = 0;
	this->inches = 0;
}

Crust::Crust(string name, int inches){
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

string Crust::getName() const {
    return this->name;
}

int Crust::getInches() const {
    return this->inches;
}

int Crust::getPrice() const {
    return this->price;
}

void Crust::setPrice(int price){
    this->price = price;
}
