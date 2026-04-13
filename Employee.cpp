
//Employee.cpp

#include "Employee.h"
//Ruquaiya Ali

#include <iostream>
using namespace std;

int Employee::totalEmployees = 0; //defining and initializing static memeber outside of the class
//gives it memory storage

//constructors:

//default constructor:
Employee::Employee() : Person() {

	department = "";
	role = "";
	monthlySalary = 0.0;
	daysAttended = 0;
	bonus = 0.0;
	deductions = 0.0;
	totalEmployees++;//incrementing counter for every time an employee is created

}

//parameterized constructor:
Employee::Employee(string name, int id, string dept, string role, double salary) :
	Person(name, id, "", "") {
	this->department = dept;
	this->role = role;
	this->monthlySalary = salary;
	this->daysAttended = 22; //default, full attendance for working days in a month
	this->bonus = 0.0;
	this->deductions = 0.0;
	totalEmployees++;//incrementing counter for every time an employee is created

}


//destructor:
Employee::~Employee() {
	totalEmployees--; //decrementing for everytime an employee is removed from the system
}


//getters:
string Employee::getDepartment() const {
	return department;
}
string Employee::getRole() const {
	return role;
}
double Employee::getMonthlySalary() const {
	return monthlySalary;
}
int Employee::getDaysAttended() const {
	return daysAttended;
}
double Employee::getBonus() const {
	return bonus;
}
double Employee::getDeductions() const {
	return deductions;

}


//setters:
void Employee::setDepartment(string d) {
	department = d;
}
void Employee::setRole(string r) {
	role = r;
}
void Employee::setMonthlySalary(double s) {
	monthlySalary = s;
}
void Employee::setDaysAttended(int days) {
	daysAttended = days;
}
void Employee::addBonus(double b) { //accumulates by summing the bonuses
	bonus += b;
}
void Employee::addDeduction(double d) {//accumulates by summing the deductions
	deductions += d;

}


//static function:
int Employee::getTotalEmployees() {
	return totalEmployees;
}

//calculate salary function:
//base salary: monthly salary + bonuses - deductions
double Employee::calculateSalary() const {
	return monthlySalary + bonus - deductions;

}


//display Info function:
void Employee::displayInfo() const {

	cout << "\n=============================\n" << endl;
	cout << "Type: Employee" << endl;
	cout << "Name: " << name << endl;
	cout << "ID: " << id << endl;
	cout << "Department: " << department << endl;
	cout << "Role: " << role << endl;
	cout << "Days Attended: " << daysAttended << endl;
	cout << "Bonuses: $" << bonus << endl;
	cout << "Deductions: $" << deductions << endl;
	cout << "Net Salary: $" << calculateSalary() << endl;


}


//toFileString format: E, id, name, dept, role, salary, daysAttended, bonus, deductions
//to_string() will convert integer and double variables into strings so that we can link 
//everything together with "+":

string Employee::toFileString() const {
	return "E," + to_string(id) + "," + name + "," + department + "," + role + ","
		+ to_string(monthlySalary) + "," + to_string(daysAttended) + "," + to_string(bonus) +
		"," + to_string(deductions);
	//this makes it into one string line so its easier to work with during file i/o implementation.
}



