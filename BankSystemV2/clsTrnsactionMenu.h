#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsDepositScreen.h"
#include "clsTrnsactionMenu.h"
#include "clsWithDraw.h"
#include "clsTotalBalance.h"
#include "clsUser.h"
#include "clsTransferScreen.h"
#include "clsTrnsferLog.h"
#include <iomanip>

using namespace std;

class clsTransactionsScreen :protected clsScreen
{
private:
    enum enTransactionsMenueOptions {
        eDeposit = 1, eWithdraw = 2,
        eShowTotalBalance = 3, eTrnsfer = 4, eTransferLog = 5, eShowMainMenue = 6
    };

    static short ReadTransactionsMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = clsInputValide<short>::ReadNumberBetween(1, 6, "Enter Number between 1 to 6? ");
        return Choice;
    }


    static void _ShowDepositScreen()
    {
        clsDepositScreen::ShowDepositScreen();
    }

    static void _ShowWithdrawScreen()
    {
        clsWithdrawScreen::ShowWithdrawScreen();
    }

    static void _ShowTotalBalancesScreen()
    {
        clsTotalBalancesScreen::ShowTotalBalances();
    }

    static void _ShowTrnsferScreen() {

        clsTransferScreen::ShowTransferScreen();

    }

    static void _ShowTransferLogScreen() {

        clsTransferLogScreen::ShowTrnsferLogScreen();
    }

    static void _GoBackToTransactionsMenue()
    {
        cout << "\n\nPress any key to go back to Transactions Menue...";
        system("pause>0");
        ShowTransactionsMenue();

    }

    static void _PerformTransactionsMenueOption(enTransactionsMenueOptions TransactionsMenueOption)
    {
        switch (TransactionsMenueOption)
        {
        case enTransactionsMenueOptions::eDeposit:
        {
            system("cls");
            _ShowDepositScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eWithdraw:
        {
            system("cls");
            _ShowWithdrawScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eShowTotalBalance:
        {
            system("cls");
            _ShowTotalBalancesScreen();
            _GoBackToTransactionsMenue();
            break;
        }

        case enTransactionsMenueOptions::eTrnsfer: {

            system("cls");
            _ShowTrnsferScreen();
            _GoBackToTransactionsMenue();

        }
        case enTransactionsMenueOptions::eTransferLog: {

            system("cls");
            _ShowTransferLogScreen();
            _GoBackToTransactionsMenue();
        }
        case enTransactionsMenueOptions::eShowMainMenue:
        {

        }
        }

    }

public:


    static void ShowTransactionsMenue()
    {

        if (!CheckAccessRights(clsUser::enPermissions::pTranactions)) {

            return;
        }

        system("cls");
        _DrawScreenHeader("\t  Transactions Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Transfer.\n";
        cout << setw(37) << left << "" << "\t[5] Transfer Log List.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformTransactionsMenueOption((enTransactionsMenueOptions)ReadTransactionsMenueOption());
    }

};