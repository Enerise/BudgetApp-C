#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

#include <iostream>
#include <vector>

#include "Income.h"
#include "AuxiliaryMethods.h"
#include "Markup.h"

using namespace std;

class FileWithIncomes{

    vector <Income> incomes;
    const string NAME_FILE_WITH_INCOMES;
    int lastIncomeId;
    int userIdInFile;

public:
    FileWithIncomes(string nameFileWithIncomes) : NAME_FILE_WITH_INCOMES(nameFileWithIncomes)
    {
        lastIncomeId = 0;
    }
    vector <Income> loadIncomesFromFile(int loggedUserId);

    //int getLastIncomeIdFromFile(int loggedUserId);
    void changeDateInFile(int incomeId);
    bool addIncomeToFile(Income income);
    int getLastIncomeId();
};



#endif
