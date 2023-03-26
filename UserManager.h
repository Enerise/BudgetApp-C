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
    int loggedInUserId;
    vector <User> users;

    User enterNewUserData();
    int getNewUserId();
    bool loginExists(string login);
    FileWithUsers fileWithUsers;

    public:
        UserManager(string nameFileWithUsers) : fileWithUsers(nameFileWithUsers) {
        loggedInUserId = 0;
        users = fileWithUsers.loadUsersFromFile();
    };
        void registerUser();
        void loginUser();
        void changePassword();
        void showAllUsers();
        int logoutUser();

        int getLoggedInUserId();
};

#endif
