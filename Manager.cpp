
#include "Manager.h"
#include <iostream>


using namespace std;


// Define static member outside class
int Manager::totalManagers = 0;


// default constructor
// starts everything at zero/empty, including the performance bonus
Manager::Manager() : Employee() {
    performanceBonus = 0.0;
    teamSize = 0;
    totalManagers++;

}


// parameterized constructor
// builds a manager object with all basic employee info + performance bonus
Manager::Manager(string name, int id, string dept, double salary, double perfBonus, int teamSize)
    : Employee(name, id, dept, "Manager", salary) {

    this->performanceBonus = perfBonus;

    this->teamSize = teamSize;

    totalManagers++;


}


// destructor
// nothing extra needed here, but defined for completeness
Manager::~Manager() {

    totalManagers--;


}

//getters
double Manager::getPerformanceBonus() const {
    return performanceBonus;
}

int Manager::getTeamSize() const {
    return teamSize;
}

// setters
void Manager::setPerformanceBonus(double b) {
    performanceBonus = b;
}

void Manager::setTeamSize(int t) {
    teamSize = t;

}


//static

int Manager::getTotalManagers() {
    return totalManagers;
}

// custom salary calculation for managers (overriden)
// combines base salary, performance reward, and adjusts for bonuses/deductions
double Manager::calculateSalary() const {
    return monthlySalary + performanceBonus + bonus - deductions; 
    //differs from normal salary because managers add a performance bonus on top
}


// prints all relevant manager details in a readable layout
void Manager::displayInfo() const {
    cout << "\n=============================\n" << endl;
    cout << "Type: Manager" << endl;
    cout << "Name: " << name << endl;
    cout << "ID: " << id << endl;
    cout << "Department: " << department << endl;
    cout << "Team Size: " << teamSize << endl;
    cout << "Days Attended: " << daysAttended << endl;
    cout << "Performance Bonus: $" << performanceBonus << endl;
    cout << "Bonuses: $" << bonus << endl;
    cout << "Deductions: $" << deductions << endl;
    cout << "Net Salary: $" << calculateSalary() << endl;
}


// prepares a comma-separated string version of the manager
// makes it easy to store and reload later from a file
string Manager::toFileString() const {
    return "M," + to_string(id) + "," + name + "," + department + "," + to_string(monthlySalary) + "," + 
        to_string(performanceBonus) + "," + to_string(teamSize) + "," +
        to_string(daysAttended) + "," + to_string(bonus) + "," +
        to_string(deductions);
}
