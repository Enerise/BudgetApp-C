#include "BalanceManager.h"

void BalanceManager::displayCurrentMonthBalance(vector <Income> incomes, vector <Expense> expenses, int firstDate)
{
    extractIncomesForCurrentMonth(incomes, firstDate);
    showExtractedIncomes();
    extractExpensesForCurrentMonth(expenses, firstDate);
    showExtractedExpenses();
    balanceSummary = sumOfIncomes - sumOfExpenses;

    cout << "Suma przychodow wynosi: " << fixed << setprecision(2) << sumOfIncomes << endl;
    cout << "Suma wydatkow wynosi: "  << fixed << setprecision(2) << sumOfExpenses << endl;

    if(sumOfIncomes > sumOfExpenses) {
        cout << "W tym miesiacu zaoszczedziles " << balanceSummary << endl << endl;
        system("pause");
    } else {
        cout << "W tym miesiacu brakuje Ci " << balanceSummary << endl << endl;
        system("pause");
    }
}

vector <Income> BalanceManager::extractIncomesForCurrentMonth(vector <Income> incomes, int firstDate) {
    Income extractIncome;

    int vectorSize = incomes.size();
    for(int i=0; i < vectorSize; i++) {

        if(firstDate <= incomes[i].getDateInt()) {
            extractIncome.setIncomeId(incomes[i].getIncomeId());
            extractIncome.setUserId(incomes[i].getUserId());
            extractIncome.setDate(incomes[i].getDate());
            extractIncome.setItem(incomes[i].getItem());
            extractIncome.setAmount(incomes[i].getAmount());
            sumOfIncomes += incomes[i].getAmount();
            extractIncome.setDateInt(incomes[i].getDateInt());
            extractedIncomes.push_back(extractIncome);

        }
    }

    sort(extractedIncomes.begin(), extractedIncomes.end());

    return extractedIncomes;
}

void BalanceManager::showExtractedIncomes() {

    int vectorSize = extractedIncomes.size();
    cout << " >>> WYSWIETLENIE WSZYSTKIM PRZYCHODOW BIEZACEGO MIESIACA <<< " << endl;
    cout << endl;
    for (int i = 0; i < vectorSize; i++) {
        cout << "Data: " << extractedIncomes[i].getDate() << endl;
        cout << "Opis: " << extractedIncomes[i].getItem() << endl;
        cout << "Kwota: " << fixed << setprecision(2) << extractedIncomes[i].getAmount() << endl << endl;
    }
}

vector <Expense> BalanceManager::extractExpensesForCurrentMonth(vector <Expense> expenses, int firstDate) {
    Expense extractExpense;

    int vectorSize = expenses.size();
    for(int i=0; i < vectorSize; i++) {

        if(firstDate <= expenses[i].getDateInt()) {
            extractExpense.setExpenseId(expenses[i].getExpenseId());
            extractExpense.setUserId(expenses[i].getUserId());
            extractExpense.setDate(expenses[i].getDate());
            extractExpense.setItem(expenses[i].getItem());
            extractExpense.setAmount(expenses[i].getAmount());
            sumOfExpenses += expenses[i].getAmount();
            extractExpense.setDateInt(expenses[i].getDateInt());
            extractedExpenses.push_back(extractExpense);
        }
    }

    sort(extractedExpenses.begin(), extractedExpenses.end());

    return extractedExpenses;
}

void BalanceManager::showExtractedExpenses() {

    int vectorSize = extractedExpenses.size();
    cout << " >>> WYSWIETLENIE WSZYSTKIM WYDATKOW BIEZACEGO MIESIACA <<< " << endl;
    cout << endl;
    for (int i = 0; i < vectorSize; i++) {
        cout << "Data: " << extractedExpenses[i].getDate() << endl;
        cout << "Opis: " << extractedExpenses[i].getItem() << endl;
        cout << "Kwota: " << fixed << setprecision(2) << extractedExpenses[i].getAmount() << endl << endl;
    }
    cout << endl;
}
