
//main.cpp
#include "EMS.h"

//this is the entry point of the program

//in this file, we create the EMS object (pointing at our txt file)
//then load any existing employees from the file
//present the menu
//then the user exits the program, we use the destructors to free memory


int main() {


	//create the system: "employees.txt" is the txt file
	EmployeeManagementSystem ems("employees.txt");

	//reading and loading any previous data to the file
	ems.loadFromFile();


	//runnig the main menu until user chooses to exit the program
	ems.runMenu();

	//after user exits, ems destructor runs automatically, and deletes everthing to free memory


	return 0;



}





