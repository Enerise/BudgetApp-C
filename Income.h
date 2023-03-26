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
    //int intDate;

public:
        Income(int incomeId = 0, int userId = 0, string date = "", string item = "", float amount = 0.0)
    {
        this->incomeId = incomeId;
        this->userId = userId;
        this->date = date;
        this->item = item;
        this->amount = amount;
    }
    //void setupDate();
   /* void setupDate (int newDate);
    void setupStringDate (string newDate);
    void setupUserId (int newUserId);
    void setupItemId (int newItemId);
    void setupItemName(string newItemName);
    void setupItemAmount(float newItemAmount);

    int getItemId();
    int getUserId();
    string getItemName();
    float getItemAmount();
    string getItemDate();
    int getIntDate();
*/
};

#endif
