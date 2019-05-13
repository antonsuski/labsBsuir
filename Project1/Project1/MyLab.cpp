#include <iostream>
#include <string.h>

using namespace std;

class Time
{
public:

	Time()
	{
		hour = 00;
		second = 00;
	}

	Time (const char time[6])
	{
		if ((int)time[0] - 48 > 2 || (int)time[3] - 48 > 5 || strlen(time) > 5)
		{
			cout << "Uncorrect time\n";
		}
		second = ((int)time[3] - 48) * 10 + ((int)time[4] - 48);
		hour = (((int)time[0] - 48) * 10) + ((int)time[1] - 48);
	}

	Time (const Time & other)
	{
		this->hour = other.hour;
		this->second = other.second;
	}

	int getHouer()
	{
		return hour;
	}

	int getSecond()
	{
		return second;
	}

	bool operator == (const Time& other)
	{
		return this->hour == other.hour && this->second == other.second ? 1 : 0;
	}

	bool operator != (const Time& other)
	{
		return this->hour != other.hour && this->second != other.second ? 1 : 0;
	}

	bool operator < (const Time& other)
	{
		return this->hour < other.hour ? 1 : (this->second < other.second ? 1 : 0);
	}

	bool operator > (const Time& other)
	{
		return this->hour > other.hour ? 1 : (this->second > other.second ? 1 : 0);
	}

	bool operator <= (const Time& other)
	{
		return this->hour <= other.hour ? 1 : (this->second <= other.second ? 1 : 0);
	}

	bool operator >= (const Time& other)
	{
		return this->hour >= other.hour ? 1 : (this->second >= other.second ? 1 : 0);
	}

	void setStandartTime()
	{
		hour = 00;
		second = 00;
	}

	void copyTime(const Time & other)
	{
		this->hour = other.hour;
		this->second = other.second;
	}

	void setTime(const char time[6])
	{
		if ((int)time[0] - 48 > 2 || (int)time[3] - 48 > 5 || strlen(time) > 5)
		{
			cout << "Uncorrect time\n";
		}
		second = ((int)time[3] - 48) * 10 + ((int)time[4] - 48);
		hour = (((int)time[0] - 48) * 10) + ((int)time[1] - 48);
	}

private:

	int hour, second;
};

class Date
{
private:

	int yer, month, day;
	Time time;

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
		time.setStandartTime();
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
		time.setStandartTime();
	}

	Date(const char date[11], const char time[6])
	{
		if ((int)date[0] - 48 > 3 || (int)date[3] - 48 > 1 || strlen(date) > 10)
		{
			cout << "Uncorrect date\n";
		}
		month = ((int)date[3] - 48) * 10 + ((int)date[1] - 48);
		day = (((int)date[0] - 48) * 10) + ((int)date[4] - 48);
		yer = (((int)date[6] - 48) * 1000) + (((int)date[7] - 48) * 100) + (((int)date[8] - 48) * 10) + ((int)date[9] - 48);

		this->time.setTime(time);
	}

	Date(const Date &other)
	{
		this->yer = other.yer;
		this->month = other.month;
		this->day = other.day;
	}

	Date(const Date& other, const Time & time)
	{
		this->yer = other.yer;
		this->month = other.month;
		this->day = other.day;
		this->time.copyTime(time);
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
		return this->day == other.day && this->month == other.month && this->yer == other.yer && this->time == other.time;
	}

	bool operator != (const Date & other)
	{
		return !(this->day == other.day && this->month == other.month && this->yer == other.yer && this->time == other.time);
	}

	bool operator  > (const Date & other)
	{
		return this->yer > other.yer ? 0 : (this->month > other.month ? 0 : (this->day > other.day ? 0 : (this->time > other.time)));
	}

	bool operator  < (const Date & other)
	{
		return this->yer < other.yer ? 0 : (this->month < other.month ? 0 : (this->day < other.day ? 0 : (this->time < other.time)));
	}

	bool operator  >= (const Date & other)
	{
		return this->yer >= other.yer ? 0 : (this->month >= other.month ? 0 : (this->day >= other.day ? 0 : (this->time >= other.time)));
	}

	bool operator  <= (const Date & other)
	{
		return this->yer <= other.yer ? 0 : (this->month <= other.month ? 0 : (this->day <= other.day ? 0 : (this->time <= other.time)));
	}

	friend class Time;
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
	static string ID;
	static int IDCounter;

private:

	int freeSeats;
	Way trainWay;
	Date departureDate;

	void generatorID()
	{
		ID[0] = trainWay.getWayNum() / 10;
		ID[1] = trainWay.getWayNum() % 10;
		ID[2] = ':';
		ID[3] = freeSeats / 10;
		ID[4] = freeSeats % 10;
		ID[5] ='.';
		ID[6] = departureDate.getDay() / 10;
		ID[7] = departureDate.getDay() % 10;
		ID[8] ='.';
		ID[9] = IDCounter++;
	}

public:

	List()
	{
		int freeSeats = 0;
		Way trainWay();
		Date departureDate();
		generatorID();
	}
		
	int getFreeSeats()
	{
		return freeSeats;
	}

	Way getTrainWay()
	{
		return trainWay;
	}

	string getID()
	{
		return ID;
	}

	Date getDepartureDate()
	{
		return departureDate;
	}

	void print()
	{
		cout << "number of free seats :" << freeSeats;
		trainWay.print();
		departureDate.print();
	}

	void printID()
	{
		cout << ID;
	}

	bool operator == (List& other)
	{
		return this->trainWay.getWayNum() == other.trainWay.getWayNum() ? 0
			: (this->freeSeats == other.freeSeats? 0 
				:(this->departureDate == other.departureDate));
	}

	bool operator != (List& other)
	{
		return !(this->trainWay.getWayNum() == other.trainWay.getWayNum() ? 0
			: (this->freeSeats == other.freeSeats ? 0
				: (this->departureDate == other.departureDate)));
	}

	bool operator < (List& other)
	{
		return this->trainWay.getWayNum() < other.trainWay.getWayNum() ? 0
			: (this->freeSeats < other.freeSeats ? 0
				: (this->departureDate < other.departureDate));
	}

	bool operator < (List& other)
	{
		return !(this->trainWay.getWayNum() < other.trainWay.getWayNum() ? 0
			: (this->freeSeats < other.freeSeats ? 0
				: (this->departureDate < other.departureDate)));
	}

	bool operator <= (List& other)
	{
		return this->trainWay.getWayNum() <= other.trainWay.getWayNum() ? 0
			: (this->freeSeats <= other.freeSeats ? 0
				: (this->departureDate <= other.departureDate));
	}

	bool operator >= (List& other)
	{
		return !(this->trainWay.getWayNum() <= other.trainWay.getWayNum() ? 0
			: (this->freeSeats <= other.freeSeats ? 0
				: (this->departureDate <= other.departureDate)));
	}
};

int List::IDCounter = 0;

int main()
{
	List a;
	a.printID;
}