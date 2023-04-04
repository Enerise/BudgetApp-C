#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H

#include <iostream>
#include <vector>

#include "Expense.h"
#include "AuxiliaryMethods.h"
#include "Markup.h"

using namespace std;

class FileWithExpenses {

    vector <Expense> expenses;
    const string NAME_FILE_WITH_EXPENSES;
    int lastExpenseId;
    int userIdInFile;

public:
    FileWithExpenses(string nameFileWithExpenses) : NAME_FILE_WITH_EXPENSES(nameFileWithExpenses) {
        lastExpenseId = 0;
    }
    vector <Expense> loadExpensesFromFile(int loggedUserId);

    void changeDateInFile(int expenseId);
    bool addExpenseToFile(Expense expense);
    int getLastExpenseId();
};



#endif
