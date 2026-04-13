
// EMS.cpp 


#include "EMS.h"
//Ruquaiya Ali

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;


//constructor:
EmployeeManagementSystem::EmployeeManagementSystem(string filename) {

	this->filename = filename;

}

//destructor: need this since we are dynamicallly creating everu single employee with "new", 
//so the pointers must be deleted to avoid leaking memory
EmployeeManagementSystem:: ~EmployeeManagementSystem() {
	for (int i = 0; i < employees.size(); i++) {
		delete employees[i]; //freeing memory

	}

	employees.clear();
}


//add employee funciton implementation
void EmployeeManagementSystem::addEmployee(Person* emp) {
	employees.push_back(emp);

	cout << "\nEmployee was added successfully.\n";
}


//remove employee function implementation
void EmployeeManagementSystem::removeEmployee(int id) {
	for (int i = 0; i < employees.size(); i++) { //searching through vector of employees 


		if (employees[i]->getID() == id) { //searching by id, and if found, delete the employee
			delete employees[i];//free memory

			employees.erase(employees.begin() + i); //erases the employee from the vector
			cout << "\nEmployee with ID: " << id << " was removed.\n"; //display if employee was found

			return;


		}

	}
	//if no employee was found, continue to display this message
	cout << "\nEmployee with ID " << id << " was not found.\n";

}


//updating attendance function implementation
void EmployeeManagementSystem::updateAttendance(int id, int days) {

	for (int i = 0; i < employees.size(); i++) {

		if (employees[i]->getID() == id) { //searching through vector using employee's id
			

			Employee* emp = (Employee*)employees[i]; //if found.....

			emp->setDaysAttended(days); //updating the attendance using setter
			cout << "\nEmployee attendace was updated.\n";//displaying message for update
			return;

		}

		

	}
	 //if not found
	cout << "\nEmployee was not found.\n";


}




//updating bonus function implementation
void EmployeeManagementSystem::updateBonus(int id, double bonus) {

	for (int i = 0; i < employees.size(); i++) { //searching through vector using the employee's id

		if (employees[i]->getID() == id) {

		
		Employee* emp = (Employee*)employees[i]; //if found....

		emp->addBonus(bonus); //add the bonuses
		cout << "\nEmployee's Bonus was added.\n"; //display this message
		return;
		}
		
		

	}
	//if not found

	cout << "\nEmployee not found.\n";



}



//updating employee deductions fuction implementation

void EmployeeManagementSystem::updateDeduction(int id, double amount) {

	for (int i = 0; i < employees.size(); i++) {

		if (employees[i]->getID() == id) { //searching throgh vector using emp id

			Employee* emp = (Employee*)employees[i]; //if found

			emp->addDeduction(amount); //add deduction to emp's salary

			cout << "\nSalary Deduction added.\n"; //display this
		return;
		}

		


	}

	//if not found
	cout << "\nEmployee not found.\n";


}




//displaying employee details funciton implementation

//the loop in this function demonstrates polymorphism,
// because each type of employe will be displayed correctly, even though they are distinct

void EmployeeManagementSystem::displayAll() const {

	if (employees.empty()) { //if there are no employees yet

		cout << "\nThere are cuurently no employees logged in the system.\n";
	return;
	}
	
	cout << "\n======== All Employee Information ========\n";
	for (int i = 0; i < employees.size(); i++) {
		employees[i]->displayInfo(); //since it is virtual,
		//it will call the specific version for each type of employee


	}



}



//displaying employee payroll details function implementation

void EmployeeManagementSystem::displayPayroll() const {
	cout << "\n======== Payroll Report ========\n";
	//setpreciosion for formating
	cout << left << setw(5) << "ID" << setw(20) << "Name" << setw(15) << "Type" << setw(12) << "Net Salary" << endl;

	cout << string(40, '=') << endl;

	double total = 0;
	for (int i = 0; i < employees.size(); i++) {

	// toFileString() is virtual and returns "E,...", "M,...", or "I,..."
	// so the first character tells us exactly what type of fucntion it is
	char typeChar = employees[i]->toFileString()[0];
	string type = "Employee";
	if (typeChar == 'M') type = "Manager";
	else if (typeChar == 'I') type = "Intern";

	double salary = employees[i]->calculateSalary(); //again, virtual function being called
	total += salary;


	cout << left << setw(5) << employees[i]->getID() << setw(20)
		<< employees[i]->getName() << setw(15) << type << "$" << fixed 
		<< setprecision(2) << salary << endl;

	}

	cout << string(40, '=') << endl;
	
	cout << "\n======== Total Payroll ========\n";


}




//displaying system summary function implementation
void EmployeeManagementSystem::displaySummary() const {

	cout << "\n======== System Summary ========\n";
	cout << "\nTotal Employees (all types): " << Employee::getTotalEmployees() << endl;
	cout << "\nManagers: " << Manager::getTotalManagers();
	cout << "\nInterns: " << Intern::getTotalInterns();


}


