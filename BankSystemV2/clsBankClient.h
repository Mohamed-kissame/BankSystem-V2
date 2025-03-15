#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include "clsDate.h"
#include <vector>
#include <fstream>

using namespace std;



class clsBankClient : public clsPerson
{
private:

    enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
    enMode _Mode;

    string _AccountNumber;
    string _PinCode;
    float _AccountBalance;
    bool _MarkForDelete = false;

    static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#")
    {
        vector<string> vClientData;
        vClientData = clsString::SplitString(Line, Seperator);

        return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
            vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));

    }

    static string _ConverClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
    {

        string stClientRecord = "";
        stClientRecord += Client.FirstName + Seperator;
        stClientRecord += Client.LastName + Seperator;
        stClientRecord += Client.Email + Seperator;
        stClientRecord += Client.Phone + Seperator;
        stClientRecord += Client.AccountNumber() + Seperator;
        stClientRecord += Client.PinCode + Seperator;
        stClientRecord += to_string(Client.AccountBalance);

        return stClientRecord;

    }

    static  vector <clsBankClient> _LoadClientsDataFromFile()
    {

        vector <clsBankClient> vClients;

        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsBankClient Client = _ConvertLinetoClientObject(Line);

                vClients.push_back(Client);
            }

            MyFile.close();

        }

        return vClients;

    }

    static void _SaveCleintsDataToFile(vector <clsBankClient> vClients)
    {

        fstream MyFile;
        MyFile.open("Clients.txt", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsBankClient C : vClients)
            {
                DataLine = _ConverClientObjectToLine(C);
                MyFile << DataLine << endl;

            }

            MyFile.close();

        }

    }

    void _Update()
    {
        vector <clsBankClient> _vClients;
        _vClients = _LoadClientsDataFromFile();

        for (clsBankClient& C : _vClients)
        {
            if (C.AccountNumber() == AccountNumber())
            {
                C = *this;
                break;
            }

        }

        _SaveCleintsDataToFile(_vClients);

    }

    void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }

    void _AddNew() {

        _AddDataLineToFile(_ConverClientObjectToLine(*this));
    }

    static clsBankClient _GetEmptyClientObject()
    {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

    string _PrepareTrnsferLogRecord(float Amount, clsBankClient Destination, string UserName, string Seperator = "#//#") {

        string TransferLogRecord = "";

        TransferLogRecord += clsDate::GetSystemDateTimeStrin() + Seperator;
        TransferLogRecord += AccountNumber() + Seperator;
        TransferLogRecord += Destination.AccountNumber() + Seperator;
        TransferLogRecord += to_string(Amount) + Seperator;
        TransferLogRecord += to_string(AccountBalance) + Seperator;
        TransferLogRecord += to_string(Destination.AccountBalance) + Seperator;
        TransferLogRecord += UserName;
        return TransferLogRecord;
    }

    void _RegisterTransferLog(float Amount, clsBankClient Destination, string UserName) {

        string stDateLine = _PrepareTrnsferLogRecord(Amount, Destination, UserName);

        fstream MyFile;

        MyFile.open("TrnsferLog.txt", ios::out | ios::app);

        if (MyFile.is_open()) {

            MyFile << stDateLine << endl;

            MyFile.close();
        }
    }

    struct stTransferLogRecord;

    static stTransferLogRecord _ConvertTrnsferLogToRecord(string Line, string Seperator = "#//#") {


        stTransferLogRecord stTransferLog;

        vector <string> vTrnsfer = clsString::SplitString(Line, Seperator);

        stTransferLog.DateTime = vTrnsfer[0];
        stTransferLog.AccountNumberSource = vTrnsfer[1];
        stTransferLog.AccountNumberDestination = vTrnsfer[2];
        stTransferLog.Amount = stof(vTrnsfer[3]);
        stTransferLog.s_Balance = stof(vTrnsfer[4]);
        stTransferLog.s_Balance = stof(vTrnsfer[5]);
        stTransferLog.UserName = vTrnsfer[6];

        return stTransferLog;
    }



public:

    struct stTransferLogRecord {

        string DateTime;
        string AccountNumberSource;
        string AccountNumberDestination;
        float Amount;
        float s_Balance;
        float d_Balance;
        string UserName;
    };

    clsBankClient(enMode Mode, string FirstName, string LastName,
        string Email, string Phone, string AccountNumber, string PinCode,
        float AccountBalance) :
        clsPerson(FirstName, LastName, Email, Phone)

    {
        _Mode = Mode;
        _AccountNumber = AccountNumber;
        _PinCode = PinCode;
        _AccountBalance = AccountBalance;

    }

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }


    string AccountNumber()
    {
        return _AccountNumber;
    }

    void SetPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }

    string GetPinCode()
    {
        return _PinCode;
    }
    __declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

    void SetAccountBalance(float AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }

    float GetAccountBalance()
    {
        return _AccountBalance;
    }
    __declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;


    static clsBankClient Find(string AccountNumber)
    {


        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.AccountNumber() == AccountNumber)
                {
                    MyFile.close();
                    return Client;
                }

            }

            MyFile.close();

        }

        return _GetEmptyClientObject();
    }

    static clsBankClient Find(string AccountNumber, string PinCode)
    {


        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
                {
                    MyFile.close();
                    return Client;
                }

            }

            MyFile.close();

        }
        return _GetEmptyClientObject();
    }

    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExists = 2 };

    enSaveResults Save()
    {

        switch (_Mode)
        {
        case enMode::EmptyMode:
        {

            return enSaveResults::svFaildEmptyObject;
        }

        case enMode::UpdateMode:
        {


            _Update();

            return enSaveResults::svSucceeded;

            break;
        }

        case enMode::AddNewMode: {

            if (clsBankClient::IsClientExist(_AccountNumber)) {

                return enSaveResults::svFaildAccountNumberExists;
            }
            else {

                _AddNew();

                _Mode = enMode::UpdateMode;
                return enSaveResults::svSucceeded;
            }
        }

        }

    }

    bool Delete() {

        vector <clsBankClient> _vClient;
        _vClient = _LoadClientsDataFromFile();

        for (clsBankClient& C : _vClient) {

            if (C.AccountNumber() == _AccountNumber) {

                C._MarkForDelete = true;
                break;
            }
        }

        _SaveCleintsDataToFile(_vClient);

        *this = _GetEmptyClientObject();

        return true;
    }

    static bool IsClientExist(string AccountNumber)
    {

        clsBankClient Client1 = clsBankClient::Find(AccountNumber);
        return (!Client1.IsEmpty());
    }

    static clsBankClient GetAddNewClientObject(string AccountNumber) {

        return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
    }

    static vector <clsBankClient> GetClientList() {

        return _LoadClientsDataFromFile();
    }

    static float GetTotalBalances() {

        vector <clsBankClient> vClients = clsBankClient::GetClientList();

        double TotalBlances = 0;

        for (clsBankClient Client : vClients) {

            TotalBlances += Client.AccountBalance;
        }

        return TotalBlances;
    }

    void Deposit(double Amount) {

        _AccountBalance += Amount;
        Save();
    }

    bool WithDraw(double Amount) {

        if (Amount > _AccountBalance) {

            return false;
        }
        else {

            _AccountBalance -= Amount;
            Save();
        }
    }

    bool Trnsfer(float Amount, clsBankClient& DestinationClient, string UserName) {

        if (Amount > AccountBalance) {

            return false;
        }

        WithDraw(Amount);
        DestinationClient.Deposit(Amount);
        _RegisterTransferLog(Amount, DestinationClient, UserName);
        return true;
    }

    static vector <stTransferLogRecord> GetTrnsferLogList() {

        vector <stTransferLogRecord> vTrnsferLogRecord;


        fstream MyFile;

        MyFile.open("TrnsferLog.txt", ios::in);

        if (MyFile.is_open()) {


            string Line;

            stTransferLogRecord stLogTrnsfer;

            while (getline(MyFile, Line)) {

                stLogTrnsfer = _ConvertTrnsferLogToRecord(Line);

                vTrnsferLogRecord.push_back(stLogTrnsfer);

            }
            MyFile.close();
        }

        return vTrnsferLogRecord;
    }
};