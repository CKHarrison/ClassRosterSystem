#include <iostream>
#include "SoftwareStudent.h"

//empty softwareStudent constructor with the initialization of the base Student constructor
SoftwareStudent::SoftwareStudent() : Student() {
	//setting the degree type enum;
	degree_type = SOFTWARE;
}

//full constructor
SoftwareStudent::SoftwareStudent(std::string studentID, std::string first_name, std::string last_name,
	std::string email_address, int age, int number_of_days[], Degree degree)
	:Student(studentID, first_name, last_name, email_address, age, number_of_days) { //initialization of Student base class

	degree_type = SOFTWARE;
}

//Overriding base class virtual functions
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