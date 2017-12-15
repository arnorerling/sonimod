#include "MainDomain.h"

MainDomain::MainDomain()
{
    //ctor
}

void MainDomain::checkUserFile() {
    vector<User> userList = mainRep.getUsers();
}

bool MainDomain::checkValidInput(const string &select) {
    if (select.length() == 1) {
        return true;
    }
    throw InvalidInputException();
    return false;
}

User MainDomain::checkUser(const string &name, string &password) {
    vector<User> userList = mainRep.getUsers();
    char *arrchar = const_cast<char*>(password.c_str());
    arrchar = charmd5.digestString(arrchar);
    password = arrchar;
    for (unsigned int i = 0; i < userList.size(); i++){
        if (userList[i].getName() == name && userList[i].getPassword() == password) {
            return userList[i];
        }
    }
    throw NotFoundException();
}
