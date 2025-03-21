#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsUser.h" 
#include "clsInputValidate.h"

class clsUpdateClientScreen :protected clsScreen

{
private:

    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }

    static void ReadClientInfo(clsBankClient& Client)
    {
        cout << "\nEnter FirstName: ";
        Client.FirstName = clsInputValide<string>::ReadString();

        cout << "\nEnter LastName: ";
        Client.LastName = clsInputValide<string>::ReadString();

        cout << "\nEnter Email: ";
        Client.Email = clsInputValide<string>::ReadString();

        cout << "\nEnter Phone: ";
        Client.Phone = clsInputValide<string>::ReadString();

        cout << "\nEnter PinCode: ";
        Client.PinCode = clsInputValide<string>::ReadString();

        cout << "\nEnter Account Balance: ";
        Client.AccountBalance = clsInputValide<float>::ReadNumber();
    }

public:

    static void ShowUpdateClientScreen()
    {

        if (!CheckAccessRights(clsUser::enPermissions::pUpdateClients)) {

            return;
        }

        _DrawScreenHeader("\tUpdate Client Screen");

        string AccountNumber = "";

        cout << "\nPlease Enter client Account Number: ";
        AccountNumber = clsInputValide<string>::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValide<string>::ReadString();
        }

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);

        _PrintClient(Client1);

        cout << "\nAre you sure you want to update this client y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {

            cout << "\n\nUpdate Client Info:";
            cout << "\n____________________\n";


            ReadClientInfo(Client1);

            clsBankClient::enSaveResults SaveResult;

            SaveResult = Client1.Save();

            switch (SaveResult)
            {
            case  clsBankClient::enSaveResults::svSucceeded:
            {
                cout << "\nAccount Updated Successfully :-)\n";

                _PrintClient(Client1);
                break;
            }
            case clsBankClient::enSaveResults::svFaildEmptyObject:
            {
                cout << "\nError account was not saved because it's Empty";
                break;

            }

            }

        }

    }
};