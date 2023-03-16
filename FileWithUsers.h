#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "User.h"
#include "AuxiliaryMethods.h"

using namespace std;

class FileWithUsers
{
    vector <User> uzytkownicy;
    string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(User uzytkownik);
    string nazwaPlikuZUzytkownikami1;
    bool czyPlikJestPusty();

public:
    FileWithUsers(string nazwaPlikuZUzytkownikami) //: nazwaPlikuZUzytkownikami1(nazwaPlikuZUzytkownikami)
    {
        nazwaPlikuZUzytkownikami1 = nazwaPlikuZUzytkownikami;
    }
    void dopiszUzytkownikaDoPliku(User uzytkownik);
    //void zapiszWszystkichUzytkownikowDoPliku(vector <Uzytkownik> uzytkownicy);
};
