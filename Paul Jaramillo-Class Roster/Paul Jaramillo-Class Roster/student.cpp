#include "student.h"

Student::Student() {
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->email = "";
	for (int i = 0; i < numDaysArraySize; i++) { this->numDays[i] = 0; }
	this->degreeProgram = DegreeProgram::SECURITY;
};

Student::Student(string studentID, string firstName, string lastName, string email, int age, int numDays[], DegreeProgram degreeProgram)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	for (int i = 0; i < numDaysArraySize; i++) { this->numDays[i] = numDays[i]; }
	this->degreeProgram = degreeProgram;
}

Student::~Student() {}

string Student::getID() { return this->studentID; }
string Student::getFirstName() { return this->firstName; }
string Student::getLastName() { return this->lastName; }
string Student::getEmail() { return this->email; }
int Student::getAge() { return this->age; }
int* Student::getNumDays() { return this->numDays; }
DegreeProgram Student::getDegree() { return this->degreeProgram; }

void Student::setID(string ID) { this->studentID = ID; }
void Student::setFirstName(string firstName) { this->firstName = firstName; }
void Student::setLastName(string lastName) { this->lastName = lastName; }
void Student::setEmail(string email) { this->email = email; }
void Student::setAge(int age) { this->age = age; }
void Student::setNumDays(int numDays[])
{
	for (int i = 0; i < numDaysArraySize; i++) { this->numDays[i] = numDays[i]; }
}
void Student::setDegreeProgram(DegreeProgram degree) { this->degreeProgram = degree; }

void Student::print()
{
	cout << this->getID() << '\t';
	cout << this->getFirstName() << '\t';
	cout << this->getLastName() << '\t';
	cout << this->getEmail() << '\t';
	cout << this->getAge() << '\t';
	cout << this->getNumDays() << '\t';
	cout << degreeStrings[this->getDegree()] << endl;
}

