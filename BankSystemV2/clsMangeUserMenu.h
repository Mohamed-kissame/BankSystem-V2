#pragma once
#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsUser.h"
#include "clsAddNewUsers.h"
#include "clsUsersList.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUser.h"
#include "clsFindUser.h"

using namespace std;

class clsMangeUserMenu : protected clsScreen
{

private:

	enum enManageUser { eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3, eUpdateUser = 4, eFindUser = 5, eMainMenu = 6 };

	static short _ReadMangeMenuOption() {

		cout << setw(37) << left << "" << "choose what do you want to do? [1 ro 6]?";
		short choice = clsInputValide<short>::ReadNumberBetween(1, 6, "Invalide Entre A Number Between [1,6]");
		return choice;
	}

	static void _GoBackToManageMenu() {

		cout << setw(37) << left << "" << "\n\tPress any key to go back to Manage Menue...\n";

		system("pause>0");

		ShowMangeMenu();
	}

	static void _ShowAllUsers() {

		clsListUsersScreen::ShowUsersList();

	}

	static void _ShowAddNewUser() {

		clsAddNewUserScreen::ShowAddNewUserScreen();
	}

	static void _ShowDeleteUser() {

		clsDeleteUserScreen::ShowDeleteUserScreen();
	}

	static void _ShowUpdateUser() {

		clsUpdateUserScreen::ShowUpdateUserScreen();
	}

	static void _ShowFindUser() {

		clsFindUserScreen::ShowFindUserScreen();
	}

	static void _PerformManageUserMenuOption(enManageUser ManageMenuOption) {

		switch (ManageMenuOption) {

		case enManageUser::eListUsers: {

			system("cls");

			_ShowAllUsers();
			_GoBackToManageMenu();

			break;
		}
		case enManageUser::eAddNewUser: {

			system("cls");

			_ShowAddNewUser();
			_GoBackToManageMenu();
			break;
		}
		case enManageUser::eDeleteUser: {

			system("cls");
			_ShowDeleteUser();
			_GoBackToManageMenu();
			break;
		}
		case enManageUser::eUpdateUser: {

			system("cls");
			_ShowUpdateUser();
			_GoBackToManageMenu();
			break;
		}
		case enManageUser::eFindUser: {

			system("cls");
			_ShowFindUser();
			_GoBackToManageMenu();
			break;
		}
		case enManageUser::eMainMenu: {

		}
		}
	}

public:

	static void ShowMangeMenu() {

		if (!CheckAccessRights(clsUser::enPermissions::pManageUsers)) {

			return;
		}

		system("cls");
		_DrawScreenHeader("\tManage Users Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tManage Users\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Show Users List.\n";
		cout << setw(37) << left << "" << "\t[2] Add New User.\n";
		cout << setw(37) << left << "" << "\t[3] Delete User.\n";
		cout << setw(37) << left << "" << "\t[4] Update User Info.\n";
		cout << setw(37) << left << "" << "\t[5] Find User.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		_PerformManageUserMenuOption((enManageUser)_ReadMangeMenuOption());
	}
};