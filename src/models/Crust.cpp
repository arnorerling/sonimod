#include "Crust.h"


Crust::Crust() {
	this->name = "";
	this->price = 0;
	this->inches = 0;
}

Crust::Crust(string name, int price, int inches) {

	this->name = name;
	this->price = price;
	this->inches = inches;
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
    out << "Price: " << crust.price;
	return out;
}

istream& operator >> (istream& in, Crust& crust) {

	cout << "Name: ";
	cin >> ws;
	getline(in, crust.name);
    cout << "Inches: ";
	in >> crust.inches;
    cout << "Price: ";
	in >> crust.price;
    return in;
}


string Crust::getName() {
    return this->name;
}

int Crust::getInches() {
    return this->inches;
}

int Crust::getPrice() {
    return this->price;
}
