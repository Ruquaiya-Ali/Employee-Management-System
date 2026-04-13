
#pragma once
#include <string>
#include "Employee.h"
using std::string;// only brings in string
using std::cout;  // only brings in cout if you need it in the header


// Manager is a specialized type of Employee
// It keeps everything from Employee but adds an extra reward based on performance


class Manager : public Employee {


private:
    double performanceBonus; // extra earnings tied to how well the manager performs
    int teamSize;
    static int totalManagers;

public:
    // constructors
    Manager();
    Manager(string name, int id, string dept, double salary, double perfBonus, int teamSize);


    // destructor
    ~Manager();

    //getters:
    // returns the manager’s performance bonus
    double getPerformanceBonus() const;
    int getTeamSize() const;

    //setters:
    // allows updating the performance-based bonus
    void setPerformanceBonus(double b);
    void setTeamSize(int t);

    static int getTotalManagers();

    //override virtual functions:
    // redefines how salary is calculated specifically for managers
    double calculateSalary() const override;


    // prints out all manager-specific details in a clean format
    void displayInfo() const override;


    // converts manager data into a single line string (used when saving to file)
    string toFileString() const override;
};
