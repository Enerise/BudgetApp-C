#include "PersonalBudget.h"
#include "AuxiliaryMethods.h"

string AuxiliaryMethods::convertIntegerToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string AuxiliaryMethods::loadLine()
{
    cin.sync();
    string entry = "";
    getline(cin, entry);
    return entry;
}

/*string AuxiliaryMethods::pobierzLiczbe(string tekst, int pozycjaZnaku)
{
    string liczba = "";
    while(isdigit(tekst[pozycjaZnaku]) == true)
    {
        liczba += tekst[pozycjaZnaku];
        pozycjaZnaku ++;
    }
    return liczba;
}*/

string AuxiliaryMethods::changeFirstLetterForUpperCaseAndOthersForLowerCase(string text)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

int AuxiliaryMethods::convertStringtoInteger(string number)
{
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}

int AuxiliaryMethods::loadInteger()
{
    string entry = "";
    int number = 0;

    while (true)
    {
        cin.sync();
        getline(cin, entry);

        stringstream myStream(entry);
        if (myStream >> number)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return number;
}

char AuxiliaryMethods::loadChar()
{
    string entry = "";
    char sign  = {0};

    while (true)
    {
        cin.sync();
        getline(cin, entry);

        if (entry.length() == 1)
        {
            sign = entry[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return sign;
}

