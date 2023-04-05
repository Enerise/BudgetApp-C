#ifndef ITEMMANAGER_H
#define ITEMMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>

#include "FileWithIncomes.h"
#include "FileWithExpenses.h"
#include "AuxiliaryMethods.h"
#include "DateManager.h"

using namespace std;

class ItemManager {
    vector <Income> incomes;
    vector <Expense> expenses;
    const int LOGGED_IN_USER_ID;
    FileWithIncomes fileWithIncomes;
    FileWithExpenses fileWithExpenses;
    DateManager dateManager;


    Income getNewIncomeData();
    Expense getNewExpenseData();

    string provideDate(char choice);

public:
    ItemManager(int loggedInUserId, string nameFileWithIncomes, string nameFileWithExpenses)
        : LOGGED_IN_USER_ID(loggedInUserId), fileWithIncomes(nameFileWithIncomes), fileWithExpenses(nameFileWithExpenses) {
        incomes = fileWithIncomes.loadIncomesFromFile(LOGGED_IN_USER_ID);
        expenses = fileWithExpenses.loadExpensesFromFile(LOGGED_IN_USER_ID);

    }
    void showAllIncomes();
    void showAllExpenses();
    void addIncome();
    void addExpense();
    void displayCurrentMonthBalance();
};

#endif
