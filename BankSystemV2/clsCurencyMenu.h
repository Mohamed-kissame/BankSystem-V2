#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsCurencyList.h"
#include "clsFindCurency.h"
#include "clsUpdateCurencyRate.h"
#include "clsCalculatCurency.h"



class clsCurency : protected clsScreen
{

private:

	enum enCurency {

		eListCurency = 1, eFindCurency = 2, eUpdateCurency = 3, eCalculatorCurency = 4, eMainMenu = 5

	};

	static short _ReadCurencyMenu() {

		cout << setw(37) << left << "" << "choose what do you want to do? [1 to 5]?";
		short Choice = clsInputValide <short>::ReadNumberBetween(1, 5, "Invalide! Enter Please a Number Betwenn [1,5]");
		return Choice;
	}

	static void _ShowListCurencyScreen() {

		clsCurrenciesListScreen::ShowCurrenciesListScreen();
	}

	static void _ShowFindCurencyScreen() {

		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateCurencyScreen() {

		clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
	}

	static void _ShowCalculatorCurencyScreen() {

		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}

	static void _GoBackToCurencyMenu() {


		cout << setw(37) << left << "" << "\n\tPress any key to go back to Curency Menue...\n";

		system("pause>0");
	}

	static void _PerformCurencyMenuOption(enCurency CurencyOption) {

		switch (CurencyOption) {

		case enCurency::eListCurency: {

			system("cls");
			_ShowListCurencyScreen();
			_GoBackToCurencyMenu();
			break;
		}
		case enCurency::eFindCurency: {

			system("cls");
			_ShowFindCurencyScreen();
			_GoBackToCurencyMenu();
			break;
		}
		case enCurency::eUpdateCurency: {

			system("cls");
			_ShowUpdateCurencyScreen();
			_GoBackToCurencyMenu();
			break;
		}
		case enCurency::eCalculatorCurency: {

			system("cls");
			_ShowUpdateCurencyScreen();
			_GoBackToCurencyMenu();
			break;
		}
		case enCurency::eMainMenu: {


		}
		}
	}

public:

	static void ShowCurencyMenu() {

		system("cls");
		_DrawScreenHeader("\t\tCurency Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tCurency Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Show Curency List.\n";
		cout << setw(37) << left << "" << "\t[2] find Curency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Calculate Curency.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformCurencyMenuOption((enCurency)_ReadCurencyMenu());
	}
};