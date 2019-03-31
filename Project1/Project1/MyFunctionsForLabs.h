#pragma once
#include <iostream>
#include <ctime>

using namespace std;

void printArray(int **arr, int rows, int colons);
void generateArray(int **& integerArray, int rows, int cols);
void deleteArray(int ** integerArray, int rows, int cols);
void fillArrayRandomValue(int ** integerArray, int rows, int cols, int div);
void fillArrayBinar(int ** integerArray, int rows, int cols);
void fillArrayByKeyboard(int ** integerArray, int rows, int cols);
void swapCols(int **integerArray, int counterRows, int counterBack, int cols);
void swapRows(int **integerArray, int counterRows, int counterBack, int rows);
bool findPolendromInTheRow(int **integerArray, int yourRow, int cols);
bool checkForAsceding(int **integerArray, int cols, int yourElementInRow, int yourElementInCols);
bool checkForDesceding(int **integerArray, int yourElementInRow, int yourElementInCols);
bool checkUniq(int **integerArray, int yourElementInRow, int yourElementInCols);
double sumOfRow(int **arr, int rows, int colons);
double foundMinInRow(int **arr, int rows, int colons);

void printArray(int **arr, int rows, int colons)
{
	for (int countRows = 0; countRows < rows; countRows++)
	{
		for (int countColons = 0; countColons < colons; countColons++)
		{
			cout << arr[countRows][countColons] << "\t";
		}
		cout << endl;
	}
}

void generateArray(int **& integerArray, int rows, int cols)
{
	integerArray = new int *[rows];
	for (int countRows = 0; countRows < rows; countRows++)
	{
		integerArray[countRows] = new int[cols];
	}
}

void deleteArray(int ** integerArray, int rows, int cols)
{
	for (int countRows = 0; countRows < rows; countRows++)
	{
		delete[] integerArray[countRows];
	}
	delete[] integerArray;
}

void fillArrayRandomValue(int ** integerArray, int rows, int cols, int div)
{
	srand(time(0));
	for (int counterRows = 0; counterRows < rows; counterRows++)
	{
		for (int counterCols = 0; counterCols < cols; counterCols++)
		{
			integerArray[counterRows][counterCols] = rand() % div;
		}
	}
}

void fillArrayBinar(int ** integerArray, int rows, int cols)
{
	srand(time(0));
	for (int counterRows = 0; counterRows < rows; counterRows++)
	{
		for (int counterCols = 0; counterCols < cols; counterCols++)
		{
			integerArray[counterRows][counterCols] = rand() % 2;
		}
	}
}

void fillArrayByKeyboard(int ** integerArray, int rows, int cols)
{
	for (int counterRows = 0; counterRows < rows; counterRows++)
	{
		for (int counterCols = 0; counterCols < cols; counterCols++)
		{
			cout << "enter your element of array " << "[" << counterRows << "]" << "[" << counterCols << "] ";
			cin >> integerArray[counterRows][counterCols];
		}
	}
}

void swapCols(int **integerArray, int counterRows, int counterBack, int cols)
{

	for (int counterCols = 0; counterCols < cols; counterCols++)
	{
		int ptrTamporaryArray{ 0 };
		ptrTamporaryArray = integerArray[counterRows][counterCols];
		integerArray[counterRows][counterCols] = integerArray[counterBack][counterCols];
		integerArray[counterBack][counterCols] = ptrTamporaryArray;
	}
}

void swapRows(int **integerArray, int counterRows, int counterBack, int rows)
{
	for (int counterRow = 0; counterRow < rows; counterRow++)
	{
		int ptrTamporaryArray{ 0 };
		ptrTamporaryArray = integerArray[counterRow][counterRows];
		integerArray[counterRow][counterRows] = integerArray[counterRow][counterBack];
		integerArray[counterRow][counterBack] = ptrTamporaryArray;
	}
}

bool findPolendromInTheRow(int **integerArray, int usersChoiceRow, int cols)
{
	for (int counterCols = 0; counterCols < int(cols / 2); counterCols++)
	{
		if (integerArray[usersChoiceRow][counterCols] != integerArray[usersChoiceRow][cols - 1 - counterCols])
		{
			return false;
		}
	}
	return true;
}

bool checkForAsceding(int ** integerArray, int cols, int yourElementInRow, int yourElementInCols)
{
	int counterCols = yourElementInCols;
	for (; counterCols < cols; counterCols++)
	{
		if (integerArray[yourElementInRow][yourElementInCols] >= integerArray[yourElementInRow][counterCols]
			&& yourElementInCols != counterCols)
		{
			return false;
		}
	}
	return true;
}

bool checkForDesceding(int **integerArray, int yourElementInRow, int yourElementInCols)
{
	int counterColsLeft = yourElementInCols;
	for (; counterColsLeft >= 0; counterColsLeft--)
	{
		if (integerArray[yourElementInRow][yourElementInCols] <= integerArray[yourElementInRow][counterColsLeft]
			&& yourElementInCols != counterColsLeft)
		{
			return false;
		}
	}
	return true;
}

bool checkUniq(int **integerArray, int yourElementInRow, int yourElementInCols)
{
	for (int counterRows = yourElementInRow; 0 <= counterRows; counterRows--)
	{
		for (int counterCols = yourElementInCols; 0 <= counterCols; counterCols--)
		{
			if (integerArray[yourElementInRow][yourElementInCols] == integerArray[counterRows][counterCols] &&
				&integerArray[yourElementInRow][yourElementInCols] != &integerArray[counterRows][counterCols])
			{
				return false;
			}
		}
	}
	return true;
}

double sumOfRow(int **arr, int rows, int colons)
{
	double sum = 0;
	for (int counterColons = 0; counterColons < colons; counterColons++)
	{
		sum += arr[rows][counterColons];
	}
	return sum;
}

double foundMinInRow(int **arr, int rows, int colons)
{
	double min = arr[0][0];
	for (int counterRows = 0; counterRows < rows; counterRows++)
	{
		if (arr[counterRows][colons] <= min)
		{
			min = arr[counterRows][colons];
		}
	}
	return min;
}