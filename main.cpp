#include <iostream>
#include <windows.h>

#include "PersonalBudget.h"

using namespace std;

int main() {
    PersonalBudget personalBudget;//("Uzytkownicy.txt", "Adresaci.txt");
    char choice;
    while(true) {
        //if(ksiazkaAdresowa.pobierzIdZalogowanegoUzytkownika() == 0) {
            choice = personalBudget.selectOptionFromMainMenu();
            switch(choice) {
            case '1':
                personalBudget.registerUser();
                break;
            case '2':
                //personalBudget.logowanieUzytkownika();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        } /*else {
            wybor = ksiazkaAdresowa.wybierzOpcjeZMenuUzytkownika();

            switch(wybor) {
                case '1':
                    ksiazkaAdresowa.dodajAdresata();
                    break;
                case '2':
                    ksiazkaAdresowa.wyszukajAdresatowPoImieniu();
                    break;
                case '3':
                    ksiazkaAdresowa.wyszukajAdresatowPoNazwisku();
                    break;
                case '4':
                    ksiazkaAdresowa.wyswietlWszystkichAdresatow();
                    break;
                case '5':
                    ksiazkaAdresowa.usunAdresata();
                    break;
                 case '6':
                    ksiazkaAdresowa.edytujAdresata();
                    break;
                case '7':
                    ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
                    break;
                case '8':
                    ksiazkaAdresowa.wylogowanieUzytkownika();
                    break;
                }
            }
        }*/
    return 0;
}
