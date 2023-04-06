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
    const string NAME_FILE_WITH_EXPENSES;

public:
    PersonalBudget (string nameFileWithUsers, string nameFileWithIncomes, string nameFileWithExpenses):
        userManager(nameFileWithUsers), NAME_FILE_WITH_INCOMES(nameFileWithIncomes), NAME_FILE_WITH_EXPENSES(nameFileWithExpenses) {
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
    void addExpense();
    void displayCurrentMonthBalance();
    void displayPreviousMonthBalance();
    void displaySelectedPeriodBalance();

    char selectOptionFromMainMenu();
    char selectOptionFromUserMenu();

};

#endif
