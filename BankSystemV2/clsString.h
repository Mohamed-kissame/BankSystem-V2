#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class clsString
{

private:

	string _Value;
public:

	clsString() {

		_Value = "";

	}

	clsString(string value) {

		_Value = value;

	}

	void SetValue(string Value) {

		_Value = Value;
	}

	string GetValue() {

		return _Value;
	}

	__declspec(property(get = GetValue, put = SetValue)) string value;


	static void PrintFirstLetterOfEachWord(string S1) {

		bool IsFirstLater = true;

		for (short i = 0; i < S1.length(); i++) {

			if (S1[i] != ' ' && IsFirstLater) {

				cout << S1[i] << endl;
			}

			IsFirstLater = (S1[i] == ' ' ? true : false);
		}
	}

	void PrintFirstLetterOfEachWord() {

		PrintFirstLetterOfEachWord(_Value);
	}

	static string UpperFirstLetterOfEachWord(string S1) {

		bool IsFirstLetter = true;

		for (short i = 0; i < S1.length(); i++) {

			if (S1[i] != ' ' && IsFirstLetter) {

				S1[i] = toupper(S1[i]);
			}

			IsFirstLetter = (S1[i] == ' ' ? true : false);
		}

		return S1;
	}


	string UpperFirstLetterOfEachWord() {

		return UpperFirstLetterOfEachWord(_Value);
	}

	static string LowerFirstLetterOfEachWord(string s1) {

		bool IsFirstLetter = true;

		for (short i = 0; i < s1.length(); i++) {

			if (s1[i] != ' ' && IsFirstLetter) {

				s1[i] = tolower(s1[i]);
			}

			IsFirstLetter = (s1[i] == ' ' ? true : false);
		}

		return s1;
	}

	string LowerFirstLetterOfEachWord() {

		return LowerFirstLetterOfEachWord(_Value);
	}

	static string UpperAllLetterOfAStrin(string s1) {

		for (short i = 0; i < s1.length(); i++) {

			s1[i] = toupper(s1[i]);
		}

		return s1;
	}

	void UpperAllLetterOfAStrin() {

		_Value = UpperAllLetterOfAStrin(_Value);
	}

	static string LowerAllLetterOfAString(string s1) {

		for (short i = 0; i < s1.length(); i++) {

			s1[i] = tolower(s1[i]);
		}

		return s1;
	}

	void LowerAllLetterOfAString() {

		_Value = LowerAllLetterOfAString(_Value);
	}

	static char InvertCase(char charat) {

		return isupper(charat) ? tolower(charat) : toupper(charat);
	}

	static string InvertAllLetterCase(string s1) {

		for (short i = 0; i < s1.length(); i++) {

			s1[i] = InvertCase(s1[i]);
		}

		return s1;
	}

	void InvertAllLetterCase() {

		_Value = InvertAllLetterCase(_Value);
	}

	enum enWhatToCount
	{
		SmallLetters = 0, CapitalLetter = 1, All = 3

	};

	static short LengthOfString(string s1) {

		return s1.length();
	}

	short Length() {

		return _Value.length();
	}

	static short CountCapitalLetters(string s1) {

		short CountCapitalLetter = 0;

		for (short i = 0; i < s1.length(); i++) {

			if (isupper(s1[i]))
				CountCapitalLetter++;
		}

		return CountCapitalLetter;
	}

	short CountCapitalLetters() {

		return CountCapitalLetters(_Value);
	}

	static short CountSmallLetter(string s1) {

		short CountSmallLetter = 0;

		for (short i = 0; i < s1.length(); i++) {

			if (islower(s1[i]))
				CountSmallLetter++;

		}

		return CountSmallLetter;

	}

	short CountSmallLetter() {

		return CountSmallLetter(_Value);
	}

	static short CountACharacterInString(string s1, char Letter) {

		short CountLetter = 0;

		for (short i = 0; i < s1.length(); i++) {

			if (s1[i] == Letter) {

				CountLetter++;
			}
		}

		return CountLetter;
	}

	static short CountLetters(string S1, enWhatToCount WhatToCount = enWhatToCount::All)
	{


		if (WhatToCount == enWhatToCount::All)
		{
			return S1.length();
		}

		short Counter = 0;

		for (short i = 0; i < S1.length(); i++)
		{

			if (WhatToCount == enWhatToCount::CapitalLetter && isupper(S1[i]))
				Counter++;


			if (WhatToCount == enWhatToCount::SmallLetters && islower(S1[i]))
				Counter++;


		}

		return Counter;

	}


	static bool IsVowel(char Letter) {

		Letter = tolower(Letter);

		return ((Letter == 'a') || (Letter == 'e') || (Letter == 'i') || (Letter == 'o') || (Letter == 'u'));
	}


	static short CountSpecificLetter(string s1, char Letter, bool MatchCase = true) {

		short countLetter = 0;

		for (short i = 0; i < s1.length(); i++) {

			if (MatchCase) {

				if (s1[i] == Letter)
					countLetter++;
			}
			else {

				if (tolower(s1[i]) == tolower(Letter))
					countLetter++;
			}
		}
		return countLetter;
	}

	short  CountSpecificLetter(char Letter, bool MatchCase = true)
	{
		return CountSpecificLetter(_Value, Letter, MatchCase);
	}

	void CheckIsVowel(char Letter) {


		if (IsVowel(Letter))
			cout << "\nYes Letter \'" << Letter << "\' is vowel";

		else

			cout << "\nNo Letter \'" << Letter << "\' is NOT vowel";

	}

	static vector <string> SplitString(string s1, string Delim) {

		short pos = 0;
		string sWord;
		vector <string> String;

		while ((pos = s1.find(Delim)) != std::string::npos) {

			sWord = s1.substr(0, pos);

			if (sWord != "") {

				String.push_back(sWord);
			}

			s1.erase(0, pos + Delim.length());
		}

		if (s1 != "") {

			String.push_back(s1);
		}

		return String;
	}

	vector <string> SplitString(string Delim) {

		return SplitString(_Value, Delim);
	}

	static short CountString(string s1, string Delim = " ") {


		short pos = 0;
		string sWord;
		short counter = 0;

		while ((pos = s1.find(Delim)) != std::string::npos) {

			sWord = s1.substr(0, pos);

			if (sWord != "") {

				counter++;
			}

			s1.erase(0, pos + Delim.length());
		}

		if (s1 != "") {

			++counter;
		}

		return counter;

	}

	short CountString() {

		return CountString(_Value);

	}

	static int ScorOfString(string S1) {

		int SaveValue = S1[0];
		int Results = 0;

		for (short i = 0; i < S1.length(); i++) {

			Results += abs(SaveValue - S1[i]);

			SaveValue = S1[i];
		}

		return Results;

	}

	void ScorOfString() {

		_Value = ScorOfString(_Value);
	}

	static int CountVowelLetter(string s1) {

		int CountVowelLetter = 0;

		for (short i = 0; i < s1.length(); i++) {

			if (IsVowel(s1[i])) {

				CountVowelLetter++;

			}
		}

		return CountVowelLetter;
	}

	int CountVowelLetter() {

		return CountVowelLetter(_Value);

	}

	static void PrintAllVowels(string s1) {

		cout << "\nVowels in string are: ";

		for (short i = 0; i < s1.length(); i++) {

			if (IsVowel(s1[i])) {

				cout << s1[i] << " ";

			}
		}
	}

	void PrintAllVowels() {

		PrintAllVowels(_Value);
	}

	static void PrintEachWord(string s1) {

		string sWord;
		string Delim = " ";
		short pos = 0;

		cout << "\nYour string words are: \n\n";

		while ((pos = s1.find(Delim)) != std::string::npos) {

			sWord = s1.substr(0, pos);

			if (sWord != "") {

				cout << sWord << endl;
			}

			s1.erase(0, pos + Delim.length());
		}

		if (s1 != "") {

			cout << s1 << endl;
		}
	}

	void PrintEachWord() {

		PrintEachWord(_Value);
	}

	static string TirmLeft(string s1) {

		for (short i = 0; i < s1.length(); i++) {

			if (s1[i] != ' ') {

				return s1.substr(1, s1.length() - 1);
			}
		}

		return "";

	}

	void TirmLeft() {

		_Value = TirmLeft(_Value);
	}

	static string TirmRight(string s1) {

		for (short i = s1.length(); i >= 0; i++) {

			if (s1[i] != ' ') {

				return s1.substr(0, i + 1);
			}
		}

		return "";

	}

	void TirmRight() {

		_Value = TirmRight(_Value);
	}

	static string Tirm(string s1) {

		return(TirmLeft(TirmRight(s1)));

	}

	void Tirm() {

		_Value = Tirm(_Value);
	}

	static string JoinString(vector<string> vString, string Delim = " ") {

		string S1 = "";

		for (string& s : vString)
		{

			S1 = S1 + s + Delim;

		}

		return S1.substr(0, S1.length() - Delim.length());

	}

	static string JoinString(string arrString[], short Length, string Delim)
	{

		string S1 = "";

		for (short i = 0; i < Length; i++)
		{
			S1 = S1 + arrString[i] + Delim;
		}

		return S1.substr(0, S1.length() - Delim.length());

	}


	static string ReverseWordsInString(string S1)
	{
		vector<string> vString;


		string S2 = "";

		vString = SplitString(S1, " ");

		// declare iterator

		vector<string>::iterator iter = vString.end();

		while (iter != vString.begin())
		{
			--iter;
			S2 += *iter + " ";
		}
		S2 = S2.substr(0, S2.length() - 1); //remove last space.

		return S2;
	}

	void ReverseWordsInString() {

		_Value = ReverseWordsInString(_Value);
	}

	static string ReplaceWordInStringUsingBuiltInFunction(string S1, string StringToReplace, string sRepalceTo)
	{
		short pos = S1.find(StringToReplace);

		while (pos != std::string::npos)
		{
			S1 = S1.replace(pos, StringToReplace.length(), sRepalceTo);

			pos = S1.find(StringToReplace);//find next
		}
		return S1;
	}

	static string ReplaceWordInStringUsingSplit(string S1, string
		StringToReplace, string sRepalceTo, bool MatchCase = true)
	{
		vector<string> vString = SplitString(S1, " ");
		for (string& s : vString)
		{
			if (MatchCase)
			{
				if (s == StringToReplace)
				{
					s = sRepalceTo;
				}
			}
			else
			{
				if (LowerAllLetterOfAString(s) ==
					LowerAllLetterOfAString(StringToReplace))
				{
					s = sRepalceTo;
				}
			}
		}
		return JoinString(vString, " ");
	}

	static string RemovePunctuations(string S1)
	{
		string S2 = "";

		for (short i = 0; i < S1.length(); i++)
		{
			if (!ispunct(S1[i]))
			{
				S2 += S1[i];
			}
		}
		return S2;
	}

	void RemovePunctuations() {

		_Value = RemovePunctuations(_Value);
	}

};