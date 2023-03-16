#include "PersonalBudget.h"
#include "AuxiliaryMethods.h"

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
