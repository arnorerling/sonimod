#include "Topping.h"

Topping::Topping(){
	this->name[0] = '\0';
	this->price = 0;
}

Topping::Topping(string name){

	this->name = name;
	this->price = 0;
}

Topping::Topping(string name, int price){

	this->name = name;
	this->price = price;
}

void Topping::write(ofstream& fout) const {

    int strLen = name.length() + 1;
    fout.write((char*)(&strLen), sizeof(int));
    fout.write(name.c_str(), strLen);

    fout.write((char*)(&price), sizeof(int));
}

void Topping::read(ifstream& fin) {
    int strLen = name.length();

    fin.read((char*)(&strLen), sizeof(int));
    char *str = new char[strLen];
    fin.read(str, strLen);
    name = str;

    fin.read((char*)(&price), sizeof(int));

    delete[] str;
}

ostream& operator << (ostream& out, const Topping& topping){

    out << "Name: " << topping.name << " ";
    out << "Price: " << topping.price << endl;
	return out;

}

string Topping::getName() const {
    return this->name;
}

int Topping::getPrice() const {
	return this->price;
}

void Topping::setPrice(int price){
    this->price = price;
}
