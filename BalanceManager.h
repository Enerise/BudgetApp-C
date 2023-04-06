#ifndef BALANCEMANAGER_H
#define BALANCEMANAGER_H

#include <iostream>
#include <vector>
#include <iomanip>

#include "Expense.h"
#include "Income.h"
#include "AuxiliaryMethods.h"


using namespace std;

class BalanceManager {

    vector <Income> extractedIncomes;
    vector <Expense> extractedExpenses;
    float sumOfIncomes;
    float sumOfExpenses;
    float balanceSummary;

    vector <Income> extractIncomesForCurrentMonth(vector <Income> incomes, int firstDate);
    vector <Expense> extractExpensesForCurrentMonth(vector <Expense> expenses, int firstDate);

    vector <Income> extractIncomesForPreviousMonthAndSelectedPeriod(vector <Income> incomes, int firstDate, int lastDate);
    vector <Expense> extractExpensesForPreviousMonthAndSelectedPeriod(vector <Expense> expenses, int firstDate, int lastDate);

    void resetToDefaultValue();
    void showExtractedIncomes();
    void showExtractedExpenses();

public:
    BalanceManager() {
        sumOfIncomes = 0;
        sumOfExpenses = 0;
        balanceSummary = 0;
    };

    void displayCurrentMonthBalance(vector <Income> incomes, vector <Expense> expenses, int firstDate);
    void displayPreviousMonthBalanceAndSelectedPeriod(vector <Income> incomes, vector <Expense> expenses, int firstDate, int lastDate);

};



#endif
