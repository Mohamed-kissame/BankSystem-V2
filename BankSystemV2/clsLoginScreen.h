#pragma once
#include "clsUser.h"
#include "clsMainScreen.h"
#include "Global.h"


class clsLoginScreen : protected clsScreen
{

private:

	static bool _Login() {

		bool LoginFail = false;

		string UserName, Password;

		short FaildLogin = 0;

		do {

			if (LoginFail) {

				FaildLogin++;

				cout << "\nInvalide Username/Password:\n\n";
				cout << "\nYou Have " << (3 - FaildLogin)
					<< " Trials to Login.\n\n";
			}

			if (FaildLogin == 3) {

				cout << "You are Locked after 3 faild Trails \n\n";
				return false;
			}

			cout << "Enter Username?";
			cin >> UserName;

			cout << "Enter Password?";
			cin >> Password;

			CurrentUser = clsUser::Find(UserName, Password);


			LoginFail = CurrentUser.IsEmpty();



		} while (LoginFail);

		CurrentUser.RegisterLogIn();
		clsMainScreen::ShowMainMenue();
		return true;

	}

public:

	static bool ShowLoginScreen() {

		system("cls");
		_DrawScreenHeader("\t Login Screen");
		return _Login();
	}
};