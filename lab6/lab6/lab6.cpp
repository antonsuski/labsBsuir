﻿#include "pch.h"
#include <iostream>
#include <string>
#include <ctime>
#include <math.h>

using namespace std;

double sumStirng(char myString[]);
void sortArray(double ptr[], int size);
void var1();
void var2();
void var3();
void var4();
void var5();
void var6();
void var7();
void var8();
void var9();

int main()
{
	double arr[3] = {12,31,1};
	sortArray(arr, 3);
	for (int counter = 0; counter < 3; counter++)
	{
		cout << arr[counter];
		cout << endl;
	}
}

double sumStirng(char myString[])
{
	double sum = 0;
	int checkFloat = 0;
	int counterExponenta = 1;

	for (int counterString = 0; counterString < strlen(myString); counterString++)
	{
		if (myString[counterString] == '.')
		{
			checkFloat = 1;
			continue;
		}
		switch (checkFloat)
		{
		case(0): 
			{
			sum += (double)myString[counterString] - 48;
				break;
			}
		case(1):
		{
			sum += ((double)myString[counterString] - 48) / pow(10.,counterExponenta);
			counterExponenta++;
			break;
		}
		default:
			break;
		}
	}
	return sum;
}

void sortArray(double ptr[], int size)
{
	for (int  counterArray = 0; counterArray < size; counterArray++)
	{
		for (int counterBack = counterArray; counterBack < size; counterBack++)
		{
			if (ptr[counterArray] > ptr[counterBack])
			{
				swap(ptr[counterArray], ptr[counterBack]);
			}
		}
	}
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
	char myString[2][100];

	cout << "Enter your string" << endl;
	gets_s(myString[0]);

	for (int counterStringFirst = 0, counterStringSecond = 0; counterStringFirst < strlen(myString[0]); counterStringFirst++)
	{
		if (myString[0][counterStringFirst] <= '0' || myString[0][counterStringFirst] <= '9' || myString[0][counterStringFirst] == '.')
		{
			myString[1][counterStringSecond] = myString[0][counterStringFirst];
			counterStringSecond++;
		}
		else
		{
			myString[1][counterStringSecond] = '\0';
			counterStringSecond = 0;
			for (; counterStringSecond < strlen(myString[1]); counterStringSecond++)
			{
				if (myString[1][counterStringSecond]=='.')
				{
					puts(myString[1]);
				}
			}
			counterStringSecond = 0;
		}
	}
}

void var8()
{
	// не понятное задание
	char myString[2][100];

	cout << "Enter your string" << endl;
	gets_s(myString[0]);
}

void var9()
{
	char myString[100], groupString[100];
	int size = 0, counterGroupString = 0, counterArray = 0;

	cout << "Enter your string" << endl;
	gets_s(myString);
	for (int counterString = 0; counterString <= strlen(myString); counterString++)
	{
		if (myString[counterString] == ' ' || myString[counterString] == '\0')
		{
			size++;
		}
	}
	double * ptrArray = new double[size];
	for (int counterString = 0; counterString < strlen(myString); counterString++)
	{
		if (myString[counterString] != ' ' || myString[counterString] != '\0')
		{
			groupString[counterGroupString] = myString[counterString];
			counterGroupString++;
		}
		else
		{
			groupString[counterGroupString] = '\0';
			counterGroupString = 0;
			ptrArray[counterArray]=sumStirng(groupString);
			counterArray++;
		}
	}
	cout << endl;

	for (counterArray = 0; counterArray < size; counterArray++)
	{
		cout << ptrArray[counterArray];
	}
	cout << endl;

	delete[] ptrArray;
}