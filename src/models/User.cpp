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

User::User(string username) {
    this->username = username;
    this->password = "";
    this->jobNumber = '\0';
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

string User::getJob(char &jobNumber) const{
    switch(jobNumber) {
        case '1': return "Mananger";
        break;
        case '2': return "Sales";
        break;
        case '3': return "Baker";
        break;
        case '4': return "Delivery";
        break;
        default: return "Invalid job";
    }
}

ostream& operator << (ostream &out, User &user) {
    out << "Username: " << user.username;
    out << " Job: " << user.getJob(user.jobNumber) << endl;
    return out;
}

bool operator == (const User &left_user, const User &right_user) {
    if (left_user.username == right_user.username) {
        return true;
    }
    return false;
}
