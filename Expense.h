#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>

using namespace std;

class Expense {
    int expenseId;
    int userId;
    string date;
    string item;
    float amount;
    int dateInt;

public:
    Expense(int expenseId = 0, int userId = 0, string date = "", string item = "", float amount = 0.0, int dateInt = 0) {
        this->expenseId = expenseId;
        this->userId = userId;
        this->date = date;
        this->item = item;
        this->amount = amount;
        this->dateInt = dateInt;
    }

    void setExpenseId (int newExpenseId);
    void setUserId (int newUserId);
    void setDate (string newDate);
    void setItem (string newItem);
    void setAmount (float newAmount);
    void setDateInt (int newDateInt);

    int getExpenseId();
    int getUserId();
    string getDate();
    string getItem();
    float getAmount();
    int getDateInt();

};

#endif
