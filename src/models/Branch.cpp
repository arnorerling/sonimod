#include "Branch.h"

Branch::Branch()
{

}

Branch::Branch(string name) {
    this->name = name;
}


void Branch::write(ofstream& fout) const {

    int strLen = name.length() + 1;

    fout.write((char*)(&strLen), sizeof(int));
    fout.write(name.c_str(), strLen);
}

void Branch::read(ifstream& fin) {

    int strLen = name.length();

    fin.read((char*)(&strLen), sizeof(int));
    char *str = new char[strLen];

    fin.read(str, strLen);
    name = str;

    delete[] str;
}

ostream &operator <<(ostream &out, Branch &branch) {

    out << branch.name << endl;
    return out;
}

string Branch::getName(){
    return this->name;
}