//searching by ID fucntion implementation
Person* EmployeeManagementSystem::searchByID(int id) const {

	for (int i = 0; i< employees.size(); i++) {
		
		if (employees[i]->getID() == id) { //searching thru vector
			return employees[i]; //return employee at that index, if found

		}


	}//if not found...

	return nullptr; 
	cout << "\nSorry, could not find employee with that ID.\n";

}


//find and display by name funciton implementation
void EmployeeManagementSystem::searchByName(string name) const {

	bool found = false; //bool var to keep track of if found or not
	for (int i = 0; i< employees.size(); i++) {

		if (employees[i]->getName() == name) { //if found...
			employees[i]->displayInfo(); //display their info

			found = true; //change bool to true

		}


	}// if not found...
	
	if (!found) cout << "\nNo employee found with the name: '" << name << "'\n";



}






//reaidng from file function implementation (loadfromfile)
//this will read the employees.txt file and create the employee objects, each line
//will start with E, M, or I, in order to identify the type of employee

void EmployeeManagementSystem::loadFromFile() {

	ifstream file(filename);
	if (!file) {
		cout << "\nNo existing data was found, freshly starting the system .\n";
		return;
	}

	char type; //for type of employee (E,M or I)

	while (file >> type) { //reads one character (either E, M, or I)

		file.ignore();//this skips the comma after E,M,I


		if (type == 'E') { //if employee...
			int id, daysAttended;
			double salary, bonus, deductions;
			string name, dept, role;

			//reading each field, using file.ignore() to ignore commas after number entries
			// using getline func to read string entries 
			file >> id; file.ignore();
			getline(file, name, ',');
			getline(file, dept, ',');
			getline(file, role, ',');
			file >> salary; file.ignore();
			file >> daysAttended; file.ignore();
			file >> bonus; file.ignore();
			file >> deductions;
			//end of reading

			//dynamically creating an employee to populate the vector
			// based on the employee data from line that was just read
			Employee* e = new Employee(name, id, dept, role, salary);
			e->setDaysAttended(daysAttended);
			if (bonus > 0) {
				e->addBonus(bonus);
			}
			if (deductions > 0) {
				e->addDeduction(deductions);
			}

			employees.push_back(e);


		}else if (type == 'M') {//if manager....
			int id, teamSize, daysAttended;
			double salary, perfBonus, bonus, deductions;
			string name, dept;


			//reading each field, using file.ignore() to ignore commas after number entries
			// using getline func to read string entries   
			file >> id; file.ignore();
			getline(file, name, ',');
			getline(file, dept, ',');
			file >> salary; file.ignore();
			file >> perfBonus; file.ignore();
			file >> teamSize; file.ignore();
			file >> daysAttended; file.ignore();
			file >> bonus; file.ignore();
			file >> deductions;
			//end of reading
			//dynamically creating a manager to populate the vector
			//based on the manager data from line that was just read
			Manager* m = new Manager(name, id, dept, salary, perfBonus, teamSize);
			m->setDaysAttended(daysAttended);
			if (bonus > 0) {
				m->addBonus(bonus);
			}
			if (deductions > 0) {
				m->addDeduction(deductions);
			}

		employees.push_back(m);

		}	
		else if (type == 'I') {

			int id, hoursWorked;
			double hourlyRate;
			string name, dept, school;

			//reading each field, using file.ignore() to ignore commas after number entries
			// using getline func to read string entries 
			file >> id; file.ignore();
			getline(file, name, ',');
			getline(file, dept, ',');
			file >> hourlyRate; file.ignore();
			file >> hoursWorked; file.ignore();
			getline(file, school, ',');
			//end of reading

			//dynamically creating an intern to populate the vector
			//based on the intern data from line that was just read
			Intern* i = new Intern(name, id, dept, hourlyRate, hoursWorked, school);

			employees.push_back(i);

		}

	}//after reading through all the entries and storing all the data, close the file
	file.close();
	cout << "\nData was successfully loaded from " << filename << "\n";

}


//writing into files function implementation
//this writes employee data and saves it to the file
//each object will know how to format its own line 
// (toFileString, using E, M, or I in the beginning etc)

void EmployeeManagementSystem::saveToFile() {
	ofstream file(filename);
	if (!file) {
		cout << "\nError, could not open the file for saving.\n";
		return;
	}


	for (int i = 0; i < employees.size(); i++) {
		file << employees[i]->toFileString() << "\n"; //virtual function being called
		//object wilk know what formatting to use depending on type of employee it is

	} file.close();
	cout << "\nData successfully saved to " << filename << endl;

}

//getting next id helper funciton implementation
//this works by going thru all existing employees,
//finding the highest ID number currently in use,
//then returning that ID number + 1 to represent the next available ID number
int EmployeeManagementSystem::getNextID() const {
	int maxID = 1000;

	for (int i = 0; i < employees.size(); i++) {

		if (employees[i]->getID() > maxID) {
			maxID = employees[i]->getID();

		}
		

	}
	return maxID + 1;
}


