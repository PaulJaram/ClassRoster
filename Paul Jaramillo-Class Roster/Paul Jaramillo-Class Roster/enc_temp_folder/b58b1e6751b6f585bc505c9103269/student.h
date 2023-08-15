#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"
using std::string;
using std::cout;
using std::endl;

class Student
{
public:
	const static int numDaysArraySize = 3;
private:
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	int numDays[numDaysArraySize];
	DegreeProgram degreeProgram;
public:
	/*constructor*/
	Student();
	Student(string studentID, string firstName, string lastName, string email, int age, int numDays[], DegreeProgram degreeProgram);
	~Student();
	/*accessors or getters*/
	string getID();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int* getNumDays();
	DegreeProgram getDegree();

	/*mutators or setters*/
	void setID(string ID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmail(string email);
	void setAge(int age);
	void setNumDays(int numDays[]);
	void setDegreeProgram(DegreeProgram degree);

	void print();/*prints specific student data*/


};
