#include "User.h"

User::User()
{
    //ctor
}

User::User(string username, string password, char jobNumber) {
    this->username = username;
    this->password = password;
    this->jobNumber = jobNumber;
}

void User::write(ofstream& fout) const {

    int strLen = username.length() + 1;
    fout.write((char*)(&strLen), sizeof(int));
    fout.write(username.c_str(), strLen);

    int strLen1 = password.length() + 1;
    fout.write((char*)(&strLen1), sizeof(int));
    fout.write(password.c_str(), strLen1);

    fout.write((char*)(&jobNumber), sizeof(int));
}

void User::read(ifstream& fin) {

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

string User::getName() const {
    return this->username;
}

string User::getPassword() const {
    return this->password;
}

char User::getJobNumber() const {
    return this->jobNumber;
}
