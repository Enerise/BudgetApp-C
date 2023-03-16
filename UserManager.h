#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "User.h"

using namespace std;

class UserManager
{
    //int idZalogowanegoUzytkownika;
    vector <User> users;

    User enterNewUserData();
    int getNewUserId();
    bool loginExists(string login);
    //PlikZUzytkownikami plikZUzytkownikami;

    public:
        void registerUser();
};
