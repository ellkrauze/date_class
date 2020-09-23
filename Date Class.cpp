#include "Class_header.h"

Date::Date()
{ 
	this->day = day_default;
	this->month = month_default;
	this->year = year_default;
}
Date::Date(int year)
{
	day = day_default;
	month = month_default;
	this->year = year;
}
Date::Date(int year, Month month)
{
	day = day_default;
	this->year = year;
	this->month = month;
}
Date::Date(int year, Month month, int day)
{
	this->year = year;
	this->month = month;
	this->day = day;
}
Date::Date(const Date &obj)
{
	// Конструктор копирования
	day = obj.day;
	month = obj.month;
	year = obj.year;
}
Date::~Date()
{

}

void Date::SetDay(int day)
{
	this->day = day;
}

void Date::SetMonth(Month month)
{
	this->month = month;
}
void Date::SetYear(int year)
{
	this->year = year;
}

int Date::YYYYMMDD(int year, Month month, int day)
{
	int date = year * 10000 + month.monthNumber * 100 + day;
	return date;
}

bool isLeap(int year)
{
	if (year % 100 != 0 && year % 4 == 0 || year % 400 == 0)
		return true;
	return false;
}

int numberOfDaysInMonth(int month, int year)
{
	switch (month)
	{
	case 0: 
		return 31;
	case 1:
		return 31;
	case 2:
		if (isLeap(year) == true) { return 29; }
		else return 28;
	case 3:
		return 31;
	case 4: 
		return 30;
	case 5: 
		return 31;
	case 6: 
		return 30;
	case 7: 
		return 31;
	case 8: 
		return 31;
	case 9: 
		return 30;
	case 10: 
		return 31;
	case 11: 
		return 30;
	case 12: 
		return 31;
	}
}

Date DatePlusDays(Date &obj, int n)
{
	int monthIndex = obj.GetMonth().monthNumber;
	int nYear = obj.GetYear();
	int days = obj.GetDay() + n;

	if (days > numberOfDaysInMonth(monthIndex, nYear))
	{
		while (days > numberOfDaysInMonth(monthIndex, nYear))
		{
			days -= numberOfDaysInMonth(monthIndex, nYear);

			// to next month
			++monthIndex;

			if (monthIndex > 12)
			{
				monthIndex = 1;
				++nYear; // next year
			}
		}
	}
	if (days < 1)
	{
		while (days < 1)
		{
			--monthIndex;
			days += numberOfDaysInMonth(monthIndex, nYear);
			

			if (monthIndex < 1)
			{
				monthIndex = 12;
				--nYear;
			}
		}
	}

	Date newObj(nYear, Date::months[monthIndex-1], days); 
	return newObj;
}


Date& Date::operator=(const Date &obj)
{
	// Перегрузка оператора присваивания
	day = obj.day;
	month = obj.month;
	year = obj.year;

	return *this;
}
Date Date::operator++(int)
{
	*this = DatePlusDays(*this, 1);
	
	return *this;
}
Date Date::operator--(int)
{
	*this = DatePlusDays(*this, -1);

	return *this;
}

Date operator +(Date &obj, int n)
{
	// Прибавить n дней (Объект1.Дни = Объект2.Дни + Дни)
	// Date today(2020, "oct", 7);
	// Date tommorow = today + 1;
	Date result(obj);
	result = DatePlusDays(result, n);
	return result;
}

Date operator -(Date &obj, int n)
{
	Date result(obj);
	result = DatePlusDays(result, -n);
	return result;
}

bool Date::operator == (Date &obj)
{
	return (this->day == obj.day && this->month.monthNumber == obj.month.monthNumber && this->year == obj.year);
}
bool Date::operator != (Date &obj)
{
	return !(this->day == obj.day && this->month.monthNumber == obj.month.monthNumber && this->year == obj.year);
}
bool Date::operator < (Date &obj)
{
	return YYYYMMDD(year, month, day) < YYYYMMDD(obj.year, obj.month, obj.day);
}

bool Date::operator>(Date & obj)
{
	return YYYYMMDD(year, month, day) > YYYYMMDD(obj.year, obj.month, obj.day);
}

Date & operator +=(Date &obj, int n)
{
	obj = DatePlusDays(obj, n);
	return obj;
}

Date & operator -=(Date &obj, int n)
{
	// Прибавить n дней
	// Date tdate1;
	// tdate1 -= 2;
	// tdate1 = tdate1 - 2;
	obj = DatePlusDays(obj, -n);
	return obj;
}

ostream& operator<<(ostream& os, const Date& obj)
{
	os << obj.day << ' ' << obj.month.s_month << ' ' << obj.year;
	return os;
}

istream & operator>>(istream & is, Date & obj)
{
	int day, year, month;

	cout << "Enter day = ";
	is >> day;
	cout << "Enter month (number) = ";
	is >> month;
	cout << "Enter year = ";
	is >> year;
	obj.SetDay(day); obj.SetMonth(Date::months[month - 1]); obj.SetYear(year);
	cout << "Data is entered!\nYour data is " << obj << endl;
	return is;
}

Month const Date::jan{ "jan", 1 }; Month const Date::feb{ "feb", 2 };
Month const Date::mar{ "mar", 3 }; Month const Date::apr{ "apr", 4 };
Month const Date::may{ "may", 5 }; Month const Date::jun{ "jun", 6 };
Month const Date::jul{ "jul", 7 }; Month const Date::aug{ "aug", 8 };
Month const Date::sep{ "sep", 9 }; Month const Date::oct{ "oct", 10 };
Month const Date::nov{ "nov", 11 }; Month const Date::dec{ "dec", 12 };

int Date::day_default = 1;
int Date::year_default = 1971;
Month Date::month_default = Date::jan;

Month Date::months[12]{
		Date::jan, Date::feb, Date::mar, Date::apr,
		Date::may, Date::jun, Date::jul, Date::aug,
		Date::sep, Date::oct, Date::nov, Date::dec
};

int main()
{
	
	Date date1, date2(1995), date3(1995, Date::mar), date4(1995, Date::may, 5);

	//date1 = date2 + date3;    // не должно работать!

	Date tdate1, tdate2;

	tdate1 += 2; cout << "tdate1: " << tdate1 << endl;
	tdate2++; cout << "tdate2: " << tdate2 << endl;
	tdate2++; cout << "tdate2: " << tdate2 << endl;

	if (tdate1 != tdate2) cout << "Something wrong\n";

	else cout << "As expected\n";

	cout << date1 << endl << date2 << endl << date3 << endl << date4 << endl;

	Date today = Date(2018, Date::sep, 10);
	cout << today << endl;
	Date tomorrow;

	tomorrow = today + 21;

	cout << tomorrow << endl;

	Date data;
	cin >> data;

	////Date never = 43 + today;  //Не должно работать!

	//cout << tomorrow << endl;

	getchar();
	return 0;
}