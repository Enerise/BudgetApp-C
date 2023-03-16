#include "UserManager.h"

void UserManager::registerUser(){
    User user = enterNewUserData();

    users.push_back(user);
    //plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

User UserManager::enterNewUserData()
{
    User user;

    user.setUserId(getNewUserId());
    string login;
    do
    {
        cout << "Podaj login: ";
        cin >> login;
        user.setLogin(login);
    } while (loginExists(user.getLogin()) == true);

    string password;
    cout << "Podaj haslo: ";
    cin >> password;
    user.setPassword(password);

    string userName;
    cout << "Podaj imie: ";
    cin >> userName;
    user.setUserName(userName);

    string userSurname;
    cout << "Podaj nazwisko: ";
    cin >> userSurname;
    user.setUserSurname(userSurname);

    return user;
}

int UserManager::getNewUserId()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getUserId() + 1;
}

bool UserManager::loginExists(string login)
{
   int lengthVectorUsers = users.size();

    for(int i = 0; i < lengthVectorUsers; i++)
    {
        if(users[i].getLogin() == login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}
