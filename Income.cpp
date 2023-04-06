#include "Income.h"

void Income::setUserId (int newUserId) {
    if (newUserId >= 0)
        userId = newUserId;
}

void Income::setIncomeId (int newIncomeId) {
    incomeId = newIncomeId;
}

void Income::setDate (string newDate) {
    date = newDate;
}

void Income::setItem (string newItem) {
    item = newItem;
}

void Income::setAmount (float newAmount) {
    amount = newAmount;
}

void Income::setDateInt (int newDateInt) {
    dateInt = newDateInt;
}

int Income::getIncomeId() {
    return incomeId;
}

int Income::getUserId() {
    return userId;
}

string Income::getDate() {
    return date;
}

string Income::getItem() {
    return item;
}

float Income::getAmount() {
    return amount;
}

int Income::getDateInt() {
    return dateInt;
}
