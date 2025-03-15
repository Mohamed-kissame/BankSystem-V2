#pragma once

#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include <fstream>
#include "clsBankClient.h"


class clsTransferLogScreen :protected clsScreen
{

private:

    static void PrintTrnsferLogRecordLine(clsBankClient::stTransferLogRecord TransferLog)
    {

        cout << setw(8) << left << "" << "| " << setw(23) << left << TransferLog.DateTime;
        cout << "| " << setw(8) << left << TransferLog.AccountNumberSource;
        cout << "| " << setw(8) << left << TransferLog.AccountNumberDestination;
        cout << "| " << setw(8) << left << TransferLog.Amount;
        cout << "| " << setw(10) << left << TransferLog.s_Balance;
        cout << "| " << setw(10) << left << TransferLog.d_Balance;
        cout << "| " << setw(8) << left << TransferLog.UserName;
    }

public:

    static void ShowTrnsferLogScreen()
    {



        vector <clsBankClient::stTransferLogRecord> vTrnsferLogRecord = clsBankClient::GetTrnsferLogList();

        string Title = "\tTrnsfer Log List Screen";
        string SubTitle = "\t\t(" + to_string(vTrnsferLogRecord.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(23) << "Date/Time";
        cout << "| " << left << setw(8) << "s.Acct";
        cout << "| " << left << setw(8) << "d.Acct";
        cout << "| " << left << setw(8) << "Amount";
        cout << "| " << left << setw(10) << "s.Balance";
        cout << "| " << left << setw(10) << "d.Balance";
        cout << "| " << left << setw(8) << "User";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vTrnsferLogRecord.size() == 0)
            cout << "\t\t\t\tNo Logins Available In the System!";
        else

            for (clsBankClient::stTransferLogRecord Record : vTrnsferLogRecord)
            {

                PrintTrnsferLogRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }

};