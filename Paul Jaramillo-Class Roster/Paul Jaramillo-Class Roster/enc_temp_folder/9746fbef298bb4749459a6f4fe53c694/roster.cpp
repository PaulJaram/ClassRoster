#include "roster.h"

void Roster::parse(string studentData)
{
	for (int i = 0; i <= numStudents; i++)
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
		int daysInCourse1 = stod(studentData.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = studentData.find(",", lhs);
		int daysInCourse2 = stod(studentData.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = studentData.find(",", lhs);
		int daysInCourse3 = stod(studentData.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		DegreeProgram degree = SECURITY;
		if (studentData.at(lhs) == 'N') { degree = NETWORK; }
		else if (studentData.at(lhs + 1) == 'O') { degree = SOFTWARE; }

		add(sID, fName, lName, email, age, daysInCourse1, daysInCourse2, daysInCourse3, degree);
	}
}
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
	int daysInCourse[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	Student student;
	student.setID(studentID);
	student.setFirstName (firstName);
	student.setLastName(lastName);
	student.setEmail(emailAddress);
	student.setAge(age);
	student.setNumDays(daysInCourse);
	student.setDegreeProgram(degreeProgram);

	
}


void Roster::printAll()
{

	for (int i = 0; i <= Roster::numStudents; i++)
	{
	  classRosterArray[i]->Student::print();
	}
}
void Roster::printByDegree(DegreeProgram degree)
{
	for (int i = 0; i < numStudents; i++)
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
	for (int i = 0; i < numStudents; i++)
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

	for (int i = 0; i < numStudents; i++)
	{


		cout << "The average for " << classRosterArray[i]->getID();
		cout << " is ";
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