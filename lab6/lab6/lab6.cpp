#include "pch.h"
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

void var1();
void var2();
void var3();
void var4();
void var5();
void var6();
void var7();

int main()
{
	
}

void var1()
{
	char binarNumbersString[100], groupString[100];
	int conterOfGroups = 0, counterGroupString = 0;

	gets_s(binarNumbersString);

	for (int counterBinarString = 0; counterBinarString <= strlen(binarNumbersString); counterBinarString++)
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
	char binarString[100], minBinarString[100], mirrorMinBinarString[100];
	int counterMinBinarString = 0, counterBinarString = 0;

	cout << "Enter your binar string with out spaces" << endl;
	gets_s(binarString);

	for (; counterBinarString < strlen(binarString); counterBinarString++)
	{
		if (binarString[counterBinarString - 1] == binarString[counterBinarString] || counterBinarString == 0)
		{
			minBinarString[counterMinBinarString] = binarString[counterMinBinarString];
			counterMinBinarString++;
		}
		else
		{
			minBinarString[counterMinBinarString] = '\0';
			counterMinBinarString = 0;
			break;
		}
	}
	for (; counterBinarString < strlen(binarString); counterBinarString++)
	{
		if (binarString[counterBinarString - 1] == binarString[counterBinarString] ||
			binarString[counterBinarString + 1] == binarString[counterBinarString] ||
			binarString[counterBinarString + 1] == '\0')
		{
			mirrorMinBinarString[counterMinBinarString] = binarString[counterBinarString];
			counterMinBinarString++;
		}
		if (binarString[counterBinarString + 1] != binarString[counterBinarString])
		{
			mirrorMinBinarString[counterMinBinarString] = '\0';
			if (strlen(mirrorMinBinarString) <= strlen(minBinarString))
			{
				strcpy_s(minBinarString, mirrorMinBinarString);
			}
			counterMinBinarString = 0;
		}
	}
	puts(minBinarString);
}

void var3()
{
	char binarString[100], maxBinarString[100], mirrorMinBinarString[100];
	int counterMinBinarString = 0, counterBinarString = 0;

	cout << "Enter your binar string with out spaces" << endl;
	gets_s(binarString);

	for (; counterBinarString < strlen(binarString); counterBinarString++)
	{
		if (binarString[counterBinarString - 1] == binarString[counterBinarString] || counterBinarString == 0)
		{
			maxBinarString[counterMinBinarString] = binarString[counterMinBinarString];
			counterMinBinarString++;
		}
		else
		{
			maxBinarString[counterMinBinarString] = '\0';
			counterMinBinarString = 0;
			break;
		}
	}
	for (; counterBinarString < strlen(binarString); counterBinarString++)
	{
		if (binarString[counterBinarString - 1] == binarString[counterBinarString] ||
			binarString[counterBinarString + 1] == binarString[counterBinarString] ||
			binarString[counterBinarString + 1] == '\0')
		{
			mirrorMinBinarString[counterMinBinarString] = binarString[counterBinarString];
			counterMinBinarString++;
		}
		if (binarString[counterBinarString + 1] != binarString[counterBinarString])
		{
			mirrorMinBinarString[counterMinBinarString] = '\0';
			if (strlen(mirrorMinBinarString) >= strlen(maxBinarString))
			{
				strcpy_s(maxBinarString, mirrorMinBinarString);
			}
			counterMinBinarString = 0;
		}
	}
	cout << strlen(maxBinarString);
}

void var4()
{
	char binarString[100], gproupString[100];
	int counterGroupString = 0;

	cout << "Enter your binar string with out spaces" << endl;
	gets_s(binarString);

	for (int counterBinarString = 0; counterBinarString < strlen(binarString); counterBinarString++)
	{
		if (binarString[counterBinarString - 1] == binarString[counterBinarString] ||
			binarString[counterBinarString + 1] == binarString[counterBinarString] ||
			binarString[counterBinarString + 1] == '\0')
		{
			gproupString[counterGroupString] = binarString[counterBinarString];
			counterGroupString++;
		}
		if (binarString[counterBinarString + 1] != binarString[counterBinarString])
		{
			gproupString[counterGroupString] = '\0';
			if (strlen(gproupString)% 2 == 0) 
			{
				puts(gproupString);
			}
			counterGroupString = 0;
		}
	}
}

void var5()
{
	char binarString[100], groupString[100];
	int counterGroupString = 0, counterOfOne = 0;

	cout << "Enter your string" << endl;
	gets_s(binarString);

	for (int counterBinarString = 0; counterBinarString <= strlen(binarString); counterBinarString++)
	{
		if (binarString[counterBinarString] != ' ')
		{
			groupString[counterGroupString] = binarString[counterBinarString];
			counterGroupString++;
		}
		if(binarString[counterBinarString] == ' ' || binarString[counterBinarString] == '\0')
		{
			groupString[counterGroupString] = '\0';
			counterGroupString = 0;
			if (strlen(groupString) % 2 != 0)
			{
				for (int counterSubgroup = 0; counterSubgroup < strlen(groupString); counterSubgroup++)
				{
					if (groupString[counterSubgroup] == '1')
					{
						counterOfOne++;
					}
				}
			}
		}
	}
	cout << counterOfOne;
}

void var6()
{
	char string[2][100];

	cout << "Enter your string" << endl;
	gets_s(string[0]);

	for (int counterStringFirst = 0,counterStringSecond = 0; counterStringFirst <strlen(string[0]); counterStringFirst++)
	{
		if (string[0][counterStringFirst] <= '0' || string[0][counterStringFirst] <= '9')
		{
			string[1][counterStringSecond] = string[0][counterStringFirst];
			counterStringSecond++;
		}
		if (counterStringFirst + 1 == strlen(string[0]))
		{
			string[1][counterStringSecond] = '\0';
		}
	}
	puts(string[1]);
}

void var7()
{

}