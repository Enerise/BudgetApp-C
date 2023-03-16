#include <iostream>

#include "UserManager.h"


using namespace std;

class PersonalBudget
{
    UserManager userManager;

public:

    void registerUser();
    char selectOptionFromMainMenu();
};
