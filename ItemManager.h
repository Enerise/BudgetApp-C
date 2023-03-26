#ifndef ITEM_H
#define ITEM_H

#include <iostream>

#include "FileWithIncomes.h"
#include "AuxiliaryMethods.h"

using namespace std;

class ItemManager{
    const int LOGGED_IN_USER_ID;
    FileWithIncomes fileWithIncomes;

public:
    ItemManager(string nameFileWithIncomes, int loggedInUserId)
        : fileWithIncomes(nameFileWithIncomes), LOGGED_IN_USER_ID(loggedInUserId)
        {
            //adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
        }

    void addIncome();
};

#endif
