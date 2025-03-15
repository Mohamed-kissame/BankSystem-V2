#pragma once
#include <iostream>
#include <string>
#include "clsDate.h"

using namespace std;

template <class T>
class clsInputValide
{
public:

	static  T IsNumberBetween(T Number, T From, T To) {

		return (Number >= From && Number <= To) ? true : false;
	}

	static bool IsDateBetween(clsDate Date, clsDate From, clsDate To)
	{


		if ((clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
			&&
			(clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
			)
		{
			return true;
		}


		if ((clsDate::IsDate1AfterDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
			&&
			(clsDate::IsDate1BeforeDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
			)
		{
			return true;
		}

		return false;
	}

	static T ReadNumberBetween(T From, T To, string ErrorMessage) {

		T Number = ReadNumber();

		while (!IsNumberBetween(Number, From, To)) {

			cout << ErrorMessage;
			Number = ReadNumber();
		}

		return Number;
	}

	static T ReadNumber(string ErrorMessage = "Invalid Number, Enter again\n") {

		T Number = 0;

		while (!(cin >> Number)) {

			cin.clear();
			cin.ignore(std::numeric_limits<streamsize>::max(), '/n');
			cout << ErrorMessage;

		}

		return Number;
	}

	static bool IsValideDate(clsDate Date) {

		return clsDate::IsValidDate(Date);

	}

	static T ReadString() {

		T s = "";

		getline(cin >> ws, s);

		return s;
	}

};