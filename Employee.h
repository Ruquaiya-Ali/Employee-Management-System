#pragma once
//Employee.h

#include "Person.h"

//Ruquaiya Ali
#include <string>

using std::string;// only brings in string
using std::cout;  // only brings in cout if you need it in the header


//The "Employee" class inherits from "Person" (it's a derived class)
//it represents a general full-time employee with a salary
//also, it overrides "calculateSalary()" and "displaInfo()" from "Person".



class Employee : public Person {

protected: //these are protected so manager/intern can access once they've been derived
	string department;
	string role;
	double monthlySalary;
	int daysAttended;
	double bonus;
	double  deductions;


private:
	static int totalEmployees; //static member (ONE copy is shared among all objects)
	//this will track the total number of employees logged in the system



public:
	//constructors:
	Employee(); //default
	Employee(string name, int id, string dept, string role, double salary); //parameterized

	//destructor:
	virtual ~Employee();

	//getters:
	string getDepartment() const;
	string getRole() const;
	double getMonthlySalary()const;
	int getDaysAttended() const;
	double getBonus() const;
	double getDeductions() const;


	//setters:
	void setDepartment(string d);
	void setRole(string r);
	void setMonthlySalary(double s);
	void setDaysAttended(int days);
	void addBonus(double b);
	void addDeduction(double d);

	static int getTotalEmployees(); //static member function, can be called without an object


	//override the pure virtual functions from "Person"
	//salary = monthlySalary + bonus - deductions
	double calculateSalary() const override;
	void displayInfo() const override;
	string toFileString() const override;


};
