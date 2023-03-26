#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>

#include "UserManager.h"


using namespace std;

class PersonalBudget
{
    UserManager userManager;

public:
PersonalBudget (string nameFileWithUsers): userManager(nameFileWithUsers){
    };
    void registerUser();
    void loginUser();
    void changePassword();
    void logoutUser();

    void showAllUsers();
    int getLoggedInUserId();

    char selectOptionFromMainMenu();
    char selectOptionFromUserMenu();
};

#endif
