#include "UserManager.h"

void UserManager::registerUser() {
    User user = enterNewUserData();

    users.push_back(user);
    fileWithUsers.addUserToFile(user);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

void UserManager::loginUser() {
    User user;
    string login = "", password = "";

    cout << endl << "Podaj login: ";
    login = AuxiliaryMethods::loadLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end()) {
        if (itr -> getLogin() == login) {
            for (int numberOfAttempts = 3; numberOfAttempts > 0; numberOfAttempts--) {
                cout << "Podaj haslo. Pozostalo prob: " << numberOfAttempts << ": ";
                password = AuxiliaryMethods::loadLine();

                if (itr -> getPassword() == password) {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    loggedInUserId = itr -> getUserId();
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return;
}

User UserManager::enterNewUserData() {
    User user;

    user.setUserId(getNewUserId());
    string login;
    do {
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

int UserManager::getNewUserId() {
    if (users.empty() == true)
        return 1;
    else
        return users.back().getUserId() + 1;
}

bool UserManager::loginExists(string login) {
    int lengthVectorUsers = users.size();

    for(int i = 0; i < lengthVectorUsers; i++) {
        if(users[i].getLogin() == login) {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

void UserManager::changePassword() {
    string newPassword = "";
    cout << "Podaj nowe haslo: ";
    newPassword = AuxiliaryMethods::loadLine();

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++) {
        if (itr -> getUserId() == loggedInUserId) {
            itr -> setPassword(newPassword);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    fileWithUsers.changePasswordInFileUsers(loggedInUserId, newPassword);
}

void UserManager::showAllUsers() {

    int vectorSize = users.size();
    for (int i = 0; i < vectorSize; i++) {
        cout << "User ID: " << users[i].getUserId() << endl;
        cout << "Login: " << users[i].getLogin() << endl;
        cout << "Password: " << users[i].getPassword() << endl;
        cout << "User name: " << users[i].getUserName() << endl;
        cout << "User surname: " << users[i].getUserSurname() << endl << endl;
    }
}

int UserManager::getLoggedInUserId() {
    return loggedInUserId;
}

int UserManager::logoutUser() {
    loggedInUserId = 0;
    cout << "Zostales pomyslnie wylogowany" << endl;
    system("pause");
    return loggedInUserId;
}

bool UserManager::isUserLoggedIn() {
    if(loggedInUserId > 0)
        return true;
    else
        return false;
}
