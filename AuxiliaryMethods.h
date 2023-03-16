#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>

using namespace std;

class AuxiliaryMethods
{
public:
    static string convertIntegerToString(int number);
    static string loadLine();
    //static string pobierzLiczbe(string tekst, int pozycjaZnaku);
    static string changeFirstLetterForUpperCaseAndOthersForLowerCase(string text);
    static int convertStringtoInteger(string number);
    static int loadInteger();
    static char loadChar();
};

#endif
