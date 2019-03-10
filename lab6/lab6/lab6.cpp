#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

void var1();
void var2();

int main()
{
	var1();
}

void var1()
{
	char binarNumbersString[100], groupString[100];
	int conterOfGroups = 0, counterGroupString = 0;

	gets_s(binarNumbersString);

	for (int  counterBinarString = 0; counterBinarString <= strlen(binarNumbersString); counterBinarString++)
	{
		if (binarNumbersString[counterBinarString] != ' ')
		{
			groupString[counterGroupString] = binarNumbersString[counterBinarString];
			counterGroupString++;
		}
		if (binarNumbersString[counterBinarString] == ' ' || binarNumbersString[counterBinarString] == '\0')
		{
			groupString[counterGroupString] = '\0';
			counterGroupString = 0;

			if (strlen(groupString) == 5)
			{
				conterOfGroups++;
			}
		}
	}
	cout << conterOfGroups;
}

void var2()
{
	char binarString[100], minBinarString[100];
	int counterMinBinarString = 0;
	
	cout << "Enter your binar string with out spaces" << endl;
	gets_s(binarString);

	for (int counterBinarString = 0; counterBinarString < strlen(binarString); counterBinarString++)
	{

	}
}