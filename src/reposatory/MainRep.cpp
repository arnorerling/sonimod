#include "MainRep.h"

MainRep::MainRep() {

}

vector<Username> MainRep::getUsers() {
    vector <Username> usernames;
    ifstream fin;
    fin.open("Users_Binary.dat", ios::binary);
    if(fin.is_open()) {
        Username username;
        while(!fin.eof()){
            username.read(fin);
            if(!fin.eof()){
                usernames.push_back(username);
            }
        }
        fin.close();
    }
    return usernames;
}
