#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	
	cout << "Course: 867 Scripting and Programming Application" << endl;
	cout << "Progranmming Laguange: C++" << endl;
	cout << "ID Number: 001654617" << endl;
	cout << "Name: Paul Jaramillo" << endl;
	cout << endl;

	Roster classRoster;


	const string studentData[] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Paul,Jaramillo,jaramillo.paul12@gmail.com,26,30,49,32,SOFTWARE" };

	for (int i = 0; i < Roster::numStudents; i++)
	{
		classRoster.parse(studentData[i]);

	}
	cout << "All Students:" << endl;
	classRoster.printAll();

	classRoster.printInvalidEmails();



	//loop through classRosterArray and for each element

	cout << "Average Days In Course:" << endl;
	classRoster.printAverageDaysInCourse();


	classRoster.printByDegree(SOFTWARE);

	classRoster.remove("A3");

	classRoster.printAll();

	classRoster.remove("A3");

	//expected: the above line should print a message saying such a student with this ID was not found.
}