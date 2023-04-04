#include "FileWithUsers.h"

void FileWithUsers::addUserToFile(User user) {
    CMarkup xml;

    bool fileExists = xml.Load( NAME_FILE_WITH_USERS );

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("userId", user.getUserId());
    xml.AddElem("login", user.getLogin());
    xml.AddElem("password", user.getPassword());
    xml.AddElem("name", user.getUserName());
    xml.AddElem("surname", user.getUserSurname());

    xml.Save("users.xml");
}

vector <User> FileWithUsers::loadUsersFromFile() {
    User user;
    vector <User> users;
    int userId;
    string login, password, userName, userSurname;

    CMarkup xml;
    bool fileExists = xml.Load(NAME_FILE_WITH_USERS);

    if (fileExists) {
        xml.FindElem();
        xml.IntoElem();
        while (xml.FindElem("User")) {
            xml.IntoElem();
            xml.FindElem( "userId");
            userId = atoi(xml.GetData().c_str());//atoi( MCD_2PCSZ(xml.GetData()));
            user.setUserId(userId);
            xml.FindElem( "login");
            login = xml.GetData();
            user.setLogin(login);
            xml.FindElem( "password");
            password = xml.GetData();
            user.setPassword(password);
            xml.FindElem( "name");
            userName = xml.GetData();
            user.setUserName(userName);
            xml.FindElem( "surname");
            userSurname = xml.GetData();
            user.setUserSurname(userSurname);
            users.push_back(user);

            xml.OutOfElem();
        }
    }
    return users;
}

void FileWithUsers::changePasswordInFileUsers(int loggedUserId, string newPassword) {
    CMarkup xml;
    bool fileExists = xml.Load(NAME_FILE_WITH_USERS);
    int userIdInFile;//size_t userIdInFile {}; //?
    if (fileExists) {
        xml.FindElem("Users");
        xml.IntoElem();
        while (xml.FindElem("User")) {
            xml.IntoElem();
            xml.FindElem("userId");
            userIdInFile = AuxiliaryMethods::convertStringtoInteger(xml.GetData());
            if (userIdInFile == loggedUserId) {
                xml.FindElem("password");
                xml.SetData(newPassword);
                break;
            }
            xml.OutOfElem();
        }
        xml.Save("Users.xml");
    } else
        cout << "Nie mozna otworzyc pliku !" << endl;
}
