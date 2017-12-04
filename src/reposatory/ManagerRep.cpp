#include "ManagerRep.h"

ManagerRep::ManagerRep()
{
    //ctor
}

void ManagerRep::addCrust(const Crust &crust) {
    ofstream fout;
    fout.open("Crust_Binary.dat", ios::binary|ios::app);
    if(fout.is_open()) {
        crust.write(fout);
        fout.close();
    }
    else {
        cout << "File did not open" << endl;
    }
}

void ManagerRep::addTopping(const Topping &topping) {
    ofstream fout;
    fout.open("Topping_Binary.dat", ios::binary|ios::app);
    if(fout.is_open()) {
        topping.write(fout);
        fout.close();
    }
    else {
        cout << "File did not open" << endl;
    }
}

void ManagerRep::addDrink(const Drink &drink) {
    ofstream fout;
    fout.open("Drink_Binary.dat", ios::binary|ios::app);
    if(fout.is_open()) {
        drink.write(fout);
        fout.close();
    }
    else {
        cout << "File did not open" << endl;
    }
}

void ManagerRep::addSidedish(const Sidedish &sidedish) {
    ofstream fout;
    fout.open("Sidedish_Binary.dat", ios::binary|ios::app);
    if(fout.is_open()) {
        sidedish.write(fout);
        fout.close();
    }
    else {
        cout << "File did not open" << endl;
    }
}

void ManagerRep::addBranch(const Branch &branch) {
    ofstream fout;
    fout.open("Branch_Binary.dat", ios::binary|ios::app);
    if(fout.is_open()) {
        branch.write(fout);
        fout.close();
    }
    else {
        cout << "File did not open" << endl;
    }
}

void ManagerRep::printDrinks() {
    Drink drink;
    ifstream fin;
    fin.open("Drink_Binary.dat", ios::binary);
    if(fin.is_open()) {
        while(!fin.eof()){
            drink.read(fin);
            if(!fin.eof()){
                cout << drink << endl;
            }
        }
        fin.close();
    }
}
