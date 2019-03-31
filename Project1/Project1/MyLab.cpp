#include <iostream>
#include <string>

using namespace std;

class Date
{
private:

	int yer, month, day;

	void setYer(int yer)
	{
		this->yer = yer;
	}

	void setMonth(int month)
	{
		this->month = month;
	}

	void setDay(int day)
	{
		this->day = day;
	}

public:

	Date()
	{
		month = 01;
		day = 01;
		yer = 2019;
	}

	Date(const char date[11])
	{
		if ((int)date[0] - 48 > 1 || (int)date[3] - 48 > 3 || strlen(date) > 10)
		{
			cout << "Uncorrect date";
		}
		month = ((int)date[0] - 48)*10 + ((int)date[1] - 48);
		day = (((int)date[3] - 48) * 10) + ((int)date[4] - 48);
		yer = (((int)date[6] - 48)*1000) + (((int)date[7] - 48)*100) + (((int)date[8] - 48)*10) + ((int)date[9] - 48);
	}

	Date()
	{

	}

	int getYer()
	{
		return yer;
	}

	int getMonth()
	{
		return month;
	}

	int getDay()
	{
		return day;
	}

	void print() 
	{
		cout << "Yer " << yer << "\nMonth " << month/10 << month%10 << "\nDay " << day/10 << day%10 << endl;
	}
};


int main()
{
	Date a("01.12.2019");
	a.print();
}