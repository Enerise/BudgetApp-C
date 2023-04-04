#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <vector>
#include <windows.h>

#include "FileWithIncomes.h"
#include "AuxiliaryMethods.h"
#include "DateManager.h"

using namespace std;

class ItemManager {
    vector <Income> incomes;
    const int LOGGED_IN_USER_ID;
    FileWithIncomes fileWithIncomes;
    DateManager dateManager;

    Income getNewIncomeData();

    string provideDate(char choice);

public:
    ItemManager(string nameFileWithIncomes, int loggedInUserId)
        : fileWithIncomes(nameFileWithIncomes), LOGGED_IN_USER_ID(loggedInUserId) {
        incomes = fileWithIncomes.loadIncomesFromFile(LOGGED_IN_USER_ID);
        //adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    }
    void  showAllIncomes();
    void addIncome();
};

#endif
