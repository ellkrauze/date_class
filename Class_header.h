#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Month
{
	string s_month;
	int monthNumber;
};

class Date
{
	int day, year;
	Month month;


public:

	static int day_default, year_default; 
	static Month month_default;

	static const Month jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec;

	static Month months[12];
	

	Date();
	Date(int year);
	Date(int year, Month month);
	Date(int year, Month month, int day);
	Date(const Date &obj);

	void SetDay(int day);
	void SetMonth(Month month);
	void SetYear(int year);
	const int GetDay() { return day; }
	const Month GetMonth() { return month; }
	const int GetYear() { return year; }
	int YYYYMMDD(int year, Month month, int day);

	
	

	Date& operator=(const Date &obj);
	friend Date& operator+=(Date &obj, int n);
	friend Date& operator -=(Date &obj, int n);
	Date operator++(int);
	Date operator--(int);
	friend Date operator +(Date &obj, int n);
	friend Date operator -(Date &obj, int n);
	bool operator == (Date &obj);
	bool operator != (Date &obj);
	bool operator < (Date &obj);
	bool operator > (Date &obj);
	friend ostream& operator << (ostream& os, const Date& obj);
	friend istream& operator >> (istream& is, Date& obj);
	
	~Date(void);
};


Date DatePlusDays(Date &obj, int days);
int numberOfDaysInMonth(int month, int year);
bool isLeap(int year);


