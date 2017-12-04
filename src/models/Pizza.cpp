#include "Pizza.h"
using namespace std;

Pizza::Pizza() {
    price = 0;
}

Pizza::Pizza(string &name, vector<Topping> &toppings, Crust &crust, int &price) {
    this->name = name;
    this->toppings = toppings;
    this->crust = crust;
    this->price = price;
}

void Pizza::write(ofstream& fout) const {

    int strLen = name.length() + 1;
    fout.write((char*)(&strLen), sizeof(int));
    fout.write(name.c_str(), strLen);

    int tCount = toppings.size();
    fout.write((char*)(&tCount), sizeof(int));

    for (int i = 0; i < tCount; i++) {
        fout.write((char*)(&toppings[i]), sizeof(Topping));
    }

    fout.write((char*)(&crust), sizeof(Crust));

    fout.write((char*)(&price), sizeof(int));
}

void Pizza::read(ifstream& fin) {

    int strLen = name.length();

    fin.read((char*)(&strLen), sizeof(int));
    char *str = new char[strLen];
    fin.read(str, strLen);
    name = str;

    int tCount;
    fin.read((char*)(&tCount), sizeof(int));

    Topping topping;
    for (int i = 0; i < tCount; i++) {
        fin.read((char*)(&topping), sizeof(Topping));
        toppings.push_back(topping);
    }
    fin.read((char*)(&crust), sizeof(Crust));
    fin.read((char*)(&price), sizeof(int));

    delete[] str;
}

/*Topping Pizza::addTopping() {
    Topping topping;
    string choose = " ";

    cout << "------Topping List------" << endl;
    ifstream fin;
    fin.open("Toppings_Binary.dat", ios::binary);
    while(!fin.eof()) {
        topping.read(fin);
        if(!fin.eof()) {
        cout << topping;
        }
    }
    cout << "-----------------------" << endl;
    fin.close();

    while (choose != topping.getName()) {
        cout << "Choose a topping" << endl;
        cin >> ws;
        getline(cin, choose);

        fin.open("Toppings_Binary.dat", ios::binary);
        while(!fin.eof()) {
            topping.read(fin);
            if(choose == topping.getName()){
                fin.close();
                return topping;
            }
        }
        cout << "This topping is not avalible" << endl;
        fin.close();
    }
}

Crust Pizza::addCrust() {
    Crust crust;
    string choose = " ";
    int inches = 0;

    cout << "------Crust List------" << endl;
    ifstream fin;
    fin.open("Crusts_Binary.dat", ios::binary);
    while(!fin.eof()) {
        crust.read(fin);
        if(!fin.eof()) {
        cout << crust << endl;
        }
    }
    cout << "-----------------------" << endl;
    fin.close();

    while (choose != crust.getName() && inches != crust.getInches()) {
        cout << "Choose a crust" << endl;
        cin >> ws;
        getline(cin, choose);
        cout << "Choose size" << endl;
        cin >> inches;

        fin.open("Crusts_Binary.dat", ios::binary);
        while(!fin.eof()) {
            crust.read(fin);
            if(choose == crust.getName() && inches == crust.getInches()){
                fin.close();
                return crust;
            }
        }
        cout << "This crust is not avalible" << endl;
        fin.close();
    }

}

void Pizza::displayPizza(Pizza& pizza) {
    cout << pizza;
=======
>>>>>>> afdc87cafd30aff0bb023ca10c658deeb2b6737d
}*/

void Pizza::setPrice(){
    for(unsigned int i = 0;this->toppings.size(); i++){
        this->price += this->toppings[i].getPrice();
    }
    this->price += this->crust.getPrice();
}

int Pizza::getPrice(){
    return this->price;
}


