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

vector<Drink> ManagerRep::getDrink() {
    vector <Drink> drinks;
    ifstream fin;
    fin.open("Drink_Binary.dat", ios::binary);
    if(fin.is_open()) {
        Drink drink;
        while(!fin.eof()){
            drink.read(fin);
            if(!fin.eof()){
                drinks.push_back(drink);
            }
        }
        fin.close();
    }
    return drinks;
}

vector<Sidedish> ManagerRep::getSidedish() {
    vector <Sidedish> sidedishes;
    ifstream fin;
    fin.open("Sidedish_Binary.dat", ios::binary);
    if(fin.is_open()) {
        Sidedish sidedish;
        while(!fin.eof()){
            sidedish.read(fin);
            if(!fin.eof()){
                sidedishes.push_back(sidedish);
            }
        }
        fin.close();
    }
    return sidedishes;
}

vector<Branch> ManagerRep::getBranch() {
    vector <Branch> branches;
    ifstream fin;
    fin.open("Branch_Binary.dat", ios::binary);
    if(fin.is_open()) {
        Branch branch;
        while(!fin.eof()){
            branch.read(fin);
            if(!fin.eof()){
                branches.push_back(branch);
            }
        }
        fin.close();
    }
    return branches;
}

void ManagerRep::changeDrinkList(vector<Drink> &drinks) {

    ofstream fout;
    fout.open("Drink_Binary.dat", ios::binary);
    if(fout.is_open()) {
        for (int i = 0; i < drinks.size(); i++) {
            drinks[i].write(fout);
        }
        fout.close();
    }
    else {
        cout << "File did not open" << endl;
    }
}

void ManagerRep::changeSidedishList(vector<Sidedish> &sidedishes) {

    ofstream fout;
    fout.open("Sidedish_Binary.dat", ios::binary);
    if(fout.is_open()) {
        for (int i = 0; i < sidedishes.size(); i++) {
            sidedishes[i].write(fout);
        }
        fout.close();
    }
    else {
        cout << "File did not open" << endl;
    }
}

 void ManagerRep::changeBranchList(vector<Branch> &branches) {

    ofstream fout;
    fout.open("Branch_Binary.dat", ios::binary);
    if(fout.is_open()) {
        for (int i = 0; i < branches.size(); i++) {
            branches[i].write(fout);
        }
        fout.close();
    }
    else {
        cout << "File did not open" << endl;
    }
 }
