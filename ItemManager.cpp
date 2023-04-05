#include "ItemManager.h"


void ItemManager::addIncome() {
    showAllIncomes();
    system("pause");
    Income income;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO PRZYCHODU <<<" << endl << endl;
    income = getNewIncomeData();

    incomes.push_back(income);
    if(fileWithIncomes.addIncomeToFile(income)) {
        //lastIdIncome = fileWithIncomes.getLastIncomeId();
        //fileWithIncomes.changeDateInFile(lastIdIncome);
        cout << "Nowy przychod zostal dodany" << endl;
    }

    else
        cout << "Blad. Nie udalo sie dodac nowego przychodu do pliku." << endl;
    system("pause");
}

Income ItemManager::getNewIncomeData() {

    Income income;
    string dateStr, item;
    float amount;
    char choice;
    //int dataInt;

    income.setIncomeId( fileWithIncomes.getLastIncomeId() + 1);
    income.setUserId(LOGGED_IN_USER_ID) ;

    cout << "Czy przychod ma zostac dodany z data dzisiejsza?" << endl;;
    cout << "Jesli tak wcisnij klawisz 't'" << endl;
    cout << "Jesli nie wcisnij klawisz 'n'" << endl;
    choice = AuxiliaryMethods::loadChar();
    dateStr = provideDate(choice);

    income.setDate(AuxiliaryMethods::addDashesToDate(dateStr));
    income.setDateInt(AuxiliaryMethods::convertStringtoInteger(dateStr));

    cout << "Podaj nazwe/opis przychodu: ";
    item = AuxiliaryMethods::loadLine();

    cout << "Podaj kwote przychodu: ";
    amount = AuxiliaryMethods::loadAmount();

    income.setItem(item);
    income.setAmount(amount);

    return income;
}

void ItemManager::addExpense(){
    showAllExpenses();
    system("pause");
    Expense expense;
    //int lastIdExpense;
    system("cls");
    cout << " >>> DODAWANIE NOWEGO WYDATKU <<<" << endl << endl;
    expense = getNewExpenseData();

    expenses.push_back(expense);
    if(fileWithExpenses.addExpenseToFile(expense)) {
        //lastIdExpense = fileWithExpenses.getLastExpenseId();
        //fileWithExpenses.changeDateInFile(lastIdExpense);
        cout << "Nowy wydatek zostal dodany" << endl;
    }

    else
        cout << "Blad. Nie udalo sie dodac nowego wydatku do pliku." << endl;
    system("pause");
}

Expense ItemManager::getNewExpenseData() {

    Expense expense;
    string dateStr, item;
    float amount;
    char choice;

    expense.setExpenseId( fileWithExpenses.getLastExpenseId() + 1);
    expense.setUserId(LOGGED_IN_USER_ID) ;

    cout << "Czy wydatek ma zostac dodany z data dzisiejsza?" << endl;;
    cout << "Jesli tak wcisnij klawisz 't'" << endl;
    cout << "Jesli nie wcisnij klawisz 'n'" << endl;
    choice = AuxiliaryMethods::loadChar();

    dateStr = (provideDate(choice));

    expense.setDate(AuxiliaryMethods::addDashesToDate(dateStr));
    expense.setDateInt(AuxiliaryMethods::convertStringtoInteger(dateStr));

    cout << "Podaj nazwe/opis wydatku: ";
    item = AuxiliaryMethods::loadLine();

    cout << "Podaj kwote wydatku: ";
    amount = AuxiliaryMethods::loadAmount();

    expense.setItem(item);
    expense.setAmount(amount);

    return expense;
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
                cout << "Data niepoprawna" << endl;
        }
    }
}

void ItemManager::displayCurrentMonthBalance() {
    int currentMonth;
   currentMonth = dateManager.getCurrentDateWithoutDayAndDashes();
    cout << currentMonth << endl;
    system("pause");


}

void ItemManager::showAllIncomes() {

    int vectorSize = incomes.size();
    for (int i = 0; i < vectorSize; i++) {
        cout << "Income ID: " << incomes[i].getIncomeId() << endl;
        cout << "User ID: " << incomes[i].getUserId() << endl;
        cout << "Date: " << incomes[i].getDate() << endl;
        cout << "Item: " << incomes[i].getItem() << endl;
        cout << "UAmoutn: " << incomes[i].getAmount() << endl;
        cout << "DateInt: " << incomes[i].getDateInt() << endl << endl;
    }

}

void ItemManager::showAllExpenses() {

    int vectorSize = expenses.size();
    for (int i = 0; i < vectorSize; i++) {
        cout << "Income ID: " << expenses[i].getExpenseId() << endl;
        cout << "User ID: " << expenses[i].getUserId() << endl;
        cout << "Date: " << expenses[i].getDate() << endl;
        cout << "Item: " << expenses[i].getItem() << endl;
        cout << "UAmoutn: " << expenses[i].getAmount() << endl;
        cout << "DateInt: " << expenses[i].getDateInt() << endl << endl;
    }

}
