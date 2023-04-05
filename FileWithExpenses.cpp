#include "FileWithExpenses.h"

bool FileWithExpenses::addExpenseToFile(Expense expense) {
    lastExpenseId++;
    string amount;

    CMarkup xml;

    bool fileExists = xml.Load( NAME_FILE_WITH_EXPENSES );

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem("expenseId", expense.getExpenseId());
    xml.AddElem("userId", expense.getUserId());
    xml.AddElem("date", expense.getDate());
    xml.AddElem("item", expense.getItem());
    amount = AuxiliaryMethods::convertFloatToString(expense.getAmount());
    xml.AddElem("amount", amount);


    xml.Save(NAME_FILE_WITH_EXPENSES);

    return true;
}

void FileWithExpenses::changeDateInFile(int expenseId) {
    CMarkup xml;
    bool fileExists = xml.Load(NAME_FILE_WITH_EXPENSES);
    string dateWithoutDashes, dateWithDashes;

    if (fileExists) {
        xml.FindElem("Expenses");
        xml.IntoElem();
        while (xml.FindElem("Expense")) {
            xml.IntoElem();
            xml.FindElem("expenseId");
            userIdInFile = AuxiliaryMethods::convertStringtoInteger(xml.GetData());
            if (userIdInFile == expenseId) {
                xml.FindElem("date");
                dateWithoutDashes = xml.GetData();
                dateWithDashes = AuxiliaryMethods::addDashesToDate(dateWithoutDashes);
                xml.SetData(dateWithDashes);
                break;
            }
            xml.OutOfElem();
        }
        xml.Save("Expenses.xml");
    } else
        cout << "Nie mozna otworzyc pliku !" << endl;
}


vector <Expense> FileWithExpenses::loadExpensesFromFile(int loggedUserId) {
    Expense expense;
    int userIdInFile;
    string date, item;
    float amount;

    CMarkup xml;
    bool fileExists = xml.Load(NAME_FILE_WITH_EXPENSES);

    if (fileExists) {
        xml.FindElem("Expenses");
        xml.IntoElem();
        while (xml.FindElem("Expense")) {
            xml.IntoElem();
            xml.FindElem("expenseId");
            lastExpenseId = AuxiliaryMethods::convertStringtoInteger(xml.GetData());
            xml.FindElem("userId");
            userIdInFile = AuxiliaryMethods::convertStringtoInteger(xml.GetData());
            if (userIdInFile == loggedUserId) {
                expense.setExpenseId(lastExpenseId);

                expense.setUserId(userIdInFile);

                xml.FindElem( "date");
                date = xml.GetData();
                expense.setDate(date);
                date = AuxiliaryMethods::removeDashesFromDate(date);
                expense.setDateInt(AuxiliaryMethods::convertStringtoInteger(date));
                xml.FindElem( "item");
                item = xml.GetData();
                expense.setItem(item);
                xml.FindElem( "amount");
                amount = AuxiliaryMethods::convertStringToFloat(xml.GetData());
                expense.setAmount(amount);
                expenses.push_back(expense);

                xml.OutOfElem();
            } else xml.OutOfElem();
        }
    }

    return expenses;
}

int FileWithExpenses::getLastExpenseId() {
    return lastExpenseId;
}
