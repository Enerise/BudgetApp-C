#include "FileWithUsers.h"

void FileWithUsers::dopiszUzytkownikaDoPliku(User uzytkownik)
{
    fstream plikTekstowy;
    string liniaZDanymiUzytkownika = "";
    plikTekstowy.open(nazwaPlikuZUzytkownikami1.c_str(), ios::app);

    if (plikTekstowy.good())
    {
        liniaZDanymiUzytkownika = zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(uzytkownik);

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

string FileWithUsers::zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(User uzytkownik)
{
    string liniaZDanymiUzytkownika = "";
    liniaZDanymiUzytkownika += AuxiliaryMethods::convertIntegerToString(uzytkownik.getUserId())+ '|';
    liniaZDanymiUzytkownika += uzytkownik.getLogin() + '|';
    liniaZDanymiUzytkownika += uzytkownik.getPassword() + '|';

    return liniaZDanymiUzytkownika;
}

bool FileWithUsers::czyPlikJestPusty() {
    bool pusty = true;
    fstream plikTekstowy;
    plikTekstowy.open(nazwaPlikuZUzytkownikami1.c_str(), ios::app);

    if (plikTekstowy.good() == true) {
        plikTekstowy.seekg(0, ios::end);
        if (plikTekstowy.tellg() != 0)
            pusty = false;
    }

    plikTekstowy.close();
    return pusty;
}
