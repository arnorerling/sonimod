#include "Username.h"

Username::Username()
{
    //ctor
}

Username::Username(string username, string password, char jobNumber) {
    this->username = username;
    this->password = password;
    this->jobNumber = jobNumber;
}

void Username::write(ofstream& fout) const {

    int strLen = username.length() + 1;
    fout.write((char*)(&strLen), sizeof(int));
    fout.write(username.c_str(), strLen);

    int strLen1 = password.length() + 1;
    fout.write((char*)(&strLen1), sizeof(int));
    fout.write(password.c_str(), strLen1);

    fout.write((char*)(&jobNumber), sizeof(int));
}

void Username::read(ifstream& fin) {

    int strLen = username.length();
    fin.read((char*)(&strLen), sizeof(int));
    char *str = new char[strLen];
    fin.read(str, strLen);
    username = str;

    int strLen1 = password.length();
    fin.read((char*)(&strLen1), sizeof(int));
    char *str1 = new char[strLen1];
    fin.read(str1, strLen1);
    password= str1;

    fin.read((char*)(&jobNumber), sizeof(int));

    delete[] str;
    delete[] str1;
}

string Username::getName() const {
    return this->username;
}

string Username::getPassword() const {
    return this->password;
}

char Username::getJobNumber() const {
    return this->jobNumber;
}
