
#include "pch.h"
#include<iostream>
#include<string>
#include<cctype>
#include<algorithm>
#include<Windows.h>

using namespace std;

//We require a few 'global' variables
string code = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int k;

void encrypt(string str)
{
	string process = "Encrypting...";

	for (auto i = 0; i < str.size(); i++)
		str[i] = toupper(str[i]);

	for (auto i = 0; i < process.size(); i++)
	{
		cout << process[i];
		Sleep(100);
	}
	cout << "\n\n";

	char c[sizeof(str)/sizeof(str[0])];
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ')
		{
			c[i] = str[i];
			cout << c[i];
		}
		else
		{
			//find the letter from the alphabet list
			int pos_x = code.find((char)str[i]);
			//Encrypt using E=(x+k) mod 26
			pos_x = (pos_x + k) % 26;
			//replace the letter in the current position with the position obtained from the modular equation
			c[i] = code[pos_x];
			//keep printing...
			cout << c[i];
		}
	}
}

void decrypt(string str)
{
	string process = "Decrypting...";

	for (auto i = 0; i < str.size(); i++)
		str[i] = toupper(str[i]);

	for (auto i = 0; i < process.size(); i++)
	{
		cout << process[i];
		Sleep(100);
	}
	cout << "\n\n";


	char c[sizeof(str) / sizeof(str[0])];
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ')
		{
			c[i] = str[i];
			cout << c[i];
		}
		else
		{
			//find the letter from the alphabet list
			int pos_x = code.find((char)str[i]);
			//Decrypt using D=(x-k) mod 26
			pos_x = (pos_x - k);
			//if this expression is negative then turn it into positive before doing mod 26
			//this is done by adding cycles of 26 to this pos_x value
			while (pos_x < 0)
				pos_x += 26;
			//now perform modulo division
			pos_x %= 26;
			//replace the letter in the current position with the position obtained from the modular equation
			c[i] = code[pos_x];
			//keep printing...
			cout << c[i];
		}
	}
}

int main()
{
	//variables_list_start
	string intro_1 = "Caesar Cipher Program v1.00";
	string intro_2 = "Coded by Awnon Bhowmik\n\n";

	string plain_text;

	//variables_list_end;

	for (auto i = 0; i < intro_1.size(); i++)
	{
		cout << intro_1[i];
		Sleep(100);
	}
	cout << endl;
	for (auto i = 0; i < intro_2.size(); i++)
	{
		cout << intro_2[i];
		Sleep(100);
	}

	cout << "Enter shift:";
	cin >> k;

	cout << endl << "Enter string: ";
	cin.ignore();
	getline(cin, plain_text);

	cout << "1. Encrypt\n2. Decrypt";
	cout << "\n\n Choose one:";
	int choice;
	cin >> choice;
	//While we may have done it using logical if statements
	//I chose to use switch statement since we are dealing with only 2 cases
	//the other cases are by default unimportant to us
	switch (choice)
	{
	case 1:
		encrypt(plain_text);
		break;
	case 2:
		decrypt(plain_text);
		break;
	default:
		cout << "Wrong input!";
		break;
	}
	return 0;
}