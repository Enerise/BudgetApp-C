#include "PersonalBudget.h"
#include "AuxiliaryMethods.h"

void PersonalBudget::registerUser() {
    userManager.registerUser();
}

void PersonalBudget::loginUser() {
    userManager.loginUser();
    if(userManager.isUserLoggedIn()) {
        itemManager = new ItemManager(userManager.getLoggedInUserId(), NAME_FILE_WITH_INCOMES, NAME_FILE_WITH_EXPENSES);
    }
}

void PersonalBudget::changePassword() {
    userManager.changePassword();
}

void PersonalBudget::showAllUsers() {
    userManager.showAllUsers();
}

char PersonalBudget::selectOptionFromMainMenu() {
    char choice;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = AuxiliaryMethods::loadChar();

    return choice;
}

char PersonalBudget::selectOptionFromUserMenu() {
    char choice;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z biezacego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Zmien haslo" << endl;
    cout << "8. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = AuxiliaryMethods::loadChar();

    return choice;
}


int PersonalBudget::getLoggedInUserId() {
    return userManager.getLoggedInUserId();
}

void PersonalBudget::logoutUser() {

    userManager.logoutUser();
    delete itemManager;
    itemManager = NULL;
}

void PersonalBudget::addIncome() {
    if(userManager.isUserLoggedIn()) {
        itemManager->addIncome();
    } else {
        cout << "Aby dodac adresata, nalezy najpierw sie zalogowac" << endl;
        system("pause");
    }
}

void PersonalBudget::addExpense() {
    if(userManager.isUserLoggedIn()) {
        itemManager->addExpense();
    } else {
        cout << "Aby dodac adresata, nalezy najpierw sie zalogowac" << endl;
        system("pause");
    }
}

void PersonalBudget::displayCurrentMonthBalance() {
    if(userManager.isUserLoggedIn()) {
        itemManager->displayCurrentMonthBalance();
    } else {
        cout << "Aby dodac adresata, nalezy najpierw sie zalogowac" << endl;
        system("pause");
    }
}

void PersonalBudget::displayPreviousMonthBalance() {
    if(userManager.isUserLoggedIn()) {
        itemManager->displayPreviousMonthBalance();
    } else {
        cout << "Aby dodac adresata, nalezy najpierw sie zalogowac" << endl;
        system("pause");
    }
}

void PersonalBudget::displaySelectedPeriodBalance() {
    if(userManager.isUserLoggedIn()) {
        itemManager->displaySelectedPeriodBalance();
    } else {
        cout << "Aby dodac adresata, nalezy najpierw sie zalogowac" << endl;
        system("pause");
    }
}
