#include "roster.h"

void Roster::parse(string studentData)
{
	int rhs = studentData.find(",");
	string sID = studentData.substr(0, rhs);

	int lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string fName = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string lName = studentData, substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string email = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int age = stod(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int numDays1 = stod(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int numDays2 = stod(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int numDays3 = stod(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	DegreeProgram degree = SECURITY;
	if (studentData.at(lhs) == 'N') { degree = NETWORK; }
	else if (studentData.at(lhs + 1) == 'O') { degree = SOFTWARE; }

	add(sID, fName, lName, email, age, numDays1, numDays2, numDays3, degree);
}
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
	int daysInCourse[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };

	classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);
}


void Roster::printAll()
{

	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		classRosterArray[i]->Student::print();
	}
}
void Roster::printByDegree(DegreeProgram degree)
{
	for (int i = 0; i <= lastIndex; i++)
	{
		if (degree == classRosterArray[i]->getDegree())
		{
			classRosterArray[i]->print();
		}
		cout << endl;
	}
}
void Roster::printInvalidEmails()
{
	bool yay = false;
	for (int i = 0; i <= lastIndex; i++)
	{
		string email = classRosterArray[i]->getEmail();
		if (!email.find('@') || !email.find('.') || email.find(' '))
		{
			yay = true;
			cout << email << endl;
		}

	}
	if (!yay)
	{
		cout << "None." << endl;
	}
}
void Roster::printAverageDaysInCourse()
{

	for (int i = 0; i <= lastIndex; i++)
	{


		cout << "The average for " << classRosterArray[i]->getID() << "is";
		cout << (classRosterArray[i]->getNumDays()[0]
			+ classRosterArray[i]->getNumDays()[1]
			+ classRosterArray[i]->getNumDays()[2]) / 3 << endl;

	}
}
void Roster::remove(string studentID)
{
	bool val = false;

	for (int i = 0; i <= lastIndex; i++)
	{
		if (studentID == classRosterArray[i]->getID())
		{
			cout << "Removed: " << studentID;
			val = true;
			Student* temp = classRosterArray[i];
			classRosterArray[i] = classRosterArray[numStudents - 1];
			classRosterArray[numStudents - 1] = temp;
		}
		Roster::lastIndex--;
	}
	if (!val)
	{
		cout << "Student not found." << endl;
	}
}
Roster::~Roster() {}