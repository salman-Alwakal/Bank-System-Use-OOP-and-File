#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global.h"
#include "clsUser.h"

class clsLoginScreen :protected clsScreen
{

private:

    void _LoginFile()
    {
        
    }

    static  bool _Login()
    {
      
        bool LoginFaild = false;
        short FaildLoginCount = 0;

        string Username, Password;
        do
        {

            if (LoginFaild)
            {
                FaildLoginCount++;
                cout << "\nInvlaid Username/Password!\n\n";
                cout << "\nYou have " << (3-FaildLoginCount)
                    << " Trials to login\n";
            }

            if (FaildLoginCount == 3)
            {
                cout << "\nYour are Locked after 3 faild trails \n\n";
                return false;
            }

            cout << "\nEnter Username? ";
            cin >> Username;

            cout << "\nEnter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);
            LoginFaild = CurrentUser.IsEmpty();

            

        } while (LoginFaild);

        CurrentUser.RegisterLogin();
        clsMainScreen::ShowMainMenue();
        return true;
       
    }

public:


    static bool ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t  Login Screen");
       return _Login();

    }

};

