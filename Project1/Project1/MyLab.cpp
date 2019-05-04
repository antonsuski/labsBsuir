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
		day = 31;
		month = 03;
		yer = 2019;
	}

	Date(const char date[11])
	{
		if ((int)date[0] - 48 > 3 || (int)date[3] - 48 > 1 || strlen(date) > 10)
		{
			cout << "Uncorrect date\n";
		}
		month = ((int)date[3] - 48) * 10 + ((int)date[1] - 48);
		day = (((int)date[0] - 48) * 10) + ((int)date[4] - 48);
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
			cout << "Uncorrect date\n";
		}
		month = ((int)date[3] - 48) * 10 + ((int)date[1] - 48);
		day = (((int)date[0] - 48) * 10) + ((int)date[4] - 48);
		yer = (((int)date[6] - 48) * 1000) + (((int)date[7] - 48) * 100) + (((int)date[8] - 48) * 10) + ((int)date[9] - 48);
	}

	Date & operator = (const Date & other)
	{
		this->day = other.day;
		this->month = other.month;
		this->yer = other.yer;
		return *this;
	}

	Date & operator + (const Date & other)
	{
		if ((this->month == 2) && (this->yer % 400 == 0) && (this->yer % 4 == 0))
		{
			this->day = +other.day;
			this->month += this->day / 30;
			this->day %= 30;
			this->yer += this->month / 13;
			this->month %= 13;
		}
		else if ((this->month == 2))
		{
			this->day = +other.day;
			this->month += this->day / 29;
			this->day %= 29;
			this->yer += this->month / 13;
			this->month %= 13;
		}
		else if (this->month == 1,3,5,7,8,10,12)
		{
			this->day = +other.day;
			this->month += this->day / 32;
			this->day %= 32;
			this->yer += this->month / 13;
			this->month %= 13;
		}
		else
		{
			this->day = +other.day;
			this->day %= 31;
			this->month += this->day / 31;
			this->yer += this->month / 13;
			this->month %= 13;
		}
		return *this;
	}

	//Date & operator - (const Date & other)
	//{
	//	if ((this->month == 2) && (this->yer % 400 == 0) && (this->yer % 4 == 0))
	//	{
	//		this->day += other.day;
	//		this->month += this->day / 30;
	//		this->day %= 30;
	//		this->yer += this->month / 13;
	//		this->month %= 13;
	//	}
	//	else if ((this->month == 2))
	//	{
	//		this->day +=other.day;
	//		this->month += this->day / 29;
	//		this->day %= 29;
	//		this->yer += this->month / 13;
	//		this->month %= 13;
	//	}
	//	else if (this->month == 1, 3, 5, 7, 8, 10, 12)
	//	{
	//		this->day +=other.day;
	//		this->month += this->day / 32;
	//		this->day %= 32;
	//		this->yer += this->month / 13;
	//		this->month %= 13;
	//	}
	//	else
	//	{
	//		this->day = +other.day;
	//		this->day %= 31;
	//		this->month += this->day / 31;
	//		this->yer += this->month / 13;
	//		this->month %= 13;
	//	}
	//	return *this;
	//}

	bool operator == (const Date & other)
	{
		return this->day == other.day && this->month == other.month && this->yer == other.yer;
	}

	bool operator != (const Date & other)
	{
		return !(this->day == other.day && this->month == other.month && this->yer == other.yer);
	}

	bool operator  > (const Date & other)
	{
		return this->yer > other.yer ? 0 : (this->month > other.month ? 0 : (this->day > other.day ? 0 : 1));
	}

	bool operator  < (const Date & other)
	{
		return this->yer < other.yer ? 0 : (this->month < other.month ? 0 : (this->day < other.day ? 0 : 1));
	}

	bool operator  >= (const Date & other)
	{
		return this->yer >= other.yer ? 0 : (this->month >= other.month ? 0 : (this->day >= other.day ? 0 : 1));
	}

	bool operator  <= (const Date & other)
	{
		return this->yer <= other.yer ? 0 : (this->month <= other.month ? 0 : (this->day <= other.day ? 0 : 1));
	}
};
class Way 
{
private:

	int wayNum;
	string city;

public:

	Way()
	{
		wayNum = 0;
		city = "city";
	}

	Way(int wayNum,string city)
	{
		this->wayNum = wayNum;
		this->city = city;
	}

	int getWayNum()
	{
		return wayNum;
	}
	
	string getCity()
	{
		return city;
	}

	void setWayNum(int wayNum)
	{
		this->wayNum = wayNum;
	}

	void setCity(string city)
	{
		this->city = city;
	}

	void print()
	{
		cout << endl << "way number is: " << wayNum << "\ncity is " << city;
		cout << endl;
	}
};
class List
{
	friend class Date;
	friend class Way;

private:

	int freeSeats;
	Way trainWay;
	Date deparrtureDate;

public:

	List()
	{
		int freeSeats = 0;
		Way trainWay();
		Date deparrtureDate();
	}
		
	int getCounterFreeTicket()
	{
		return freeSeats;
	}

	Way getTrainWay()
	{
		return trainWay;
	}

	Date getArrive()
	{
		return deparrtureDate;
	}

	void print()
	{
		cout << "number of free seats :" << freeSeats;
		trainWay.print();
		deparrtureDate.print();
	}
};

int main()
{
	return 0;
}