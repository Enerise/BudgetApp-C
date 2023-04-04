#include "User.h"

void User::setUserId (int newUserId) {
    if (newUserId >= 0)
        userId = newUserId;
}

void User::setLogin (string newLogin) {
    login = newLogin;
}

void User::setPassword (string newPassword) {
    password = newPassword;
}

void User::setUserName (string newUserName) {
    userName = newUserName;
}

void User::setUserSurname (string newUserSurname) {
    userSurname = newUserSurname;
}

int User::getUserId() {
    return userId;
}

string User::getLogin() {
    return login;
}

string User::getPassword() {
    return password;
}

string User::getUserName() {
    return userName;
}

string User::getUserSurname() {
    return userSurname;
}
