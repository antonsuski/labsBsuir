#include "pch.h"
#include <iostream>
#include <ctime>

using namespace std;

void printArray(int **arr, int rows, int colons);
void generateArray(int **& integerArray, int rows, int cols);
void deleteArray(int ** integerArray, int rows, int cols);
void fillArrayRandomValue(int ** integerArray, int rows, int cols,  int div);
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
void var1();
void var2();
void var3();
void var4();
void var5();
void var6();
void var7();
void var8();
void var9();
void var10();


int main()
{
	var9();
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
	fillArrayRandomValue(integerArray, rows, cols, 10);
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
	fillArrayRandomValue(integerArray, rows, cols, 10);
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
		rows{ 2 },
		cols{ 2 },
		counterOfVariousElements{ 0 };

	generateArray(integerArray, rows, cols);
	fillArrayRandomValue(integerArray, rows, cols, 4);

	for (int counterRows = 0; counterRows < rows; counterRows++)
	{
		for (int counterCols = 0; counterCols < cols; counterCols++)
		{
			if (checkUniq(integerArray,counterRows,counterCols))
			{
				counterOfVariousElements++;
			}
		}
	}
	printArray(integerArray, rows, cols);
	deleteArray(integerArray, rows, cols);
	cout << counterOfVariousElements;
}

void var7()
{
	int ** integerArray,
		rows{ 3 },
		cols{ 3 };

	generateArray(integerArray, rows, cols);
	fillArrayRandomValue(integerArray, rows, cols, 3);
	printArray(integerArray, rows, cols);

	for (int counterRows = 0; counterRows < rows; counterRows++)
	{
		for (int counterBack = counterRows; counterBack < rows; counterBack++)
		{
			if (integerArray[counterRows][0] > integerArray[counterBack][0])
			{
				swapCols(integerArray, counterRows, counterBack, cols);
			}
		}
	}
	cout << endl;
	printArray(integerArray, rows, cols);
	deleteArray(integerArray, rows, cols);
}

void var8()
{
	int ** integerArray,
		rows{ 3 },
		cols{ 3 };

	generateArray(integerArray, rows, cols);
	fillArrayRandomValue(integerArray, rows, cols, 2);
	printArray(integerArray, rows, cols);

	for (int counterRows = 0; counterRows < rows; counterRows++)
	{
		for (int counterBack = counterRows; counterBack < rows; counterBack++)
		{
			if (sumOfRow(integerArray,counterRows,cols) > sumOfRow(integerArray, counterBack, cols))
			{
				swapCols(integerArray, counterRows, counterBack, cols);
			}
		}
	}
	cout << endl;
	printArray(integerArray, rows, cols);
	deleteArray(integerArray, rows, cols);
}

void var9()
{
	int ** integerArray,
		rows{ 3 },
		cols{ 3 };

	generateArray(integerArray, rows, cols);
	fillArrayRandomValue(integerArray, rows, cols, 9);
	printArray(integerArray, rows, cols);

	for (int counterRows = 0; counterRows < rows; counterRows++)
	{
		for (int counterBack = counterRows; counterBack < rows; counterBack++)
		{
			if (foundMinInRow(integerArray,cols,counterRows) > foundMinInRow(integerArray,cols,counterBack))
			{
				swapRows(integerArray, counterRows, counterBack, cols);
			}
		}
	}
	cout << endl;
	printArray(integerArray, rows, cols);
	deleteArray(integerArray, rows, cols);
}

void var10() 
{

}