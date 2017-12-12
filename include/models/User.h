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
        User();
        User(string username);
        User(string username, string password, char jobNumber);

        void read(ifstream& fin);
        void write(ofstream& fout) const;

        string getName() const;
        string getPassword() const;
        char getJobNumber() const;
        string getJob() const;

        void setName(const string &name);
        void setPassword(const string &pw);
        void setJobNumber(const int &num);

        friend ostream& operator << (ostream &out, User &user);
        friend bool operator == (const User &left_user, const User &right_user);
};

#endif // USERNAME_H
