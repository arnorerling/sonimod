#include "Drink.h"

Drink::Drink(){

	this->name = "";
	this->price = 0;
	this->liter = 0;
}

Drink::Drink(string name, int size, int price){

	this->name = name;
	this->liter = size;
    this->price = price;
}

void Drink::write(ofstream& fout) const {

    int strLen = name.length() + 1;
    fout.write((char*)(&strLen), sizeof(int));
    fout.write(name.c_str(), strLen);

    fout.write((char*)(&price), sizeof(int));
    fout.write((char*)(&liter), sizeof(int));
}

void Drink::read(ifstream& fin){

    int strLen = name.length();
    fin.read((char*)(&strLen), sizeof(int));

    char *str = new char[strLen];
    fin.read(str, strLen);
    name = str;

    fin.read((char*)(&price), sizeof(int));
    fin.read((char*)(&liter), sizeof(int));

    delete[] str;

}

ostream& operator << (ostream& out, const Drink& drink){

    out << "Name: " << drink.name << " ";
    out << "Size: " << drink.liter << " ";
    out << "Price: " << drink.price << endl;
    return out;
}

string Drink::getName() {
    return this->name;
}

int Drink::getPrice(){
    return this->price;
}

int Drink::getLiter() {
    return this->liter;
}
