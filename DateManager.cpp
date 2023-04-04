#include "DateManager.h"

void DateManager::calculateCurrentDate() {
    year = getCurrentYear();
    currentDate = (year * 10000);
    month = getCurrentMonth();
    currentDate += (month * 100);
    day = getCurrentDay();
    currentDate += day;
}
int DateManager::getCurrentYear() {
    year = gottime->tm_year + 1900;
    return year;
}

int DateManager::getCurrentMonth() {
    month = gottime->tm_mon + 1;
    return month;
}

int DateManager::getCurrentDay() {
    day = gottime->tm_mday;
    return day;
}

string DateManager::getCurrentDateWithoutDashes() {
    string currentDateStr = AuxiliaryMethods::convertIntegerToString(currentDate);
    return currentDateStr;
}

bool DateManager::isDateCorrect(string date) {

    int yearFromUser = (date[0]-'0')*1000 + (date[1]-'0')*100 + (date[2]-'0')*10 + (date[3]-'0');
    int monthFromUser = (date[5]-'0')*10 + (date[6]-'0');
    int dayFromUser = (date[8]-'0')*10 + (date[9]-'0');

    if (!isValidFormatDate(date)) {
        return false;
    } else if (!isValidYear(yearFromUser)) {
        return false;
    } else if (!isValidMonth(monthFromUser)) {
        return false;
    } else if (dayFromUser >= 1 && dayFromUser <= 31) {
        if (isValidDay(dayFromUser, monthFromUser, yearFromUser)) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }

    return true;
}

bool DateManager::isValidFormatDate (string date) {

    if ((date.size() != 10) || (date[0] != 2) || (date[4] != '-') || (date[7] != '-'))
        return false;
    else
        return true;
}

bool DateManager::isValidYear (int yearFromUser) {

    if (yearFromUser > getCurrentYear() || yearFromUser < MIN_VALID_YEAR) {
        return false;
    }
    return true;
}

bool DateManager::isValidMonth(int monthFromUser) {
    if (monthFromUser < 1 || monthFromUser > 12) {
        return false;
    }
    return true;
}

bool DateManager::isValidDay (int dayFromUser, int monthFromUser, int yearFromUser) {

    if (monthFromUser == 2) {
        if ((isLeap(yearFromUser)) && (dayFromUser == 29)) {
            return true;
        } else if (dayFromUser >= 1 && dayFromUser <= 28) {
            return true;
        } else if (dayFromUser < 1 && dayFromUser >= 30) {
            return false;
        }
    } else if (monthFromUser == 4 || monthFromUser == 6 || monthFromUser == 9 || monthFromUser == 11) {
        if (dayFromUser >= 1 && dayFromUser <= 30) {
            return true;
        } else return false;
    } else if (monthFromUser == 1 || monthFromUser == 3 || monthFromUser == 5 || monthFromUser == 7 || monthFromUser == 8 || monthFromUser == 10 || monthFromUser == 12) {
        if (dayFromUser >= 1 && dayFromUser <= 31) {
            return true;
        } else return false;
    }
    return false;
}

bool DateManager::isLeap(int yearFromUser) {
    if(((yearFromUser % 4 == 0) && (yearFromUser % 100 != 0)) || (yearFromUser % 400 == 0)) {
        return true;
    } else return false;
}
