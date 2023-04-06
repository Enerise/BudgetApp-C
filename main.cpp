#include <iostream>
#include <windows.h>

#include "PersonalBudget.h"

using namespace std;

int main() {
    PersonalBudget personalBudget ("Users.xml", "Incomes.xml", "Expenses.xml");
    char choice;
    while(true) {
        if(personalBudget.getLoggedInUserId() == 0) {
            choice = personalBudget.selectOptionFromMainMenu();
            switch(choice) {
            case '1':
                personalBudget.registerUser();
                break;
            case '2':
                personalBudget.loginUser();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        } else {
            choice = personalBudget.selectOptionFromUserMenu();

            switch(choice) {
            case '1':
                personalBudget.addIncome();
                break;
            case '2':
                personalBudget.addExpense();
                break;
            case '3':
                personalBudget.displayCurrentMonthBalance();
                break;
            case '4':
                personalBudget.displayPreviousMonthBalance();
                break;
            case '5':
                personalBudget.displaySelectedPeriodBalance();
                break;
            case '7':
                personalBudget.changePassword();
                break;
            case '8':
                personalBudget.logoutUser();
                break;
            }
        }
    }
    return 0;
}
