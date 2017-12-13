#include "MainRep.h"
#include "md5.h"

MainRep::MainRep() {

}

vector<User> MainRep::getUsers() {
    vector <User> users;
    ifstream fin;
    fin.open("Users_Binary.dat", ios::binary);
    if(fin.is_open()) {
        User user;
        while(!fin.eof()){
            user.read(fin);
            if(!fin.eof()){
                users.push_back(user);
            }
        }
        fin.close();
    }
    else {
        User user;
        user.setName("admin");
        user.setJobNumber('1');
        string password = "admin";
        char *arrChar = const_cast<char*>(password.c_str());
        arrChar = charmd5.digestString(arrChar);
        user.setPassword(arrChar);
        ofstream fout;
        fout.open("Users_Binary.dat", ios::binary);
        user.write(fout);
        fout.close();
        throw FileNotOpenException();
    }
    return users;
}
