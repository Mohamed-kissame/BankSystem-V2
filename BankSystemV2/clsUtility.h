#pragma once
#include <iostream>
#include "clsDate.h"
#include <string>


class clsUtility
{

public:

	static void Srand() {

		srand((unsigned)time(NULL));
	}

	static int RandomNumber(int From, int To) {

		int Rand = rand() % (To - From + 1) + From;

		return Rand;
	}

	static void FillArrayWithRandom(int arr[], int arrLength, int From, int To) {

		for (short i = 0; i < arrLength; i++) {

			arr[i] = RandomNumber(From, To);
		}
	}

	static void PrintArry(int arr[], int arrLength) {

		for (short i = 0; i < arrLength; i++) {

			cout << arr[i] << " ";
		}
	}

	static void PrintDigits(int Number) {

		int Remainder = 0;

		while (Number > 0) {

			Remainder = Number % 10;
			Number = Number / 10;

			cout << Remainder << endl;
		}
	}

	static int SumOfDigits(int Number) {

		int Remainder = 0, Sum = 0;

		while (Number > 0) {

			Remainder = Number % 10;
			Number = Number / 10;
			Sum += Remainder;
		}

		return Sum;
	}

	static int ReverseNumber(int Number) {

		int Remainder = 0, Number2 = 0;

		while (Number > 0)
		{

			Remainder = Number % 10;
			Number = Number / 10;
			Number2 = Number2 * 10 + Remainder;

		}

		return Number2;
	}

	static int CountDigitFrequencyu(short DigitToCheck, int Number) {

		int FreqCount = 0, Remainder = 0;

		while (Number > 0) {

			Remainder = Number % 10;
			Number = Number / 10;

			if (Remainder == DigitToCheck) {

				FreqCount++;
			}
		}

		return FreqCount;
	}

	static void PrintAllDigitsFrequency(int Number) {

		cout << endl;

		for (short i = 0; i < 10; i++) {

			int DigitsToCount = 0;

			DigitsToCount = CountDigitFrequencyu(i, Number);

			if (DigitsToCount > 0) {

				cout << "Digit " << i << " Frequency is " << DigitsToCount << " Time(s).\n";
			}
		}
	}

	static string IsPalindromNumber(int Number) {

		return Number == ReverseNumber(Number) ? "\nYes, it is a Palindrom Number." : "\nNo, it is NOT a Palindrom Number.";
	}

	static void PrintWordsFromAAAtoZZZ() {

		cout << "\n";

		string word = "";

		for (int i = 65; i <= 90;i++) {

			for (int j = 65; j <= 90; j++) {

				for (int z = 65; z <= 90; z++) {

					word = word + char(i);
					word = word + char(j);
					word = word + char(z);

					cout << word << endl;

					word = "";

				}
			}

			cout << "\n_______________________________\n";
		}
	}

	static bool GeussPassword(string OriginalPassword) {

		string word = "";
		int count = 0;

		for (int i = 65; i <= 90;i++) {

			for (int j = 65; j <= 90; j++) {

				for (int z = 65; z <= 90; z++) {

					word = word + char(i);
					word = word + char(j);
					word = word + char(z);

					cout << "Trial [" << count << "] : " << word << endl;

					if (word == OriginalPassword) {

						cout << "\nPassword is " << word << "\n";
						cout << "Found After " << count << " Trial(s)\n";
						return true;
					}

					word = "";
				}
			}
		}

		return false;

	}

	static string EncryptText(string Text, short EncryptionKey = 2) {

		for (short i = 0; i < Text.length(); i++) {

			Text[i] = char((int)Text[i] + EncryptionKey);
		}

		return Text;
	}

	static string DecryptText(string Text, short EncryptionKey = 2) {

		for (short i = 0; i < Text.length(); i++) {

			Text[i] = char((int)Text[i] - EncryptionKey);
		}

		return Text;
	}

	enum enCharType {
		SmallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4, MixChars
		= 5
	};

	static char GetRandomCharacter(enCharType CharType) {

		if (CharType == MixChars)
		{

			CharType = (enCharType)RandomNumber(1, 3);

		}


		switch (CharType) {

		case enCharType::SmallLetter: {

			return char(RandomNumber(97, 122));
			break;
		}
		case enCharType::CapitalLetter: {

			return char(RandomNumber(65, 90));
			break;
		}
		case enCharType::SpecialCharacter: {

			return char(RandomNumber(33, 47));
			break;
		}
		case enCharType::Digit: {

			return char(RandomNumber(48, 57));
			break;
		}
		default:
			return '/0';
		}
	}

	static string GenerateWord(enCharType CharType, short Length) {

		string Word;

		for (int i = 1; i <= Length; i++) {

			Word = Word + GetRandomCharacter(CharType);
		}

		return Word;
	}

