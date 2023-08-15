#pragma once
#include "student.h"

class Roster
{
public:
	int lastIndex = -1;
	const static int numStudents = 5;
	Student* classRosterArray[numStudents];


public:
	void parse(string row);

	void add(string ID,
		string fName,
		string lName,
		string email,
		int age,
		int numDays1,
		int numDays2,
		int numDays3,
		DegreeProgram degree);
	void printAll();
	void printByDegree(DegreeProgram degree);
	void printInvalidEmails();
	void printAverageDaysInCourse();
	void remove(string studentID);

	~Roster();

};