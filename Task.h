#pragma once
#include <string>
#include <fstream>
using namespace std;


struct Date
{
	int day;
	int month;
	int year;
};

class Task 
{
protected:
	string title;
	string subject;
	Date deadline;
	bool status;
public:
	Task()
	{
		title = "";
		subject = "";
		status = false;
		deadline = { 0, 0, 0 };
	}
	Task(string t, string s, Date d, bool ss)
	{
		title = t;
		subject = s;
		deadline = d;
		status = ss;
	}

	void setTitle(string t) { title = t; }
	void setSubject(string subject);
	void setStatus(string status);

	string getTitle() const { return title; }
	string getSubject() const { return subject; }
	bool getStatus() const { return status; }

};
struct Date {
    int day, month, year;
};

