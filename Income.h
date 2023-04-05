#ifndef INCOME_H
#define INCOME_H

#include <iostream>

using namespace std;

class Income {
    int incomeId;
    int userId;
    string date;
    string item;
    float amount;
    int dateInt;

public:
    Income(int incomeId = 0, int userId = 0, string date = "", string item = "", float amount = 0.0, int dateInt = 0) {
        this->incomeId = incomeId;
        this->userId = userId;
        this->date = date;
        this->item = item;
        this->amount = amount;
        this->dateInt = dateInt;
    }

    void setIncomeId (int newIncomeId);
    void setUserId (int newUserId);
    void setDate (string newDate);
    void setItem (string newItem);
    void setAmount (float newAmount);
    void setDateInt (int newDateInt);

    int getIncomeId();
    int getUserId();
    string getDate();
    string getItem();
    float getAmount();
    int getDateInt();
};

#endif
