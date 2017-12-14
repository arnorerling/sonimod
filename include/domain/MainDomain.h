#ifndef MAINDOMAIN_H
#define MAINDOMAIN_H
#include "MainRep.h"
#include "InvalidInputException.h"
#include "NotFoundException.h"
using namespace std;

class MainDomain
{
    private:
        MainRep mainRep;
        MD5 charmd5;

    public:
        MainDomain();
        void checkUserList();
        bool checkValidInput(string &select);
        User checkUser(string &name, string &password);
};

#endif // MAINDOMAIN_H
