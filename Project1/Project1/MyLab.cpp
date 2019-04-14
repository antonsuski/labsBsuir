#include <iostream>

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
		month = 03;
		day = 30;
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

	Date(const Date &other)
	{
		this->yer = other.yer;
		this->month = other.month;
		this->day = other.day;
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
		cout << "Yer " << yer << "\nMonth " << month / 10 << month % 10 << "\nDay " << day / 10 << day % 10 << endl << endl;
	}

	void setParametrsByConsol()
	{
		char date[11];
		cout << "Enter your date in format like this: 12.31.2049" << endl;
		gets_s(date);

		if ((int)date[0] - 48 > 1 || (int)date[3] - 48 > 3 || strlen(date) > 10)
		{
			cout << "Uncorrect date";
		}
		month = ((int)date[0] - 48) * 10 + ((int)date[1] - 48);
		day = (((int)date[3] - 48) * 10) + ((int)date[4] - 48);
		yer = (((int)date[6] - 48) * 1000) + (((int)date[7] - 48) * 100) + (((int)date[8] - 48) * 10) + ((int)date[9] - 48);
	}

	Date & operator = (const Date & other)
	{
		this->day = other.day;
		this->month = other.month;
		this->yer = other.yer;
		return *this;
	}

	Date operator + (const Date & other)
	{
		Date temp;
		if (this->month % 2 == 1)
		{
			temp.day = (this->day + other.day) % 31;
		}
		else
		{

		}
	}

	bool operator == (const Date & other)
	{
		return this->day == other.day && this->month == other.month && this->yer == other.yer;
	}

	bool operator != (const Date & other)
	{
		return !(this->day == other.day && this->month == other.month && this->yer == other.yer);
	}

	//bool operator > (const Date & other)
	//{
	//	this->yer > other.yer ?  true:
	//}

	//bool operator > (const Date & other)
	//{
	//	if (this->yer > other.yer)
	//	{
	//		return true;
	//	}
	//	if (this->month > other.yer)
	//	{
	//		return true;
	//	}
	//	if (this->day > other.day)
	//	{
	//		return true;
	//	}
	//	return false;
	//}
	bool operator  > (const Date & other)
	{
		return this->yer > other.yer ? 1 : (this->month > other.yer ? 1 : (this->day > other.day ? 1 : 0));
	}
	//bool operator  < (const Date & other)
	//{
	//	this->yer > other.yer ? return !1 : !(this->month > other.yer ? return 1 : (this->day > other.day ? return 1 : 0))
	//}
	//bool operator  >= (const  Date & other)
	//{
	//	this->yer >= other.yer ? return 1 : (this->month >= other.yer ? return 1 : (this->day >= other.day ? return 1 : 0))
	//}
	//bool operator  <= (const Date & other)
	//{
	//	this->yer <= other.yer ? return 1 : (this->month <= other.yer ? return 1 : (this->day <= other.day ? return 1 : 0))
	//}
};


int main()
{
	Date a("03.12.2019");
	Date b("02.12.2019");
	bool c = a > b;
	cout << c;
	return 0;
}