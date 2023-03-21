#include "FileWithUsers.h"

void FileWithUsers::addUserToFile(User user)
{
   CMarkup xml;

    bool fileExists = xml.Load( NAME_FILE_WITH_USERS );

    if (!fileExists)
    {
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

    /*fstream plikTekstowy;
    string liniaZDanymiUzytkownika = "";
    plikTekstowy.open(nazwaPlikuZUzytkownikami1.c_str(), ios::app);

    if (plikTekstowy.good())
    {
        liniaZDanymiUzytkownika = zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(user);

        if (czyPlikJestPusty())
        {
            plikTekstowy << liniaZDanymiUzytkownika;
        }
        else
        {
            plikTekstowy << endl << liniaZDanymiUzytkownika ;
        }
    }
    else
        cout << "Nie udalo sie otworzyc pliku " << nazwaPlikuZUzytkownikami1 << " i zapisac w nim danych." << endl;
    plikTekstowy.close();
}
*/
}
