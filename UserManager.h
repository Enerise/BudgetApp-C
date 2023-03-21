#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "User.h"
#include "FileWithUsers.h"

using namespace std;

class UserManager
{
    //int idZalogowanegoUzytkownika;
    vector <User> users;

    User enterNewUserData();
    int getNewUserId();
    bool loginExists(string login);
    FileWithUsers fileWithUsers;

    public:
        UserManager(string nazwaPlikuZUzytkownikami) : fileWithUsers(nazwaPlikuZUzytkownikami) {
        //idZalogowanegoUzytkownika = 0;
        //uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
    };
        void registerUser();
};

#endif
