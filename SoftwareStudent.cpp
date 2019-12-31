#include <iostream>
#include "SoftwareStudent.h"

//Empty constructor creates security student initializes base student class
SoftwareStudent::SoftwareStudent() : Student() {
	degree_type = SOFTWARE;
}

SoftwareStudent::SoftwareStudent(std::string studentID, std::string first_name, std::string last_name, std::string email_address,
	int age, int number_of_days[], Degree degree)
	: Student(studentID, first_name, last_name, email_address, age, number_of_days) {
	degree_type = SOFTWARE;
}

Degree SoftwareStudent::get_degree_type() {
	return SOFTWARE;
}

void SoftwareStudent::print() {
	this->Student::print();
	std::cout << "Degree Program: SOFTWARE" << std::endl;
}

SoftwareStudent::~SoftwareStudent() {
	Student::~Student();
}