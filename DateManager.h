#ifndef DATEMANAGER_H
#define DATEMANAGER_H

#include <iostream>
#include <ctime>

#include "AuxiliaryMethods.h"

using namespace std;

class DateManager {
    time_t tim = time(NULL);
    struct tm *gottime = gmtime(&tim);

    int year, month, day, currentDate;
    string currentDateStr;

    const int MIN_VALID_YEAR = 2000;

    void calculateCurrentDate();


    bool isValidFormatDate (string date);
    bool isValidYear(int yearFromUser);
    bool isValidMonth(int monthFromUser);
    bool isLeap(int yearFromUser);
    bool isValidDay (int dayFromUser, int monthFromUser, int yearFromUser);

public:
    DateManager() {
        currentDateStr = "";
        calculateCurrentDate();
    }
    int getCurrentYear();
    int getCurrentMonth();
    int getCurrentDay();
    int getCurrentDateWithoutDayAndDashes();
    int getPreviousDateMonthWithFirstDay();
    int getPreviousDateMonthWithLastDay();
    bool isDateCorrect(string date);
    string getCurrentDateWithoutDashes();

};


#endif
