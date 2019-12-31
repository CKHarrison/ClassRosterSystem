#include <iostream>
#include "SecurityStudent.h"

//Empty constructor creates security student initializes base student class
SecurityStudent::SecurityStudent() : Student() {
	degree_type = SECURITY;
}

SecurityStudent::SecurityStudent(std::string studentID, std::string first_name, std::string last_name, std::string email_address,
	int age, int number_of_days[], Degree degree)
	: Student(studentID, first_name, last_name, email_address, age, number_of_days) {
	degree_type = SECURITY;
}

Degree SecurityStudent::get_degree_type() {
	return SECURITY;
}

void SecurityStudent::print() {
	this->Student::print();
	std::cout << "Degree Program: SECURITY" << std::endl;
}

SecurityStudent::~SecurityStudent() {
	Student::~Student();
}