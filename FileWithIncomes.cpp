#include "FileWithIncomes.h"

bool FileWithIncomes::addIncomeToFile(Income income)
{
    lastIncomeId++;
    string amount;

    CMarkup xml;

    bool fileExists = xml.Load( NAME_FILE_WITH_INCOMES );

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("incomeId", income.getIncomeId());
    xml.AddElem("userId", income.getUserId());
    xml.AddElem("date", income.getDate());
    xml.AddElem("item", income.getItem());
    amount = AuxiliaryMethods::convertFloatToString(income.getAmount());
    xml.AddElem("amount", amount);


    xml.Save(NAME_FILE_WITH_INCOMES);

    return true;
}

void FileWithIncomes::changeDateInFile(int incomeId)
{
    CMarkup xml;
    bool fileExists = xml.Load(NAME_FILE_WITH_INCOMES);
    int incomeIdInFile;//size_t userIdInFile {}; //?
    string dateWithoutDashes, dateWithDashes;

    if (fileExists)
    {
        xml.FindElem("Incomes");
        xml.IntoElem();
        while (xml.FindElem("Income"))
        {
            xml.IntoElem();
            xml.FindElem("incomeId");
            userIdInFile = AuxiliaryMethods::convertStringtoInteger(xml.GetData());
            if (userIdInFile == incomeId)
            {
                xml.FindElem("date");
                dateWithoutDashes = xml.GetData();
                dateWithDashes = AuxiliaryMethods::addDashesToDate(dateWithoutDashes);
                xml.SetData(dateWithDashes);
                break;
            }
            xml.OutOfElem();
        }
        xml.Save("Incomes.xml");
    }
    else
        cout << "Nie mozna otworzyc pliku !" << endl;
}


vector <Income> FileWithIncomes::loadIncomesFromFile(int loggedUserId)
{
    Income income;
    //vector <User> users;
    int userIdInFile;
    string date, item;
    float amount;

    CMarkup xml;
    bool fileExists = xml.Load(NAME_FILE_WITH_INCOMES);

    if (fileExists) {
        xml.FindElem("Incomes");
        xml.IntoElem();
        while (xml.FindElem("Income")) {
            xml.IntoElem();
            xml.FindElem("incomeId");
            lastIncomeId = AuxiliaryMethods::convertStringtoInteger(xml.GetData());
            xml.FindElem("userId");
            userIdInFile = AuxiliaryMethods::convertStringtoInteger(xml.GetData());
            if (userIdInFile == loggedUserId) {
                income.setIncomeId(lastIncomeId);

                income.setUserId(userIdInFile);

                xml.FindElem( "date");
                date = xml.GetData();
                date = AuxiliaryMethods::removeDashesFromDate(date);
                income.setDate(date);
                xml.FindElem( "item");
                item = xml.GetData();
                income.setItem(item);
                xml.FindElem( "amount");
                amount = AuxiliaryMethods::convertStringToFloat(xml.GetData());
                income.setAmount(amount);
                incomes.push_back(income);

                xml.OutOfElem();
            }
            else xml.OutOfElem();
        }
    }

    return incomes;
}

int FileWithIncomes::getLastIncomeId()
{
    return lastIncomeId;
}
