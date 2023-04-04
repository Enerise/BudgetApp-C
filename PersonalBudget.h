#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>

#include "UserManager.h"
#include "ItemManager.h"


using namespace std;

class PersonalBudget {
    UserManager userManager;
    ItemManager *itemManager;
    const string NAME_FILE_WITH_INCOMES;

public:
    PersonalBudget (string nameFileWithUsers, string nameFileWithIncomes):
        userManager(nameFileWithUsers), NAME_FILE_WITH_INCOMES(nameFileWithIncomes) {
        itemManager = NULL;
    };
    ~PersonalBudget() {
        delete itemManager;
        itemManager = NULL;
    }
    void registerUser();
    void loginUser();
    void changePassword();
    void logoutUser();

    void showAllUsers();
    int getLoggedInUserId();

    void addIncome();

    char selectOptionFromMainMenu();
    char selectOptionFromUserMenu();

};

#endif
