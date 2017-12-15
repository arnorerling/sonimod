#ifndef USERNAME_H
#define USERNAME_H
#include <string>
#include <iostream>
#include <fstream>
#include "md5.h"

using namespace std;


class User {
    private:
        string username;
        string password;
        char jobNumber;
        MD5 charmd5;

    public:
        //constructors
        User();
        User(string username);
        User(string username, string password, char jobNumber);

        //read and write into files
        void read(ifstream& fin);
        void write(ofstream& fout) const;

        //gets private variables
        string getName() const;
        string getPassword() const;
        char getJobNumber() const;
        string getJob() const;

        //sets private variables
        void setName(const string &name);
        void setPassword(const string &pw);
        void setJobNumber(int num);

        //overwrites cout operator
        friend ostream& operator << (ostream &out, User &user);
        //checks if two users have the same name
        friend bool operator == (const User &left_user, const User &right_user);
};

#endif // USERNAME_H
