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

float AuxiliaryMethods::loadAmount()
{
    string entry = "";
    float number;

    while (true)
    {
        cin.sync();
        getline(cin, entry);

        entry = changeComaToDot(entry);

        stringstream myStream(entry);
        if (myStream >> number)
            break;
        cout << "To nie jest kwota. Wpisz ponownie. " << endl;
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

string AuxiliaryMethods::addDashesToDate(string date)
{
    string dateWithDashes;
    dateWithDashes = date.insert (4,1,'-');
    dateWithDashes = dateWithDashes.insert (7,1,'-');

    return dateWithDashes;
}

string AuxiliaryMethods::removeDashesFromDate(string date) {

    string dateWithoutDashes;

    for (int i = 0 ; i <= date.length(); i++) {
        if (date[i] != '-') {
            dateWithoutDashes += date[i];
        }
    }
    return dateWithoutDashes;
}

string AuxiliaryMethods::convertFloatToString(float number)
{
    stringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

float AuxiliaryMethods::convertStringToFloat(string number)
{
    float numberFloat = stof(number);
    return numberFloat;
}

string AuxiliaryMethods::changeComaToDot(string amount) {

    for(int i = 0; i < amount.length(); i++ ) {
        if(amount[i] == ',')
            amount[i] = '.';
    }

    return amount;
}

