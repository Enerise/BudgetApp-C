#include "ItemManager.h"


void ItemManager::addIncome() {
    showAllIncomes();
    system("pause");
    Income income;
    int lastIdIncome;
    system("cls");
    cout << " >>> DODAWANIE NOWEGO PRZYCHODU <<<" << endl << endl;
    income = getNewIncomeData();

    incomes.push_back(income);
    if(fileWithIncomes.addIncomeToFile(income)) {
        lastIdIncome = fileWithIncomes.getLastIncomeId();
        fileWithIncomes.changeDateInFile(lastIdIncome);
        cout << "Nowy przychod zostal dodany" << endl;
    }

    else
        cout << "Blad. Nie udalo sie dodac nowego przychodu do pliku." << endl;
    system("pause");
}

Income ItemManager::getNewIncomeData() {

    Income income;
    string dateStr, item;
    int incomeId, userId, dateInt;
    float amount;
    char choice;

    income.setIncomeId( fileWithIncomes.getLastIncomeId() + 1);
    income.setUserId(LOGGED_IN_USER_ID) ;

    cout << "Czy przychod ma zostac dodany z data dzisiejsza?" << endl;;
    cout << "Jesli tak wcisnij klawisz 't'" << endl;
    cout << "Jesli nie wcisnij klawisz 'n'" << endl;
    choice = AuxiliaryMethods::loadChar();

    income.setDate(provideDate(choice));

    cout << "Podaj nazwe/opis przychodu: ";
    item = AuxiliaryMethods::loadLine();

    cout << "Podaj kwote przychodu: ";
    amount = AuxiliaryMethods::loadAmount();

    income.setItem(item);
    income.setAmount(amount);

    return income;
}

string ItemManager::provideDate(char choice) {
    string dateStr;
    while(true) {
        if (choice == 't') {
            dateStr = dateManager.getCurrentDateWithoutDashes();
            return dateStr;
        } else if(choice == 'n') {
            cout << "Wprowadz date w formacie rrrr-mm-dd" << endl;
            dateStr = AuxiliaryMethods::loadLine();
            if(dateManager.isDateCorrect(dateStr)) {
                dateStr = AuxiliaryMethods::removeDashesFromDate(dateStr);
                return dateStr;
            } else
                cout << "Data niepoprawna. Wprowadz ponownie date w formacie rrrr-mm-dd";
        }
    }
}

void ItemManager::showAllIncomes() {

    for (int i = 0; i < incomes.size(); i++) {
        cout << "Income ID: " << incomes[i].getIncomeId() << endl;
        cout << "User ID: " << incomes[i].getUserId() << endl;
        cout << "Date: " << incomes[i].getDate() << endl;
        cout << "Item: " << incomes[i].getItem() << endl;
        cout << "UAmoutn: " << incomes[i].getAmount() << endl << endl;
    }

}
