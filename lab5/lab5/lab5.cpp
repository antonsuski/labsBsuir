#include "pch.h"
#include <iostream>
#include <ctime>

using namespace std;

void printArray(int **arr, int rows, int colons);
void generateArray(int **& integerArray, int rows, int cols);
void deleteArray(int ** integerArray, int rows, int cols);
void fillArrayRandomValue(int ** integerArray, int rows, int cols);
void fillArrayBinar(int ** integerArray, int rows, int cols);
void fillArrayByKeyboard(int ** integerArray, int rows, int cols);
bool findPolendromInTheRow(int **integerArray, int yourRow, int cols);
bool checkForAsceding(int **integerArray, int cols, int yourElementInRow, int yourElementInCols);
bool checkForDesceding(int **integerArray, int yourElementInRow, int yourElementInCols);
bool checkUniq(int **integerArray, int rows, int cols, int yourElementInRow, int yourElementInCols);
void var1();
void var2();
void var3();
void var4();
void var5();
void var6();

int main()
{
	var6();
}


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

void fillArrayRandomValue(int ** integerArray, int rows, int cols)
{
	srand(time(0));
	for (int counterRows = 0; counterRows < rows; counterRows++)
	{
		for (int counterCols = 0; counterCols < cols; counterCols++)
		{
			integerArray[counterRows][counterCols] = rand() % 10;
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

bool checkUniq(int **integerArray, int rows, int cols, int yourElementInRow, int yourElementInCols)
{
	for (int counterRows = 0; counterRows < rows; counterRows++)
	{
		for (int counterCols = 0; counterCols < cols; counterCols++)
		{
			if (integerArray[rows][cols] == integerArray[yourElementInRow][yourElementInCols])
			{
				return false;
			}
		}
	}
	return true;
}

void var1()
{
	srand(time(0));

	int ** integerArray,
		rows{ 3 },
		cols{ 3 },
		userChoiseRow{ rand() % 3 },
		userChoiseCols{ rand() % 3 },
		sumColsItems = 0;

	generateArray(integerArray, rows, cols);
	fillArrayBinar(integerArray, rows, cols);
	printArray(integerArray, rows, cols);
	cout << "user choise " << userChoiseRow + 1 << " " << userChoiseCols + 1 << endl;

	for (int counterRows = 0; counterRows < rows; counterRows++)
	{
		sumColsItems = +integerArray[counterRows][userChoiseCols];
	}

	if (sumColsItems)
	{
		integerArray[userChoiseRow][userChoiseCols] = 1;
	}

	printArray(integerArray, rows, cols);
	deleteArray(integerArray, rows, cols);
}

void var2()
{
	srand(time(0));

	int ** integerArray,
		rows{ 3 },
		cols{ 3 },
		userChoiseRow{ rand() % 3 },
		userChoiseCols{ rand() % 3 };

	bool isArraySort = true;

	generateArray(integerArray, rows, cols);
	fillArrayRandomValue(integerArray, rows, cols);
	printArray(integerArray, rows, cols);
	cout << "user choise " << userChoiseRow + 1 << " " << userChoiseCols + 1 << endl;

	for (int counterColons = 1; counterColons < cols; counterColons++)
	{
		if (integerArray[userChoiseRow][counterColons - 1] < integerArray[userChoiseRow][counterColons])
		{
			isArraySort = false;
		}
	}

	if (isArraySort)
	{
		integerArray[userChoiseRow][userChoiseCols] = 1;
	}
	else
	{
		integerArray[userChoiseRow][userChoiseCols] = 0;
	}
	printArray(integerArray, rows, cols);
	deleteArray(integerArray, rows, cols);
}

void var3()
{
	srand(time(0));

	int ** integerArray,
		rows{ 3 },
		cols{ 3 },
		usersChoiceRow{ 0 },
		usersChoiceCols{ 0 };

	generateArray(integerArray, rows, cols);
	fillArrayBinar(integerArray, rows, cols);
	printArray(integerArray, rows, cols);

	findPolendromInTheRow(integerArray, usersChoiceRow, cols) ?
		integerArray[usersChoiceRow][usersChoiceCols] = 1 : integerArray[usersChoiceRow][usersChoiceCols] = 0;

	printArray(integerArray, rows, cols);
	deleteArray(integerArray, rows, cols);
}

void var4()
{
	int ** integerArray,
		rows{ 3 },
		cols{ 3 },
		counterOfUnicElements{ 0 },
		rowAmount{ 0 };

	generateArray(integerArray, rows, cols);
	fillArrayRandomValue(integerArray, rows, cols);
	printArray(integerArray, rows, cols);
	for (int counterCols = 0; counterCols < cols; counterCols++)
	{
		for (int counterRows = 0; counterRows < rows; counterRows++)
		{
			for (int rowsConterAmount = 0; rowsConterAmount < cols; rowsConterAmount++)
			{
				if (counterRows != rowsConterAmount)
				{
					rowAmount += integerArray[counterCols][rowsConterAmount];
				}
			}
			if (integerArray[counterCols][counterRows] > rowAmount)
			{
				counterOfUnicElements++;
			}
			rowAmount = 0;
		}
	}
	cout << counterOfUnicElements;
	deleteArray(integerArray, rows, cols);
}

void var5()
{
	int ** integerArray,
		rows{ 3 },
		cols{ 3 },
		counterOfUnicElements{ 0 };
	generateArray(integerArray, rows, cols);
	fillArrayByKeyboard(integerArray, rows, cols);
	for (int counterRwos = 0; counterRwos < rows; counterRwos++)
	{
		for (int counterCols = 0; counterCols < cols; counterCols++)
		{
			if (checkForAsceding(integerArray, cols, counterRwos, counterCols) && checkForDesceding(integerArray, counterRwos, counterCols))
			{
				counterOfUnicElements++;
			}
		}
	}
	cout << counterOfUnicElements;
	deleteArray(integerArray, rows, cols);
}

void var6()
{
	int ** integerArray,
		rows{ 3 },
		cols{ 3 },
		counterOfVariousElements{ 0 };
	generateArray(integerArray, rows, cols);
	fillArrayRandomValue(integerArray, rows, cols);
	for (int counterRows = 0; counterRows < rows; counterRows++)
	{
		for (int counterCols = 0; counterCols < cols; counterCols++)
		{
			if (checkUniq(integerArray,rows,cols,counterRows,counterCols))
			{
				counterOfVariousElements++;
			}
		}
	}
	deleteArray(integerArray, rows, cols);
	cout << counterOfVariousElements;
}
