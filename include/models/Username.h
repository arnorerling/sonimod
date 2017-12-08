#ifndef USERNAME_H
#define USERNAME_H
#include <string>
#include <iostream>
#include <fstream>
using namespace std;


class Username
{
    private:
        string username;
        string password;
        char jobNumber;
    public:
        Username();
        Username(string username, string password, char jobNumber);

        void read(ifstream& fin);
        void write(ofstream& fout) const;

        string getName() const;
        string getPassword() const;
        char getJobNumber() const;
};

#endif // USERNAME_H
