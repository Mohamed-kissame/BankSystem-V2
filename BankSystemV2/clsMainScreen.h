#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsClientListScreen.h"
#include "clsAddNewClient.h"
#include "clsDeleteClient.h"
#include "clsUpdateClient.h"
#include "clsFindClient.h"
#include "clsTrnsactionMenu.h"
#include "clsMangeUserMenu.h"
#include "Global.h"
#include "clsLoginScreen.h"
#include "clsLoginRegisterScreen.h"
#include "clsCurencyMenu.h"
#include <iomanip>

using namespace std;

class clsMainScreen : protected clsScreen
{

private:
	enum enMainMenuOptions {
		eListClients = 1, eAddNewClient = 2, eDeleteClient = 3
		, eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenu = 6,
		eManageUsers = 7, eLoginRegister = 8, Curency = 9, eExit = 10
	};

	static short _ReadMainMenuOption() {

		cout << setw(37) << left << "" << "choose what do you want to do? [1 to 10]?";
		short choice = clsInputValide <short>::ReadNumberBetween(1, 10, "Invalide Entre A Number Between [1,10]");
		return choice;
	}

	static void _GoBackToMainMenu() {

		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

		system("pause>0");
		ShowMainMenue();

	}

	static void _ShowAllClientScreen() {

		clsClientListScreen::ShowClientsList();
	}

	static void _ShowAddNewClientScreen() {

		clsAddNewClient::ShowAddNewClientScreen();
	}

	static void _ShowDeleteClientScreen() {

		clsDeleteClientScreen::ShowDeleteClientScreen();
	}

	static void _ShowUpdateClientScreen() {

		clsUpdateClientScreen::ShowUpdateClientScreen();
	}

	static void _ShowFindClientScreen() {

		clsFindClientScreen::ShowFindClientScreen();
	}

	static void _ShowTrnsactionMenuScreen() {

		clsTransactionsScreen::ShowTransactionsMenue();
	}

	static void _ShowMangeuserMenuScreen() {

		clsMangeUserMenu::ShowMangeMenu();
	}

	static void _ShowLoginRegisterScreen() {

		clsLoginRegisterScreen::ShowLoginRegisterScreen();
	}

	static void _ShowCurencyMenu() {

		clsCurency::ShowCurencyMenu();
	}

	static void _Logout() {

		CurrentUser = clsUser::Find("", "");

	}

	static void _PerformMainMenuOption(enMainMenuOptions MainMenu) {

		switch (MainMenu) {

		case enMainMenuOptions::eListClients: {

			system("cls");
			_ShowAllClientScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOptions::eAddNewClient: {

			system("cls");
			_ShowAddNewClientScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOptions::eDeleteClient: {

			system("cls");
			_ShowDeleteClientScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOptions::eUpdateClient: {

			system("cls");
			_ShowUpdateClientScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOptions::eFindClient: {

			system("cls");
			_ShowFindClientScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOptions::eShowTransactionsMenu: {

			system("cls");
			_ShowTrnsactionMenuScreen();
			ShowMainMenue();
			break;
		}
		case enMainMenuOptions::eManageUsers: {

			system("cls");
			_ShowMangeuserMenuScreen();
			ShowMainMenue();
			break;
		}

		case enMainMenuOptions::eLoginRegister: {

			system("cls");
			_ShowLoginRegisterScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOptions::Curency: {

			system("cls");
			_ShowCurencyMenu();
			ShowMainMenue();
			break;

		}

		case enMainMenuOptions::eExit: {

			system("cls");
			_Logout();
			break;
		}
		}
	}

public:

	static void ShowMainMenue()
	{

		system("cls");
		_DrawScreenHeader("\t\tMain Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
		cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
		cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
		cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
		cout << setw(37) << left << "" << "\t[5] Find Client.\n";
		cout << setw(37) << left << "" << "\t[6] Transactions.\n";
		cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
		cout << setw(37) << left << "" << "\t[8] Show Login Register List.\n";
		cout << setw(37) << left << "" << "\t[9] Curency Menue.\n";
		cout << setw(37) << left << "" << "\t[10] Logout.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformMainMenuOption((enMainMenuOptions)_ReadMainMenuOption());
	}

};