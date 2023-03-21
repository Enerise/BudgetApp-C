#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "User.h"
#include "AuxiliaryMethods.h"
#include "Markup.h"

using namespace std;

class FileWithUsers
{
    vector <User> users;
    const string NAME_FILE_WITH_USERS;

public:
    FileWithUsers(string nameFileWithUsers) : NAME_FILE_WITH_USERS(nameFileWithUsers)
    {
    }
    void addUserToFile(User user);
    vector <User> loadUsersFromFile();
    //void zapiszWszystkichUzytkownikowDoPliku(vector <Uzytkownik> users);
};

#endif
