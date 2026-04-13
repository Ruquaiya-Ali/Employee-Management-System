#pragma once
//Person.h


//Ruquaiya Ali
#include <string>
#include <iostream>
using std::string;// only brings in string
using std::cout;  // only brings in cout if you need it in the header


//creating abstract base class called "Person"
//other objects must inherit from this class
//this class provides shared attributes using pure virtual functions for all people in the EMS


class Person {

protected: //so that derived classes can access

	string name;
	int id;
	string address;
	string phone;


public:
	//constructors:

	Person(); //default constructor
	Person(string name, int id, string address, string phone); //parameterized constructor


	//virtual destructor:
	virtual ~Person();

	//getters:
	string getName() const;
	int getID() const;
	string getAddress() const;
	string getPhone() const;

	//setters: 
	void setName(string n);
	void setAddress(string a);
	void setPhone(string p);

	//pure virtual functions: 
	// = 0 meaning no implementation,
	// every derived class must override these (asbtract)
	virtual double calculateSalary() const = 0;
	virtual void displayInfo() const = 0;
	virtual string toFileString() const = 0; //for file saving


};
