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
        // Constructor
        MainDomain();

        //checks if user file exists
        void checkUserFile();
        //check if input is valid (1 digit)
        bool checkValidInput(string &select);
        //check if user is in file
        User checkUser(string &name, string &password);
};

#endif // MAINDOMAIN_H
