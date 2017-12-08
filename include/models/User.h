#ifndef USERNAME_H
#define USERNAME_H
#include <string>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


class User {
    private:
        string username;
        string password;
        char jobNumber;
    public:
        User();
        User(string username);
        User(string username, string password, char jobNumber);

        void read(ifstream& fin);
        void write(ofstream& fout) const;

        string getName() const;
        string getPassword() const;
        char getJobNumber() const;
        string getJob(char &jobNumber) const;

        friend ostream& operator << (ostream &out, User &user);
        friend bool operator == (const User &left_user, const User &right_user);
};

#endif // USERNAME_H
