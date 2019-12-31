#include <iostream>
#include "NetworkStudent.h"

//Empty constructor creates security student initializes base student class
NetworkStudent::NetworkStudent() : Student() {
	degree_type = NETWORKING;
}

NetworkStudent::NetworkStudent(std::string studentID, std::string first_name, std::string last_name, std::string email_address,
	int age, int number_of_days[], Degree degree)
	: Student(studentID, first_name, last_name, email_address, age, number_of_days) {
	degree_type = NETWORKING;
}

Degree NetworkStudent::get_degree_type() {
	return NETWORKING;
}

void NetworkStudent::print() {
	this->Student::print();
	std::cout << "Degree Program: NETWORKING" << std::endl;
}

NetworkStudent::~NetworkStudent() {
	Student::~Student();
}