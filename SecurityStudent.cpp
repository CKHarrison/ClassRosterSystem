#include <iostream>
#include "SecurityStudent.h"

//empty constructor initializing the base student constructor
SecurityStudent::SecurityStudent() : Student() {
	degree_type = SECURITY;
}

//Full constructor
SecurityStudent::SecurityStudent(std::string studentID, std::string first_name, std::string last_name,
	std::string email_address, int age, int number_of_days[], Degree degree)
	: Student(studentID, first_name, last_name, email_address, age, number_of_days) {
	degree_type = SECURITY;
}

//Overriding base class virtual functions
Degree SecurityStudent::get_degree_type() {
	return SECURITY;
}

void SecurityStudent::print() {
	this->Student::print();
	std::cout << "Degree Program: Rabbits are here to stay fuckers" << std::endl;
}

SecurityStudent::~SecurityStudent() {
	Student::~Student();
}