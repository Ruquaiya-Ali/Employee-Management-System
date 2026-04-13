
#pragma once
// This class represents interns who are paid hourly.
// It further demonstrates many forms.

#include "Employee.h"
#include <string>
// Intern.h
using std::string;// only brings in string
using std::cout;  // only brings in cout if you need it in the header





class Intern : public Employee {

private:
    double hourlyRate;
    int hoursWorked;
    string school;

    static int totalInterns;


public:

    // Default constructor
    Intern();
    // Parameterized constructor
    Intern(string name, int id, string dept, double hourlyRate, int hoursWorked, string school);

    //destructor
    ~Intern();


    //getters:
    double getHourlyRate() const;
    int getHoursWorked() const;
    string getSchool() const;

    //setters: 
    void setHourlyRate(double r);
    void setHoursWorked(int h);
    void setSchool(string s);
    
    //static func
    static int getTotalInterns();


    //overide virtual functions, intern salary differs because there is no monthly base salary
    //intern salary = hourlyrate * hoursworked

    double calculateSalary() const override;
    void displayInfo() const override;
    string toFileString() const override;


};
