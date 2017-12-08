#ifndef MAINDOMAIN_H
#define MAINDOMAIN_H
#include "MainRep.h"
#include "InvalidInputException.h"
#include <string>
#include "Username.h"
using namespace std;

class MainDomain
{
    private:
        MainRep mainRep;

    public:
        MainDomain();
        bool checkValidInput(string &select);
        Username checkUser(string &name, string &password);
};

#endif // MAINDOMAIN_H
