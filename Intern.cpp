


//intern.cpp
#include "Intern.h"
//Reesha Lodi
using namespace std;


// Define static member outside class
int Intern::totalInterns = 0;


// Default constructor
Intern::Intern() : Employee() {
	hourlyRate = 0.0;
	hoursWorked = 0;
	school = "";
	totalInterns++;

}

// Parameterized constructor
Intern::Intern(string name, int id,string dept, double hourlyRate, int hoursWorked, string school)
	: Employee(name, id, dept, "Intern", 0.0) {

	this->hourlyRate = hourlyRate;
	this-> hoursWorked = hoursWorked;
	this->school = school;
	totalInterns++;

}

// Destructor
Intern::~Intern() {
	totalInterns--;

}

// Getters
double Intern::getHourlyRate() const {
	return hourlyRate;
}

int Intern::getHoursWorked() const {
	return hoursWorked;
}

string Intern::getSchool() const {
	return school;

}

int Intern::getTotalInterns() {
	return totalInterns;
}

// Setters
void Intern::setHourlyRate(double rate) {
	hourlyRate = rate;
}

void Intern::setHoursWorked(int hours) {
	hoursWorked = hours;
}

void Intern::setSchool(string s) {
	school = s;

}




// Salary calculation (hourly-based) - overriden 
//interns have a different formula than employee or manager
//they are paid hourly, with no base, and no perfomance bonus
double Intern::calculateSalary() const {
	return hourlyRate * hoursWorked;
}

// Display info (overriden)
void Intern::displayInfo() const {
	cout << "\n=============================\n" << endl;
	cout << "Type: Intern" << endl;
	cout << "Name: " << name << endl;
	cout << "ID: " << id << endl;
	cout << "Department; " << department << endl;
	cout << "School: " << school << endl;
	cout << "Hourly Rate: $" << hourlyRate << endl;
	cout << "Hours Worked: " << hoursWorked << endl;
	cout << "Salary: $" << calculateSalary() << endl;
}

// File format: I,id,name,dept,rate,hours,school
string Intern::toFileString() const {
	return "I," + to_string(id) + "," + name + "," + department + "," + 
		to_string(hourlyRate) + "," + to_string(hoursWorked) + "," + school;
}


