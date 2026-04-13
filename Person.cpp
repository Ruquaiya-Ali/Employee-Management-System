
// Person.cpp

#include "Person.h"
//Ruquaiya Ali
using namespace std;
//default constructor (initializing to empty/zero)
Person::Person() {

	name = "";
	id = 0;
	address = "";
	phone = "";

}


//parameterized constructor (fields are set at time of creation)
Person::Person(string name, int id, string address, string phone) {
	this->name = name; //using "this->" because the parameter names match member names
	this->id = id;
	this->address = address;
	this->phone = phone;


}


//virtual destructor: (must be defined even if body is empty)
Person::~Person(){}


//getters:
string Person::getName() const {
	return name;
}
int Person::getID() const {
	return id;
}
string Person::getAddress() const {
	return address;
}
string Person::getPhone() const {
	return phone;
}



//setters:
void Person::setName(string n) {
	name = n;
}
void Person::setAddress(string a) {
	address = a;
}
void Person::setPhone(string p) {
	phone = p;
}