//Main Menu loops implementation
void EmployeeManagementSystem::runMenu() {
	
	int choice= 0;

	while (choice != 9) {

		cout << "\n========================================\n";
		cout << "\n   EMPLOYEE MANAGEMENT SYSTEM\n";
		cout << "\n========================================\n";

		cout << "\n1. add an Employee\n";
		cout << "\n2. Add a Manager\n";
		cout << "\n3. Add an Intern\n";
		cout << "\n4. Remove an Employee\n";
		cout << "\n5. Search by ID\n";
		cout << "\n6. Display all Employees\n";
		cout << "\n7. Display Payroll\n";
		cout << "\n8. Update Attendance, Bonuses, or Deductions\n";
		cout << "\n9. Save & Exit the program\n";

		cout << "\n\nEnter choice: ";
		cin >> choice;


		if (choice == 1) {

			//add Employee
			string name, dept, role;
			double salary = 0.0;
			int id = getNextID(); 
			//this assigns id number based on if there are any employees
			//already logged into the program and just assigns it the previous employee's ID + 1

			cout << "\nName: "; cin.ignore(); getline(cin, name);
			cout << "\nDepartment: "; getline(cin, dept);
			cout << "\nRole: "; getline(cin, role);
			cout << "\nMonthly Salary: $"; 
			cin >> salary;

			addEmployee(new Employee(name, id, dept, role, salary));
			//added a new employee with the above info

		}


		else if (choice == 2) {

			//add a manager


			string name, dept;
			double salary = 0.0;
			double perfBonus = 0.0;
			int teamSize;
			int id = getNextID();

			cout << "\nName: "; cin.ignore(); getline(cin, name);
			cout << "\nDepartment: "; getline(cin, dept);
			cout << "\nMonthly Salary: $"; 
			cin >> salary;
			cout << "\nPerformance Bonus: $"; 
			cin >> perfBonus;
			cout << "\nTeam Size: ";
			cin >> teamSize;

			addEmployee(new Manager(name, id, dept, salary, perfBonus, teamSize));
			//added a new manager with the above info




		}


		else if (choice == 3) {
			//add an intern
			string name, dept, school;
			double hourlyRate = 0.0;
			int hours;
			int id = getNextID();

			cout << "\nName: "; cin.ignore(); getline(cin, name);
			cout << "\nDepartment: "; cin.ignore(); getline(cin, dept);
			cout << "\nSchool: "; cin.ignore(); getline(cin, school);
			cout << "\nHourly rate: $"; 
			cin >> hourlyRate;
			cout << "\nHours worked: ";
			cin >> hours;

			addEmployee(new Intern(name, id, dept, hourlyRate, hours, school));//fix this
			//added a new intern with the above info



		}
		else if(choice == 4) {

			//remove an employee
			int id;

			cout << "\nEnter Employee's ID to remove them: ";
			cin >> id;

			removeEmployee(id); //removeEmployee() gets called with ID as parameter



		}
		else if (choice == 5) {
			//search by id	

			int id;

			cout << "\nEnter ID to search: ";
			cin >> id;

			Person* p = searchByID(id);

			if (p) { //if person with that ID exists....

			p->displayInfo(); //display their info

			}
			else {
				cout << "\nPerson not found.\n"; //otherwise, display this

			}
			



		}
		else if (choice == 6) {
			//display all
			displayAll();
			displaySummary();
			

		}
		else if (choice == 7) {
			//display payroll info
			displayPayroll();

		}
		else if (choice == 8) {
			//update their attendance, bonuses, and deductions
			int id;
			int selection;

			cout << "\nEnter Employee ID: ";
			cin >> id;

			cout << "\n1. Update Employee attendance\n";
			cout << "\n2. Update Employee's bonuses\n";
			cout << "\n3. Update Employee's deductions\n";
			cout << "\nMake a selection: ";

			cin >> selection;

			if (selection == 1) {
				int days;
				cout << "\nDays attended (out of 22 working days): ";
				cin >> days;

				updateAttendance(id, days); //call update attendance function


			}
			else if (selection == 2) {

				double b;
				cout << "\nAdd Bonus Amount: $";
				cin >> b;
				
				updateBonus(id, b); //call update bonus funciton


			}
			else if (selection == 3) {
				double d;
				cout << "\nEnter Deduction Amount: $";
				cin >> d;

				updateDeduction(id, d); //call update deduction function
				 

			}


		}
		else if (choice == 9) {


			saveToFile();
			cout << "\n\nExiting the program. Goodbye\n";
			//exit message
		}
		else {

			cout << "\n\nInvalid choice, please enter an integer from 1 - 9.\n";
			//input validation

		}



	}



}







