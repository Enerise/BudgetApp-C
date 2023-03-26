#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

#include <iostream>
#include <vector>

#include "Income.h"
#include "AuxiliaryMethods.h"

using namespace std;

class FileWithIncomes{

    vector <Income> incomes;
    const string NAME_FILE_WITH_INCOMES;

public:
    FileWithIncomes(string nameFileWithIncomes) : NAME_FILE_WITH_INCOMES(nameFileWithIncomes)
    {
    }
    //void addUserToFile(User user);
};



#endif
