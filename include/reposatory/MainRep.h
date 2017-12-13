#ifndef MAINREP_H
#define MAINREP_H
#include "NotFoundException.h"
#include "FileNotOpenException.h"
#include "MainRep.h"
#include "User.h"
#include <vector>
#include <string>
#include "md5.h"

class MainRep {

    private:
        MD5 charmd5;
    public:
        MainRep();
        vector<User> getUsers();
};

#endif // MAINREP_H
