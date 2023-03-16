#include <iostream>

#include "UserManager.h"


using namespace std;

class PersonalBudget
{
    UserManager userManager;

public:
PersonalBudget (string nazwaPlikuZUzytkownikami):
    userManager(nazwaPlikuZUzytkownikami){
    };
    void registerUser();
    char selectOptionFromMainMenu();
};
