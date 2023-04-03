#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

class AuxiliaryMethods
{
public:
    static string convertIntegerToString(int number);
    static string loadLine();
    static string changeFirstLetterForUpperCaseAndOthersForLowerCase(string text);
    static int convertStringtoInteger(string number);
    static string convertFloatToString(float number);
    static float convertStringToFloat(string number);
    static int loadInteger();
    static char loadChar();
    static string addDashesToDate(string date);
    static string removeDashesFromDate(string date);
    static float loadAmount();
    static string changeComaToDot(string amount);
};

#endif
