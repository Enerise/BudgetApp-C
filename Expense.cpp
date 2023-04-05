#include "Expense.h"

void Expense::setUserId (int newUserId) {
    if (newUserId >= 0)
        userId = newUserId;
}

void Expense::setExpenseId (int newExpenseId) {
    expenseId = newExpenseId;
}

void Expense::setDate (string newDate) {
    date = newDate;
}

void Expense::setItem (string newItem) {
    item = newItem;
}

void Expense::setAmount (float newAmount) {
    amount = newAmount;
}

void Expense::setDateInt (int newDateInt) {
    dateInt = newDateInt;
}

int Expense::getExpenseId() {
    return expenseId;
}

int Expense::getUserId() {
    return userId;
}

string Expense::getDate() {
    return date;
}

string Expense::getItem() {
    return item;
}

float Expense::getAmount() {
    return amount;
}

int Expense::getDateInt() {
    return dateInt;
}