	static string GenerateKey(enCharType CharType = CapitalLetter) {

		string Key = "";

		Key = GenerateWord(CharType, 4) + "-";
		Key = Key + GenerateWord(CharType, 4) + "-";
		Key = Key + GenerateWord(CharType, 4) + "-";
		Key = Key + GenerateWord(CharType, 4) + "-";

		return Key;
	}

	static void GenerateKeys(short NumberOfKeys) {

		for (int i = 1; i <= NumberOfKeys; i++) {

			cout << "Key [" << i << "] : ";
			cout << GenerateKey() << endl;
		}
	}

	static int TimesRepeated(int Number, int arr[100], int arrLength) {

		int count = 0;

		for (int i = 0; i <= arrLength; i++) {

			if (Number == arr[i]) {

				count++;
			}

		}

		return count;
	}

	static int MaxNumberInArry(int arr[100], int arrLength) {

		int Max = 0;

		for (short i = 0; i < arrLength;i++) {

			if (arr[i] > Max) {

				Max = arr[i];
			}
		}

		return Max;
	}

	static int MinNumberInArray(int arr[100], int arrLength) {

		int Min = 0;

		for (short i = 0; i < arrLength; i++) {

			if (arr[i] < Min) {

				Min = arr[i];
			}
		}

		return Min;
	}

	static int SumArray(int arr[100], int arrLength) {

		int Sum = 0;

		for (short i = 0; i < arrLength; i++) {

			Sum += arr[i];
		}

		return Sum;
	}

	static float ArrayAverage(int arr[100], int arrLength) {

		return (float)SumArray(arr, arrLength) / arrLength;
	}

	static void CopyArry(int arrSource[100], int arrDestiantion[100], int arrLength) {

		for (short i = 0; i < arrLength; i++) {

			arrDestiantion[i] = arrSource[i];
		}
	}

	static void FillArrayWithRandomWords(string arr[100], int arrLength, enCharType CharType, short Wordlength) {

		for (int i = 0; i < arrLength; i++)
			arr[i] = GenerateWord(CharType, Wordlength);

	}

	static void FillArryWithRandomKey(string arr[100], int arrLength, enCharType CharType) {

		for (short i = 0; i < arrLength; i++) {

			arr[i] = GenerateKey(CharType);
		}
	}

	static void Swap(int& a, int& b) {

		int Temp;

		Temp = a;
		a = b;
		b = Temp;

	}

	static void Swap(double& a, double& b) {

		double Temp;

		Temp = a;
		a = b;
		b = Temp;

	}

	static void Swap(bool& a, bool& b) {

		bool Temp;

		Temp = a;
		a = b;
		b = Temp;

	}

	static void Swap(float& a, float& b) {

		float Temp;

		Temp = a;
		a = b;
		b = Temp;

	}

	static void Swap(string& a, string& b) {

		string Temp;

		Temp = a;
		a = b;
		b = Temp;

	}

	static void Swap(char& a, char& b) {

		char Temp;

		Temp = a;
		a = b;
		b = Temp;

	}

	static void Swap(clsDate& a, clsDate& b) {

		clsDate::SwapDates(a, b);

	}

	static void ShuffleArry(int arr[100], int arrLength) {

		for (int i = 0; i < arrLength; i++) {

			Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
		}
	}

	static  void ShuffleArray(string arr[100], int arrLength)
	{

		for (int i = 0; i < arrLength; i++)
		{
			Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
		}

	}

	static string  Tabs(short NumberOfTabs)
	{
		string t = "";

		for (int i = 1; i < NumberOfTabs; i++)
		{
			t = t + "\t";
			cout << t;
		}
		return t;

	}

	static string NumberToText(int Number){

		if (Number == 0)
		{
			return "";
		}

		if (Number >= 1 && Number <= 19)
		{
			string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
		"Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
		  "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

			return  arr[Number] + " ";

		}

		if (Number >= 20 && Number <= 99)
		{
			string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
			return  arr[Number / 10] + " " + NumberToText(Number % 10);
		}

		if (Number >= 100 && Number <= 199)
		{
			return  "One Hundred " + NumberToText(Number % 100);
		}

		if (Number >= 200 && Number <= 999)
		{
			return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
		}

		if (Number >= 1000 && Number <= 1999)
		{
			return  "One Thousand " + NumberToText(Number % 1000);
		}

		if (Number >= 2000 && Number <= 999999)
		{
			return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
		}

		if (Number >= 1000000 && Number <= 1999999)
		{
			return  "One Million " + NumberToText(Number % 1000000);
		}

		if (Number >= 2000000 && Number <= 999999999)
		{
			return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
		}

		if (Number >= 1000000000 && Number <= 1999999999)
		{
			return  "One Billion " + NumberToText(Number % 1000000000);
		}
		else
		{
			return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
		}


	}


};