
#pragma once
#include <vector>
#include <string>
#include "Employee.h"
#include "Manager.h"
#include "Intern.h"

using std::string;// only brings in string
using std::cout;  // only brings in cout if you need it in the header
using std::vector; //only brings in vector


// this class acts like the "controller" of the whole program
// it stores all employees and handles operations on them


class EmployeeManagementSystem {
private:
    vector<Person*> employees; // one list to store ALL types (polymorphism)
    string filename;

public:
    // constructor
    EmployeeManagementSystem(string filename);


    // destructor (must clean up dynamic memory)
    ~EmployeeManagementSystem();


    // core features
    void addEmployee(Person* emp);
    void removeEmployee(int id);
    void updateAttendance(int id, int days);
    void updateBonus(int id, double bonus);
    void updateDeduction(int id, double amount);

    //display features
    void displayAll() const; //shows employees with their informations
    void displayPayroll() const; //shows payroll for all employees
    void displaySummary() const; //shows totals


    //search features
    Person* searchByID(int id) const;
    void searchByName(string name) const;


    // file handling
    void saveToFile(); //writes to the file
    void loadFromFile(); //reads from employees.txt

    //menu function
    void runMenu(); //main loop of the program, keeps running until user exits the program


private:

    int getNextID() const; //helper function to get the next available ID

};

