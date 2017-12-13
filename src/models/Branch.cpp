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

ostream &operator << (ostream &out, const Branch &branch) {
    out << branch.name << endl;
    return out;
}

bool operator == (const Branch &left_branch, const Branch &right_branch) {
    if (left_branch.name == right_branch.name) {
        return true;
    }
    return false;
}

string Branch::getName()const {
    return this->name;
}

void Branch::setName(const string name) {
    this->name = name;
}
