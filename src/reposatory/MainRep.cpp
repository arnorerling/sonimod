#include "MainRep.h"

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
    return users;
}
